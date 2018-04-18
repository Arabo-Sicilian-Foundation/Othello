#ifndef MAIN_C
#define MAIN_C

#include "jeux.h"

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

    plateau_init(p);
    jeux_init(p);
    
    couleur = NOIR;
    while(position_gagnante(p,NOIR) || position_gagnante(p,BLANC))
    {
	if(position_gagnante(p,NOIR))
	    while(couleur == NOIR)
	    {
		printf("\nNOIR\n");
		scanf("%c %d",&y,&x);
		if(coup_valide(p,x-1,y-97,NOIR))
		{
		    capture(p,x-1,y-97,NOIR);
		    plateau_afficher(p);
		    couleur = BLANC;
		}
		else
		{
		    viderBuffer();
		    fprintf(stdout,"Coup invalide\n");
		}
	    }
	viderBuffer();
	if(position_gagnante(p,BLANC))
	    while(couleur == BLANC)
	    {
		printf("\nBLANC\n");
		scanf("%c %d",&y,&x);
		if(coup_valide(p,x-1,y-97,BLANC))
		{
		    capture(p,x-1,y-97,BLANC);
		    plateau_afficher(p);
		    couleur = NOIR;
		}
		else
		{
		    viderBuffer();
		    fprintf(stdout,"Coup invalide\n");
		}
	    }
	viderBuffer();
    }
    gagnant(p);
    
    exit(0);
}

#endif
