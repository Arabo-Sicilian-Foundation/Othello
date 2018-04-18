#ifndef JEUX_H
#define JEUX_H

#include "plateau.h"

void jeux_init(plateau p);

int position_gagnante(plateau p, int couleur);

void capture(plateau p, int x, int y, int couleur);

int coup_valide(plateau p, int x, int y, int couleur);

void gagnant(plateau p);

#endif