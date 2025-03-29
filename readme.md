# Hamming(7,4) Project

Takes 4-bit data and adds 3 parity bits forming 7-bit codeword.
Can correct single bit error and dectect two-bit errors.

Get -> Encode -> Check -> Decode

Wat du..
- Encode 4-bit data into 7-bit Hamming code using parity rules
    - introduce random bit flip to simulate noise
- use syndrome decoding to detect error bit
    - flip the bit back
- Decode 7-bit Hamming code back to 4-bit data

https://www.youtube.com/watch?v=X8jsijhllIA
https://www.youtube.com/watch?v=h0jloehRKas



## Parity bits
extra bits added to enable error detection and correction calculated using XOR
Number of parity bits is choosen by 2^{p} >= d + p + 1
- p is number of parity bits
- d is  number of data bits -> d+p = total number of bits in codeword
For hamming(7,4) -> d = 4
- Using 3 parity bits for this project

parity bits are placed in powers of two positions
- how do you place elements in only powers of 2 pos and fill rest spots


## Syndrome decoding
