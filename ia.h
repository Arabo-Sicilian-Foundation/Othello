#ifndef IA_H
#define IA_H

#include "jeux.h"

/* Renvoie 1 si l'ia a pu jouer et 0 sinon */
void ia_aleatoire(plateau p);

/* Crée une arbre des coups possibles et de leurs valeurs (profondeur 1)*/
arbre ia_niveau1(plateau p);

/* Joue le meilleur coup possible en fonction des données de l'arbre a */
void coup_ordinateur(arbre a, plateau p);
#endif
