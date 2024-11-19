#include <stdio.h>
#include <string.h>

int comp_word(const char *in, char *out) {
    int removed = 0;
    int j = 0;
    int len = strlen(in);

    for (int i = 0; i < len; i++) {
        if (i == 0 || in[i] != in[i - 1]) {
            out[j++] = in[i];
        } else {
            removed++;
        }
    }

    out[j] = '\0';
    return removed;
}

void comp_words(char words[][100], int count, char res[][100], int *total_removed) {
    *total_removed = 0;

    for (int i = 0; i < count; i++) {
        int removed = comp_word(words[i], res[i]);
        *total_removed += removed;
    }
}

int main() {
    char words[3][100] = {"booooook", "coooool", "heeeey"};
    int count = 3;
    char res[3][100];
    int total_removed = 0;

    comp_words(words, count, res, &total_removed);

    for (int i = 0; i < count; i++) {
        printf("%s\n", res[i]);
    }

    printf("Total removed: %d\n", total_removed);

    return 0;
}
