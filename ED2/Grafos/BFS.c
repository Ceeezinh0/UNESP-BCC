#include<stdio.h>
#include<stdlib.h>

#define Max_Vertice 5

int visitado[Max_Vertice];

typedef struct No{
    int vertice;
    struct No* prox;
} No;

No* CriarNo(int vertice){
    No* novoNo = (No*)malloc(sizeof(No*));
    novoNo -> vertice = vertice;
    novoNo -> prox = NULL;
    return novoNo;
}

void AdicionarAresta(No* listaAdj[], int origem, int destino){
    No* novoNo = CriarNo(destino);
    novoNo -> prox = listaAdj[origem];
    listaAdj[origem] = novoNo;
}

void Enfileirar(int fila[], int *frente, int *tras, int vertice){
    fila[++(*tras)] = vertice;
}

int Desenfileirar(int fila[], int *frente){
    return fila[(*frente)++];
}

void BFS(No* listaAdj[], int verticeInicial){
    int fila[Max_Vertice], frente =0, tras =-1;

    visitado[verticeInicial] = 1;

    Enfileirar(fila, &frente, &tras, verticeInicial);

    printf("Visitando vertice em ordem de BFS a partir do vertice %d : \n", verticeInicial);

    while(frente <= tras){
        int verticeAtual = Desenfileirar(fila, &frente);

        printf("Visitando o vertice %d\n", verticeAtual);

        No* adj = listaAdj[verticeAtual];
        while (adj){
            if(!visitado[adj->vertice]){
                visitado[adj->vertice] = -1;

                Enfileirar(fila, &frente, &tras, adj->vertice);
            }
            adj = adj->prox;
        }
    }
}

void ImprimirListaAdj(No* listaAdj[], int n){
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

int main(){
    int VO, VD;
    No* listaAdj[Max_Vertice] = {NULL};

    while (scanf("%d %d", &VO, &VD), VO != 0 || VD != 0) {
        AdicionarAresta(listaAdj, VO, VD);
    }

    ImprimirListaAdj(listaAdj, Max_Vertice);

    for (int i = 0; i < Max_Vertice; i++) {
        visitado[i] = 0;
    }

    BFS(listaAdj, 0);

    return 0;
}