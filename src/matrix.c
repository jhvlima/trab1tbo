#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __matrix{
    int source;
    char** nomeVertices;
    float** adjacencias;
};