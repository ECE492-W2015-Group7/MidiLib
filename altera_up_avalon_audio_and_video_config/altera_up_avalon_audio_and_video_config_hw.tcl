# +----------------------------------------------------------------------------+
# | License Agreement                                                          |
# |                                                                            |
# | Copyright (c) 1991-2010 Altera Corporation, San Jose, California, USA.     |
# | All rights reserved.                                                       |
# |                                                                            |
# | Any megafunction design, and related net list (encrypted or decrypted),    |
# |  support information, device programming or simulation file, and any other |
# |  associated documentation or information provided by Altera or a partner   |
# |  under Altera's Megafunction Partnership Program may be used only to       |
# |  program PLD devices (but not masked PLD devices) from Altera.  Any other  |
# |  use of such megafunction design, net list, support information, device    |
# |  programming or simulation file, or any other related documentation or     |
# |  information is prohibited for any other purpose, including, but not       |
# |  limited to modification, reverse engineering, de-compiling, or use with   |
# |  any other silicon devices, unless such use is explicitly licensed under   |
# |  a separate agreement with Altera or a megafunction partner.  Title to     |
# |  the intellectual property, including patents, copyrights, trademarks,     |
# |  trade secrets, or maskworks, embodied in any such megafunction design,    |
# |  net list, support information, device programming or simulation file, or  |
# |  any other related documentation or information provided by Altera or a    |
# |  megafunction partner, remains with Altera, the megafunction partner, or   |
# |  their respective licensors.  No other licenses, including any licenses    |
# |  needed under any third party's intellectual property, are provided herein.|
# |  Copying or modifying any file, or portion thereof, to which this notice   |
# |  is attached violates this copyright.                                      |
# |                                                                            |
# | THIS FILE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    |
# | IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   |
# | FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    |
# | THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER |
# | LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    |
# | FROM, OUT OF OR IN CONNECTION WITH THIS FILE OR THE USE OR OTHER DEALINGS  |
# | IN THIS FILE.                                                              |
# |                                                                            |
# | This agreement shall be governed in all respects by the laws of the State  |
# |  of California and by the laws of the United States of America.            |
# |                                                                            |
# +----------------------------------------------------------------------------+

# TCL File Generated by Altera University Program
# DO NOT MODIFY

# +-----------------------------------
# | module altera_up_avalon_audio_and_video_config
# | 
set_module_property DESCRIPTION "I2C bus for audio and video configuration on DE-Series Boards"
set_module_property NAME altera_up_avalon_audio_and_video_config
set_module_property VERSION 9.1
set_module_property GROUP "University Program/Audio & Video"
set_module_property AUTHOR "Altera University Program"
set_module_property DISPLAY_NAME "Audio and Video Config"
set_module_property DATASHEET_URL "doc/Audio_and_Video_Config.pdf"
#set_module_property TOP_LEVEL_HDL_FILE Altera_UP_Avalon_Audio_and_Video_Config.v
#set_module_property TOP_LEVEL_HDL_MODULE Altera_UP_Avalon_Audio_and_Video_Config
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE false
#set_module_property ANALYZE_HDL false
set_module_property VALIDATION_CALLBACK validate
set_module_property ELABORATION_CALLBACK elaborate
set_module_property GENERATION_CALLBACK generate
# | 
# +-----------------------------------

# +-----------------------------------
# | files
# | 
#add_file Altera_UP_Avalon_Audio_and_Video_Config.v {SYNTHESIS SIMULATION}
# | 
# +-----------------------------------

# +-----------------------------------
# | parameters
# | 
add_parameter device string "On-Board Peripherals" 
set_parameter_property device DISPLAY_NAME "Audio/Video Device"
set_parameter_property device GROUP "Components"
set_parameter_property device UNITS None
set_parameter_property device AFFECTS_ELABORATION true
set_parameter_property device AFFECTS_GENERATION true
#set_parameter_property device ALLOWED_RANGES {"On-Board Peripherals" "1.3 Megapixel Camera (TRDB_DC2)" "5 Megapixel Camera (TRDB_D5M)" "LCD Screen (TRDB_LCM)" "LCD with touchscreen (TRDB_LTM)"}
set_parameter_property device ALLOWED_RANGES {"On-Board Peripherals" "1.3 Megapixel Camera (TRDB_DC2)" "5 Megapixel Camera (TRDB_D5M)" "LCD with touchscreen (TRDB_LTM)"}
set_parameter_property device VISIBLE true
set_parameter_property device ENABLED true

add_parameter board string DE2
set_parameter_property board DISPLAY_NAME "DE Board"
set_parameter_property board GROUP "Components"
set_parameter_property board UNITS None
set_parameter_property board AFFECTS_ELABORATION true
set_parameter_property board AFFECTS_GENERATION true
set_parameter_property board ALLOWED_RANGES {DE1 DE2 "DE2-70" "DE2-115"}
set_parameter_property board VISIBLE true
set_parameter_property board ENABLED true

add_parameter eai boolean false
set_parameter_property eai DISPLAY_NAME "Auto Initialize Device(s)"
set_parameter_property eai GROUP "Components"
set_parameter_property eai UNITS None
set_parameter_property eai AFFECTS_ELABORATION true
set_parameter_property eai AFFECTS_GENERATION true
set_parameter_property eai VISIBLE true
set_parameter_property eai ENABLED true

add_parameter audio_in string "Microphone to ADC"
set_parameter_property audio_in DISPLAY_NAME "Audio In Path"
set_parameter_property audio_in GROUP "Auto Initialization Parameters for Audio"
set_parameter_property audio_in UNITS None
set_parameter_property audio_in AFFECTS_ELABORATION true
set_parameter_property audio_in AFFECTS_GENERATION true
set_parameter_property audio_in ALLOWED_RANGES {"Microphone to ADC" "Line In to ADC"}
set_parameter_property audio_in VISIBLE true
set_parameter_property audio_in ENABLED false

add_parameter dac_enable boolean true
set_parameter_property dac_enable DISPLAY_NAME "Audio Out - Enable DAC Output"
set_parameter_property dac_enable GROUP "Auto Initialization Parameters for Audio"
set_parameter_property dac_enable UNITS None
set_parameter_property dac_enable AFFECTS_ELABORATION true
set_parameter_property dac_enable AFFECTS_GENERATION true
set_parameter_property dac_enable VISIBLE true
set_parameter_property dac_enable ENABLED false

add_parameter mic_bypass boolean false
set_parameter_property mic_bypass DISPLAY_NAME "Audio Out - Microphone Bypass"
set_parameter_property mic_bypass GROUP "Auto Initialization Parameters for Audio"
set_parameter_property mic_bypass UNITS None
set_parameter_property mic_bypass AFFECTS_ELABORATION true
set_parameter_property mic_bypass AFFECTS_GENERATION true
set_parameter_property mic_bypass VISIBLE true
set_parameter_property mic_bypass ENABLED false

add_parameter line_in_bypass boolean false
set_parameter_property line_in_bypass DISPLAY_NAME "Audio Out - Line In Bypass"
set_parameter_property line_in_bypass GROUP "Auto Initialization Parameters for Audio"
set_parameter_property line_in_bypass UNITS None
set_parameter_property line_in_bypass AFFECTS_ELABORATION true
set_parameter_property line_in_bypass AFFECTS_GENERATION true
set_parameter_property line_in_bypass VISIBLE true
set_parameter_property line_in_bypass ENABLED false

add_parameter mic_attenuation string "-6dB"
set_parameter_property mic_attenuation DISPLAY_NAME "Microphone Attenuation"
set_parameter_property mic_attenuation GROUP "Auto Initialization Parameters for Audio"
set_parameter_property mic_attenuation UNITS None
set_parameter_property mic_attenuation AFFECTS_ELABORATION true
set_parameter_property mic_attenuation AFFECTS_GENERATION true
set_parameter_property mic_attenuation ALLOWED_RANGES {"-6dB" "-9dB" "-12dB" "-15dB"}
set_parameter_property mic_attenuation VISIBLE false
set_parameter_property mic_attenuation ENABLED false

add_parameter data_format string "Left Justified"
set_parameter_property data_format DISPLAY_NAME "Data Format"
set_parameter_property data_format GROUP "Auto Initialization Parameters for Audio"
set_parameter_property data_format UNITS None
set_parameter_property data_format AFFECTS_ELABORATION true
set_parameter_property data_format AFFECTS_GENERATION true
set_parameter_property data_format ALLOWED_RANGES {"DSP Mode" "I2S Format" "Left Justified" "Right Justified"}
set_parameter_property data_format VISIBLE true
set_parameter_property data_format ENABLED false

add_parameter bit_length integer 24
set_parameter_property bit_length DISPLAY_NAME "Bit Length"
set_parameter_property bit_length GROUP "Auto Initialization Parameters for Audio"
set_parameter_property bit_length UNITS None
set_parameter_property bit_length AFFECTS_ELABORATION true
set_parameter_property bit_length AFFECTS_GENERATION true
set_parameter_property bit_length ALLOWED_RANGES {32 24 20 16}
set_parameter_property bit_length VISIBLE true
set_parameter_property bit_length ENABLED false

add_parameter sampling_rate string "48 kHz"
set_parameter_property sampling_rate DISPLAY_NAME "Sampling Rate"
set_parameter_property sampling_rate GROUP "Auto Initialization Parameters for Audio"
set_parameter_property sampling_rate UNITS None
set_parameter_property sampling_rate AFFECTS_ELABORATION true
set_parameter_property sampling_rate AFFECTS_GENERATION true
set_parameter_property sampling_rate ALLOWED_RANGES {"32 kHz" "48 kHz" "96 kHz"}
#set_parameter_property sampling_rate ALLOWED_RANGES {"32" "48" "96" "44.1" "88.2"}
#set_parameter_property sampling_rate ALLOWED_RANGES {"32" "48" "96" "Advanced"}
set_parameter_property sampling_rate VISIBLE true
set_parameter_property sampling_rate ENABLED false

add_parameter bosr string "250fs/256fs"
set_parameter_property bosr DISPLAY_NAME "Base Over-Sampling Rate"
set_parameter_property bosr GROUP "Auto Initialization Parameters for Audio (Advanced)"
set_parameter_property bosr UNITS None
set_parameter_property bosr AFFECTS_ELABORATION true
set_parameter_property bosr AFFECTS_GENERATION true
set_parameter_property bosr ALLOWED_RANGES {"250fs/256fs" "272fs/384fs"}
set_parameter_property bosr DERIVED true
set_parameter_property bosr VISIBLE false
set_parameter_property bosr ENABLED false

add_parameter sr_register integer 0
set_parameter_property sr_register DISPLAY_NAME "Sampling Rate Register Setting"
set_parameter_property sr_register GROUP "Auto Initialization Parameters for Audio (Advanced)"
set_parameter_property sr_register UNITS None
set_parameter_property sr_register AFFECTS_ELABORATION true
set_parameter_property sr_register AFFECTS_GENERATION true
set_parameter_property sr_register ALLOWED_RANGES 0:15
set_parameter_property sr_register DERIVED true
set_parameter_property sr_register VISIBLE false
set_parameter_property sr_register ENABLED false

add_parameter video_format string "NTSC"
set_parameter_property video_format DISPLAY_NAME "Video Source Format"
set_parameter_property video_format GROUP "Auto Initialization Parameters for Video"
set_parameter_property video_format UNITS None
set_parameter_property video_format AFFECTS_ELABORATION true
set_parameter_property video_format AFFECTS_GENERATION true
set_parameter_property video_format ALLOWED_RANGES {"NTSC" "PAL"}
set_parameter_property video_format VISIBLE true
set_parameter_property video_format ENABLED false
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point clock_reset
# | 
add_interface clock_reset clock end
set_interface_property clock_reset ptfSchematicName ""

add_interface_port clock_reset clk clk Input 1
add_interface_port clock_reset reset reset Input 1
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point avalon_av_config_slave
# | 
add_interface avalon_av_config_slave avalon end clock_reset
set_interface_property avalon_av_config_slave addressAlignment DYNAMIC
set_interface_property avalon_av_config_slave bridgesToMaster ""
set_interface_property avalon_av_config_slave burstOnBurstBoundariesOnly false
#set_interface_property avalon_av_config_slave explicitAddressSpan 16
set_interface_property avalon_av_config_slave holdTime 0
set_interface_property avalon_av_config_slave isBigEndian  false
set_interface_property avalon_av_config_slave isFlash false
set_interface_property avalon_av_config_slave isMemoryDevice false
set_interface_property avalon_av_config_slave isNonVolatileStorage false
set_interface_property avalon_av_config_slave linewrapBursts false
set_interface_property avalon_av_config_slave maximumPendingReadTransactions 0
set_interface_property avalon_av_config_slave minimumUninterruptedRunLength 1
set_interface_property avalon_av_config_slave printableDevice false
set_interface_property avalon_av_config_slave readLatency 1
set_interface_property avalon_av_config_slave readWaitTime 0
set_interface_property avalon_av_config_slave setupTime 0
set_interface_property avalon_av_config_slave timingUnits cycles
set_interface_property avalon_av_config_slave writeWaitTime 0

add_interface_port avalon_av_config_slave address address Input 2
add_interface_port avalon_av_config_slave byteenable byteenable Input 4
add_interface_port avalon_av_config_slave read read Input 1
add_interface_port avalon_av_config_slave write write Input 1
add_interface_port avalon_av_config_slave writedata writedata Input 32
add_interface_port avalon_av_config_slave readdata readdata Output 32
add_interface_port avalon_av_config_slave waitrequest waitrequest Output 1
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point external_interface
# | 
add_interface external_interface conduit end

add_interface_port external_interface I2C_SDAT export Bidir 1
add_interface_port external_interface I2C_SCLK export Output 1
# | 
# +-----------------------------------

# +-----------------------------------
# | Validation function
# | 
proc validate {} {
	set device [ get_parameter_value "device" ]
	set board [ get_parameter_value "board" ]
	set eai [ get_parameter_value "eai" ]
	set audio_in [ get_parameter_value "audio_in" ]
	set dac_enable [ get_parameter_value "dac_enable" ]
	set mic_bypass [ get_parameter_value "mic_bypass" ]
	set line_in_bypass [ get_parameter_value "line_in_bypass" ]
	set mic_attenuation [ get_parameter_value "mic_attenuation" ]
	set data_format [ get_parameter_value "data_format" ]
	set bit_length [ get_parameter_value "bit_length" ]
	set sampling_rate [ get_parameter_value "sampling_rate" ]
	set bosr [ get_parameter_value "bosr" ]
	set sr_register [ get_parameter_value "sr_register" ]
	
	set_parameter_property board ENABLED false

	set_parameter_property audio_in ENABLED false
	set_parameter_property dac_enable ENABLED false
	set_parameter_property mic_bypass ENABLED false
	set_parameter_property line_in_bypass ENABLED false
	set_parameter_property mic_attenuation ENABLED false
	set_parameter_property data_format ENABLED false
	set_parameter_property bit_length ENABLED false
	set_parameter_property sampling_rate ENABLED false
	set_parameter_property bosr ENABLED false
	set_parameter_property sr_register ENABLED false
	set_parameter_property video_format ENABLED false

	if { ($device == "On-Board Peripherals") } {
		set_parameter_property board ENABLED true
		if { $eai } {
			set_parameter_property audio_in ENABLED true
			set_parameter_property dac_enable ENABLED true
			set_parameter_property mic_bypass ENABLED true
			set_parameter_property line_in_bypass ENABLED true
			set_parameter_property mic_attenuation ENABLED true
			set_parameter_property data_format ENABLED true
			set_parameter_property bit_length ENABLED true
			set_parameter_property sampling_rate ENABLED true
			set_parameter_property bosr ENABLED true
			set_parameter_property sr_register ENABLED true
			if { ($board != "DE1") } {
				set_parameter_property video_format ENABLED true
			}

			if { $data_format == "Left Justified" } {
			} else {
				send_message info "The data format must be Left Justified, if using the Altera UP Audio IP Core."
			}

			if { $sampling_rate == "32 kHz" } {
				set_parameter_value "sr_register" 6
			} elseif { $sampling_rate == "48 kHz" } {
				set_parameter_value "sr_register" 0
			} else {
				set_parameter_value "sr_register" 7
			}
		}
	}
}
# | 
# +-----------------------------------

# +-----------------------------------
# | Elaboration function
# | 
proc elaborate {} {
	set device [ get_parameter_value "device" ]
	if { ($device == "LCD Screen (TRDB_LCM)") || ($device == "LCD with touchscreen (TRDB_LTM)") } {
		# +-----------------------------------
		# | connection point external_interface
		# | 
		add_interface_port external_interface I2C_SCEN export Output 1
		# | 
		# +-----------------------------------
	}
}
# | 
# +-----------------------------------

# +-----------------------------------
# | Generation function
# | 
proc generate {} {
	send_message info "Starting Generation of Audio and Video Config"

	# get parameter values
	set device			[ get_parameter_value "device" ]
	set board			[ get_parameter_value "board" ]
	set eai				[ get_parameter_value "eai" ]
	set audio_in		[ get_parameter_value "audio_in" ]
	set dac_enable		[ get_parameter_value "dac_enable" ]
	set mic_bypass		[ get_parameter_value "mic_bypass" ]
	set line_in_bypass	[ get_parameter_value "line_in_bypass" ]
	set mic_attenuation	[ get_parameter_value "mic_attenuation" ]
	set data_format		[ get_parameter_value "data_format" ]
	set bit_length		[ get_parameter_value "bit_length" ]
	set bosr			[ get_parameter_value "bosr" ]
	set sr_register		[ get_parameter_value "sr_register" ]
	set video_format	[ get_parameter_value "video_format" ]

#	set i2c_bus_mode [ format "I2C_BUS_MODE:1'b%d" [ string match "LCD Screen*" $device ] ]
	if { $device == "On-Board Peripherals" } {
		set dw		"DW:26"
		set aiaw	"AIAW:5"
		set sbcw	"SBCW:4"
		set sccw	"SCCW:11"

		if { $board == "DE1" } {
			set airs	"AIRS:10"
			set cfg_type "CFG_TYPE:8'h01"
		} elseif { $board == "DE2" } {
			set airs	"AIRS:50"
			set cfg_type "CFG_TYPE:8'h02"
		} else {
			set airs	"AIRS:57"
			set cfg_type "CFG_TYPE:8'h03"
		}

		set read_mask	 "READ_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'hFF, 1'b0}"
		set write_mask	"WRITE_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1}"

	} elseif { $device == "1.3 Megapixel Camera (TRDB_DC2)" } {
		set dw		"DW:35"
		set airs	"AIRS:23"
		set aiaw	"AIAW:4"
		set sbcw	"SBCW:5"
		set sccw	"SCCW:11"
		set cfg_type "CFG_TYPE:8'h10"
		set read_mask	 "READ_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'hFF, 1'b0, 8'hFF, 1'b0}"
		set write_mask	"WRITE_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1}"

	} elseif { $device == "5 Megapixel Camera (TRDB_D5M)" } {
		set dw		"DW:35"
		set airs	"AIRS:25"
		set aiaw	"AIAW:4"
		set sbcw	"SBCW:5"
		set sccw	"SCCW:11"

		set cfg_type 	"CFG_TYPE:8'h11"
		set read_mask	 "READ_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'hFF, 1'b0, 8'hFF, 1'b0}"
		set write_mask	"WRITE_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1}"

	} elseif { $device == "LCD Screen (TRDB_LCM)" } {
		set dw		"DW:15"
		set airs	"AIRS:20"
		set aiaw	"AIAW:4"
		set sbcw	"SBCW:4"
		set sccw	"SCCW:11"
		set cfg_type "CFG_TYPE:8'h20"
		set read_mask	 "READ_MASK:{6'h00, 1'b1, 1'b1, 8'h00}"
		set write_mask	"WRITE_MASK:{6'h00, 1'b0, 1'b1, 8'h00}"

	} elseif { $device == "LCD with touchscreen (TRDB_LTM)" } {
		set dw		"DW:15"
		set airs	"AIRS:26"
		set aiaw	"AIAW:4"
		set sbcw	"SBCW:4"
		set sccw	"SCCW:11"
		set cfg_type "CFG_TYPE:8'h21"
		set read_mask	 "READ_MASK:{6'h00, 1'b1, 1'b1, 8'h00}"
		set write_mask	"WRITE_MASK:{6'h00, 1'b0, 1'b1, 8'h00}"

	} else {
		set dw		"DW:35"
		set aiaw	"AIAW:5"
		set sbcw	"SBCW:4"
		set sccw	"SCCW:11"

		set airs	"AIRS:0"
		set cfg_type "CFG_TYPE:8'h00"

		set read_mask	 "READ_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'hFF, 1'b0}"
		set write_mask	"WRITE_MASK:{8'h00, 1'b1, 8'h00, 1'b1, 8'h00, 1'b1}"
	}
	set main_params "$dw;$airs;$aiaw;$sbcw;$sccw;$cfg_type"

	## get audio auto init values
	set line_in_bypass 	[ expr [ string match "true" $line_in_bypass ] * 8 ]
	set dac_enable 		[ expr [ string match "true" $dac_enable ] * 16 ]
	set mic_bypass 		[ expr [ string match "true" $mic_bypass ] * 64 ]
	if { $audio_in == "Microphone to ADC" } {
		set aud_adc_path [ format "AUD_ADC_PATH:9'd%d" [ expr [ expr $mic_bypass + $dac_enable ] + [ expr $line_in_bypass + 133 ] ] ]
	} elseif { $mic_bypass } {`
		set aud_adc_path [ format "AUD_ADC_PATH:9'd%d" [ expr [ expr $mic_bypass + $dac_enable ] + [ expr $line_in_bypass + 129 ] ] ]
	} else {
		set aud_adc_path [ format "AUD_ADC_PATH:9'd%d" [ expr [ expr $mic_bypass + $dac_enable ] + [ expr $line_in_bypass + 130 ] ] ]
	}

	if { $data_format == "DSP Mode" } {
		set data_format 3 
	} elseif { $data_format == "I2S Format" } {
		set data_format 2 
	} elseif { $data_format == "Left Justified" } {
		set data_format 1 
	} else {
		set data_format 0 
	}
	if { $bit_length == 32 } {
		set bit_length 3
	} elseif { $bit_length == 24 } {
		set bit_length 2
	} elseif { $bit_length == 20 } {
		set bit_length 1
	} else {
		set bit_length 0
	}
	set aud_data_format [ format "AUD_DATA_FORMAT:9'd%d" [ expr [ expr $bit_length * 4 ] + [ expr $data_format + 64 ] ] ]

	if { $bosr == "250fs/256fs" } {
		set bosr 0
	} else {
		set bosr 2
	}
	set sr_register [ expr $sr_register * 4 ]
	set aud_sample_ctrl [ format "AUD_SAMPLE_CTRL:9'd%d" [ expr $bosr + $sr_register ] ]

	# set section values
	set use_ob_mode	 [ format "USE_OB_MODE:%d"  [ string match "On-Board*" $device ] ]
	set use_dc2_mode [ format "USE_DC2_MODE:%d" [ string match "1.3*" $device ] ]
	set use_d5m_mode [ format "USE_D5M_MODE:%d" [ string match "5**" $device ] ]
	set use_lcm_mode [ format "USE_LCM_MODE:%d" [ string match "LCD Screen (TRDB_LCM)*" $device ] ]
	set use_ltm_mode [ format "USE_LTM_MODE:%d" [ string match "LCD with*" $device ] ]

#	set use_ob_a_mode	[ format "USE_OB_A_MODE:%d" [ string match "On-Board - Audio only (DE1)" $device ] ]
#	set use_ob_av_mode	[ format "USE_OB_AV_MODE:%d" [ string match "On-Board - Audio and Video (DE2)" $device ] ]
	set mode_sections	"$use_ob_mode;$use_dc2_mode;$use_d5m_mode;$use_lcm_mode;$use_ltm_mode" 

	if { $eai } {
		set use_ai				"USE_AUTO_INIT:1"
		set use_ob_ai			[ format "USE_OB_AUTO_INIT:%d" [ string match "On-Board*" $device ] ]
		set use_ob_de1_ai		[ format "USE_OB_DE1_AUTO_INIT:%d" [ string match "DE1" $board ] ]
		set use_ob_de2_ai		[ format "USE_OB_DE2_35_AUTO_INIT:%d" [ string match "DE2" $board ] ]
		set use_ob_de2_70_ai	[ format "USE_OB_DE2_70_AUTO_INIT:%d" [ string match "DE2-70" $board ] ]
		set use_ob_de2_115_ai	[ format "USE_OB_DE2_115_AUTO_INIT:%d" [ string match "DE2-115" $board ] ]
		set use_dc2_ai			[ format "USE_DC2_AUTO_INIT:%d" [ string match "1.3*" $device ] ]
		set use_d5m_ai			[ format "USE_D5M_AUTO_INIT:%d" [ string match "5*" $device ] ]
		set use_lcm_ai			[ format "USE_LCM_AUTO_INIT:%d" [ string match "LCD Screen (TRDB_LCM)*" $device ] ]
		set use_ltm_ai			[ format "USE_LTM_AUTO_INIT:%d" [ string match "LCD with*" $device ] ]
		set ai_sections "$use_ai;$use_ob_ai;$use_ob_de1_ai;$use_ob_de2_ai;$use_ob_de2_70_ai;$use_ob_de2_115_ai;$use_dc2_ai;$use_d5m_ai;$use_lcm_ai;$use_ltm_ai"
	} else {
		set ai_sections "USE_AUTO_INIT:0;USE_OB_AUTO_INIT:0;USE_OB_DE1_AUTO_INIT:0;USE_OB_DE2_35_AUTO_INIT:0;USE_OB_DE2_70_AUTO_INIT:0;USE_OB_DE2_115_AUTO_INIT:0;USE_DC2_AUTO_INIT:0;USE_D5M_AUTO_INIT:0;USE_LCM_AUTO_INIT:0;USE_LTM_AUTO_INIT:0"
	}

	set use_ntsc_video	"USE_NTSC_VIDEO:0"
	if { $video_format == "NTSC" } {
		set use_ntsc_video	"USE_NTSC_VIDEO:1"
	}
	
	# set arguments
	set params "$main_params;$aud_adc_path;$aud_data_format;$aud_sample_ctrl"
	set sections "$mode_sections;$ai_sections;$use_ntsc_video" 

	# get generation settings
#	set dest_language	[ get_generation_property HDL_LANGUAGE ]
	set dest_dir 		[ get_generation_property OUTPUT_DIRECTORY ]
	set dest_name		[ get_generation_property OUTPUT_NAME ]
	add_file "$dest_dir$dest_name.v" {SYNTHESIS SIMULATION}

	# Generate HDL
	source "up_ip_generator.tcl"
	alt_up_generate "$dest_dir$dest_name.v" "hdl/altera_up_avalon_av_config.v" $dest_name $params $sections
	file copy -force "hdl/altera_up_av_config_serial_bus_controller.v" $dest_dir
	file copy -force "hdl/altera_up_slow_clock_generator.v" $dest_dir
	if { $eai } {
		file copy -force "hdl/altera_up_av_config_auto_init.v" $dest_dir
		if { $device == "1.3 Megapixel Camera (TRDB_DC2)" } {
			file copy -force "hdl/altera_up_av_config_auto_init_dc2.v" $dest_dir

		} elseif { $device == "5 Megapixel Camera (TRDB_D5M)" } {
			file copy -force "hdl/altera_up_av_config_auto_init_d5m.v" $dest_dir

		} elseif { $device == "LCD Screen (TRDB_LCM)" } {
			file copy -force "hdl/altera_up_av_config_auto_init_lcm.v" $dest_dir

		} elseif { $device == "LCD with touchscreen (TRDB_LTM)" } {
			file copy -force "hdl/altera_up_av_config_auto_init_ltm.v" $dest_dir

		# Must be on-board peripherals
		} elseif { $board == "DE1" } {
			file copy -force "hdl/altera_up_av_config_auto_init_ob_audio.v" $dest_dir
		} elseif { $board == "DE2" } {
			file copy -force "hdl/altera_up_av_config_auto_init_ob_de2_35.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_audio.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_adv7181.v" $dest_dir
		} elseif { $board == "DE2-70" } {
			file copy -force "hdl/altera_up_av_config_auto_init_ob_de2_70.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_audio.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_adv7180.v" $dest_dir
		} elseif { $board == "DE2-115" } {
			file copy -force "hdl/altera_up_av_config_auto_init_ob_de2_115.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_audio.v" $dest_dir
			file copy -force "hdl/altera_up_av_config_auto_init_ob_adv7180.v" $dest_dir
		}
	}

	# generate top level template
	#alt_up_create_instantiation_template "$dest_dir$dest_name.inst.v" $dest_name "external_interface"
}
# | 
# +-----------------------------------

