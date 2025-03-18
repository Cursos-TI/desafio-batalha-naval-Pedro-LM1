#include <stdio.h>


int main(){
    int tabuleiro[10][10];


    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // vetores dos barcos
    int barco1[3] = {3,3,3};
    int barco2[3] = {3,3,3};

    // confere se o barco ultrapassa a coluna
    int linha1 = 2, coluna1 = 3;
    if(coluna1 + 2 < 10){
        for(int h = 0; h < 3; h++){
            tabuleiro[linha1][coluna1 + h] = barco1[h];
        }
    }

    // confere se o barco ultrapassa a linha
    int linha2 = 5, coluna2 = 6;
    if(linha2 + 2 < 10){
        for(int v = 0; v < 3; v++){
            tabuleiro[linha2 + v][coluna2] = barco2[v];
        }
    }

    printf("\n");
    printf(" ");
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for(int c = 0; c < 10; c++){
        printf(" %c", linha[c]);
    }
     
    for(int i = 0; i < 10; i++){
        printf("\n%2i ", i+1);
        for(int j = 0; j < 10; j++){
            printf("%i ", tabuleiro[i][j]);
        }
    }

    return 0;
}