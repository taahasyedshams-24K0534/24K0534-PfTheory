#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Species {
    char** supplies;
    int numSupplies;
};

void initializeInventory(struct Species* speciesArray, int* numSpecies) {
    printf("Enter the number of species: ");
    scanf("%d", numSpecies);

    speciesArray = (struct Species*)malloc(*numSpecies * sizeof(struct Species));

    for (int i = 0; i < *numSpecies; i++) {
        printf("Enter the number of supplies for species %d: ", i + 1);
        scanf("%d", &speciesArray[i].numSupplies);

        speciesArray[i].supplies = (char**)malloc(speciesArray[i].numSupplies * sizeof(char*));
        for (int j = 0; j < speciesArray[i].numSupplies; j++) {
            speciesArray[i].supplies[j] = (char*)malloc(100 * sizeof(char));
            strcpy(speciesArray[i].supplies[j], "");
        }
    }
}

void addSupplies(struct Species* speciesArray, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        printf("\nEnter supplies for species %d:\n", i + 1);
        for (int j = 0; j < speciesArray[i].numSupplies; j++) {
            printf("Enter supply %d for species %d: ", j + 1, i + 1);
            scanf("%s", speciesArray[i].supplies[j]);
        }
    }
}

void updateSupplies(struct Species* speciesArray, int numSpecies) {
    int speciesIndex, supplyIndex;
    printf("\nEnter the species index to update (1 to %d): ", numSpecies);
    scanf("%d", &speciesIndex);
    if (speciesIndex < 1 || speciesIndex > numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    printf("Enter the supply index to update (1 to %d): ", speciesArray[speciesIndex - 1].numSupplies);
    scanf("%d", &supplyIndex);
    if (supplyIndex < 1 || supplyIndex > speciesArray[speciesIndex - 1].numSupplies) {
        printf("Invalid supply index.\n");
        return;
    }

    printf("Enter the new name for supply %d of species %d: ", supplyIndex, speciesIndex);
    scanf("%s", speciesArray[speciesIndex - 1].supplies[supplyIndex - 1]);
}

void removeSpecies(struct Species* speciesArray, int* numSpecies) {
    int speciesIndex;
    printf("\nEnter the species index to remove (1 to %d): ", *numSpecies);
    scanf("%d", &speciesIndex);
    if (speciesIndex < 1 || speciesIndex > *numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    for (int i = 0; i < speciesArray[speciesIndex - 1].numSupplies; i++) {
        free(speciesArray[speciesIndex - 1].supplies[i]);
    }
    free(speciesArray[speciesIndex - 1].supplies);

    for (int i = speciesIndex - 1; i < *numSpecies - 1; i++) {
        speciesArray[i] = speciesArray[i + 1];
    }

    (*numSpecies)--;
    speciesArray = (struct Species*)realloc(speciesArray, (*numSpecies) * sizeof(struct Species));
}

void displayInventory(struct Species* speciesArray, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        printf("\nSpecies %d:\n", i + 1);
        for (int j = 0; j < speciesArray[i].numSupplies; j++) {
            if (strlen(speciesArray[i].supplies[j]) > 0) {
                printf("  Supply %d: %s\n", j + 1, speciesArray[i].supplies[j]);
            }
        }
    }
}

int main() {
    struct Species* speciesArray;
    int numSpecies;

    initializeInventory(speciesArray, &numSpecies);
    addSupplies(speciesArray, numSpecies);
    displayInventory(speciesArray, numSpecies);
    updateSupplies(speciesArray, numSpecies);
    displayInventory(speciesArray, numSpecies);
    removeSpecies(speciesArray, &numSpecies);
    displayInventory(speciesArray, numSpecies);

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < speciesArray[i].numSupplies; j++) {
            free(speciesArray[i].supplies[j]);
        }
        free(speciesArray[i].supplies);
    }
    free(speciesArray);

    return 0;
}
