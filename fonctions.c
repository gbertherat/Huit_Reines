#include "fonctions.h"

/* La fonction initSolution permet d'initialiser une solution en mettant chacune de 
 * ses cases à -1
 * Entrée: solution - La solution à initialiser
 * Entrée: size - La taille de la solution
 */
void initSolution(int * solution, int size){
	for(int i = 0; i <= size; i++){
		solution[i] = -1;
	}
}

/*
 * La fonction printSolution permet d'afficher une solution donnée dans la console.
 * Entrée: solution - La solution à afficher
 * Entrée: size - La taille de la solution
 */
void printSolution(int * solution, int size){
	for(int i = 1; i < size; i++){ // Pour chaque ligne
		for(int j = 1; j < size; j++){ // Pour chaque colonne de cette ligne
			printf("|");
			if(solution[i] == j){ 
				printf("*"); // On affiche "*"" si il y'a une pièce à la position i,j
			} else {
				printf(" "); // On affiche " " sinon
			}
		}
		printf("|\n");
	}
	printf("\n");
}

/*
 * La fonction isQueenSafe permet de vérifier si on peut placer une reine à une 
 * position (ligne,colonne) donnée.
 * Entrée: solution - La solution à vérifier
 * Entrée: ligne & colonne - Les coordonnées où l'on souhaite placer une reine
 * Entrée: size - La taille de la solution
 * Sortie: true si la reine peut être placer, false sinon
 */
bool isQueenSafe(int * solution, int ligne, int colonne, int size){
  for(int i = 1; i < size; i++){ // Pour chaque ligne
    if(solution[i] > -1){
			/* On vérifie les conditions suivantes:
			 * - Pas d'autre reine sur la ligne
			 * - Pas d'autre reine sur la colonne
			 * - Pas d'autre reine sur les diagonales
			 */
      if (ligne == i || colonne == solution[i] || ( abs(ligne - i) == abs(colonne - solution[i]) ) ){
        return false; // Si une reine est trouvée, on retourne false
      }
    }
	}
  return true; // Si tout est bon, on retourne true
}

bool isBishopSafe(int * solution, int ligne, int colonne, int size){
	for(int i = 1; i < size; i++){
		if(solution[i] > -1){
			if(abs(ligne-i) == abs(colonne-solution[i])){
				return false;
			}
		}
	}
	return true;
}

/*
 * La fonction search permet de rechercher toutes les solutions possibles pour 
 * le placement des pièces dans une grille de taille donnée.
 * Entrée: solution - La solution initiale
 * Entrée: size - La taille de la solution
 * Entrée: ligne - La ligne à partir de laquelle commencer la recherche
 * Sortie: true s'il n'y a pas eu d'erreur, false sinon.
 */
bool search(int * solution, int size, int ligne, int type, char * filename){
	if(ligne >= size){
		printSolution(solution, size);
		saveSolution(solution, size, filename);
		return true;
	}

	for(int colonne = 1; colonne < size; ++colonne){
		if(type == 1){ // Si la variante choisie est les 8 reines
			if(isQueenSafe(solution, ligne, colonne, size)){
				solution[ligne] = colonne;
				search(solution, size, ligne+1, type, filename);
				solution[ligne] = -1;
			}
		} 
	}
	return false;
}

/* La fonction saveSolution permet de sauvegarder une solution dans un fichier
 * Entrée: solution - La solution à sauvegarder
 * Entrée: size - La taille de la solution
 * Entrée: filename - Le nom du fichier, (avec extension!)
 */
void saveSolution(int * solution, int size, char * filename){
	char toSave;
	FILE* file = fopen(filename, "a+");
	for(int i = 1; i < size; i++){
		toSave = solution[i];
		fprintf(file, "%i", toSave);
		fputc(' ', file);
	}
	fputc('\n', file);
	fclose(file);
}