#ifndef PLATEAU_C
#define PLATEAU_C

#include "plateau.h"

void plateau_init(plateau p)
{
    int i,j;
    
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	    p[i][j] = VIDE;
}

void plateau_afficher(plateau p)
{
    int i,j;

    fprintf(stdout,"   ---------------- \n");
    for(i=0;i<8;i++)
    {
	fprintf(stdout,"%d |",i+1);
	for(j=0;j<8;j++)
	{
	    if(p[i][j] == VIDE)
		fprintf(stdout," .");
	    if(p[i][j] == NOIR)
		fprintf(stdout," N");
	    if(p[i][j] == BLANC)
		fprintf(stdout," B");
	}
	fprintf(stdout,"|\n");
    }
    fprintf(stdout,"   ---------------- \n");
    fprintf(stdout,"    A B C D E F G H \n");
}

void plateau_recopie(plateau p, plateau cp)
{
    int i,j;

    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	    cp[i][j] = p[i][j];
}

#endif
