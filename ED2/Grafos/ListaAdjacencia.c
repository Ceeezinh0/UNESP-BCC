#include <stdio.h>
#include <stdlib.h>

#define Max_Vertice 5

typedef struct No {
    int vertice;
    struct No* prox;
} No;

No* criarNo(int vertice) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = vertice;
    novoNo->prox = NULL;
    return novoNo;
}

void adicionarAresta(No* listaAdj[], int origem, int destino) {

    No* novoNo = criarNo(destino);
    novoNo->prox = listaAdj[origem];
    listaAdj[origem] = novoNo;
}

void imprimirListaAdj(No* listaAdj[], int n) {
    for (int i = 0; i < n; i++) {
        No* temp = listaAdj[i];
        printf("Vertice %d:", i);
        while (temp) {
            printf(" -> %d", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

int main() {
    
    int V_O, V_D;
    No* listaAdj[Max_Vertice] = {NULL};

    while (scanf("%d %d", &V_O, &V_D), V_O != 0 || V_D != 0) {
        adicionarAresta(listaAdj, V_O, V_D);
    }

    imprimirListaAdj(listaAdj, Max_Vertice);

    return 0;
}
