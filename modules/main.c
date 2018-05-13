#ifndef MAIN_C
#define MAIN_C

#include "ia.h"
#include <MLV/MLV_all.h>
#include <unistd.h> /* Pour la gestion des options en arguments */

/*Vide l'entrée standard stdin*/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int main(int argc, char *argv[])
{
    MLV_create_window("Reversi","Reversi",400,400);

    int option, niveau = -1;
    plateau p;
    int x = 0;
    int y = 0;
    int couleur;
    arbre a = arbre_vide();
    int pf = 0;
    int *prof = &pf;
    int prof_global = -1;
    
    while((option = getopt(argc, argv, "n:p:")) != -1)
    {
	switch(option)
	{
	case 'n':
	    niveau = atoi(optarg);
	    break;
	case 'p':
	    if(atoi(optarg) > 0)
		prof_global = atoi(optarg);
	    else
	    {
		fprintf(stderr,"profondeur invalide\n");
		exit(-1);
	    }
	    break;
	}
    }

    if(niveau < 0 || niveau > 3)
    {
	fprintf(stderr,"Entrez un niveau entre 0 et 3 avec l'option -n\n");
	exit(-1);
    }

    /* Par défaut, la profondeur est de 5 pour les niveaux 2 et 3 et de 2 pour le niveau 1 */
    
    /* Si l'utilisateur a entré une profondeur, on la modifie dans le fichier ia.c */
    if(prof_global != -1)
	modifier_prof(prof_global);
    
    /* L'ia de niveau 1 utilise toujours une profondeur de 2 */
    if(niveau == 1)
	modifier_prof(2);
    
    /* Crée un plateau et l'initialise à la configuration de base*/
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
	    if(niveau == 0)
		ia_aleatoire(p);
	    else
	    {
		a = ia_arbre(p,prof);
		*prof = 0;
		coup_ordinateur(a,p,niveau);
		free(a);
	    }
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
