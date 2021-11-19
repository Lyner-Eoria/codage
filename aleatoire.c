#include <aleatoire.h>

// génère un nombre aléatoire avec un code à longueur maximale
int *codeLM(int taille, int taille_code, int generateur[], int taille_gen) {
	int i, j, k, next, code[taille_code] , temp[taille_code], *res = calloc(taille, sizeof(int));
	for(j = 0; j < taille_code; j++) {
		code[j] = 1;
	}
	for(i = 0; i < taille; i++) {
		for(j = 0; j < taille_code; j++) {
			temp[j] = code[j];
			if(j) {
				code[j] = temp[j-1];
			}
			else {
				for(k = 0, next = 0; k < taille_gen; k++) {
					next = next ^ code[generateur[k]];
				}
				code[j] = next;
			}
		}
		res[i] = code[taille_code-1];
	}
	return res;
}
