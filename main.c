#include <stdio.h>
#include <stdlib.h>

void displayMatches(int matches);

int chooseAmount();

int generateTake();

void breakLine();

int main() {
    // over est un boolean qui représente l'état du jeu (1: en cours, 0: terminé)
    int over = 0;
    // turn est un boolean qui représente le tour du joueur (1: joueur, 0: ordinateur)
    int turn = 1;
    // round est un entier qui représente le numéro du tour
    int round = 1;
    // matches est un entier qui représente le nombre d'allumettes restantes
    int matches = 30;

    printf("\n");

    // Tant que le jeu n'est pas terminé
    while (!over) {
        printf("--- Round %d ---\n", round);

        // Si c'est le tour du joueur
        if (turn) {
            // On affiche le nombre d'allumettes restantes
            printf("A vous de jouer !");
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            // On demande au joueur de choisir le nombre d'allumettes qu'il veut retirer
            int take = chooseAmount();

            printf("Vous retirez %d allumettes.", take);
            breakLine();

            // On retire le nombre d'allumettes choisi par le joueur
            matches -= take;

            // Si le nombre d'allumettes est inférieur ou égal à 0, le joueur perds la partie
            if (matches <= 0) {
                printf("Vous avez perdu la partie !\n");
                // On met le jeu en état terminé
                over = 1;
            } else {
                // Sinon On passe le tour à l'ordinateur
                turn = 0;
            }
        } else {
            // Si c'est le tour de l'ordinateur
            printf("A l'ordinateur de jouer !");
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            // On génère un nombre aléatoire entre 1 et 3 pour l'ordinateur
            int take = generateTake();

            printf("Le bot retire %d allumettes.", take);
            breakLine();

            // On retire le nombre d'allumettes choisi par l'ordinateur
            matches -= take;

            // Si le nombre d'allumettes est inférieur ou égal à 0, l'ordinateur perds la partie
            if (matches <= 0) {
                printf("Vous avez gagne la partie !\n");
                // On met le jeu en état terminé
                over = 1;
            }
                // Sinon on passe le tour au joueur
            else {
                turn = 1;
            }
        }
        // On incrémente le numéro du tour
        round++;
    }
    return 0;
}

void displayMatches(int matches) {
    // On affiche le nombre d'allumettes restantes par des pipes
    for (int i = 0; i < matches; i++) {
        printf("| ");
    }
    // On affiche les allumettes déjà prises par des points
    for (int i = 0; i < 30 - matches; i++) {
        printf(". ");
    }
}

void breakLine() {
    // Un double retour à la ligne pour plus de visibilité
    printf("\n\n");
}

int chooseAmount() {
    // On déclare une variable correspondant au nombre d'allumettes que le joueur veut retirer
    int take;

    // Tant que le nombre d'allumettes n'est pas compris entre 1 et 3
    do {
        // On demande au joueur de choisir le nombre d'allumettes qu'il veut retirer
        printf("Combien d'allumettes voulez-vous retirer ?\n");
        scanf("%d", &take);

        // Si le nombre d'allumettes est inférieur à 1 ou supérieur à 3,
        // on affiche un message d'erreur demandant au joueur de choisir un nombre entre 1 et 3
        if (take < 1 || take > 3) {
            printf("Tu n'as le droit que de retirer 1, 2 ou 3 allumettes !\n");
        }
    } while (take < 1 || take > 3);

    return take;
}

int generateTake() {
    // On génère un nombre aléatoire entre 1 et 3
    return rand() % 3 + 1;
}