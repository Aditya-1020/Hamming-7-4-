#include <stdio.h>
#include <string.h>

#define BIT_SZ 4

int main(int argc, char *argv[]) {

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
        data[i] = input[i] - '0';  // Convert '0'/'1' char to int (ASCII trick)
    }

    printf("Received data: ");
    for (int i = 0; i < BIT_SZ; i++) {
        printf("%d", data[i]);
    }
    printf("\n");
    
    return 0;
}