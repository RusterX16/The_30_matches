#include <stdio.h>
#include <stdlib.h>

void displayMatches(int matches);
void breakLine();
int chooseAmount();
int generateTake();
int checkOver(int matches, int turn);

int main() {
    int over = 0;
    int turn = 1;
    int round = 1;
    int matches = 30;

    printf("\n");

    while (!over) {
        printf("--- Round %d ---\n", round);

        if (turn) {
            printf("A vous de jouer !");
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            int take = chooseAmount();

            printf("Vous retirez %d allumettes.", take);
            breakLine();

            matches -= take;
            over = checkOver(matches, take);
            turn = 0;
        } else {
            printf("Au bot de jouer !");
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            int take = generateTake();

            printf("Le bot retire %d allumettes.", take);
            breakLine();

            matches -= take;
            over = checkOver(matches, take);
            turn = 1;
        }
        round++;
    }
    return 0;
}

void displayMatches(int matches) {
    for (int i = 0; i < matches; i++) {
        printf("| ");
    }
    for (int i = 0; i < 30 - matches; i++) {
        printf(". ");
    }
}

void breakLine() {
    printf("\n\n");
}

int chooseAmount() {
    int take;

    do {
        printf("Combien d'allumettes voulez-vous retirer ?\n");
        scanf("%d", &take);

        if (take < 1 || take > 3) {
            printf("Tu n'as le droit que de retirer 1, 2 ou 3 allumettes !\n");
        }
    } while (take < 1 || take > 3);

    return take;
}

int generateTake() {
    return rand() % 3 + 1;
}

int checkOver(int matches, int turn) {
    if (matches <= 0) {
        if (turn) {
            printf("Vous avez gagne !\n");
        } else {
            printf("Vous avez perdu !\n");
        }
        return 1;
    }
    return 0;
}