#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initSolution(int * solution, int size);

void printSolution(int * solution, int size);

bool isQueenSafe(int * solution, int ligne, int colonne, int size);

bool isBishopSafe(int * solution, int ligne, int colonne, int size);

bool search(int * solution, int size, int ligne, int type, char * filename);

void saveSolution(int * solution, int size, char * filename);

#endif