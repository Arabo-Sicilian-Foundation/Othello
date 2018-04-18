#ifndef IA_C
#define IA_C

#include "ia.h"
#include <time.h>

int ia_aleatoire(plateau p)
{
	int x = rand() % 8;
	int y = rand() % 8;

	if(!position_gagnante(p,NOIR))
	{
		return 0;
	}

	while(!coup_valide(p,x,y,NOIR))
	{
		x = rand() % 8;
		y = rand() % 8;
	}

	capture(p,x,y,NOIR);
}

#endif
