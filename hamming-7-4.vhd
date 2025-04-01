-- ====================================================================
-- Entity Name: hamming_7_4
-- Description: VHDL file for Hamming (7,4) implementation.
-- Author: [Your Name]
-- Date: [Date]
-- ====================================================================

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity hamming_7_4_encoder is
    Port (
        DATA : in  bit_vector(3 downto 0);
        HAM_OUT : out bit_vector(6 downto 0)
    );
end hamming_7_4_encoder;

architecture RTL of hamming_7_4_encoder is
begin

    -- Encoder
    process(DATA)
    begin
        HAM_OUT(2) <= DATA(0);
        HAM_OUT(4) <= DATA(1);
        HAM_OUT(5) <= DATA(2);
        HAM_OUT(6) <= DATA(3);

        -- calculating parity bits
        HAM_OUT(0) <= HAM_OUT(2) xor HAM_OUT(4) xor HAM_OUT(6);
        HAM_OUT(1) <= HAM_OUT(2) xor HAM_OUT(5) xor HAM_OUT(6);
        HAM_OUT(3) <= HAM_OUT(4) xor HAM_OUT(5) xor HAM_OUT(6);
    end process;

end RTL;

entity hamming_7_4_decoder is
    Port (
        HAM_IN : in bit_vector(6 downto 0);
        DATA_OUT : out bit_vector(3 downto 0);
        SYNDROME : out bit_vector(2 downto 0)
    );
end hamming_7_4_decoder;

architecture RTL of hamming_7_4_decoder is
begin

    -- Decoder
    process(HAM_IN)
    begin
        -- Step 1: Recalculate parity bits based on the received HAM_IN.
        -- Step 2: Generate the 3-bit syndrome by comparing recalculated parity bits with received parity bits.
        SYNDROME(0) <= HAM_IN(2) xor HAM_IN(4) xor HAM_IN(6);
        SYNDROME(1) <= HAM_IN(2) xor HAM_IN(5) xor HAM_IN(6);
        SYNDROME(2) <= HAM_IN(4) xor HAM_IN(5) xor HAM_IN(6);

        -- Step 3: If the syndrome is non-zero, identify the erroneous bit position.
        -- Step 4: Correct the erroneous bit in HAM_IN.
        -- Step 5: Extract the corrected 4-bit data from HAM_IN.
        -- Step 6: Assign the syndrome to the SYNDROME output.
    end process;

end RTL;