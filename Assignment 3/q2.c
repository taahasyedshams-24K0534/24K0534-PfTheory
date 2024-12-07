#include <stdio.h>
#include <string.h>
struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

void playerdet(struct Player player) {
    printf("Enter the name of the player: ");
    scanf("%s", player.playerName);

    player.totalScore = 0;

    for (int i = 0; i < 12; i++) {
        int score;
        printf("Enter the score for ball %d (0-6): ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player.ballScores[i] = score;
            player.totalScore += score;
        } else {
            printf("Invalid score! Score must be between 0 and 6. Ball %d will be marked but not counted.\n", i + 1);
            player.ballScores[i] = 0;
        }
    }
}

int validateScore(int score) {
    return score >= 0 && score <= 6;
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("\n%s wins with a total score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("\n%s wins with a total score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("\nIt's a tie! Both players have a total score of %d.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\nMatch Summary:\n");
    printf("Player: %s\n", player1.playerName);
    printf("Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n\n", (float)player1.totalScore / 12);

    printf("Player: %s\n", player2.playerName);
    printf("Scores: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", (float)player2.totalScore / 12);
}
