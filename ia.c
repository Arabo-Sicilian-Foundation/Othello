#ifndef IA_C
#define IA_C

#include "ia.h"
#include <time.h>

void ia_aleatoire(plateau p)
{
	int x = rand() % 8;
	int y = rand() % 8;

	while(!coup_valide(p,x,y,BLANC))
	{
		x = rand() % 8;
		y = rand() % 8;
	}

	capture(p,x,y,BLANC);
}

#endif
