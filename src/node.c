#include <stdio.h>
#include <stdlib.h>

#include "node.h"

struct __node
{
    int idVert;
    float distancia;
    int pai;
};

Node* nodeCreate(int idVert, float distancia)
{
    Node* node = (Node*) malloc (sizeof(Node));
    node->distancia = distancia;
    node->idVert = idVert;
    node->pai = idVert;
    return node;
}

int nodeGetId(Node* node)
{
    return node->idVert;
}

int nodeGetPai(Node* node)
{
    return node->pai;
}


float nodeGetDistancia(Node* node)
{
    return node->distancia;
}

void nodeSetDistancia(Node* node, float distancia)
{
    node->distancia = distancia;
}

void nodeSetPai(Node* node, int pai)
{
    node->pai = pai;
}

void nodeDestroyArvoreMinima(Node** arvoreMinima, int nVertices)
{
    if(arvoreMinima){
        for(int i = 0; i < nVertices; i++){
            if(arvoreMinima[i]) free(arvoreMinima[i]);
        }
        free(arvoreMinima);
    }
}

