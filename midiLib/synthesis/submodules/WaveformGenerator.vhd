-- Original Author	: Bharathwaj Muthuswamy
-- Additional Author : Peter Crinklaw
-- Based on version by	: Eric Lunty, Kyle Brooks, Peter Roland
-- http://www.ece.ualberta.ca/~elliott/ece492/appnotes/2012w/Audio_Codec_G2/waveform_gen.vhd

library ieee;
use ieee.std_logic_1164.all;
--use ieee.std_logic_arith.all;
use ieee.numeric_std.all;

entity WaveformGenerator is

port (

	-- system signals
	clk         : in  std_logic;
	reset_n       : in  std_logic;
  
  
	-- Frequency control
	avs_writedata_phase_increments_voice0   : in  std_logic_vector(63 downto 0);
	avs_write_n_phase_increments_voice0   	: in  std_logic;
	
	avs_writedata_phase_increments_voice1   : in  std_logic_vector(63 downto 0);
	avs_write_n_phase_increments_voice1 	: in  std_logic;
	
	avs_writedata_phase_increments_voice2   : in  std_logic_vector(63 downto 0);
	avs_write_n_phase_increments_voice2 	: in  std_logic;
	
	
	--note end signals
	--writedata is not read, only included to satisfy avalon mm interface
	avs_writedata_note_end_voice0   : in  std_logic_vector(7 downto 0);
	avs_write_n_note_end_voice0   	: in  std_logic;
	
	avs_writedata_note_end_voice1   : in  std_logic_vector(7 downto 0);
	avs_write_n_note_end_voice1   	: in  std_logic;
	
	avs_writedata_note_end_voice2   : in  std_logic_vector(7 downto 0);
	avs_write_n_note_end_voice2   	: in  std_logic;

	
	--wave shape selector, uniform across all voices
	avs_writedata_wave_shapes 	: in std_logic_vector(7 downto 0);
	avs_write_n_wave_shapes 	: in std_logic	
  );
end entity;


architecture rtl of WaveformGenerator is


component VoiceGenerator is
port (
	-- system signals
	clk         : in  std_logic;
	reset_n       : in  std_logic;
  
	--Frequency control
	--Bottom 16 bits are for first oscillator, next 16 are for second, next 16 are for third
	phase_increments   	: in  std_logic_vector(63 downto 0);
	
	-- Envelope control
	start_note_n		: in std_logic;
	end_note_n			: in std_logic;	
	
	wave_shapes			: in std_logic_vector(7 downto 0);
	
	waveSum				: out std_logic_vector(15 downto 0)
  );
end component;



signal voice0_wave : std_logic_vector(15 downto 0);
signal voice1_wave : std_logic_vector(15 downto 0);
signal voice2_wave : std_logic_vector(15 downto 0);

signal oscillator0_wave_shape_s : std_logic_vector(7 downto 0);
signal oscillator1_wave_shape_s : std_logic_vector(7 downto 0);
signal oscillator2_wave_shape_s : std_logic_vector(7 downto 0);

signal waveSum : std_logic_vector(15 downto 0);


begin
	

waveSum <= std_logic_vector(unsigned(voice0_wave) + 
							unsigned(voice1_wave) + 
							unsigned(voice2_wave) );


v0: VoiceGenerator
	port map(
		clk => clk,
		reset_n => reset_n,
		phase_increments => avs_writedata_phase_increments_voice0,
		start_note_n => avs_write_n_phase_increments_voice0,
		end_note_n => avs_write_n_note_end_voice0,
		wave_shapes => avs_writedata_wave_shapes,
		waveSum => voice0_wave
	);

	
v1: VoiceGenerator
	port map(
		clk => clk,
		reset_n => reset_n,
		phase_increments => avs_writedata_phase_increments_voice1,
		start_note_n => avs_write_n_phase_increments_voice1,
		end_note_n => avs_write_n_note_end_voice1,
		wave_shapes => avs_writedata_wave_shapes,
		waveSum => voice1_wave
	);

v2: VoiceGenerator
	port map(
		clk => clk,
		reset_n => reset_n,
		phase_increments => avs_writedata_phase_increments_voice2,
		start_note_n => avs_write_n_phase_increments_voice2,
		end_note_n => avs_write_n_note_end_voice2,
		wave_shapes => avs_writedata_wave_shapes,
		waveSum => voice2_wave
	);	


end architecture;