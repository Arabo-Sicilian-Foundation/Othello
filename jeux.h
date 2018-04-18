#ifndef JEUX_H
#define JEUX_H

#include "arbre.h"

/*Crée un plateau avec seulement les 4 pions initiaux*/
void jeux_init(plateau p);

/*Vérifie qu'il existe une position valide pour la couleur donnée*/
int position_gagnante(plateau p, int couleur);

/*Capture les pions de la couleur opposée*/
int capture(plateau p, int x, int y, int couleur);

/*Vérifie que le coup à la position (x,y) est valide*/
int coup_valide(plateau p, int x, int y, int couleur);

/*Calcule les points et donne le vainqueur à la fin de la partie*/
void gagnant(plateau p);

#endif
