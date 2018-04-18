#ifndef IA_C
#define IA_C

#include "ia.h"
#include <time.h>

void ia_aleatoire(plateau p)
{
    int x = rand() % 8;
    int y = rand() % 8;

    /* On retente un coup aléatoire tant qu'il n'est pas valide */
    while(!coup_valide(p,x,y,BLANC))
    {
	x = rand() % 8;
	y = rand() % 8;
    }

    /* puis on capture les pions une fois qu'on est bon */
    capture(p,x,y,BLANC);
}

arbre ia_niveau1(plateau p, int *prof)
{
    arbre a = arbre_vide();
    plateau tmp;
    int i,j,no_fils=0;
    int couleur;
    
    a = creer_arbre_position(p);

    if(*prof <= PROF)
    {
	/* On crée un plateau temporaire tmp pour ne pas modifier p */
	plateau_recopie(p,tmp);

	/* On change la couleur selon si c'est le tour de l'ia ou du joueur */
	if(*prof % 2 == 0)
	    couleur = BLANC;
	else
	    couleur = NOIR;
    
	/* On crée un fils pour chaque coup possible */
	for(i=0;i<8;i++)
	    for(j=0;j<8;j++)
	    {
		if(coup_valide(tmp,i,j,couleur))
		{
		    inserer_fils(a,no_fils,evaluation_plateau(tmp,i,j,couleur,prof));
		    /* On redescend d'un niveau quand toutes les possibilités ont été exploré */
		    *prof -= 1;
		    no_fils++;
		}
	    }
	/* Affiche les fils et leurs valeurs */
	/*for(i=0;i<a->nb_fils;i++)
	{
	    plateau_afficher(a->tab_fils[i]->position);
	    printf("Valeur de la position: %d\n\n",a->tab_fils[i]->valeur_plateau);
	    }*/
    }
    return a;
}

int valeur_arbre(arbre a, int prof)
{
    int valeur_max = 0;
    int valeur_min = 100;
    int i;

    /* Si on pas aux feuilles, on avance dans l'arbre */
    /* On calcule ainsi toutes les valeurs des noeuds en prenant la valeur maximale ou minimale de fils de chaque noeud */
    if(prof <= PROF)
    {
	for(i=0;i<a->nb_fils;i++)
	{
	    a->tab_fils[i]->valeur_plateau = valeur_arbre(a->tab_fils[i],prof+1);
	}
    }

    for(i=0;i<a->nb_fils;i++)
    {
	/* Si la profondeur est impaire, c'est au tour du joueur humain, on choisit donc la solution qui minimise ses gains */
	if(prof % 2 != 0)
	{
	    if(a->tab_fils[i]->valeur_plateau <= valeur_min)
	    {
		valeur_min = a->tab_fils[i]->valeur_plateau;
	    }  
	}
	/* Si la profondeur est impaire, c'est au tour de l'IA, on choisit donc la solution qui maximise ses gains */
	if(prof % 2 == 0)
	{
	    if(a->tab_fils[i]->valeur_plateau >= valeur_max)
	    {
		valeur_max = a->tab_fils[i]->valeur_plateau;
	    }
	}
    }
  
    if(prof % 2 != 0)
	return valeur_min;
    else
	return valeur_max;

}

void coup_ordinateur(arbre a, plateau p)
{
    int prof = 0;
    int i;

    a->valeur_plateau = valeur_arbre(a,prof);

    /* On choisi le coup rapportant le plus de points parmis tous les coups possibles */
    for(i=0;i<a->nb_fils;i++)
    {
	if(a->valeur_plateau <= a->tab_fils[i]->valeur_plateau)
	{
	    plateau_recopie(a->tab_fils[i]->position,p);
	}
    }
}

    
#endif
