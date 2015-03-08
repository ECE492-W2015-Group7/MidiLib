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


#include <stdio.h>
#include "includes.h"
#include <math.h>


/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2

/*Defines the buffer size */
#define     BUFFER_SIZE    128

//total number of lasers (voices)
#define 	TOTAL_VOICES	8


//WaveSelection
#define		WAVE_SINE		32
#define		WAVE_SAW		8
#define		WAVE_SQUARE		1
#define		WAVE_NONE		0

//this is the size of our LUT
#define		SINE_TABLE_SIZE		4096
#define		FREQ_MAX			4294967296


//MIDI Signals received == 3 bytes
//Byte 1: Note status
//This defines the note statuses
#define		NOTE_ON			1
#define		NOTE_OFF		0



//Byte 2: Pitch (Note)
//this defines the notes frequencies
#define		FREQ_EMPTY_NOTE		0
#define 	FREQ_BASE			8.1757989156
#define		FREQ_CLK			50000000


#define		EMPTY_NOTE			0


//Byte 3: Velocity
//this defines the velocities
#define		OFF_VELOCITY	0

struct voice
{
	int status;
	int note;
	int velocity;
};

static struct voice VOICE_TABLE[TOTAL_VOICES];


//This will fetch memory address of the synthesizer components
void fetchSynthAddresses(int voiceNum, double ** voicePhaseAddr, int ** noteOffAddr, int ** waveformShapesAddr)
{
	*voicePhaseAddr =  12;
	*noteOffAddr = 3;
	*waveformShapesAddr = 14;


	//int *waveformShapesAddr = (int *)WAVEFORMGENERATOR_0_WAVE_SHAPES_BASE;

	/*
		//this gets the memory address of the selected memory components
		switch(voiceNum){
		case 0:
			voicePhaseAddr = (int *) WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE0_BASE;
			break;
		case 1:
			voicePhaseAddr = (int *) WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE1_BASE;
			break;
		case 2:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE2_BASE;
			break;
		case 3:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE3_BASE;
			break;
		case 4:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE4_BASE;
			break;
		case 5:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE5_BASE;
			break;
		case 6:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE6_BASE;
			break;
		case 7:
			voicePhaseAddr = (int *)WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_BASE;
			noteOffAddr = (int *) WAVEFORMGENERATOR_0_NOTE_END_VOICE7_BASE;
			break;
		default:
			voicePhaseAddr = 0;
			noteOffAddr = 0;
			break;

		}
		*/


}


//this sends the Note to selected voice

void sendNoteOn2Voice( int voiceNum, float sampleFreq)
{
	double *voicePhaseAddr = (int *)0;
	int *noteOffAddr = (int *)0;
	int *waveformShapesAddr = (int *)0;

	printf("A: %p\n",voicePhaseAddr);
	printf("B: %p\n",noteOffAddr);
	printf("C: %p\n",waveformShapesAddr);

	fetchSynthAddresses(voiceNum, &voicePhaseAddr,&noteOffAddr, &waveformShapesAddr);
	printf("A: %d\n",voicePhaseAddr);
	printf("B: %d\n",noteOffAddr);
	printf("C: %d\n",waveformShapesAddr);


	int sampleFreqOsc1=sampleFreq;
	printf("OSC1: %d\n",sampleFreqOsc1);
	int sampleFreqOsc2= sampleFreq *2;
	printf("OSC2: %d\n",sampleFreqOsc2);
	int sampleFreqOsc3= sampleFreq /2;
	printf("OSC3: %d\n",sampleFreqOsc3);

	//while the address is not 0
	if (voicePhaseAddr != 0)
	{
		unsigned int upper =   sampleFreqOsc1;
		unsigned int lower = (sampleFreqOsc2 << 16) + (sampleFreqOsc3);

		printf("Waveform: %d\n", WAVE_SINE + WAVE_SAW + WAVE_SQUARE);
		printf("hey1: %u\n",upper);
		printf("hey2: %u\n",lower);

		*voicePhaseAddr	= (upper << 32) + lower ;
		*noteOffAddr 	= 11;
		*waveformShapesAddr = WAVE_SINE + WAVE_SAW + WAVE_SQUARE;

	}


}


//this sends the Note to selected voice

void sendNoteOff2Voice( int voiceNum)
{
	double *voicePhaseAddr = (int *)0;
	int *noteOffAddr = (int *)0;
	int *waveformShapesAddr = (int *)0;

	printf("A: %d\n",voicePhaseAddr);
	printf("B: %d\n",noteOffAddr);
	printf("C: %d\n",waveformShapesAddr);

	fetchSynthAddresses(voiceNum, &voicePhaseAddr,&noteOffAddr, &waveformShapesAddr);
	printf("A: %d\n",voicePhaseAddr);
	printf("B: %d\n",noteOffAddr);
	printf("C: %d\n",waveformShapesAddr);


	//while the address is not 0
	if (voicePhaseAddr != 0)
	{
		*voicePhaseAddr	= 0;
		*noteOffAddr 	= 11;
		*waveformShapesAddr = WAVE_NONE;

	}


}



/**
 * This Iterate through the voice/note table and look for an empty voice
 * If it finds an unused (off) note, it will use that voice
 * If all the voices are used, it does nothing
 *
 * it returns the index
 */
int turnOnVoice(int noteNum, int velocity,float sampleFreq){

	int index = 0;

	  for (index = 0; index < TOTAL_VOICES; index++)
	  {
		  if (NOTE_OFF == VOICE_TABLE[index].status)
		  {
			  VOICE_TABLE[index].note = noteNum;
			  VOICE_TABLE[index].status = NOTE_ON;
			  VOICE_TABLE[index].velocity = velocity;

			  sendNoteOn2Voice(index,sampleFreq);

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
int turnOffVoice(int noteNum, int velocity){

	int index = 0;

	  for (index = 0; index < TOTAL_VOICES; index++)
	  {
		  if (noteNum == VOICE_TABLE[index].note)
		  {
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
float midiNote2midiFreq(int midiNote)
{
	return FREQ_BASE*pow(2,(midiNote/12));
}


/**
 * This will calculate the sampling frequency used to sample the SINE LUT
 */
float midiFreq2sampleFreq(float midiFreq)
{

	float sampleFreq = (midiFreq/FREQ_CLK)*FREQ_MAX;

	return sampleFreq;

}



/* Prints "Hello World" and sleeps for three seconds */
void PollForNotesTask(void* pdata)
{

	int noteStatus = NOTE_OFF;
	int pitch = 20;
	int velocity = 120;

	float midiFreq = 0;
	float sampleFreq = 0;
	int voiceNumber = 0;
	int testing = 0;
	int count = 0;

  while (1)
  { 
	  if (count  ==5)
	   {
		   testing =1;
	   }
	  if (count == -1)
	  {
		  testing =0;
	  }


	   if (testing == 0 && count  <5)
	  {

		  velocity = 10;
		    pitch = pitch + 20;

	  }
	  if(testing ==1 && count > -1 )
	   {

		   pitch = pitch - 20;
			  velocity = 0;


	   }

	   if (velocity != 0)
		  {
			  midiFreq = midiNote2midiFreq(pitch);
			  printf("MIDI FRQ: %f\n", midiFreq);
			  sampleFreq = midiFreq2sampleFreq(midiFreq);
			  printf("SAMPLE FRQ: %f\n", sampleFreq);
			  voiceNumber = turnOnVoice(pitch, velocity, sampleFreq);
			  printf("VOICE ON: %d\n", voiceNumber);
			  count++;

		  }
		  else
		  {
			  voiceNumber = turnOffVoice(pitch, velocity);
			  printf("VOICE OFF: %d\n", voiceNumber);
			  count--;

		  }

	  OSTimeDlyHMSM(0, 0, 5, 0);


  }
}







/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{

	int noteStatus = NOTE_ON;
	int pitch = 60;
	int velocity = 120;

	//Slong phase_inc =

	  //phase_inc =
  while (1)
  {
	  int x =1;
  }


}






/* The main function creates two task and starts multi-tasking */
int main(void)
{

  OSTaskCreateExt(PollForNotesTask,
                  NULL,
                  (void *)&task1_stk[TASK_STACKSIZE-1],
                  TASK1_PRIORITY,
                  TASK1_PRIORITY,
                  task1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);


  OSTaskCreateExt(task2,
                  NULL,
                  (void *)&task2_stk[TASK_STACKSIZE-1],
                  TASK2_PRIORITY,
                  TASK2_PRIORITY,
                  task2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
  OSStart();
  return 0;
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