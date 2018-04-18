#ifndef MAIN_C
#define MAIN_C

#include "ia.h"

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
    plateau p;
    int x;
    char y = 1;
    int couleur;
    int points;
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
		scanf("%c %d",&y,&x);
		/*Si le coup est valide, on capture les pions et c'est au joueur suivant de jouer*/
		if(coup_valide(p,x-1,y-97,NOIR))
		{
		    points = capture(p,x-1,y-97,NOIR);
		    printf("%d\n",points);
		    plateau_afficher(p);
		    couleur = BLANC;
		}
		/*Sinon le joueur choisit une autre position*/
		else
		{
		    viderBuffer();
		    fprintf(stdout,"Coup invalide\n");
		}
	    }
	    viderBuffer();
	}
	else
	    couleur = BLANC;

	if(position_gagnante(p,BLANC))
	{
	    printf("\nBLANC\n");
	    a = ia_niveau1(p,prof);
	    coup_ordinateur(a,p);
	    free(a);
	    plateau_afficher(p);
	    couleur = NOIR;
	}
	else
	    couleur = NOIR;
    }
    gagnant(p);

    exit(0);
}

#endif
