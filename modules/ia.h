#ifndef IA_H
#define IA_H

#define PROF 5
#include "jeux.h"

/* Modifie la profondeur globale si l'utilisateur a utilisé l'option -p */
void modifier_prof(int prof);

/* Joue de manière aléatoire */
void ia_aleatoire(plateau p);

/* Crée une arbre des coups possibles et de leurs valeurs */
arbre ia_arbre(plateau p, int *prof);

/* Joue le meilleur coup possible en fonction des données de l'arbre a */
void coup_ordinateur(arbre a, plateau p, int niveau);

int valeur_arbre(arbre a, int prof);

/* minimax avec l'algorithme alpha-beta	 */
/* source :
http://lig-membres.imag.fr/pernet/Enseignements/L3METI_ProgOO/MinMaxAlphaBeta.pdf */
int alphabeta(arbre a, int prof, int alpha, int beta);

#endif
