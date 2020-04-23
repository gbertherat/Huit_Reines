#include "fonctions.h"

bool initSolutionTest(int ** solution){
	return solution[0][0] == -1;
}

bool isQueenSafeTest(int ** solution){
	return (isQueenSafe(solution, 0, 0, 8)) == false && (isQueenSafe(solution, 1, 1, 8) == true);
}

bool isBishopSafeTest(int ** solution){
	return (isBishopSafe(solution, 1, 3, 8)) == false && (isBishopSafe(solution, 1, 1, 8) == true);
}

bool isKingSafeTest(int ** solution){
	return (isKingSafe(solution, 1, 4, 8)) == false && (isKingSafe(solution, 1, 1, 8) == true);
}

bool isKnightSafeTest(int ** solution){
	return (isKnightSafe(solution, 2, 3, 8)) == false && (isKnightSafe(solution, 1, 1, 8) == true);
}

bool searchTest(int ** solution, bool isSafe(int **, int, int, int), char * filename){
	search(solution, 8, 0, 8, 8*8, 0, 0, isSafe, filename);
	FILE *file;
	int nbLines = 0;
	char filechar[40], chr;

	file = fopen(filename, "r");
	chr = getc(file);
	while (chr != EOF){
			if (chr == '\n'){
					nbLines++;
			}
			chr = getc(file);
	}
	fclose(file);
	if(isSafe == isQueenSafe){
		return nbLines == 828;
	} else if(isSafe == isBishopSafe){
		return nbLines == 2304;
	} else if(isSafe == isKingSafe){
		return nbLines == 2534139;
	} else if(isSafe == isKnightSafe){
		return nbLines == 18;
	}
	return -1;
}

int main(void){
	int ** solution = malloc(8*sizeof(int *));
	initSolution(solution, 8);
	printf("Test initSolution(): %s\n", initSolutionTest(solution) ? "True" : "False");
	
	// Test des fonctions isSafe //
	solution[0][0] = 0;
	solution[0][1] = 4; 
	
	printf("\nTest isQueenSafe(): %s\n", isQueenSafeTest(solution) ? "True" : "False");
	printf("\nTest isBishopSafe(): %s\n", isBishopSafeTest(solution) ? "True" : "False");
	printf("\nTest isKingSafe(): %s\n", isKingSafeTest(solution) ? "True" : "False");
	printf("\nTest isKnightSafe(): %s\n", isKnightSafeTest(solution) ? "True" : "False");

	solution[0][0] = -1;
	solution[0][1] = -1;

	printf("\nTest searchQueen(): %s\n", searchTest(solution, &isQueenSafe, "reines_test.txt") ? "True" : "False");
	printf("\nTest searchBishop(): %s\n", searchTest(solution, &isBishopSafe, "fous_test.txt") ? "True" : "False");
	printf("\nTest searchKing(): %s\n", searchTest(solution, &isKingSafe, "rois_test.txt") ? "True" : "False");
	printf("\nTest searchKnight(): %s\n", searchTest(solution, &isKnightSafe, "cavaliers_test.txt") ? "True" : "False");
	
	freeSolution(solution, 8);
	return 0;
}
