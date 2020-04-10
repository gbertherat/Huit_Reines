#include "fonctions.h"

int main(void) {
	int n = 8;
	n++;

	int type = 5;
	printf("Quelle variante souhaitez-vous?\n\
		1) Les 8 reines\n\
		2) Les 14 fous\n\
		3) Les 16 rois\n\
		4) Les 32 cavaliers\n\
		5) Annuler\n\
	 >> ");
	scanf("%i", &type);

	if(type == 5){return 1;}

	int * solution = malloc(n*sizeof(int *));
	initSolution(solution, n);

	char filename[24];
	printf("Entrez le nom du fichier, avec extension, ou vous souhaitez enregistrer les solutions\n>> ");
	scanf("%s", filename);	

	search(solution, n, 1, type, filename);
	
	free(solution);
	return 1;
}