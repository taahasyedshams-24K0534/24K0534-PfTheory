#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_strings(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

void group_anagrams(char *transactions[], int num_transactions) {
    char *sorted_transactions[num_transactions];
    char *anagram_groups[num_transactions][num_transactions];
    int group_count = 0;

    for (int i = 0; i < num_transactions; i++) {
        char *sorted = strdup(transactions[i]);
        qsort(sorted, strlen(sorted), sizeof(char), compare_strings);

        int found_group = 0;
        for (int j = 0; j < group_count; j++) {
            if (strcmp(sorted, sorted_transactions[j]) == 0) {
                anagram_groups[j][i] = transactions[i];
                found_group = 1;
                break;
            }
        }

        if (!found_group) {
            sorted_transactions[group_count] = sorted;
            anagram_groups[group_count][0] = transactions[i];
            group_count++;
        } else {
            free(sorted);
        }
    }

    for (int i = 0; i < group_count; i++) {
        printf("[");
        for (int j = 0; j < num_transactions && anagram_groups[i][j] != NULL; j++) {
            printf("'%s'", anagram_groups[i][j]);
            if (anagram_groups[i][j + 1] != NULL) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main() {
    char *transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int num_transactions = 6;

    group_anagrams(transactions, num_transactions);

    return 0;
}
