-- Original Author	: Bharathwaj Muthuswamy
-- Additional Author : Peter Crinklaw
-- Based on version by	: Eric Lunty, Kyle Brooks, Peter Roland
-- http://www.ece.ualberta.ca/~elliott/ece492/appnotes/2012w/Audio_Codec_G2/waveform_gen.vhd

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity Oscillator is

port (

  -- system signals
  clk         : in  std_logic;
  reset_n       : in  std_logic;
  
  -- NCO frequency control
  phase_inc   : in  std_logic_vector(15 downto 0);
  
  wave_shape : in std_logic_vector(1 downto 0);
  
  -- Output waveforms
  wave_out     : out std_logic_vector(15 downto 0)
  );
end entity;


architecture rtl of Oscillator is

constant SIN := "01";
constant SQU := "10";
constant SAW := "11";

component SinLut
port 
	(
	clk      : in  std_logic;
	--en       : in  std_logic;
	
	--Address input
	addr     : in  std_logic_vector(11 downto 0);
	
	--Sine output
	sin_out  : out std_logic_vector(15 downto 0)
	);
end component;

signal  phase_acc     : std_logic_vector(15 downto 0);
signal  lut_addr      : std_logic_vector(11 downto 0);
signal  lut_addr_reg  : std_logic_vector(11 downto 0);

signal  sin_out     : std_logic_vector(7 downto 0);
signal  squ_out     : std_logic_vector(7 downto 0);
signal  saw_out     : std_logic_vector(7 downto 0);

begin


--------------------------------------------------------------------------
-- Phase accumulator increments by 'phase_inc' every clock cycle        --
-- Output frequency determined by formula: Phase_inc = (Fout/Fclk)*2^32 --
-- E.g. Fout = 36MHz, Fclk = 100MHz,  Phase_inc = 36*2^32/100           --
-- Frequency resolution is 100MHz/2^32 = 0.00233Hz                      --
--------------------------------------------------------------------------
	

phase_acc_reg: process(clk, reset_n)
begin
  if reset_n = '0' then
    	phase_acc <= (others => '0');

  elsif clk'event and clk = '1' then
    --if en = '1' then
      	phase_acc <= unsigned(phase_acc) + unsigned(phase_inc_s);  
    --end if;
  end if;
end process phase_acc_reg;

get_output: process(clk, reset_n)
begin
  if reset_n = '0' then
    	wave_out <= (others => '0');

  elsif clk'event and clk = '0' then
		case wave_shape is
			when SIN =>		wave_out <= sin_out;
			when SQU =>		wave_out <= squ_out;
			when SAW =>		wave_out <= saw_out;
			when others =>  wave_out <= x"0000";
		end case;
  end if;
end process phase_acc_reg;

---------------------------------------------------------------------
-- use top 12-bits of phase accumulator to address the SIN LUT --
---------------------------------------------------------------------

lut_addr <= phase_acc(15 downto 4);

----------------------------------------------------------------------
-- SIN LUT is 4096 by 12-bit ROM                                    --
-- 12-bit output allows sin amplitudes between 2047 and -2047       --
-- (-2048 not used to keep the output signal perfectly symmetrical) --
-- Phase resolution is 2Pi/4096 = 0.088 degrees                     --
----------------------------------------------------------------------

lut: SinLut

  port map
  (
    	clk       => clk,
    	--en        => en,
    	addr      => lut_addr,
		sin_out   => sin_out
  );

---------------------------------
-- Hide the latency of the LUT --
---------------------------------

delay_regs: process(clk)
begin
  if clk'event and clk = '1' then
    --if en = '1' then
      	lut_addr_reg <= lut_addr;
    --end if;
  end if;
end process delay_regs;

---------------------------------------------
-- Square output is msb of the accumulator --
---------------------------------------------

squ_out <= "0011111111111111" when lut_addr_reg(11) = '1' else "1100000000000000";

-------------------------------------------------------
-- Sawtooth output is top 16-bits of the accumulator --
-------------------------------------------------------

saw_out <= lut_addr_reg(11 downto 0);

end rtl;