#ifndef IA_H
#define IA_H

#define PROF 4
#include "jeux.h"

/* Joue de manière aléatoire */
void ia_aleatoire(plateau p);

/* Crée une arbre des coups possibles et de leurs valeurs (profondeur 1)*/
arbre ia_niveau1(plateau p, int *prof);

/* Joue le meilleur coup possible en fonction des données de l'arbre a */
void coup_ordinateur(arbre a, plateau p);

int valeur_arbre(arbre a, int prof);
#endif
