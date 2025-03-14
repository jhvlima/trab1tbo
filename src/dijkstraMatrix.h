#ifndef DIJKSTRAMATRIX_H
#define DIJKSTRAMATRIX_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrix.h"
#include "node.h"
#include "ioHandler.h"

Node** dijkstraMatrix(Matrix* matrix);

int resolveComDijkstraMatrix(char* entradaPath, char* saidaPath);

#endif