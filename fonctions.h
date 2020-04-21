#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void initSolution(int ** solution, int listSize);

void freeSolution(int ** solution, int listSize);

void printSolution(int ** solution, int listSize);

bool isQueenSafe(int ** solution, int ligne, int colonne, int listSize);

bool isBishopSafe(int ** solution, int ligne, int colonne, int listSize);

bool isKingSafe(int ** solution, int ligne, int colonne, int listSize);

bool isKnightSafe(int ** solution, int ligne, int colonne, int listSize);

bool search(int ** solution, int nbSolFinal, int nbSolActuel, int casesAPlacer, int casesRestante, int line, int col, bool isSafe(int **, int, int, int), char * filename);

void saveSolution(int ** solution, int listSize, char * filename);

#endif
