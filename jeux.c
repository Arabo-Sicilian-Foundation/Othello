#ifndef JEUX_C
#define JEUX_C

#include "jeux.h"

void jeux_init(plateau p)
{
    /*Crée la configuration de base du jeux et l'affiche*/
    p[3][3] = BLANC;
    p[4][4] = BLANC;
    p[3][4] = NOIR;
    p[4][3] = NOIR;
    plateau_afficher(p);
}

int position_gagnante(plateau p, int couleur)
{
    int i,j;

    /*Pour chaque case du plateau, on vérifie si la position est valide*/
    /*On arrête dès qu'on en trouve une*/
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	    if(coup_valide(p,i,j,couleur))
		return 1;
    return 0;
}
int capture(plateau p, int x, int y, int couleur)
{
    int i,j;
    int points = 1;

    /*Ajoute le pion à la position choisi*/
    p[x][y] = couleur;

    /*Dans chaque cas, on parcours jusqu'à trouver un pion de la même couleur encadrant une suite de pions de l'autre couleur et on capture les pions encadrés*/

/*Quand cela est possible, on capture les pions : */
    /*au-dessus*/
    if(p[x-1][y] != couleur)
	for(i=x-1;i>0;i--)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i-1][y] == couleur && p[i][y] != couleur)
	    {
		for(;i<x;i++)
		{
		    p[i][y] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*au-dessous*/
    if(p[x+1][y] != couleur)
	for(i=x+1;i<8-1;i++)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i+1][y] == couleur && p[i][y] != couleur)
	    {
		for(;i>x;i--)
		{
		    p[i][y] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*à gauche*/
    if(p[x][y-1] != couleur)
	for(i=y-1;i>0;i--)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i-1] == couleur && p[x][i] != couleur)
	    {
		for(;i<y;i++)
		{
		    p[x][i] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*à droite*/
    if(p[x][y+1] != couleur)
	for(i=y+1;i<8-1;i++)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i+1] == couleur && p[x][i] != couleur)
	    {
		for(;i>y;i--)
		{
		    p[x][i] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*sur la diagonale supérieure gauche*/
    if(p[x-1][y-1] != couleur)
	for(i=x-1,j=y-1;i>0 && j>0;i--,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j-1] == couleur && p[i][j] != couleur)
	    {
		for(;i<x && j<y;i++,j++)
		{
		    p[i][j] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*sur la diagonale supérieure droite*/
    if(p[x-1][y+1] != couleur)
	for(i=x-1,j=y+1;i>0 && j<8-1;i--,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j+1] == couleur && p[i][j] != couleur)
	    {
		for(;i<x && j>y;i++,j--)
		{
		    p[i][j] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*sur la diagonale inférieure gauche*/
    if(p[x+1][y-1] != couleur)
	for(i=x+1,j=y-1;i<8-1 && j>0;i++,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j-1] == couleur && p[i][j] != couleur)
	    {
		for(;i>x && j<y;i--,j++)
		{
		    p[i][j] = couleur;
		    points++;
		}
		break;
	    }
	}

    /*sur la diagonale inférieure droite*/
    if(p[x+1][y+1] != couleur)
	for(i=x+1,j=y+1;i<8-1 && j<8-1;i++,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j+1] == couleur && p[i][j] != couleur)
	    {
		for(;i>x && j>y;i--,j--)
		{
		    p[i][j] = couleur;
		    points++;
		}
		break;
	    }
	}
    return points;
}

int coup_valide(plateau p, int x, int y, int couleur)
{
    int i,j;

    /*Si la case est déjà occupé, le coup n'est pas valide*/
    if(p[x][y] != VIDE)
	return 0;

    /*On vérifie qu'il existe au moins une ligne, une colonne ou une diagonale telle le pion placé et un autre pion de la même couleur encadrent une suite d'au moins 1 pion de l'autre couleur, sans case vide au milieu*/

    /*On vérifie si cela est possible : */

    /*au-dessus*/
    if(p[x-1][y] != couleur)
	for(i=x-1;i>0;i--)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i-1][y] == couleur && p[i][y] != couleur)
		return 1;
	}

    /*au-dessous*/
    if(p[x+1][y] != couleur)
	for(i=x+1;i<8-1;i++)
	{
	    if(p[i][y] == VIDE)
		break;
	    if(p[i+1][y] == couleur && p[i][y] != couleur)
		return 1;
	}

    /*à gauche*/
    if(p[x][y-1] != couleur)
	for(i=y-1;i>0;i--)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i-1] == couleur && p[x][i] != couleur)
		return 1;
	}

    /*à droite*/
    if(p[x][y+1] != couleur)
	for(i=y+1;i<8-1;i++)
	{
	    if(p[x][i] == VIDE)
		break;
	    if(p[x][i+1] == couleur && p[x][i] != couleur)
		return 1;
	}

    /*sur la diagonale supérieure gauche*/
    if(p[x-1][y-1] != couleur)
	for(i=x-1,j=y-1;i>0 && j>0;i--,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j-1] == couleur && p[i][j] != couleur)
		return 1;
	}

    /*sur la diagonale supérieure droite*/
    if(p[x-1][y+1] != couleur)
	for(i=x-1,j=y+1;i>0 && j<8-1;i--,j++)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i-1][j+1] == couleur && p[i][j] != couleur)
		return 1;
	}

    /*sur la diagonale inférieure gauche*/
    if(p[x+1][y-1] != couleur)
	for(i=x+1,j=y-1;i<8-1 && j>0;i++,j--)
	{
	    if(p[i][j] == VIDE)
		break;
	    if(p[i+1][j-1] == couleur && p[i][j] != couleur)
		return 1;

	}

    /*sur la diagonale inférieure droite*/
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

    /*Calcule les points pour les deux couleurs*/
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
	    if(p[i][j] == NOIR)
		pt_noir++;
	    if(p[i][j] == BLANC)
		pt_blanc++;
	}

    /*Affiche les points*/
    fprintf(stdout,"Pions blancs : %d\n",pt_blanc);
    fprintf(stdout,"Pions noirs : %d\n",pt_noir);

    /*Annonce le vainqueur*/
    if(pt_noir > pt_blanc)
	fprintf(stdout,"Les pions noirs remportent la partie !\n");
    if(pt_noir < pt_blanc)
	fprintf(stdout,"Les pions blancs remportent la partie !\n");
    if(pt_noir == pt_blanc)
	fprintf(stdout,"Égalité !\n");
}

arbre evaluation_plateau(plateau p, int x, int y, int couleur)
{
    arbre a = arbre_vide();
    plateau tmp;
    int point;

    /* On crée un plateau temporaire */
    plateau_recopie(p,tmp);

    /* On calcule les points que rapporte cette position */
    point = capture(tmp,x,y,BLANC);

    /* On crée et renvoie l'arbre avec sa valeur */
    a = creer_arbre_position(tmp);
    a->valeur_plateau = point;

    return a;
}

#endif
