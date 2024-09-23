#include <stdio.h>

#define Max_Vertice 5

int main(){
    int V_O, V_D;
    int MatrizADJ[Max_Vertice][Max_Vertice] = {0};

    while(scanf("%d %d", &V_O, &V_D), V_O != 0 || V_D != 0){ 
        MatrizADJ[V_O][V_D] = 1;
    }

    printf("Matriz de Adjacencia!\n");

    for(int i = 0; i < Max_Vertice; i++){
        for(int j = 0; j < Max_Vertice; j++){
            printf("%d ", MatrizADJ[i][j]);
        }   
        
        printf("\n");
    }
    return 0;
}
