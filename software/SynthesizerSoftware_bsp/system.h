/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'niosII_system'
 * SOPC Builder design path: C:/Users/eorodrig/ece492/SynthesizerPrototypeV2/sythesizerPrototype_restored/niosII_system.sopcinfo
 *
 * Generated: Mon Mar 02 15:41:55 MST 2015
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x108820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x15
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x104020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x15
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_RESET_ADDR 0x104000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x108820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x15
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x104020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x15
#define NIOS2_RESET_ADDR 0x104000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_UP_AVALON_AUDIO_AND_VIDEO_CONFIG
#define __ALTERA_UP_AVALON_SRAM
#define __WAVEFORMGENERATOR


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone II"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x109070
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x109070
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x109070
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "niosII_system"


/*
 * WaveformGenerator_0_note_end_voice0 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice0 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_BASE 0x109088
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_NAME "/dev/WaveformGenerator_0_note_end_voice0"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE0_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice1 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice1 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_BASE 0x109087
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_NAME "/dev/WaveformGenerator_0_note_end_voice1"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE1_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice2 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice2 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_BASE 0x109085
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_NAME "/dev/WaveformGenerator_0_note_end_voice2"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE2_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice3 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice3 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_BASE 0x109083
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_NAME "/dev/WaveformGenerator_0_note_end_voice3"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE3_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice4 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice4 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_BASE 0x109082
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_NAME "/dev/WaveformGenerator_0_note_end_voice4"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE4_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice5 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice5 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_BASE 0x109081
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_NAME "/dev/WaveformGenerator_0_note_end_voice5"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE5_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice6 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice6 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_BASE 0x109080
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_NAME "/dev/WaveformGenerator_0_note_end_voice6"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE6_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_note_end_voice7 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_note_end_voice7 WaveformGenerator
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_BASE 0x109084
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_IRQ -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_NAME "/dev/WaveformGenerator_0_note_end_voice7"
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_SPAN 1
#define WAVEFORMGENERATOR_0_NOTE_END_VOICE7_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice0 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice0 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_BASE 0x109068
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_NAME "/dev/WaveformGenerator_0_phase_increments_voice0"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE0_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice1 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice1 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_BASE 0x109058
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_NAME "/dev/WaveformGenerator_0_phase_increments_voice1"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE1_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice2 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice2 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_BASE 0x109060
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_NAME "/dev/WaveformGenerator_0_phase_increments_voice2"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE2_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice3 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice3 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_BASE 0x109048
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_NAME "/dev/WaveformGenerator_0_phase_increments_voice3"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE3_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice4 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice4 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_BASE 0x109050
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_NAME "/dev/WaveformGenerator_0_phase_increments_voice4"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE4_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice5 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice5 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_BASE 0x109040
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_NAME "/dev/WaveformGenerator_0_phase_increments_voice5"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE5_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice6 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice6 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_BASE 0x109038
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_NAME "/dev/WaveformGenerator_0_phase_increments_voice6"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE6_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_phase_increments_voice7 configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_phase_increments_voice7 WaveformGenerator
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_BASE 0x109030
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_IRQ -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_NAME "/dev/WaveformGenerator_0_phase_increments_voice7"
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_SPAN 8
#define WAVEFORMGENERATOR_0_PHASE_INCREMENTS_VOICE7_TYPE "WaveformGenerator"


/*
 * WaveformGenerator_0_wave_shapes configuration
 *
 */

#define ALT_MODULE_CLASS_WaveformGenerator_0_wave_shapes WaveformGenerator
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_BASE 0x109086
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_IRQ -1
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_NAME "/dev/WaveformGenerator_0_wave_shapes"
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_SPAN 1
#define WAVEFORMGENERATOR_0_WAVE_SHAPES_TYPE "WaveformGenerator"


/*
 * audio_and_video_config_0 configuration
 *
 */

#define ALT_MODULE_CLASS_audio_and_video_config_0 altera_up_avalon_audio_and_video_config
#define AUDIO_AND_VIDEO_CONFIG_0_BASE 0x109020
#define AUDIO_AND_VIDEO_CONFIG_0_IRQ -1
#define AUDIO_AND_VIDEO_CONFIG_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define AUDIO_AND_VIDEO_CONFIG_0_NAME "/dev/audio_and_video_config_0"
#define AUDIO_AND_VIDEO_CONFIG_0_SPAN 16
#define AUDIO_AND_VIDEO_CONFIG_0_TYPE "altera_up_avalon_audio_and_video_config"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_0
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x109070
#define JTAG_UART_0_IRQ 1
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x104000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 16384u
#define ONCHIP_MEMORY2_0_SPAN 16384
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sram_0 altera_up_avalon_sram
#define SRAM_0_BASE 0x80000
#define SRAM_0_IRQ -1
#define SRAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SRAM_0_NAME "/dev/sram_0"
#define SRAM_0_SPAN 524288
#define SRAM_0_TYPE "altera_up_avalon_sram"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x109078
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1425333644
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x109000
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000u
#define TIMER_0_IRQ 0
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999ull
#define TIMER_0_MULT 0.0010
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000u
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"


/*
 * ucosii configuration
 *
 */

#define OS_ARG_CHK_EN 1
#define OS_CPU_HOOKS_EN 1
#define OS_DEBUG_EN 1
#define OS_EVENT_NAME_SIZE 32
#define OS_FLAGS_NBITS 16
#define OS_FLAG_ACCEPT_EN 1
#define OS_FLAG_DEL_EN 1
#define OS_FLAG_EN 1
#define OS_FLAG_NAME_SIZE 32
#define OS_FLAG_QUERY_EN 1
#define OS_FLAG_WAIT_CLR_EN 1
#define OS_LOWEST_PRIO 20
#define OS_MAX_EVENTS 60
#define OS_MAX_FLAGS 20
#define OS_MAX_MEM_PART 60
#define OS_MAX_QS 20
#define OS_MAX_TASKS 10
#define OS_MBOX_ACCEPT_EN 1
#define OS_MBOX_DEL_EN 1
#define OS_MBOX_EN 1
#define OS_MBOX_POST_EN 1
#define OS_MBOX_POST_OPT_EN 1
#define OS_MBOX_QUERY_EN 1
#define OS_MEM_EN 1
#define OS_MEM_NAME_SIZE 32
#define OS_MEM_QUERY_EN 1
#define OS_MUTEX_ACCEPT_EN 1
#define OS_MUTEX_DEL_EN 1
#define OS_MUTEX_EN 1
#define OS_MUTEX_QUERY_EN 1
#define OS_Q_ACCEPT_EN 1
#define OS_Q_DEL_EN 1
#define OS_Q_EN 1
#define OS_Q_FLUSH_EN 1
#define OS_Q_POST_EN 1
#define OS_Q_POST_FRONT_EN 1
#define OS_Q_POST_OPT_EN 1
#define OS_Q_QUERY_EN 1
#define OS_SCHED_LOCK_EN 1
#define OS_SEM_ACCEPT_EN 1
#define OS_SEM_DEL_EN 1
#define OS_SEM_EN 1
#define OS_SEM_QUERY_EN 1
#define OS_SEM_SET_EN 1
#define OS_TASK_CHANGE_PRIO_EN 1
#define OS_TASK_CREATE_EN 1
#define OS_TASK_CREATE_EXT_EN 1
#define OS_TASK_DEL_EN 1
#define OS_TASK_IDLE_STK_SIZE 512
#define OS_TASK_NAME_SIZE 32
#define OS_TASK_PROFILE_EN 1
#define OS_TASK_QUERY_EN 1
#define OS_TASK_STAT_EN 1
#define OS_TASK_STAT_STK_CHK_EN 1
#define OS_TASK_STAT_STK_SIZE 512
#define OS_TASK_SUSPEND_EN 1
#define OS_TASK_SW_HOOK_EN 1
#define OS_TASK_TMR_PRIO 0
#define OS_TASK_TMR_STK_SIZE 512
#define OS_THREAD_SAFE_NEWLIB 1
#define OS_TICKS_PER_SEC TIMER_0_TICKS_PER_SEC
#define OS_TICK_STEP_EN 1
#define OS_TIME_DLY_HMSM_EN 1
#define OS_TIME_DLY_RESUME_EN 1
#define OS_TIME_GET_SET_EN 1
#define OS_TIME_TICK_HOOK_EN 1
#define OS_TMR_CFG_MAX 16
#define OS_TMR_CFG_NAME_SIZE 16
#define OS_TMR_CFG_TICKS_PER_SEC 10
#define OS_TMR_CFG_WHEEL_SIZE 2
#define OS_TMR_EN 0

#endif /* __SYSTEM_H_ */
