#include <stdio.h>
#include <stdlib.h>

int main() {
    int over = 0;
    int turn = 1;
    int round = 1;
    int matches = 30;

    printf("\n");

    while (!over) {
        printf("--- Round %d ---\n", round);

        if (turn) {
            printf("A vous de jouer !\n\n");
            printf("Allumettes restantes : %d\n", matches);

            for (int i = 0; i < matches; i++) {
                printf("| ");
            }
            printf("\n\n");

            int take;

            do {
                printf("Combien d'allumettes voulez-vous retirer ?\n");
                scanf("%d", &take);

                if (take < 1 || take > 3) {
                    printf("Tu n'as le droit que de retirer 1, 2 ou 3 allumettes !\n");
                }
            } while (take < 1 || take > 3);

            printf("Vous retirez %d allumettes.\n\n", take);
            matches -= take;

            if (matches <= 0) {
                printf("Vous avez perdu contre le bot !\n");
                over = 1;
            }
            turn = 0;
        } else {
            printf("Au bot de jouer !\n\n");
            printf("Allumettes restantes : %d\n", matches);

            for (int i = 0; i < matches; i++) {
                printf("| ");
            }
            printf("\n\n");

            int take = rand() % 3 + 1;

            printf("Le bot retire %d allumettes.\n\n", take);
            matches -= take;

            if (matches <= 0) {
                printf("Vous avez gagne la partie !\n");
                over = 1;
            }
            turn = 1;
        }
        round++;
    }

    return 0;
}