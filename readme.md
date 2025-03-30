# Hamming(7,4) Project

This project implements Hamming(7,4) encoding and decoding to detect and correct single-bit errors in a 4-bit binary input. The program:
- Encodes 4-bit data into a 7-bit Hamming code using parity bits.
- Introduces a random bit flip to simulate noise.
- Uses syndrome decoding to detect and correct errors.
- Decodes the 7-bit Hamming code back to the original 4-bit data.

How to Run

Compilation

gcc main.c -o main

Execution

./main 1011

Note: The program expects a valid 4-bit binary number as input. If an invalid input is provided, an error message will be displayed.

---
# My notes

Wat du..
- Encode 4-bit data into 7-bit Hamming code using parity rules
    - introduce random bit flip to simulate noise
- use syndrome decoding to detect error bit
    - flip the bit back
- Decode 7-bit Hamming code back to 4-bit data


## Parity bits
extra bits added to enable error detection and correction calculated using XOR
Number of parity bits is choosen by 2^p \geq d + p + 1
- p is number of parity bits
- d is  number of data bits -> d+p = total number of bits in codeword
For hamming(7,4) -> d = 4
- Using 3 parity bits for this project

parity bits are placed in powers of two positions
- how do you place elements in only powers of 2 pos and fill rest spots


## Syndrome decoding
The main part which checks for errors
- (7,4) is recieved system recalculates parity bits
- recalculation produces set of values known as syndrome
- syndrome is binary number that represents positon of potential error
    ex: syndrome: 101 (binary 5) indicates error in 5th bit

---
