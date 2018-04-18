#ifndef PLATEAU_H
#define PLATEAU_H
#define VIDE 2
#define NOIR 1
#define BLANC 0

#include <stdio.h>
#include <stdlib.h>

typedef int plateau[8][8];


void plateau_init(plateau p);

void plateau_afficher(plateau p);

#endif
