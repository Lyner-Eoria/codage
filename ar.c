#include <kit.h>

// a ajouter au module codage
double ar(int *msg, int taille) {
	double msg_code, *probs;
	int i, j, nb_s, *s;
	probs = calloc(taille, sizeof(double))
	s = calloc(taille, sizeof(int));
	for(i = 1, nb_s = 0; i < taille; i++) {
		for(j = 0; j < nb_s && msg[i] != s[j]; j++);
		if(j == nb_s) {
			s[j] = msg[i];
			nb_s++;
		}
		probs[j]++;
	}
	probs = realloc(nb_s * sizeof(double));
	s = realloc(nb_s * sizeof(int));
	probs[0] /= nb_s;
	for(i = 1; i < nb_s; i++)
		probs[i] = probs[i] / nb_s + probs[i-1];
}
