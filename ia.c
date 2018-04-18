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

arbre ia_niveau1(plateau p)
{
    arbre a = creer_arbre_position(p);
    plateau tmp;
    int i,j,no_fils=0;

    /* On crée un plateau temporaire tmp pour ne pas modifier p */
    plateau_recopie(p,tmp);

    /* On crée un fils pour chaque coup possible */
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
	    if(coup_valide(tmp,i,j,BLANC))
	    {
		inserer_fils(a,no_fils,evaluation_plateau(tmp,i,j,BLANC));
		no_fils++;
	    }
	}
    /* Affiche les fils et leurs valeurs */
    /*for(i=0;i<no_fils;i++)
    {
	plateau_afficher(a->tab_fils[i]->position);
	printf("Valeur de la position: %d\n",a->tab_fils[i]->valeur_plateau);
	}*/
    return a;
}

void coup_ordinateur(arbre a, plateau p)
{
    int valeur_max = 0;
    int i;
    arbre tmp = arbre_vide();

    /* Parmis tous les fils de a, on choisit celui avec la plus grande valeur */
    /* L'arbre temporaire tmp prend la valeur du fils avec la plus grande valeur */
    
    for(i=0;i<a->nb_fils;i++)
	if(a->tab_fils[i]->valeur_plateau >= valeur_max)
	{
	    valeur_max = a->tab_fils[i]->valeur_plateau;
	    tmp = a->tab_fils[i];
	}

    /* On remplace p par le plateau rapportant le plus de points à l'IA */
    plateau_recopie(tmp->position,p);
    plateau_afficher(p);
}
    
#endif
