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
#endif
