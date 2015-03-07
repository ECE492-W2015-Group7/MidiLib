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
*     minutes per iteration.                                             *
**************************************************************************/


#include <stdio.h>
#include "includes.h"
#include "C:\Users\eorodrig\ece492\SynthesizerPrototypeV2\altera_up_avalon_audio\HAL\inc\altera_up_avalon_audio.h"
#include "C:\Users\eorodrig\ece492\SynthesizerPrototypeV2\altera_up_avalon_audio_and_video_config\HAL\inc\altera_up_avalon_audio_and_video_config.h"


/* Definition of Task Stacks */
#define   TASK_STACKSIZE       2048
OS_STK    task1_stk[TASK_STACKSIZE];
OS_STK    task2_stk[TASK_STACKSIZE];

/* Definition of Task Priorities */

#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2

/*Defines the buffer size */
#define     BUFFER_SIZE    128

/* Prints "Hello World" and sleeps for three seconds */
void task1(void* pdata)
{

	alt_up_audio_dev * audio_dev;



	alt_up_av_config_dev * audio_config_dev;



	    unsigned int l_buf[BUFFER_SIZE];
	    int i = 0;
	    int writeSizeL = 0;



	    /* Open Devices */
//	   audio_dev = alt_up_audio_open_dev ("/dev/audio_0");
//	    if ( audio_dev == NULL)
//	        printf("Error: could not open audio device \n");
//	    else
//	        printf("Opened audio device \n");

//	    audio_config_dev = alt_up_av_config_open_dev(AUDIO_AND_VIDEO_CONFIG_0_NAME);
//	    if ( audio_config_dev == NULL)
//	        printf("Error: could not open audio config device \n");
//	    else
//	        printf("Opened audio config device \n");

	    /* Configure WM8731 */
	    //alt_up_audio_reset_audio_core(audio_dev);
//	    alt_up_av_config_reset(audio_config_dev);

	    /* Write to configuration registers in the audio codec; see datasheet for what these values mean */
///    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x0, 0x17);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x1, 0x17);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x2, 0x79);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x3, 0x79);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x4, 0x15);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x5, 0x06);
//	    alt_up_av_config_write_audio_cfg_register(audio_config_dev, 0x6, 0x00);

	    //main loop
	    while(1)
	    {
	            //read the data from the left buffer
	          //  writeSizeL = alt_up_audio_read_fifo(audio_dev, l_buf, BUFFER_SIZE, ALT_UP_AUDIO_LEFT);

	            //shift values to a proper base value
//	            for (i = 0; i < writeSizeL; i = i+1)
//	            {
//	                l_buf[i] = l_buf[i] + 0x7fff;
//	            }

	            //write data to the L and R buffers; R buffer will receive a copy of L buffer data
	            //alt_up_audio_write_fifo (audio_dev, l_buf, writeSizeL, ALT_UP_AUDIO_RIGHT);
	          //  alt_up_audio_write_fifo (audio_dev, l_buf, writeSizeL, ALT_UP_AUDIO_LEFT);

	    }


}
/* Prints "Hello World" and sleeps for three seconds */
void task2(void* pdata)
{
  while (1)
  { 
    printf("Hello from task2\n");
    OSTimeDlyHMSM(0, 0, 3, 0);
  }
}
/* The main function creates two task and starts multi-tasking */
int main(void)
{
  
  OSTaskCreateExt(task1,
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