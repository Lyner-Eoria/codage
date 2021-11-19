#include <etalement.h>

// génère et renvoie Hn, met à jour la valeur de taille
int *H(int n, int *taille) {
	int taille_old, i;
	int *matrice = calloc(1, sizeof (int)), *copie = calloc(1, sizeof (int));
	matrice[0] = 1;
	*taille = 1;
	for(i = 0; i < n; i++) {
		// passage à la matrice suivante, on garde une copie de l'ancienne
		taille_old = *taille;
		*taille *= 2;
		copie = realloc(copie, taille_old * taille_old * sizeof (int));
		copier_matrice(copie, matrice, taille_old, taille_old, 0);
		matrice = realloc(matrice, *taille * *taille * sizeof (int));

		// copie en haut à gauche
		copier_matrice(position(matrice, 0, 0, *taille), copie, *taille, taille_old, 0);
		// copie en haut à droite
		copier_matrice(position(matrice, 0, taille_old, *taille), copie, *taille, taille_old, 0);
		// copie en bas à gauche
		copier_matrice(position(matrice, taille_old, 0, *taille), copie, *taille, taille_old, 0);
		// copie en bas à droite, on inverse les valeurs
		copier_matrice(position(matrice, taille_old, taille_old, *taille), copie, *taille, taille_old, 1);
	}
	free(copie);
	return matrice;
}

// génère une matrice de Hadamard en fonction du nombre d'utilisateurs, met à jour la valeur de taille
int *hadamard(int nb_user, int *taille) {
	int i, nb_iter = 0;
	// recherche du nombre d'itérations pour générer la matrice adaptée
	for(i = 1; i < nb_user; nb_iter++, i *= 2);
	return H(nb_iter, taille);
}


// renvoie le message étalé avec la matrice passée en paramètres (supposée adaptée)
int *etal(int *matriceHadamard, int numeroUtilisateur, int tailleLigne, int *messageUtilisateur, int tailleMessage){

        int* message = malloc(sizeof(int)*tailleLigne*tailleMessage);
        int signe = 1;
        int j = 0;
        int i = 0;


        while(i<tailleMessage){
                if(messageUtilisateur[i] == 1){
                        signe = 1;
                }
                else{
                        signe = -1;
                }
				printf("%d ", signe);
                for(j = 0;j<tailleLigne;j++){
                        *position(message, i, j, tailleLigne) = *position(matriceHadamard,numeroUtilisateur-1,j, tailleLigne) * signe;
                }
				i++;
        }
		printf("\n");
        return message;
}

// renvoie le message désétalé avec la matrice passée en paramètres (supposée adaptée)
int *desetal(int *hadamard, int nb_user, int taille_ligne, int *msg, int taille_msg) {
	int *code = malloc(taille_msg * sizeof (int));
	int i, j;
	for(i = 0; i < taille_msg; i++) {
		for(j = 0; j < taille_ligne && *position(hadamard, nb_user-1, j, taille_ligne) == *position(msg, i, j, taille_ligne); j++);
		if(j == taille_ligne) {
			code[i] = 1;
		}
		else {
			for(j = 0; j < taille_ligne && *position(hadamard, nb_user-1, j, taille_ligne) == *position(msg, i, j, taille_ligne) * -1; j++);
			if(j == taille_ligne) {
				code[i] = 0;
			}
			else {
				code[i] = -1;
			}
		}
	}
	return code;
}
