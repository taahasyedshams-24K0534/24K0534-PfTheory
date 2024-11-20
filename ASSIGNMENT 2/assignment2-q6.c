#include <stdio.h>

int firstmove(int n) {
    if (n % 5 == 0) {
        return -1;
    }
    return n % 5;
}

int main() {
    int n;

    printf("enter the number of matchsticks: ");
    scanf("%d", &n);

    int result = firstmove(n);
    if (result == -1) {
        printf("impossible for A to win \n");
    } else {
        printf("pick %d matchsticks on the first turn to guarantee a win \n", result);
    }

    return 0;
}
