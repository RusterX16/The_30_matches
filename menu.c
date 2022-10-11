#include <stdio.h>

void jeu_joueur();
void jeu_ordi(int remake);
void regles();
void menu(int remake);



int main() {
   const int NOMBRE_ALLUMETTES = 30;

   int joueurActuel = 1;


   printf("\n\t######################\n\t# Jeu des allumettes #\n\t######################\n");

   menu(0);

   return 0;
}



////////////////////////////////////////////////////

void jeu_joueur() {
   return;
}

void jeu_ordi(int remake) {
   int choix;

   if(remake == 0) {
      printf("-----------------------------");
      printf("\nVous venez de choisir Jouer contre l'ordinateur.\n\nVous disposez de plusieurs mode:\n\t1 - Facile\n\t2 - Moyen\n\t3 - Difficile\n\t4 - Menu\n");
      printf("\nVotre choix: ");
   } else {
      printf("\nVotre choix (1 or 2 or 3 ): ");
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
      printf("-----------------------------");
      menu(0);
      return;
   } else {
      jeu_ordi(1);
   }
}

void regles() {
   printf("\nLorsque vous lancerez la partie, vous verrez 30 allumettes.\nA tour de rôle vous pourrez retirer 1, 2 ou 3 allumette(s) du tas.\nCe qui réduisa ce tas.\nCelui d'entre vous deux qui retire la dernière allumette du tas PERD!\n\nVous disposez de 2 modes:\n- un mode joueur contre joueur\n- un mode jouer contre l'ordinateur.\n\nVous pourrez choisir le niveau de difficulté de l'ordinateur une fois que vous aurez cliqué sur \"Jouer contre l'ordinateur\"");
   return;
}

void menu(int remake) {
   int choix;

   if(remake == 0) {
      printf("\nBienvenue au menu de notre jeu, vous pouvez:\n\n\t1 - Jouer joueur contre joueur\n\t2 - Joueur contre l'ordinateur\n\t3 - Consulter les règles du jeu\n\t3 - Quitter le jeu\n");
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
