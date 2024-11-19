#include <stdio.h>

void histogram(int integers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < integers[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    int max = integers[0];

    for (int i = 1; i < count; i++) {
        if (integers[i] > max) {
            max = integers[i];
        }
    }

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (integers[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

  
    printf("\n");

    for (int i = 0; i < count; i++) {
        printf("%d ", integers[i]);
    }
    printf("\n");
}

int main() {
    int integers[] = {3, 4, 1, 6};
    int count = sizeof(integers) / sizeof(integers[0]);
    histogram(integers, count);

}
