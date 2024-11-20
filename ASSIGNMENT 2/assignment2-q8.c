#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, rem;
    
    while (number > 0) {
        rem = number % 10;
        decimal = decimal + rem * base;
        number = number / 10;
        base = base * 2;
    }
    
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, remainder, place = 1;
    
    while (number > 0) {
        remainder = number % 2;
        binary = binary + remainder * place;
        number = number / 2;
        place = place * 10;
    }
    
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;
    
    if (number == 0) {
        printf("0");
        return;
    }
    
    while (number != 0) {
        int rem = number % 16;
        
        if (rem < 10)
            hex[i] = rem + '0';
        else
            hex[i] = rem - 10 + 'A';
        
        i++;
        number = number / 16;
    }
    
    printf("hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void HexadecimalToDecimal(char hexnum[]) {
    int len = strlen(hexnum);
    int base = 1, decimal = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (hexnum[i] >= '0' && hexnum[i] <= '9') {
            decimal += (hexnum[i] - '0') * base;
        } else if (hexnum[i] >= 'A' && hexnum[i] <= 'F') {
            decimal += (hexnum[i] - 'A' + 10) * base;
        } else if (hexnum[i] >= 'a' && hexnum[i] <= 'f') {
            decimal += (hexnum[i] - 'a' + 10) * base;
        } else {
            printf("invalid hexadecimal character: %c\n", hexnum[i]);
            return;
        }
        base = base * 16;
    }
    
    printf("decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexnum[]) {
    int decimal = 0;
    int len = strlen(hexnum);
    
    for (int i = 0; i < len; i++) {
        if (hexnum[i] >= '0' && hexnum[i] <= '9') {
            decimal = decimal * 16 + (hexnum[i] - '0');
        } else if (hexnum[i] >= 'A' && hexnum[i] <= 'F') {
            decimal = decimal * 16 + (hexnum[i] - 'A' + 10);
        } else if (hexnum[i] >= 'a' && hexnum[i] <= 'f') {
            decimal = decimal * 16 + (hexnum[i] - 'a' + 10);
        } else {
            printf("invalid hexadecimal character: %c\n", hexnum[i]);
            return;
        }
    }
    
    printf("binary: ");
    for (int i = sizeof(decimal) * 8 - 1; i >= 0; i--) {
        int k = decimal >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    int choice, number;
    char hexnum[20];
    
    while (1) {
        printf("menu:\n");
        printf("1. binary to decimal\n");
        printf("2. decimal to binary\n");
        printf("3. decimal to hexadecimal\n");
        printf("4. hexadecimal to decimal\n");
        printf("5. binary to hexadecimal\n");
        printf("6. hexadecimal to binary\n");
        printf("7. end\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter a binary number: ");
                scanf("%d", &number);
                printf("decimal: %d\n", BinaryToDecimal(number));
                break;
                
            case 2:
                printf("enter a decimal number: ");
                scanf("%d", &number);
                printf("binary: %d\n", DecimalToBinary(number));
                break;
                
            case 3:
                printf("enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
                
            case 4:
                printf("enter a hexadecimal number: ");
                scanf("%s", hexnum);
                HexadecimalToDecimal(hexnum);
                break;
                
            case 5:
                printf("enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
                
            case 6:
                printf("enter a hexadecimal number: ");
                scanf("%s", hexnum);
                HexadecimalToBinary(hexnum);
                break;
                
            case 7:
                printf("ended\n");
                return 0;
                
            default:
                printf("invalid choice! please try again\n");
        }
    }
    
    return 0;
}
