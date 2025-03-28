#include <stdio.h>

#define ARR_SZ 6

int main(void) {

    int data[] = {1,0,1,1}; // ex: 1011
    int encoded[ARR_SZ];

    encoded[2] = data[0];  // D1 → Position 3
    encoded[4] = data[1];  // D2 → Position 5
    encoded[5] = data[2];  // D3 → Position 6
    encoded[6] = data[3];  // D4 → Position 7

    // calculating parity bits using parirty rules

    encoded[0] = encoded[2] ^ encoded[4] ^ encoded[6];  // P1 → Position 1
    encoded[1] = encoded[2] ^ encoded[5] ^ encoded[6];  // P2 → Position 2
    encoded[3] = encoded[4] ^ encoded[5] ^ encoded[6];  // P3 → Position 4

    


    return 0;
}