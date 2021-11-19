#ifndef _KIT_
#define _KIT_

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// renvoie l'addresse de matrice[i][j]
int *position(int *matrice, int i, int j, int taille_ligne);

// copie la matrice source dans la destination, peut inverser les valeurs
void copier_matrice(int *dest, int *source, int taille_dest, int taille_source, int inverser);

void afficher_matrice(int *matrice, int taille_matrice);

// copie size bytes de src dans dest
void cp(int *dest, int *src, int size);

#endif
