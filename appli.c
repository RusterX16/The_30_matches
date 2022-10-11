//
// Created by seb on 11/10/22.
//

#include <stdio.h>
#include <stdlib.h>



void jeu_joueur();
void jeu_ordi(int remake);
void jeuOrdiFacile();
void jeuOrdiMoyen();
void jeuOrdiDifficile();
void regles();
void menu(int remake);
//
void displayMatches(int matches);
int chooseAmount();
int generateTake();
void breakLine();

const int NOMBRE_ALLUMETTES = 30;



int main() {

    printf("\n\t######################\n\t# Jeu des allumettes #\n\t######################\n");

    menu(0);

    return 0;
}



////////////////////////////////////////////////////

void jeu_joueur() {
    // over est un boolean qui représente l'état du jeu (1: en cours, 0: terminé)
    int over = 0;
    // turn est un boolean qui représente le tour du joueur (1: joueur, 0: ordinateur)
    int turn = 1;
    // round est un entier qui représente le numéro du tour
    int round = 1;
    // matches est un entier qui représente le nombre d'allumettes restantes
    int matches = NOMBRE_ALLUMETTES;

    printf("\n");

    // Tant que le jeu n'est pas terminé
    while (!over) {
        printf("--- Round %d ---\n", round);

        // Si c'est le tour du joueur
        if (turn) {
            // On affiche le nombre d'allumettes restantes
            printf("Joueur %d à vous de jouer !", (turn == 1) ? 1 : 2);
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            // On demande au joueur de choisir le nombre d'allumettes qu'il veut retirer
            int take = chooseAmount();

            printf("Joueur %d vous retirez %d allumettes.", (turn == 1) ? 1 : 2, take);
            breakLine();

            // On retire le nombre d'allumettes choisi par le joueur
            matches -= take;

            // Si le nombre d'allumettes est inférieur ou égal à 0, le joueur perds la partie
            if (matches <= 0) {
                printf("Joueur %d vous avez perdu la partie !\n", (turn == 1) ? 1 : 2);
                // On met le jeu en état terminé
                over = 1;
            } else {
                // Sinon On passe le tour à l'autre joueur
                turn = 0;
            }
        } else {
            // On affiche le nombre d'allumettes restantes
            printf("Joueur %d vous de jouer !", (turn == 1) ? 1 : 2);
            breakLine();
            printf("Allumettes restantes : %d\n", matches);

            displayMatches(matches);
            breakLine();

            // On demande au joueur de choisir le nombre d'allumettes qu'il veut retirer
            int take = chooseAmount();

            printf("Joueur %d vous retirez %d allumettes.", (turn == 1) ? 1 : 2, take);
            breakLine();

            // On retire le nombre d'allumettes choisi par le joueur
            matches -= take;

            // Si le nombre d'allumettes est inférieur ou égal à 0, le joueur perds la partie
            if (matches <= 0) {
                printf("Joueur %d avez perdu la partie !\n", (turn == 1) ? 1 : 2);
                // On met le jeu en état terminé
                over = 1;
            } else {
                // Sinon On passe le tour à l'autre joueur
                turn = 1;
            }
        }
        // On incrémente le numéro du tour
        round++;
    }
    menu(0);
    return;
}

void jeu_ordi(int remake) {
    int choix;

    if(remake == 0) {
        printf("-----------------------------");
        printf("\nVous venez de choisir Jouer contre l'ordinateur.\n\nVous disposez de plusieurs mode:\n\t1 - Facile\n\t2 - Moyen\n\t3 - Difficile\n\t4 - Menu\n");
        printf("\nVotre choix: ");
    } else {
        printf("\nVotre choix (1, 2 ou 3 ): ");
    }
    scanf("%d", &choix);

    if(choix == 1) {
        jeuOrdiFacile();
        return;
    } else if(choix == 2) {
        jeuOrdiMoyen();
        return;
    } else if(choix == 3) {
        jeuOrdiDifficile();
        return;
    } else if(choix == 4) {
        printf("-----------------------------");
        menu(0);
        return;
    } else {
        jeu_ordi(1);
    }
}

void jeuOrdiFacile() {
    // over est un boolean qui représente l'état du jeu (1: en cours, 0: terminé)
    int over = 0;
    // turn est un boolean qui représente le tour du joueur (1: joueur, 0: ordinateur)
    int turn = 1;
    // round est un entier qui représente le numéro du tour
    int round = 1;
    // matches est un entier qui représente le nombre d'allumettes restantes
    int matches = NOMBRE_ALLUMETTES;

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
            int take = 3;

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
    menu(0);
    return;
}

void jeuOrdiMoyen() {
    // over est un boolean qui représente l'état du jeu (1: en cours, 0: terminé)
    int over = 0;
    // turn est un boolean qui représente le tour du joueur (1: joueur, 0: ordinateur)
    int turn = 1;
    // round est un entier qui représente le numéro du tour
    int round = 1;
    // matches est un entier qui représente le nombre d'allumettes restantes
    int matches = NOMBRE_ALLUMETTES;

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
    menu(0);
    return;
}

void jeuOrdiDifficile() {

}

void regles() {
    printf("\n-----------------------------\n");
    printf("\nLorsque vous lancerez la partie, vous verrez %d allumettes.\nA tour de rôle vous pourrez retirer 1, 2 ou 3 allumette(s) du tas.\nCe qui réduisa ce tas.\nCelui d'entre vous deux qui retire la dernière allumette du tas PERD!\n\nVous disposez de 2 modes:\n- un mode joueur contre joueur\n- un mode jouer contre l'ordinateur.\n\nVous pourrez choisir le niveau de difficulté de l'ordinateur une fois que vous aurez cliqué sur \"Jouer contre l'ordinateur\"\n", NOMBRE_ALLUMETTES);
    printf("\n-----------------------------\n");
    printf("Reprenez votre choix du menu (1, 2, 3 ou 4)");
    menu(1);
}

void menu(int remake) {
    int choix;

    if(remake == 0) {
        printf("\nBienvenue au menu de notre jeu, vous pouvez:\n\n\t1 - Jouer joueur contre joueur\n\t2 - Joueur contre l'ordinateur\n\t3 - Consulter les règles du jeu\n\t4 - Quitter le jeu\n");
        printf("\nVotre choix: ");
    } else {
        printf("\nVotre choix (1 or 2 or 3 or 4): ");
    }
    scanf("%d", &choix);

    if(choix == 1) {
        jeu_joueur();
        return;
    } else if(choix == 2) {
        jeu_ordi(0);
        return;
    } else if(choix == 3) {
        regles();
        return;
    } else if(choix == 4) {
        return;
    }
    menu(1);
}




////
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
