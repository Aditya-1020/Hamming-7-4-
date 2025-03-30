#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_SZ 7
#define BIT_SZ 4
#define CHK_SZ (ARR_SZ/2)

int main(int argc, char *argv[]) {
    
    // check if argc is valid
    if (argc != 2){
        printf("Usage: %s <4-bit binary number\n", argv[0]);
        return 1;
    }
    char *input = argv[1];

    if(strlen(input) != BIT_SZ){
        printf("Error: Input must be a 4-bit binary number.\n");
        return 1;
    }

    int data[BIT_SZ];
    
    for (int i = 0; i < BIT_SZ; i++) {
        if (input[i] != '0' && input[i] != '1') {
            printf("Error: Input must contain only '0' or '1'.\n");
            return 1;
        }
        data[i] = input[i] - '0';  // Convert '0'/'1' char to int
    }

    printf("Received data: ");
    for (int i = 0; i < BIT_SZ; i++) {
        printf("%d", data[i]);
    }
    printf("\n");


    int encoded[ARR_SZ], check[CHK_SZ], temp_arr[CHK_SZ];
    int syndrome = 0;


    // Hamming (7,4) encoding
    encoded[2] = data[0];  // D1 → Position 3
    encoded[4] = data[1];  // D2 → Position 5
    encoded[5] = data[2];  // D3 → Position 6
    encoded[6] = data[3];  // D4 → Position 7

    // calculating parity bits
    check[0] = encoded[0] = encoded[2] ^ encoded[4] ^ encoded[6];  // P1 → Position 1
    check[1] = encoded[1] = encoded[2] ^ encoded[5] ^ encoded[6];  // P2 → Position 2
    check[2] = encoded[3] = encoded[4] ^ encoded[5] ^ encoded[6];  // P3 → Position 4


    // printing array after encoding
    printf("Encoded data: ");
    for (int i = 0; i < ARR_SZ; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");

    // Simulating noise

    srand(time(NULL));
    int min = 0;
    int max = 6;

    int random_num = rand() % (max - min + 1) + min;
 
    encoded[random_num] = (encoded[random_num] == 1) ? 0 : 1; // flipping the bit if 1 set 0 if 0 set 1

    // printing flipped aray
    printf("Array after Bit flipped: ");
    for (int i = 0; i < ARR_SZ; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");

    // Syndrome decoding

    /*
    - recalculate
    - cross check to original
    - find position
    */

    temp_arr[0] = encoded[2] ^ encoded[4] ^ encoded[6];  // P1 → Position 1
    temp_arr[1] = encoded[2] ^ encoded[5] ^ encoded[6];  // P2 → Position 2
    temp_arr[2] = encoded[4] ^ encoded[5] ^ encoded[6];  // P3 → Position 4

    // array before correction
    printf("Syndrome array before correction: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", temp_arr[i]);
    }
    printf("\n");

    
    syndrome |= (temp_arr[0] != check[0]) << 0; // reads: if different set lsb of syndrome to 1 else 0
    syndrome |= (temp_arr[1] != check[1]) << 1; 
    syndrome |= (temp_arr[2] != check[2]) << 2; 

    printf("Syndrome Value: %d\n", syndrome);

    if (syndrome == 0) {
        printf("No error was introduced\n");
    } else {
        printf("Error at position %d in array\n", syndrome);
        encoded[syndrome - 1] ^= 1;
    }

    return 0;
}