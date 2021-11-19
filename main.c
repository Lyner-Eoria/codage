#include <etalement.h>
#include <kit.h>
#include <aleatoire.h>

int main() {
	int g[2] = {1, 4}, h[2] = {4, 1};
	int *m = codeLM(5, 4, g, 2);
	int *n = codeLM(5, 4, h, 2);
	for(int i = 0; i < 2; i++)
		printf("%d ", g[i]);
	printf("\n");
	for(int i = 0; i < 5; i++)
		printf("%d ", m[i]);
	printf("\n");
	printf("\n");
	for(int i = 0; i < 2; i++)
		printf("%d ", h[i]);
	printf("\n");
	for(int i = 0; i < 5; i++)
			printf("%d ", n[i]);
	printf("\n");
}

/* TEST HADAMARD/HDBN
int main() {
	int i, j, taille;
	int *msg = calloc(20, sizeof(int));
	int *m = hadamard(2, &taille);
	srand(time(0));
	for(i = 1; i < 3; i++) {
		printf("%d:\t", i);
		for(j = 0; j < 4; j++) {
			*position(msg, i-1, j, 10) = rand() % 2;
			printf("%2d ", *position(msg, i-1, j, 10));
		}
		printf("\n");
	}
	for(i = 1; i < 3; i++) {
		int *code = etal(m, i, taille, position(msg, i-1, 0, 10), 4);
		printf("%d:\n", i);
		cp(position(msg, i-1, 0, 10), code, taille * 4);
		for(j = 0; j < taille * 4 ; j++) {
			printf("%2d ", *position(msg, i-1, j, 10));
		}
		free(code);
		printf("\n");
	}
	for(i = 1; i < 3; i++) {
		int *code = desetal(m, i, taille, position(msg, i-1, 0, 10), 4);
		printf("%d:\n", i);
		cp(position(msg, i-1, 0, 10), code, taille * 4);
		for(j = 0; j < 4 ; j++) {
			printf("%2d ", *position(msg, i-1, j, 10));
		}
		free(code);
		printf("\n");
	}
	free(m);
	free(msg);
}
*/
