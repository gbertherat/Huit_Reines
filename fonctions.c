#include "fonctions.h"

/* La fonction initSolution permet d'initialiser la liste solution
 * Entrée: solution - la solution à initialiser
 * Entrée: listSize - la taille de la liste solution
 */
void initSolution(int ** solution, int listSize){
	for(int i = 0; i < listSize; i++){
		solution[i] = malloc(2*sizeof(int));
		solution[i][0] = -1;
		solution[i][1] = -1;
	}
}

/* La fonction freeSolution permet de libérer l'espace mémoire pris par une solution
 * Entrée: solution - la solution à supprimer
 * Entrée: listSize - la taille de la liste solution
 */
void freeSolution(int ** solution, int listSize){
	for(int i = 0; i < listSize; i++){
		free(solution[i]);
	}
	free(solution);
}

/*
 * La fonction printSolution permet d'afficher une solution dans la console
 * Entrée: solution - Matrice solution avec les coordonnées des pions
 * Entrée: size - La taille de l'échiquier
 */
void printSolution(int ** solution, int listSize){
	int i = 0;
	int j = 0;
	int k;
	bool found = false;
	while(i < 8){ // Tant qu'on est pas à la dernière ligne
		printf("|");
		k = 0; // On place le curseur au premier élément du tableau 'solution'
		while(k < listSize && found == false){
			if(solution[k][0] == i && solution[k][1] == j){ // Si un pion est trouvé
				printf("*"); // On met un '*'
				found = true;
			}
			k++;
		}
		if(found == false){ // Si aucun pion n'a été trouvé, on met un espace
			printf(" ");
		}
		found = false;
		j++;
		if(j == 8){ // Si on a atteint la dernière colonne+1
			i++; // On passe à la ligne suivante
			j = 0; // On revient à la première colonne
			printf("|\n");
		}
	}
	printf("\n");
}

/*
 * La fonctin isQueenSafe permet de vérifier que l'on peut placer une reine sur une case
 * Entrée: solution - Matrice solution pour vérifier l'emplacement des autres pions
 * Entrée: ligne & colonne - Coordonnées de la case à vérifier
 * Sortie: true si la case est safe, false sinon
 */
bool isQueenSafe(int ** solution, int ligne, int colonne, int listSize){
	for(int k = 0; k < listSize; k++){
		if(solution[k][0] > -1 && solution[k][1] > -1){
			if(ligne == solution[k][0]
			|| colonne == solution[k][1]
			|| abs(ligne - solution[k][0]) == abs(colonne - solution[k][1])){
				return false;
			}
		} else {
			return true;
		}
	}
	return true;
}

/*
 * La fonctin isBishopSafe permet de vérifier que l'on peut placer un fou sur une case
 * Entrée: solution - Matrice solution pour vérifier l'emplacement des autres pions
 * Entrée: ligne & colonne - Coordonnées de la case à vérifier
 * Sortie: true si la case est safe, false sinon
 */
bool isBishopSafe(int ** solution, int ligne, int colonne, int listSize){
	for(int k = 0; k < listSize; k++){
		if(solution[k][0] > -1 && solution[k][1] > -1){
			if(abs(ligne - solution[k][0]) == abs(colonne - solution[k][1])){
				return false;
			}
		} else {
			return true;
		}
	}
	return true;
}

/*
 * La fonctin isKingSafe permet de vérifier que l'on peut placer un roi sur une case
 * Entrée: solution - Matrice solution pour vérifier l'emplacement des autres pions
 * Entrée: ligne & colonne - Coordonnées de la case à vérifier
 * Sortie: true si la case est safe, false sinon
 */
bool isKingSafe(int ** solution, int ligne, int colonne, int listSize){
	for(int k = 0; k < listSize; k++){
		if(solution[k][0] > -1 && solution[k][1] > -1){
			if(pow(ligne - solution[k][0],2) <= 1
			&& pow(colonne - solution[k][1],2) <= 1){
				return false;
			}
		} else {
			return true;
		}
	}
	return true;
}


/*
 * La fonctin isKnightSafe permet de vérifier que l'on peut placer un cavalier sur une case
 * Entrée: solution - Matrice solution pour vérifier l'emplacement des autres pions
 * Entrée: ligne & colonne - Coordonnées de la case à vérifier
 * Sortie: true si la case est safe, false sinon
 */
bool isKnightSafe(int ** solution, int ligne, int colonne, int listSize){
	for(int k = 0; k < listSize; k++){
		if(solution[k][0] > -1 && solution[k][1] > -1){
			if(pow(ligne - solution[k][0],2) + pow(colonne - solution[k][1],2) == 5){
				return false;
			}
		} else {
			return true;
		}
	}
	return true;
}

/*
 * La fonction saveSolution permet de sauvegarder une solution dans un fichier
 * Entrée: solution - Liste solution à sauvegarder
 * Entrée: listeSize - Taille de la liste solution
 * Entrée: filename - Nom du fichier avec extension
 */
void saveSolution(int ** solution, int listSize, char * filename){
	char toSave;
	FILE* file = fopen(filename, "a+");
	int i = 0;
	int j = 0;
	int k;
	bool found = false;
	while(i < 8){ // Tant qu'on est pas à la dernière ligne
		fprintf(file,"|");
		k = 0; // On place le curseur au premier élément du tableau 'solution'
		while(k < listSize && found == false){
			if(solution[k][0] == i && solution[k][1] == j){ // Si un pion est trouvé
				fprintf(file,"*"); // On met un '*'
				found = true;
			}
			k++;
		}
		if(found == false){ // Si aucun pion n'a été trouvé, on met un espace
			fprintf(file," ");
		}
		found = false;
		j++;
		if(j == 8){ // Si on a atteint la dernière colonne+1
			i++; // On passe à la ligne suivante
			j = 0; // On revient à la première colonne
			fprintf(file,"|\n");
		}
	}
	fputc('\n', file);
	fclose(file);
}

/*
 * La fonction search permet de chercher toutes les solutions possibles pour une variante
 * choisie
 * Entrée: solution - La liste des solutions
 * Entrée: nbSolFinal - La taille de la liste solution
 * Entrée: nbSolActuel - Le nombre de solutions déjà trouvé
 * Entrée: line & col - Les coordonnées du pion à placer
 * Entrée: isSafe - Pointeur vers la fonction à utiliser pour déterminer si l'emplacement
 * du pion est safe
 * Entrée: filename - le nom du fichier dans lequel enregistrer les solutions
 */
bool search(int ** solution, int nbSolFinal, int nbSolActuel, int caseAPlacer, int caseRestante, int line, int col, bool isSafe(int **, int, int, int), char * filename){
	if(nbSolActuel >= nbSolFinal){ // Si le nombre de solution >= au nombre de solutions attendus
		// printSolution(solution, nbSolFinal); // On print la solution
		saveSolution(solution, nbSolFinal, filename); // On sauvegarde la solution
		return true;
	}

	if(caseAPlacer > caseRestante){
		return false;
	}

	if(col == 8){ // Si on a dépassé la dernière colonne
		col = 0; // On reviens à la première colonne
		line++;	 // On avance d'une ligne
	}

	if(line == 8){ // So on a dépassé la dernière ligne
		return false; // On retourne false
	}

	if(isSafe(solution, line, col, nbSolFinal)){ // Si l'emplacement est safe
		solution[nbSolActuel][0] = line; // On place le pion aux coordonnées (line;col)
		solution[nbSolActuel][1] = col;

		caseAPlacer--;
		caseRestante--;
		search(solution, nbSolFinal, nbSolActuel+1, caseAPlacer, caseRestante, line, col+1, isSafe, filename); // Appel récursif pour tester toutes les possibilitées

		solution[nbSolActuel][0] = -1; // On enlève le pion après tous les appels récursifs
		solution[nbSolActuel][1] = -1;
	}
	caseRestante--;
  search(solution, nbSolFinal, nbSolActuel, caseAPlacer, caseRestante, line, col+1, isSafe, filename); // Appel récursif pour juste avancer d'une colonne
	return false;
}