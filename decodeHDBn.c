#include <kit.h>
// a ajouter au module codage
int *decodeHDBn(int *sig, int taille, int type) {
	int *msg = calloc(taille, sizeof(int));
	int i, zeros, signe, viol;
	for(i = 0, zeros = 0, signe = -1, viol = -1; i < taille; i++) {
		if(sig[i] == 1 || sig[i] == -1) {
			msg[i] = signe;
			signe *= -1;
		}
		else {
			zeros++;
			if(zeros > type) {
				if(viol == 1) {
					if(signe == 1) {
						msg[i-type] = -1;
						signe *= -1;
					}
					msg[i] = -1;
				}
				else {
					if(signe == -1) {
						msg[i-type] = 1;
						signe *= -1;
					}
					msg[i] = 1;
				}
				viol *= -1;
			}
			else {
				msg[i] = 0;
			}
		}
	}
	return msg;
}
