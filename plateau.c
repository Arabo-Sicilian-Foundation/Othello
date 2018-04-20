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

/* Les coins et les bords sont des emplacements avantageux, placer un pion dans un angle ou sur un bord est plus intéressant */

int est_coin_plateau(int x, int y)
{
    /* Coin haut gauche */
    if(x == 0 && y == 0)
	return 1;
    /* Coin haut droite */
    if(x == 0 && y == 7)
	return 1;
    /* Coin bas gauche */
    if(x == 7 && y == 0)
	return 1;
    /* Coin bas droite */
    if(x == 7 && y == 7)
	return 1;

    return 0;
}

int est_bord_plateau(int x, int y)
{
    /* Bord supérieur */
    if(x == 0 && y >= 1 && y <= 7)
	return 1;
    /* Bord inférieur */
    if(x == 7 && y >= 1 && y <= 7)
	return 1;
    /* Bord gauche */
    if(y == 0 && x >= 1 && y <= 7)
	return 1;
    /* Bord droite */
    if(y == 7 && x >= 1 && y <= 7)
	return 1;

    return 0;
}


#endif
