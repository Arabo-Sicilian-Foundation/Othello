#ifndef ARBRE_C
#define ARBRE_C

#include "arbre.h"

arbre creer_arbre_position(plateau p)
{
    int i,j;
    arbre a = (arbre)malloc(sizeof(noeud));

    /*On copie p dans l'abre*/
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	    a->position[i][j] = p[i][j];
    a->nb_fils = 0;
    a->valeur_plateau = 0;
    a->tab_fils = NULL;

    return a;
}

void inserer_fils(arbre a,int no_fils,arbre fils)
{
    a->nb_fils++;
    a->tab_fils = (arbre *)realloc(a->tab_fils,a->nb_fils*sizeof(arbre));
    a->tab_fils[no_fils] = fils;
}

arbre arbre_vide()
{
    return NULL;
}

int est_arbre_vide(arbre a)
{
    return (a == NULL);
}

#endif
