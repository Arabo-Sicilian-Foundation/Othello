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

#endif
