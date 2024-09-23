//Busca em Profundidade
//Objetivo Percorrer o max de cada ramo antes de voltar

#include <stdio.h>
#include <stdlib.h>

#define Max_Vertice 5

int visitado[Max_Vertice];

typedef struct No{
    int vertice;
    struct No* prox;
}No;

No* CriarNo(int vertice){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo -> vertice = vertice;
    novoNo -> prox = NULL;
    return novoNo;
}

void AdicionarAresta(No* listaAdj[], int origem, int destino){
    No* novoNo = CriarNo(destino);
    novoNo->prox = listaAdj[origem];
    listaAdj[origem] = novoNo;
}

void DFS(No* listaAdj[], int vertice){
    visitado[vertice] = 1;

    printf("Visitando vértice %d\n", vertice);
    
    No* adj = listaAdj[vertice];

    while(adj){
        if(!visitado[adj -> vertice]){
            DFS(listaAdj, adj->vertice);
        }

        adj = adj -> prox;
    }

}

void imprimirListaAdj(No* listaAdj[], int n){
    for(int i =0; i < n; i++){
        No* temp = listaAdj[i];
        
        printf("Vertice %d:", i);

        while(temp){
            printf(" -> %d", temp->vertice);
            temp = temp ->prox;
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

    imprimirListaAdj(listaAdj, Max_Vertice);

    for(int i = 0; i < Max_Vertice; i++){
        visitado[i] = 0;
    }

    printf("Realizando DFS a partir do vértice 0:\n");

    DFS(listaAdj, 0);

    return 0;
}
//Quero saber mais sobre ordenação topológica utilizando DFS