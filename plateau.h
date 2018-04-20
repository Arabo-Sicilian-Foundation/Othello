#ifndef PLATEAU_H
#define PLATEAU_H
#define VIDE 2
#define NOIR 1
#define BLANC 0

#include <stdio.h>
#include <stdlib.h>

typedef int plateau[8][8];

/*Crée un plateau totalement vide*/
void plateau_init(plateau p);

/*Affiche l'état actuel du plateau*/
void plateau_afficher(plateau p);

/*Recopie le plateau p dans cp*/
void plateau_recopie(plateau p, plateau cp);

/* Les coins et les bords sont des emplacements avantageux, on test si le pion placé est sur un bord ou dans un coin pour adapter l'évaluation des points */
int est_coin_plateau(int x, int y);
  
int est_bord_plateau(int x, int y);
#endif
