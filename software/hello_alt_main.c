#include <stdio.h>
#include <string.h>
#include "includes.h"
#include "altera_up_avalon_character_lcd.h"
#include "midiLib.h"

#define   TASK_STACKSIZE       2048
#define   INPUT_POLLING_TASK_PRIORITY      1
#define   NUMBER_OF_LASER 8
OS_STK    inputPollingTaskStack[TASK_STACKSIZE];

void inputPollingTask(void* pdata){
	alt_up_character_lcd_dev * char_lcd_dev;
	int laserStatus;
	int* laserStatusPointer =(int* )SWITCH_BASE;
	int previousLaserStatus;

	//=========== init LCD ===========
	char_lcd_dev = alt_up_character_lcd_open_dev ("/dev/character_lcd_0");
	if ( char_lcd_dev == NULL)
		alt_printf ("Error: could not open character LCD device\n");
	else
		alt_printf ("Opened character LCD device\n");
	alt_up_character_lcd_init (char_lcd_dev);
	alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
	alt_up_character_lcd_string(char_lcd_dev, "MIDIGeneratorPrototype");

	//=========== Start polling  ===========
	while (1){
		previousLaserStatus = laserStatus;
		laserStatus = *laserStatusPointer;
		if (previousLaserStatus!=laserStatus){
			printLaserStatusOnLCD(char_lcd_dev,laserStatus);	//For debugging
			handleLaserStatusChange(previousLaserStatus,laserStatus);
		}
	}
}

/*
 * Handles changes on laserStatus, and send the corresponding MIDI signal to midiOut
 * Input: int previousStatus, int currentStatus
 */
void handleLaserStatusChange(int previousStatus, int currentStatus){
	int i;
	unsigned noteType; //0 = off 1 = on
	//Find bits that were changed
	int differentBits = previousStatus^currentStatus;		//XOR: 100 ^ 110 = 010
	int* midiOutPointer = (int*) MIDIOUT_0_BASE;
	for (i=0;i<NUMBER_OF_LASER;i++){
		if( ((1 << i) & (differentBits)) == (1 << i) ){		//if laser i is changed
			noteType = ((currentStatus &  (1 << i)) ==  (1 << i)) ?  1: 0;
			*midiOutPointer =  getMidiData(i,noteType);
			processNote(1,getNotePitch(i,noteType),getVelocity(i,noteType));
		}
	}
}

/*
 * This function construct midi signal according to the midi specification 1.0
 * More information about the specification: http://www.somascape.org/midi/tech/spec.html
 * Input: int laserIndex, int noteType (0 = off 1 = on)
 * Output: int midiData
 */
int getMidiData(int laserIndex, int noteType){

	int laserToPitchMappingTable[]={60,62,64,65,67,69,71,73};	//C4 D4 E4 F4 G4 A4 B4 C5
	int statusByte;
	int pitchByte;
	int velocityBtye;
	int midiData;

	statusByte = 144; //10010000 Note On through midi channel 1
	pitchByte = laserToPitchMappingTable[laserIndex];
	if (noteType==1){
		//Defaults to 64 in the absence of velocity sensors
		velocityBtye = 64;
	}else{
		//when velocity is zero = Note Off
		velocityBtye = 0;
	}

	//formate: 	0 statusBtye 1	0 pitchByte 1	0 velocityByte 1
	midiData = (statusByte<<21) + (1<<20) + (0<<19) + (pitchByte<<11) + (1<<10) + (0<<9) + (velocityBtye<<1) +(1<<0);

	printf("Note %i\n",laserIndex);
	printf("NoteType %i\n",noteType);
	printf("midiData %i\n",midiData);
	return midiData;
}


int getNotePitch(int laserIndex, int noteType){
	int laserToPitchMappingTable[]={60,62,64,65,67,69,71,73};	//C4 D4 E4 F4 G4 A4 B4 C5
	return laserToPitchMappingTable[laserIndex];
}

int getVelocity(int laserIndex, int noteType){
	if (noteType==1){
		//Defaults to 64 in the absence of velocity sensors
		 return 64;
	}else{
		//when velocity is zero = Note Off
		 return 0;
	}
}
/*
 * Print laserStatus as 1 and 0 on the LCD for debugging.
 * Input: alt_up_character_lcd_dev * char_lcd_dev, int laserStatus
 */
void printLaserStatusOnLCD(alt_up_character_lcd_dev * char_lcd_dev, int laserStatus){
    static char message[9];
    message[0] = '\0';
    int i;
    for (i = 128; i > 0; i >>= 1){
        strcat(message, ((laserStatus & i) == i) ? "1" : "0");
    }
	alt_up_character_lcd_init (char_lcd_dev);
	alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
	alt_up_character_lcd_string(char_lcd_dev,"Laser Status:");
	alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 1);
	alt_up_character_lcd_string(char_lcd_dev, message);
}

int main(void){

	OSTaskCreateExt(inputPollingTask,
			NULL,
			(void *)&inputPollingTaskStack[TASK_STACKSIZE-1],
			INPUT_POLLING_TASK_PRIORITY,
			INPUT_POLLING_TASK_PRIORITY,
			inputPollingTaskStack,
			TASK_STACKSIZE,
			NULL,
			0);

	OSStart();
	return 0;
}
