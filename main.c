#ifndef MAIN_C
#define MAIN_C

#include "ia.h"
#include <MLV/MLV_all.h>


/*Vide l'entrée standard stdin*/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int main()
{
	MLV_create_window("Reversi","Reversi",400,400);

    plateau p;
    int x = 0;
    int y = 0;
    int couleur;
    arbre a = arbre_vide();
    int pf = 0;
    int *prof = &pf;
    /*Crée un plateau et l'initialise à la configuration de base*/
    plateau_init(p);
    jeux_init(p);

    couleur = NOIR;

    /*Tant qu'au moins un des joueurs peut jouer*/
    while(position_gagnante(p,NOIR) || position_gagnante(p,BLANC))
    {
		/*Si les pions ont des positions valident*/
		if(position_gagnante(p,NOIR))
		{
		    /*Le tour continue jusqu'à une position valide*/
		    while(couleur == NOIR)
		    {
				printf("\nNOIR\n");

				while(!coup_valide(p,x,y,NOIR))
				{
					MLV_wait_mouse(&y, &x);
					x = x / 50;
					y = y / 50;
					printf("%d %d\n",x,y);
				}
				/*Si le coup est valide, on capture les pions et c'est au joueur suivant de jouer*/
			    capture(p,x,y,NOIR);
			    plateau_afficher(p);
			    couleur = BLANC;
	    	}
		MLV_actualise_window();
	}
	else
	    couleur = BLANC;

	if(position_gagnante(p,BLANC))
	{
	    printf("\nBLANC\n");
	    a = ia_arbre(p,prof);
		*prof = 0;
	    coup_ordinateur(a,p);
	    free(a);
	    plateau_afficher(p);
	    couleur = NOIR;
		MLV_actualise_window();
	}
	else
	    couleur = NOIR;
    }
    gagnant(p);

	MLV_free_window();
    exit(0);
}

#endif
