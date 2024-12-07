#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;
    int dotAfterAt = 0;
    int atPosition = -1;

    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = i;
        } else if (atCount == 1 && email[i] == '.') {
            dotAfterAt = 1;
        }
    }

    if (atCount == 1 && dotAfterAt && atPosition < strlen(email) - 1) {
        return 1;
    }
    return 0;
}

int main() {
    char input[1000];
    printf("Enter an email address: ");
    scanf("%999s", input);

    int length = strlen(input);
    char* email = (char*)malloc((length + 1) * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(email, input);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}
