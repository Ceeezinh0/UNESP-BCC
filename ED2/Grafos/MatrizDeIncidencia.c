#include <stdio.h>

#define Max_Vertice 5
#define Max_Arestas 5

int main(){
    int VO, VD;
    int MatrizInc[Max_Vertice][Max_Arestas] = {0};
    int aresta = 0;

    while(scanf("%d %d", &VO, &VD), VO != 0 && VD != 0){
        MatrizInc[VO-1][aresta] = 1;
        MatrizInc[VD-1][aresta] = -1;
        
        aresta++;
    }

    // Exibe a matriz de incidência
    printf("Matriz de Incidência:\n");
    for(int i = 0; i < Max_Vertice; i++){
        for(int j = 0; j < Max_Arestas; j++){
            printf("%d ", MatrizInc[i][j]);
        }
        printf("\n");
    }

    return 0;
}
