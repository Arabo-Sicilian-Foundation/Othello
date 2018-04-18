#ifndef ARBRE_H
#define ARBRE_H

#include "plateau.h"

typedef struct noeud
{
    plateau position;
    int nb_fils;
    struct noeud **tab_fils;
} noeud;

typedef noeud *arbre;

/*Créer un arbre des posibilités de placement avec le plateau actuel en racine*/ 
arbre creer_arbre_position(plateau p);

/*Insère une posibilité comme fils numéro no_fils de a */
void inserer_fils(arbre a,int no_fils,arbre fils);

arbre arbre_vide();

int est_arbre_vide(arbre a);
#endif
