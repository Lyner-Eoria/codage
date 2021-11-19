#include <kit.h>

// renvoie l'addresse de matrice[i][j]
int *position(int *matrice, int i, int j, int taille_ligne) {
	return matrice + i * taille_ligne + j;
}

// copie la matrice source dans la destination, peut inverser les valeurs
void copier_matrice(int *dest, int *source, int taille_dest, int taille_source, int inverser) {
	int i, j;
	if(inverser)
		for(i = 0; i < taille_source; i++)
			for(j = 0; j < taille_source; j++)
				// dest[i][j] = -source[i][j] (en gros)
				*position(dest, i, j, taille_dest) = *position(source, i, j, taille_source) * -1;
	else
		for(i = 0; i < taille_source; i++)
			for(j = 0; j < taille_source; j++)
				// dest[i][j] = source[i][j] (en gros)
				*position(dest, i, j, taille_dest) = *position(source, i, j, taille_source);
}

void afficher_matrice(int *matrice, int taille_matrice) {
	int i, j;
	for(i = 0; i < taille_matrice; i++) {
		for(j = 0; j < taille_matrice; j++)
			printf("%2d ", *position(matrice, i, j, taille_matrice));
		printf("\n");
	}
	printf("\n");
}

// copie size int de src dans dest
void cp(int *dest, int *src, int size) {
	int i;
	for(i = 0; i < size; i++)
		dest[i] = src[i];
}
