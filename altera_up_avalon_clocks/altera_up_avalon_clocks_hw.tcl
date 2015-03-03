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
# | module altera_up_avalon_clocks
# | 
set_module_property DESCRIPTION "Creates required PLLs for DE-Series Board Peripherals"
set_module_property NAME altera_up_avalon_clocks
set_module_property VERSION 9.2
set_module_property GROUP "University Program"
set_module_property AUTHOR "Altera University Program"
set_module_property DISPLAY_NAME "Clocks Signals for DE-Series Board Peripherals"
set_module_property DATASHEET_URL "doc/up_clocks.pdf"
#set_module_property TOP_LEVEL_HDL_FILE altera_up_avalon_clocks.v
#set_module_property TOP_LEVEL_HDL_MODULE altera_up_avalon_clocks
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
#add_file altera_up_avalon_clocks.v {SYNTHESIS SIMULATION}
# | 
# +-----------------------------------

# +-----------------------------------
# | parameters
# | 
add_parameter board string DE2
set_parameter_property board DISPLAY_NAME "DE Board"
set_parameter_property board GROUP "Configurations"
set_parameter_property board UNITS None
set_parameter_property board AFFECTS_ELABORATION true
set_parameter_property board AFFECTS_GENERATION true
set_parameter_property board ALLOWED_RANGES {DE0 DE1 DE2 "DE2-70" "DE2-115"}
#set_parameter_property board ALLOWED_RANGES {DE0 DE1 DE2 "DE2-70" "DE2-115" DE3}
set_parameter_property board VISIBLE true
set_parameter_property board ENABLED true

add_parameter sys_clk_freq integer 50
set_parameter_property sys_clk_freq DISPLAY_NAME "System Clock Frequency (MHz)"
set_parameter_property sys_clk_freq GROUP "Configurations"
set_parameter_property sys_clk_freq UNITS None
set_parameter_property sys_clk_freq AFFECTS_ELABORATION true
set_parameter_property sys_clk_freq AFFECTS_GENERATION true
set_parameter_property sys_clk_freq ALLOWED_RANGES {25 50 100 150 200}
set_parameter_property sys_clk_freq VISIBLE false
set_parameter_property sys_clk_freq ENABLED true

#add_display_item "Configurations" sys_clk_freq_text text "<html><b>Note</b>: The system may not achieve the timing required to run at the higher system clock frequencies.<br />You will have to verify adequate circuit speed by checking the timing analysis report in Quartus II.</html>"

add_parameter sdram_clk boolean true
set_parameter_property sdram_clk DISPLAY_NAME "SDRAM"
set_parameter_property sdram_clk GROUP "Optional Clocks"
set_parameter_property sdram_clk UNITS None
set_parameter_property sdram_clk AFFECTS_ELABORATION true
set_parameter_property sdram_clk AFFECTS_GENERATION true
set_parameter_property sdram_clk VISIBLE true
set_parameter_property sdram_clk ENABLED true

add_parameter vga_clk boolean true
set_parameter_property vga_clk DISPLAY_NAME "Video (VGA and 5MP Digitial Camera)"
set_parameter_property vga_clk GROUP "Optional Clocks"
set_parameter_property vga_clk UNITS None
set_parameter_property vga_clk AFFECTS_ELABORATION true
set_parameter_property vga_clk AFFECTS_GENERATION true
set_parameter_property vga_clk VISIBLE true
set_parameter_property vga_clk ENABLED true

add_parameter audio_clk boolean true
set_parameter_property audio_clk DISPLAY_NAME "Audio"
set_parameter_property audio_clk GROUP "Optional Clocks"
set_parameter_property audio_clk UNITS None
set_parameter_property audio_clk AFFECTS_ELABORATION true
set_parameter_property audio_clk AFFECTS_GENERATION true
set_parameter_property audio_clk VISIBLE true
set_parameter_property audio_clk ENABLED true

add_parameter audio_clk_freq string "12.288"
set_parameter_property audio_clk_freq DISPLAY_NAME "Audio Clock Frequency"
set_parameter_property audio_clk_freq GROUP "Optional Clocks"
set_parameter_property audio_clk_freq UNITS Megahertz
set_parameter_property audio_clk_freq AFFECTS_ELABORATION true
set_parameter_property audio_clk_freq AFFECTS_GENERATION true
set_parameter_property audio_clk_freq ALLOWED_RANGES {"18.432" "16.9344" "12.288" "11.2896" "12.0"}
set_parameter_property audio_clk_freq VISIBLE true
set_parameter_property audio_clk_freq ENABLED false
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point clk_in_primary
# | 
add_interface clk_in_primary clock end
set_interface_property clk_in_primary ptfSchematicName ""

add_interface_port clk_in_primary CLOCK_50 clk Input 1
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point sys_clk
# | 
add_interface sys_clk clock start
#set_interface_property sys_clk associatedDirectClock "clk_in_primary"
set_interface_property sys_clk clockRate 50000000
set_interface_property sys_clk clockRateKnown true

add_interface_port sys_clk sys_clk clk Output 1
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point avalon_clocks_slave
# | 
add_interface avalon_clocks_slave avalon end clk_in_primary
set_interface_property avalon_clocks_slave addressAlignment DYNAMIC
set_interface_property avalon_clocks_slave bridgesToMaster ""
set_interface_property avalon_clocks_slave burstOnBurstBoundariesOnly false
#set_interface_property avalon_clocks_slave explicitAddressSpan 2
set_interface_property avalon_clocks_slave holdTime 0
set_interface_property avalon_clocks_slave isBigEndian  false
set_interface_property avalon_clocks_slave isFlash false
set_interface_property avalon_clocks_slave isMemoryDevice false
set_interface_property avalon_clocks_slave isNonVolatileStorage false
set_interface_property avalon_clocks_slave linewrapBursts false
set_interface_property avalon_clocks_slave maximumPendingReadTransactions 0
set_interface_property avalon_clocks_slave minimumUninterruptedRunLength 1
set_interface_property avalon_clocks_slave printableDevice false
set_interface_property avalon_clocks_slave readLatency 1
set_interface_property avalon_clocks_slave readWaitTime 0
set_interface_property avalon_clocks_slave setupTime 0
set_interface_property avalon_clocks_slave timingUnits cycles
set_interface_property avalon_clocks_slave writeWaitTime 0

add_interface_port avalon_clocks_slave address address Input 1
#add_interface_port avalon_clocks_slave byteenable byteenable Input 4
#add_interface_port avalon_clocks_slave chipselect chipselect Input 1
#add_interface_port avalon_clocks_slave read read Input 1
#add_interface_port avalon_clocks_slave write write Input 1
#add_interface_port avalon_clocks_slave writedata writedata Input 32
add_interface_port avalon_clocks_slave readdata readdata Output 8
# | 
# +-----------------------------------

# +-----------------------------------
# | Validation function
# | 
proc validate {} {
	set board [ get_parameter_value "board" ]
	set sys_clk_freq [ get_parameter_value "sys_clk_freq" ]
	set sdram_clk [ get_parameter_value "sdram_clk" ]
	set audio_clk [ get_parameter_value "audio_clk" ]
	set vga_clk [ get_parameter_value "vga_clk" ]
	set audio_clk_freq [ get_parameter_value "audio_clk_freq" ]
	
	set_parameter_property sdram_clk ENABLED false
	set_parameter_property audio_clk ENABLED false
	set_parameter_property vga_clk ENABLED false
	set_parameter_property audio_clk_freq ENABLED false

	if { $board == "DE3" } {
	} elseif { $board == "DE0" } {
		set_parameter_property sdram_clk ENABLED true
		set_parameter_property vga_clk ENABLED true
	} else {
		set_parameter_property sdram_clk ENABLED true
		set_parameter_property audio_clk ENABLED true
		set_parameter_property vga_clk ENABLED true

		if { $audio_clk } {
			set_parameter_property audio_clk_freq ENABLED true
		}
	}
}
# | 
# +-----------------------------------

# +-----------------------------------
# | Elaboration function
# | 
proc elaborate {} {
	set board [ get_parameter_value "board" ]
	set sys_clk_freq [ get_parameter_value "sys_clk_freq" ]
	set sdram_clk [ get_parameter_value "sdram_clk" ]
	set audio_clk [ get_parameter_value "audio_clk" ]
	set vga_clk [ get_parameter_value "vga_clk" ]
	set audio_clk_freq [ get_parameter_value "audio_clk_freq" ]

	set_interface_property sys_clk clockRate [ expr $sys_clk_freq * 1000000 ]

	if { $board == "DE3" } {
	} else {
		if { $sdram_clk || ($audio_clk  && ($board != "DE0")) } {
			# +-----------------------------------
			# | connection point external_interface
			# | 
#			add_interface external_interface conduit end CLOCK_50
			# | 
			# +-----------------------------------
		}

		if { $sdram_clk } {
#			add_interface_port external_interface DRAM_CLK export Output 1
# +-----------------------------------
# | connection point sdram_clk
# | 
add_interface sdram_clk clock start
#set_interface_property sys_clk associatedDirectClock "clk_in_primary"
set_interface_property sdram_clk clockRate 50000000
set_interface_property sdram_clk clockRateKnown true

add_interface_port sdram_clk SDRAM_CLK clk Output 1
# | 
# +-----------------------------------

		}
		if { $audio_clk && ($board != "DE0") } {
#			add_interface_port external_interface CLOCK_27 export Input 1
#			add_interface_port external_interface AUD_XCK export Output 1
# +-----------------------------------
# | connection point clk_in_secondary
# | 
add_interface clk_in_secondary clock end
set_interface_property clk_in_secondary ptfSchematicName ""

add_interface_port clk_in_secondary CLOCK_27 clk Input 1
# | 
# +-----------------------------------

# +-----------------------------------
# | connection point aud_clk
# | 
add_interface audio_clk clock start
#set_interface_property aud_clk associatedDirectClock "clk_in_secondary"
set_interface_property audio_clk clockRate 12880000
set_interface_property audio_clk clockRateKnown true

add_interface_port audio_clk AUD_CLK clk Output 1
# | 
# +-----------------------------------

		}
		if { $vga_clk } {
			# +-----------------------------------
			# | connection point vga_clock_out
			# | 
#			add_interface vga_clk clock start
##			set_interface_property vga_clk associatedDirectClock "clock_50"
#			set_interface_property vga_clk clockRate 25000000
#			set_interface_property vga_clk clockRateKnown true

#			add_interface_port vga_clk vga_clk clk Output 1
			# | 
			# +-----------------------------------
# +-----------------------------------
# | connection point vga_clk
# | 
add_interface vga_clk clock start
#set_interface_property vga_clk associatedDirectClock "clk_in_primary"
set_interface_property vga_clk clockRate 25000000
set_interface_property vga_clk clockRateKnown true

add_interface_port vga_clk VGA_CLK clk Output 1
# | 
# +-----------------------------------

		}
	}
}
# | 
# +-----------------------------------

# +-----------------------------------
# | Generation function
# | 
proc generate {} {
	send_message info "Starting Generation of Required Clocks for DE Boards"

	# get parameter values
	set board [ get_parameter_value "board" ]
	set sys_clk_freq [ get_parameter_value "sys_clk_freq" ]
	set sdram_clk [ get_parameter_value "sdram_clk" ]
	set audio_clk [ get_parameter_value "audio_clk" ]
	set vga_clk [ get_parameter_value "vga_clk" ]
	set audio_clk_freq [ get_parameter_value "audio_clk_freq" ]

	if { $sys_clk_freq == 100 } {
		set sys_clk_mult "SYS_CLK_MULT:2"
	} elseif { $sys_clk_freq == 150 } {
		set sys_clk_mult "SYS_CLK_MULT:3"
	} elseif { $sys_clk_freq == 200 } {
		set sys_clk_mult "SYS_CLK_MULT:4"
	} else {
		set sys_clk_mult "SYS_CLK_MULT:1"
	}
	if { $sys_clk_freq == 25 } {
		set sys_clk_div "SYS_CLK_DIV:2"
	} else {
		set sys_clk_div "SYS_CLK_DIV:1"
	}

	if { $audio_clk_freq == "18.432" } {
		set aud_clk_mult "AUD_CLK_MULT:15"
		set aud_clk_div  "AUD_CLK_DIV:22"
	} elseif { $audio_clk_freq == "16.9344" } {
		set aud_clk_mult "AUD_CLK_MULT:5"
		set aud_clk_div  "AUD_CLK_DIV:8"
	} elseif { $audio_clk_freq == "12.288" } {
		set aud_clk_mult "AUD_CLK_MULT:14"
		set aud_clk_div  "AUD_CLK_DIV:31"
	} elseif { $audio_clk_freq == "11.2896" } {
		set aud_clk_mult "AUD_CLK_MULT:13"
		set aud_clk_div  "AUD_CLK_DIV:31"
	} else {
		set aud_clk_mult "AUD_CLK_MULT:4"
		set aud_clk_div  "AUD_CLK_DIV:9"
	}

	# set section values
	set use_cyclone_iii "USE_CYCLONE_III:0"
	if { $board == "DE0" } {
		set use_cyclone_iii "USE_CYCLONE_III:1"
	}

	set use_cyclone_iv "USE_CYCLONE_IV:0"
	if { $board == "DE2-115" } {
		set use_cyclone_iv "USE_CYCLONE_IV:1"
	}
	
	if { $board == "DE3" } {
		set use_sdram_clk	"USE_SDRAM_CLK:0"
		set use_aud_clk		"USE_AUDIO_CLK:0"
		set use_vga_clk		"USE_VGA_CLK:0"
	} else {
		set use_sdram_clk	[ format "USE_SDRAM_CLK:%d" [ string match "true" $sdram_clk ] ]
		if { ($board == "DE0") } {
			set use_aud_clk		"USE_AUDIO_CLK:0"
		} else {
			set use_aud_clk	[ format "USE_AUDIO_CLK:%d" [ string match "true" $audio_clk ] ]
		}
		set use_vga_clk		[ format "USE_VGA_CLK:%d" [ string match "true" $vga_clk ] ]
	}

	# set arguments
	set params "$sys_clk_mult;$sys_clk_div;$aud_clk_mult;$aud_clk_div"
	set sections "$use_cyclone_iii;$use_cyclone_iv;$use_sdram_clk;$use_aud_clk;$use_vga_clk" 

	# get generation settings
#	set dest_language	[ get_generation_property HDL_LANGUAGE ]
	set dest_dir 		[ get_generation_property OUTPUT_DIRECTORY ]
	set dest_name		[ get_generation_property OUTPUT_NAME ]
	add_file "$dest_dir$dest_name.v" {SYNTHESIS SIMULATION}

	# Generate HDL
	source "up_ip_generator.tcl"
	alt_up_generate "$dest_dir$dest_name.v" "hdl/altera_up_avalon_clocks.v" $dest_name $params $sections

	# generate top level template
	#alt_up_create_instantiation_template "$dest_dir$dest_name.inst.v" $dest_name "external_interface"
}
# | 
# +-----------------------------------

