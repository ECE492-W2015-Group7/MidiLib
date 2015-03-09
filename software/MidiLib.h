/*
 * MidiLib.h
 *
 *  Created on: 2015-03-07
 *      Author: eorodrig
 */

#ifndef MIDILIB_H_
#define MIDILIB_H_

void processNote(int noteStatus, int pitch, int velocity);
float midiFreq2sampleFreq(float midiFreq);
float midiNote2midiFreq(int midiNote);
int turnOffVoice(int noteNum, int velocity);
int turnOnVoice(int noteNum, int velocity,float sampleFreq);
void sendNoteOff2Voice( int voiceNum);
void sendNoteOn2Voice( int voiceNum, float sampleFreq);
void fetchSynthAddresses(int voiceNum, double ** voicePhaseAddr, int ** noteOffAddr, int ** waveformShapesAddr);
void initAudioCodec();



#endif /* MIDILIB_H_ */
