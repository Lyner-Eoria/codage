#ifndef _ETALEMENT_
#define _ETALEMENT_

#include <kit.h>

// génère une matrice de Hadamard en fonction du nombre d'utilisateurs, met à jour la valeur de taille
int *hadamard(int nb_user, int *taille);

// renvoie le message étalé avec la matrice passée en paramètres (supposée adaptée)
int *etal(int *matriceHadamard, int numeroUtilisateur, int tailleLigne, int *messageUtilisateur, int tailleMessage);

// renvoie le message désétalé avec la matrice passée en paramètres (supposée adaptée)
int *desetal(int *hadamard, int nb_user, int taille_ligne, int *msg, int taille_msg);

#endif
