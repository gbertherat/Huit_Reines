#include "fonctions.h"

int main(void) {
	int chessSize = 8;
	int listSize;
	bool (*function)(int **, int, int, int);

	printf("Quelles variantes souhaitez-vous?\n\
		1) Les 8 reines\n\
		2) Les 14 fous\n\
		3) Les 16 rois\n\
		4) Les 32 cavaliers\n\
		5) Annuler\n\
	>> ");
	int choix;
	scanf("%i", &choix);

	if(choix == 5){return 0;}

	switch(choix){
		case 1:
			listSize = 8;
			function = &isQueenSafe;
			break;
		case 2:
			listSize = 14;
			function = &isBishopSafe;
			break;
		case 3:
			listSize = 16;
			function = &isKingSafe;
			break;
		case 4:
			listSize = 32;
			function = &isKnightSafe;
			break;
	}

	int ** solution = malloc(listSize*sizeof(int *));
	initSolution(solution, listSize);

	char filename[100];
	printf("Entrez le nom du fichier de sauvegarde (avec extension)\n>> ");
	scanf("%s", filename);

	search(solution, listSize, 0, listSize, 8*8, 0, 0, function, filename);
	
	return 0;
}