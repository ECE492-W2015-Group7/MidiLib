/*************************************************************************
 * Copyright (c) 2004 Altera Corporation, San Jose, California, USA.      *
 * All rights reserved. All use of this software and documentation is     *
 * subject to the License Agreement located at the end of this file below.*
 **************************************************************************
 * Description:                                                           *
 * The following is a simple hello world program running MicroC/OS-II.The *
 * purpose of the design is to be a very simple application that just     *
 * demonstrates MicroC/OS-II running on NIOS II.The design doesn't account*
 * for issues such as checking system call return codes. etc.             *
 *                                                                        *
 * Requirements:                                                          *
 *   -Supported Example Hardware Platforms                                *
 *     Standard                                                           *
 *     Full Featured                                                      *
 *     Low Cost                                                           *
 *   -Supported Development Boards                                        *
 *     Nios II Development Board, Stratix II Edition                      *
 *     Nios Development Board, Stratix Professional Edition               *
 *     Nios Development Board, Stratix Edition                            *
 *     Nios Development Board, Cyclone Edition                            *
 *   -System Library Settings                                             *
 *     RTOS Type - MicroC/OS-II                                           *
 *     Periodic System Timer                                              *
 *   -Know Issues                                                         *
 *     If this design is run on the ISS, terminal output will take several*
 *     minutes per iteration.
 *
 *
 *     http://www.phy.mtu.edu/~suits/notefreqs.html
 *     newt.phys.unsw.edu.au/jw/notes.html                              *
 **************************************************************************/
#include "altera_avalon_jtag_uart_regs.h"
#include <stdio.h>
#include "altera_up_avalon_audio_and_video_config.h"
#include <math.h>
#include "system.h"

/*Defines the buffer size */
#define     BUFFER_SIZE    128

//total number of lasers (voices)
#define 	TOTAL_VOICES	8

//this is the size of our LUT
#define		 NUMBER_OF_POINTS_IN_WAVE_LUT		4096

//MIDI Signals received == 3 bytes
//Byte 1: Note status
//This defines the note statuses
#define		NOTE_ON			1
#define		NOTE_OFF		0

//Byte 2: Pitch (Note)
//this defines the notes frequencies
#define		FREQ_EMPTY_NOTE		0.0
#define 	FREQ_BASE			8.1757989156
#define		SAMPLE_RATE			32000

#define		EMPTY_NOTE			0

//Byte 3: Velocity
//this defines the velocities
#define		OFF_VELOCITY	0

// each voice has a status, pitch (note), and velocity
struct voice {
	int status;
	int note;
	int velocity;
};

//we need a list of 8 voices
static struct voice VOICE_TABLE[TOTAL_VOICES];

//This will fetch memory address of the synthesizer components
void fetchSynthAddresses(int voiceNum, long long ** voicePhaseAddr,
		int ** noteOffAddr, int ** waveformShapesAddr) {

	*waveformShapesAddr = SYNTHESIZER_0_WAVE_SHAPES_BASE;
	//this gets the memory address of the selected memory components
	switch (voiceNum) {
	case 0:
		*voicePhaseAddr = SYNTHESIZER_0_PHASE_INCREMENTS_VOICE0_BASE;
		*noteOffAddr =  SYNTHESIZER_0_NOTE_END_VOICE0_BASE;
		break;
	case 1:
		*voicePhaseAddr = SYNTHESIZER_0_PHASE_INCREMENTS_VOICE1_BASE;
		*noteOffAddr = SYNTHESIZER_0_NOTE_END_VOICE1_BASE;
		break;
	case 2:
		*voicePhaseAddr = SYNTHESIZER_0_PHASE_INCREMENTS_VOICE2_BASE;
		*noteOffAddr =  SYNTHESIZER_0_NOTE_END_VOICE2_BASE;
		break;
	case 3:
		*voicePhaseAddr =  SYNTHESIZER_0_PHASE_INCREMENTS_VOICE3_BASE;
		*noteOffAddr = SYNTHESIZER_0_NOTE_END_VOICE3_BASE;
		break;
	case 4:
		*voicePhaseAddr = SYNTHESIZER_0_PHASE_INCREMENTS_VOICE4_BASE;
		*noteOffAddr =  SYNTHESIZER_0_NOTE_END_VOICE4_BASE;
		break;
	case 5:
		*voicePhaseAddr = SYNTHESIZER_0_PHASE_INCREMENTS_VOICE5_BASE;
		*noteOffAddr = SYNTHESIZER_0_NOTE_END_VOICE5_BASE;
		break;
	case 6:
		*voicePhaseAddr =  SYNTHESIZER_0_PHASE_INCREMENTS_VOICE6_BASE;
		*noteOffAddr =  SYNTHESIZER_0_NOTE_END_VOICE6_BASE;
		break;
	case 7:
		*voicePhaseAddr =  SYNTHESIZER_0_PHASE_INCREMENTS_VOICE7_BASE;
		*noteOffAddr =  SYNTHESIZER_0_NOTE_END_VOICE7_BASE;
		break;
	default:
		*voicePhaseAddr = 0;
		*noteOffAddr = 0;
		break;
	}

}

//this sends the Note on command to selected voice

void sendNoteOn2Voice(int voiceNum, float sampleFreq) {
	long *voicePhaseAddr = (long *) 0;
	int *noteOffAddr = (int *) 0;
	int *waveformShapesAddr = (int *) 0;

	fetchSynthAddresses(voiceNum, &voicePhaseAddr, &noteOffAddr,
			&waveformShapesAddr);

	printf("A: %04x\n",voicePhaseAddr);
	printf("B: %04x\n",noteOffAddr);
	printf("C: %04x\n",waveformShapesAddr);

	int sampleFreqOsc0 = (int) sampleFreq;
	int sampleFreqOsc1 = (int) sampleFreq * 2;
	int sampleFreqOsc2 = (int) sampleFreq / 2;


	//while the address is not 0
	if (voicePhaseAddr != 0) {

		//IOWR_ALTERA_AVALON_JTAG_UART_DATA(waveformShapesAddr, 3);
		IOWR_ALTERA_AVALON_JTAG_UART_DATA(voicePhaseAddr, sampleFreqOsc0  );

		//00 01 10 11
		//1: Sin
		//2: Square
		//3: Saw
		//*waveformShapesAddr = 0<<5||1<<4||0<<3||1<<2||0<<1||1<<0;
	//	printf("Before: %02x\n", *waveformShapesAddr);


		//printf("After: %02x\n", *waveformShapesAddr);
	}

}

//this sends the Note off command to selected voice

void sendNoteOff2Voice(int voiceNum) {
	long long *voicePhaseAddr = (long long *) 0;
	int *noteOffAddr = (int *) 0;
	int *waveformShapesAddr = (int *) 0;

	fetchSynthAddresses(voiceNum, &voicePhaseAddr, &noteOffAddr,
			&waveformShapesAddr);

	//while the address is not 0
	if (voicePhaseAddr != 0) {
		*noteOffAddr = 1;
	}

}

/**
 * This Iterate through the voice/note table and look for an empty voice
 * If it finds an unused (off) note, it will use that voice
 * If all the voices are used, it does nothing
 *
 * it returns the index
 */
int turnOnVoice(int noteNum, int velocity, float sampleFreq) {

	int index = 0;

	for (index = 0; index < TOTAL_VOICES; index++) {
		if (NOTE_OFF == VOICE_TABLE[index].status) {
			VOICE_TABLE[index].note = noteNum;
			VOICE_TABLE[index].status = NOTE_ON;
			VOICE_TABLE[index].velocity = velocity;

			sendNoteOn2Voice(index, sampleFreq);

			return index;
		}
	}

	return -1;
}

/**
 * This Iterate through the voice/note table and look for a note to turn off
 * If it finds a specific note, it will reset the note to an off state
 * If it doesn't find it, it does nothing
 */
int turnOffVoice(int noteNum, int velocity) {

	int index = 0;

	for (index = 0; index < TOTAL_VOICES; index++) {
		if (noteNum == VOICE_TABLE[index].note) {
			VOICE_TABLE[index].note = EMPTY_NOTE;
			VOICE_TABLE[index].status = NOTE_OFF;
			VOICE_TABLE[index].velocity = OFF_VELOCITY;

			sendNoteOff2Voice(index);

			return index;
		}
	}

	return -1;
}

/**
 * This will calculate the frequency of the midi note
 */
float midiNote2midiFreq(int midiNote) {
	return FREQ_BASE * pow(2, (midiNote / 12));
}

/**
 * This will calculate the sampling frequency used to sample the SINE LUT
 */
float midiFreq2sampleFreq(float midiFreq) {

	float sampleFreq = (midiFreq / SAMPLE_RATE) * NUMBER_OF_POINTS_IN_WAVE_LUT;

	return sampleFreq;

}

/*This is the API for the midiDriver*
 * It requires the status of the note
 * the pitch (midi note numbeR)
 * and the velocity (velocity of 0 will result in note off
 */
void processNote(int noteStatus, int pitch, int velocity) {

	float midiFreq = 0;
	float sampleFreq = 0;
	int voiceNumber = 0;

	printf("passed MidiNote: %d\n", pitch);

	if (velocity != 0) {
		midiFreq = midiNote2midiFreq(pitch);
		printf("MIDI FRQ: %f\n", midiFreq);
		sampleFreq = midiFreq2sampleFreq(midiFreq);
		printf("SAMPLE FRQ: %f\n", sampleFreq);
		voiceNumber = turnOnVoice(pitch, velocity, sampleFreq);
		printf("VOICE ON: %d\n", voiceNumber);

	} else {
		voiceNumber = turnOffVoice(pitch, velocity);
		//printf("VOICE OFF: %d\n", voiceNumber);
	}

}

//Initializes Synthesizer Compo
void initMidiLib() {

	//alt_up_audio_dev * audio_dev;
	alt_up_av_config_dev * audio_config_dev;

	//  unsigned int l_buf[BUFFER_SIZE];
	//  int i = 0;
	//  int writeSizeL = 0;

	/* Open Devices */
	// audio_dev = alt_up_audio_open_dev ("/dev/audio_0");
	//  if ( audio_dev == NULL)
	//      printf("Error: could not open audio device \n");
	//  else
	//       printf("Opened audio device \n");
	audio_config_dev = alt_up_av_config_open_dev(AUDIO_AND_VIDEO_CONFIG_0_NAME);
	if (audio_config_dev == NULL)
		printf("Error: could not open audio config device \n");
	else
		printf("Opened audio config device \n");

	/* Configure WM8731 */
	//  alt_up_audio_reset_audio_core(audio_dev);
	alt_up_av_config_reset(audio_config_dev);

	/* Write to configuration registers in the audio codec; see datasheet for what these values mean */
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x0, 0x17);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x1, 0x17);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x2, 0xF9);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x3, 0xF9);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x4, 0x12);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x5, 0x06);
	alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x6, 0x00);

}

/******************************************************************************
 *                                                                             *
 * License Agreement                                                           *
 *                                                                             *
 * Copyright (c) 2004 Altera Corporation, San Jose, California, USA.           *
 * All rights reserved.                                                        *
 *                                                                             *
 * Permission is hereby granted, free of charge, to any person obtaining a     *
 * copy of this software and associated documentation files (the "Software"),  *
 * to deal in the Software without restriction, including without limitation   *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
 * and/or sell copies of the Software, and to permit persons to whom the       *
 * Software is furnished to do so, subject to the following conditions:        *
 *                                                                             *
 * The above copyright notice and this permission notice shall be included in  *
 * all copies or substantial portions of the Software.                         *
 *                                                                             *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
 * DEALINGS IN THE SOFTWARE.                                                   *
 *                                                                             *
 * This agreement shall be governed in all respects by the laws of the State   *
 * of California and by the laws of the United States of America.              *
 * Altera does not recommend, suggest or require that this reference design    *
 * file be used in conjunction or combination with any other product.          *
 ******************************************************************************/
