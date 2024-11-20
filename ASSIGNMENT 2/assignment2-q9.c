#include <stdio.h>

void displayGrid(char grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerP = 24;  
    char move;
    int gameRunning = 1;

    printf("Initial Grid:\n");
    displayGrid(grid);

    while (gameRunning) {
        printf("Your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        int playerRow = playerP / 5;
        int playerCol = playerP % 5;

        int newRow = playerRow, newCol = playerCol;

        if (move == 'W' || move == 'w') {
            newRow--;
        } else if (move == 'S' || move == 's') {
            newRow++;
        } else if (move == 'A' || move == 'a') {
            newCol--;
        } else if (move == 'D' || move == 'd') {
            newCol++;
        } else if (move == 'Q' || move == 'q') {
            printf("You quit the game\n");
            gameRunning = 0;
            continue;
        } else {
            printf("Invalid move! Please try again\n");
            continue;
        }

        if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5 && grid[newRow][newCol] != 'X') {
            if (grid[newRow][newCol] == 'I') {
                printf("You collected an item\n");
            }

            grid[playerRow][playerCol] = ' ';
            grid[newRow][newCol] = 'P';

            playerP = newRow * 5 + newCol;
        } else {
            printf("Invalid move\ n");
        }

        printf("\n");
        displayGrid(grid);
    }

    return 0;
}
