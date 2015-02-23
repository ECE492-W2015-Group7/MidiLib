-- Original Author	: Bharathwaj Muthuswamy
-- Additional Author : Peter Crinklaw
-- Based on version by	: Eric Lunty, Kyle Brooks, Peter Roland
-- http://www.ece.ualberta.ca/~elliott/ece492/appnotes/2012w/Audio_Codec_G2/waveform_gen.vhd

library ieee;
use ieee.std_logic_1164.all;
--use ieee.std_logic_arith.all;
use ieee.numeric_std.all;

entity VoiceGenerator is

port (
	-- system signals
	clk         : in  std_logic;
	reset_n       : in  std_logic;
  
	-- Frequency control
	--Bottom 16 bits are for first oscillator, next 16 are for second, next 16 are for third
	phase_increments   	: in  std_logic_vector(63 downto 0);
	
	-- Envelope control
	start_note_n		: in std_logic;
	end_note_n			: in std_logic;

	wave_shapes			: in std_logic_vector(7 downto 0);
	
	waveSum				: out std_logic_vector(15 downto 0)
  );
end entity;




architecture rtl of VoiceGenerator is


component Oscillator
port (

	-- system signals
	clk         : in  std_logic;
	reset_n       : in  std_logic;
  
	-- NCO frequency control
	phase_inc   : in  std_logic_vector(15 downto 0);
	
	wave_shape 	: in std_logic_vector(1 downto 0);
	-- Output waveforms
	wave_out     : out std_logic_vector(15 downto 0) 
);
end component;

signal oscillator0_phase_inc : std_logic_vector(15 downto 0) := x"0000";
signal oscillator1_phase_inc : std_logic_vector(15 downto 0) := x"0000";
signal oscillator2_phase_inc : std_logic_vector(15 downto 0) := x"0000";

signal oscillator0_output : std_logic_vector(15 downto 0);
signal oscillator1_output : std_logic_vector(15 downto 0);
signal oscillator2_output : std_logic_vector(15 downto 0);

--signal waveSum : std_logic_vector(15 downto 0);

begin

	waveSum <= std_logic_vector(unsigned(oscillator0_output) + 
								unsigned(oscillator1_output) + 
								unsigned(oscillator2_output) );


	update_phase_increments: process(start_note_n)
	begin
		if start_note_n = '0' then
			oscillator0_phase_inc <= phase_increments(15 downto 0);
			oscillator1_phase_inc <= phase_increments(31 downto 16);
			oscillator2_phase_inc <= phase_increments(47 downto 32);
		end if;
	end process ;

	o0: Oscillator
	port map
	(
		clk => clk,
		reset_n => reset_n,
		phase_inc => oscillator0_phase_inc,
		wave_shape => wave_shapes(1 downto 0),
		wave_out => oscillator0_output
	);
  
	o1: Oscillator
	port map
	(
		clk => clk,
		reset_n => reset_n,
		phase_inc => oscillator1_phase_inc,
		wave_shape => wave_shapes(3 downto 2),
		wave_out => oscillator1_output
	);
  
	o2: Oscillator
	port map
	(
		clk => clk,
		reset_n => reset_n,
		phase_inc => oscillator2_phase_inc,
		wave_shape => wave_shapes(5 downto 4),
		wave_out => oscillator3_output
	);
	
end rtl;