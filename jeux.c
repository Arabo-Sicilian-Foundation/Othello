#ifndef JEUX_C
#define JEUX_C

#include "jeux.h"

void jeux_init(plateau p)
{
    p[3][3] = BLANC;
    p[4][4] = BLANC;
    p[3][4] = NOIR;
    p[4][3] = NOIR;
    plateau_afficher(p);
}

int position_gagnante(plateau p, int couleur)
{
    int i,j;
    
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	    if(coup_valide(p,i,j,couleur))
		return 1;
    return 0;
}  
void capture(plateau p, int x, int y, int couleur)
{
    int i,j;

    if(p[x-1][y] != couleur)
	for(i=x-1;i>0;i--)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i-1][y] == couleur && p[i][y] != couleur)
	    {
		for(;i<=x;i++)
		    p[i][y] = couleur;
		break;
	    }
	}
    
    if(p[x+1][y] != couleur)
	for(i=x+1;i<8-1;i++)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i+1][y] == couleur && p[i][y] != couleur)
	    {
		for(;i>=x;i--)
		    p[i][y] = couleur;
		break;
	    }
	}
    
    if(p[x][y-1] != couleur)
	for(i=y-1;i>0;i--)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i-1] == couleur && p[x][i] != couleur)
	    {
		for(;i<=y;i++)
		    p[x][i] = couleur;
		break;
	    }
	}
    
    if(p[x][y+1] != couleur)
	for(i=y+1;i<8-1;i++)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i+1] == couleur && p[x][i] != couleur)
	    {
		for(;i>=y;i--)
		    p[x][i] = couleur;
		break;
	    }
	}
    
    if(p[x-1][y-1] != couleur)
	for(i=x-1,j=y-1;i>0 && j>0;i--,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j-1] == couleur && p[i][j] != couleur)
	    {
		for(;i<=x && j<=y;i++,j++)
		    p[i][j] = couleur;
		break;
	    }
	}
    
    if(p[x-1][y+1] != couleur)
	for(i=x-1,j=y+1;i>0 && j<8-1;i--,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j+1] == couleur && p[i][j] != couleur)
	    {
		for(;i<=x && j>=y;i++,j--)
		    p[i][j] = couleur;
		break;
	    }
	}
    
    if(p[x+1][y-1] != couleur)
	for(i=x+1,j=y-1;i<8-1 && j>0;i++,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j-1] == couleur && p[i][j] != couleur)
	    {
		for(;i>=x && j<=y;i--,j++)
		    p[i][j] = couleur;
		break;
	    }
	}
	
    if(p[x+1][y+1] != couleur)
	for(i=x+1,j=y+1;i<8-1 && j<8-1;i++,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j+1] == couleur && p[i][j] != couleur)
	    {
		for(;i>=x && j>=y;i--,j--)
		    p[i][j] = couleur;
		break;
	    }
	}
}

int coup_valide(plateau p, int x, int y, int couleur)
{
    int i,j;

    if(p[x][y] != VIDE)
	return 0;
    
    if(p[x-1][y] != couleur)
	for(i=x-1;i>0;i--)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i-1][y] == couleur && p[i][y] != couleur)
		return 1;
	}
    
    if(p[x+1][y] != couleur)
	for(i=x+1;i<8-1;i++)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i+1][y] == couleur && p[i][y] != couleur)
		return 1;
	}
    
    if(p[x][y-1] != couleur)
	for(i=y-1;i>0;i--)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i-1] == couleur && p[x][i] != couleur)
		return 1;
	}
    
    if(p[x][y+1] != couleur)
	for(i=y+1;i<8-1;i++)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i+1] == couleur && p[x][i] != couleur)
		return 1;
	}
    
    if(p[x-1][y-1] != couleur)
	for(i=x-1,j=y-1;i>0 && j>0;i--,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j-1] == couleur && p[i][j] != couleur)
		return 1;
	}
    
    if(p[x-1][y+1] != couleur)
	for(i=x-1,j=y+1;i>0 && j<8-1;i--,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j+1] == couleur && p[i][j] != couleur)
		return 1;
	}
    
    if(p[x+1][y-1] != couleur)
	for(i=x+1,j=y-1;i<8-1 && j>0;i++,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j-1] == couleur && p[i][j] != couleur)
		return 1;

	}
	
    if(p[x+1][y+1] != couleur)
	for(i=x+1,j=y+1;i<8-1 && j<8-1;i++,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j+1] == couleur && p[i][j] != couleur)
		return 1;
	}
    return 0;
}

void gagnant(plateau p)
{
    int pt_blanc = 0;
    int pt_noir = 0;
    int i,j;

    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
	    if(p[i][j] == NOIR)
		pt_noir++;
	    if(p[i][j] == BLANC)
		pt_blanc++;
	}
    fprintf(stdout,"Pions blancs : %d\n",pt_blanc);
    fprintf(stdout,"Pions noirs : %d\n",pt_noir);
    if(pt_noir > pt_blanc)
	fprintf(stdout,"Les pions noirs remportent la partie !\n");
    if(pt_noir < pt_blanc)
	fprintf(stdout,"Les pions blancs remportent la partie !\n");
    if(pt_noir == pt_blanc)
	fprintf(stdout,"Égalité !\n");
}

	
#endif
