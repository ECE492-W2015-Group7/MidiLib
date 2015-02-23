# TCL File Generated by Component Editor 12.1sp1
# Mon Feb 23 16:40:38 MST 2015
# DO NOT MODIFY


# 
# Waveform_Generator "Waveform_Generator" v1.0
# null 2015.02.23.16:40:38
# 
# 

# 
# request TCL package from ACDS 12.1
# 
package require -exact qsys 12.1


# 
# module Waveform_Generator
# 
set_module_property NAME Waveform_Generator
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property DISPLAY_NAME Waveform_Generator
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property ANALYZE_HDL AUTO
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL WaveformGenerator
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
add_fileset_file WaveformGenerator.vhd VHDL PATH WaveformGenerator.vhd


# 
# parameters
# 


# 
# display items
# 


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true

add_interface_port clock clk clk Input 1


# 
# connection point reset
# 
add_interface reset reset end
set_interface_property reset associatedClock clock
set_interface_property reset synchronousEdges DEASSERT
set_interface_property reset ENABLED true

add_interface_port reset reset_n reset_n Input 1


# 
# connection point phase_increments_voice0
# 
add_interface phase_increments_voice0 avalon end
set_interface_property phase_increments_voice0 addressUnits WORDS
set_interface_property phase_increments_voice0 associatedClock clock
set_interface_property phase_increments_voice0 associatedReset ""
set_interface_property phase_increments_voice0 bitsPerSymbol 8
set_interface_property phase_increments_voice0 burstOnBurstBoundariesOnly false
set_interface_property phase_increments_voice0 burstcountUnits WORDS
set_interface_property phase_increments_voice0 explicitAddressSpan 0
set_interface_property phase_increments_voice0 holdTime 0
set_interface_property phase_increments_voice0 linewrapBursts false
set_interface_property phase_increments_voice0 maximumPendingReadTransactions 0
set_interface_property phase_increments_voice0 readLatency 0
set_interface_property phase_increments_voice0 readWaitTime 1
set_interface_property phase_increments_voice0 setupTime 0
set_interface_property phase_increments_voice0 timingUnits Cycles
set_interface_property phase_increments_voice0 writeWaitTime 0
set_interface_property phase_increments_voice0 ENABLED true

add_interface_port phase_increments_voice0 avs_writedata_phase_increments_voice0 writedata Input 64
add_interface_port phase_increments_voice0 avs_write_n_phase_increments_voice0 write_n Input 1
set_interface_assignment phase_increments_voice0 embeddedsw.configuration.isFlash 0
set_interface_assignment phase_increments_voice0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment phase_increments_voice0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment phase_increments_voice0 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point phase_increments_voice1
# 
add_interface phase_increments_voice1 avalon end
set_interface_property phase_increments_voice1 addressUnits WORDS
set_interface_property phase_increments_voice1 associatedClock clock
set_interface_property phase_increments_voice1 associatedReset ""
set_interface_property phase_increments_voice1 bitsPerSymbol 8
set_interface_property phase_increments_voice1 burstOnBurstBoundariesOnly false
set_interface_property phase_increments_voice1 burstcountUnits WORDS
set_interface_property phase_increments_voice1 explicitAddressSpan 0
set_interface_property phase_increments_voice1 holdTime 0
set_interface_property phase_increments_voice1 linewrapBursts false
set_interface_property phase_increments_voice1 maximumPendingReadTransactions 0
set_interface_property phase_increments_voice1 readLatency 0
set_interface_property phase_increments_voice1 readWaitTime 1
set_interface_property phase_increments_voice1 setupTime 0
set_interface_property phase_increments_voice1 timingUnits Cycles
set_interface_property phase_increments_voice1 writeWaitTime 0
set_interface_property phase_increments_voice1 ENABLED true

add_interface_port phase_increments_voice1 avs_writedata_phase_increments_voice1 writedata Input 64
add_interface_port phase_increments_voice1 avs_write_n_phase_increments_voice1 write_n Input 1
set_interface_assignment phase_increments_voice1 embeddedsw.configuration.isFlash 0
set_interface_assignment phase_increments_voice1 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment phase_increments_voice1 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment phase_increments_voice1 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point phase_increments_voice2
# 
add_interface phase_increments_voice2 avalon end
set_interface_property phase_increments_voice2 addressUnits WORDS
set_interface_property phase_increments_voice2 associatedClock clock
set_interface_property phase_increments_voice2 associatedReset ""
set_interface_property phase_increments_voice2 bitsPerSymbol 8
set_interface_property phase_increments_voice2 burstOnBurstBoundariesOnly false
set_interface_property phase_increments_voice2 burstcountUnits WORDS
set_interface_property phase_increments_voice2 explicitAddressSpan 0
set_interface_property phase_increments_voice2 holdTime 0
set_interface_property phase_increments_voice2 linewrapBursts false
set_interface_property phase_increments_voice2 maximumPendingReadTransactions 0
set_interface_property phase_increments_voice2 readLatency 0
set_interface_property phase_increments_voice2 readWaitTime 1
set_interface_property phase_increments_voice2 setupTime 0
set_interface_property phase_increments_voice2 timingUnits Cycles
set_interface_property phase_increments_voice2 writeWaitTime 0
set_interface_property phase_increments_voice2 ENABLED true

add_interface_port phase_increments_voice2 avs_writedata_phase_increments_voice2 writedata Input 64
add_interface_port phase_increments_voice2 avs_write_n_phase_increments_voice2 write_n Input 1
set_interface_assignment phase_increments_voice2 embeddedsw.configuration.isFlash 0
set_interface_assignment phase_increments_voice2 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment phase_increments_voice2 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment phase_increments_voice2 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point note_end_voice0
# 
add_interface note_end_voice0 avalon end
set_interface_property note_end_voice0 addressUnits WORDS
set_interface_property note_end_voice0 associatedClock clock
set_interface_property note_end_voice0 associatedReset ""
set_interface_property note_end_voice0 bitsPerSymbol 8
set_interface_property note_end_voice0 burstOnBurstBoundariesOnly false
set_interface_property note_end_voice0 burstcountUnits WORDS
set_interface_property note_end_voice0 explicitAddressSpan 0
set_interface_property note_end_voice0 holdTime 0
set_interface_property note_end_voice0 linewrapBursts false
set_interface_property note_end_voice0 maximumPendingReadTransactions 0
set_interface_property note_end_voice0 readLatency 0
set_interface_property note_end_voice0 readWaitTime 1
set_interface_property note_end_voice0 setupTime 0
set_interface_property note_end_voice0 timingUnits Cycles
set_interface_property note_end_voice0 writeWaitTime 0
set_interface_property note_end_voice0 ENABLED true

add_interface_port note_end_voice0 avs_writedata_note_end_voice0 writedata Input 8
add_interface_port note_end_voice0 avs_write_n_note_end_voice0 write_n Input 1
set_interface_assignment note_end_voice0 embeddedsw.configuration.isFlash 0
set_interface_assignment note_end_voice0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment note_end_voice0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment note_end_voice0 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point note_end_voice1
# 
add_interface note_end_voice1 avalon end
set_interface_property note_end_voice1 addressUnits WORDS
set_interface_property note_end_voice1 associatedClock clock
set_interface_property note_end_voice1 associatedReset ""
set_interface_property note_end_voice1 bitsPerSymbol 8
set_interface_property note_end_voice1 burstOnBurstBoundariesOnly false
set_interface_property note_end_voice1 burstcountUnits WORDS
set_interface_property note_end_voice1 explicitAddressSpan 0
set_interface_property note_end_voice1 holdTime 0
set_interface_property note_end_voice1 linewrapBursts false
set_interface_property note_end_voice1 maximumPendingReadTransactions 0
set_interface_property note_end_voice1 readLatency 0
set_interface_property note_end_voice1 readWaitTime 1
set_interface_property note_end_voice1 setupTime 0
set_interface_property note_end_voice1 timingUnits Cycles
set_interface_property note_end_voice1 writeWaitTime 0
set_interface_property note_end_voice1 ENABLED true

add_interface_port note_end_voice1 avs_writedata_note_end_voice1 writedata Input 8
add_interface_port note_end_voice1 avs_write_n_note_end_voice1 write_n Input 1
set_interface_assignment note_end_voice1 embeddedsw.configuration.isFlash 0
set_interface_assignment note_end_voice1 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment note_end_voice1 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment note_end_voice1 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point note_end_voice2
# 
add_interface note_end_voice2 avalon end
set_interface_property note_end_voice2 addressUnits WORDS
set_interface_property note_end_voice2 associatedClock clock
set_interface_property note_end_voice2 associatedReset ""
set_interface_property note_end_voice2 bitsPerSymbol 8
set_interface_property note_end_voice2 burstOnBurstBoundariesOnly false
set_interface_property note_end_voice2 burstcountUnits WORDS
set_interface_property note_end_voice2 explicitAddressSpan 0
set_interface_property note_end_voice2 holdTime 0
set_interface_property note_end_voice2 linewrapBursts false
set_interface_property note_end_voice2 maximumPendingReadTransactions 0
set_interface_property note_end_voice2 readLatency 0
set_interface_property note_end_voice2 readWaitTime 1
set_interface_property note_end_voice2 setupTime 0
set_interface_property note_end_voice2 timingUnits Cycles
set_interface_property note_end_voice2 writeWaitTime 0
set_interface_property note_end_voice2 ENABLED true

add_interface_port note_end_voice2 avs_writedata_note_end_voice2 writedata Input 8
add_interface_port note_end_voice2 avs_write_n_note_end_voice2 write_n Input 1
set_interface_assignment note_end_voice2 embeddedsw.configuration.isFlash 0
set_interface_assignment note_end_voice2 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment note_end_voice2 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment note_end_voice2 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point wave_shapes
# 
add_interface wave_shapes avalon end
set_interface_property wave_shapes addressUnits WORDS
set_interface_property wave_shapes associatedClock clock
set_interface_property wave_shapes associatedReset ""
set_interface_property wave_shapes bitsPerSymbol 8
set_interface_property wave_shapes burstOnBurstBoundariesOnly false
set_interface_property wave_shapes burstcountUnits WORDS
set_interface_property wave_shapes explicitAddressSpan 0
set_interface_property wave_shapes holdTime 0
set_interface_property wave_shapes linewrapBursts false
set_interface_property wave_shapes maximumPendingReadTransactions 0
set_interface_property wave_shapes readLatency 0
set_interface_property wave_shapes readWaitTime 1
set_interface_property wave_shapes setupTime 0
set_interface_property wave_shapes timingUnits Cycles
set_interface_property wave_shapes writeWaitTime 0
set_interface_property wave_shapes ENABLED true

add_interface_port wave_shapes avs_writedata_wave_shapes writedata Input 8
add_interface_port wave_shapes avs_write_n_wave_shapes write_n Input 1
set_interface_assignment wave_shapes embeddedsw.configuration.isFlash 0
set_interface_assignment wave_shapes embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment wave_shapes embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment wave_shapes embeddedsw.configuration.isPrintableDevice 0
