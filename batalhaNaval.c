#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3


int main(){
    int tabuleiro[TAMANHO][TAMANHO];

    // dá valor 0 em todo o tabuleiro
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // Vetor do navio
    int barco[NAVIO] = {NAVIO, NAVIO, NAVIO};


    // Horizontal - verifica se ultrapassa linha e se sobrepõe
    int linha1 = 2, coluna1 = 3;
    if(coluna1 + NAVIO - 1 < TAMANHO){
        int podeColocar = 1;
        for(int h = 0; h < NAVIO; h++){
            if(tabuleiro[linha1][coluna1 + h] != 0){
                podeColocar = 0;
                break;
            }
        }
        if(podeColocar){
            for(int i = 0; i < NAVIO; i++){
                tabuleiro[linha1][coluna1 + i] = barco[i];
            }
        }
    }

    // Vertical - se ultrapassa coluna e se sobrepõe
    int linha2 = 5, coluna2 = 6;
    if(linha2 + NAVIO - 1 < TAMANHO){
        int podeColocar = 1;
        for(int v = 0; v < NAVIO; v++){
            if(tabuleiro[linha2 + v][coluna2] != 0){
                podeColocar = 0;
                break;
            }
        }
        if(podeColocar){
            for(int i = 0; i < NAVIO; i++){
                tabuleiro[linha2 + i][coluna2] = barco[i];
            }
        }
    }

    // Diagonal esquerda-baixo - verifica se ultrapassa linha, coluna e se sobrepõe
    int linha3 = 0, coluna3 = 9;
    if(linha3 + NAVIO - 1 < TAMANHO && coluna3 - (NAVIO - 1) >= 0){
        int podeColocar = 1;
        for(int i = 0; i < NAVIO; i++){
            if(tabuleiro[linha3 + i][coluna3 - i] != 0){
                podeColocar = 0;
                break;
            }
        }
        if(podeColocar){
            for(int i = 0; i < NAVIO; i++){
                tabuleiro[linha3 + i][coluna3 - i] = barco[i];
            }
        }
    }

    // Diagonal direita-cima - verifica se ultrapassa linha, coluna e se sobrepõe
    int linha4 = 8, coluna4 = 1;
    if(linha4 - (NAVIO - 1) >= 0 && coluna4 + NAVIO - 1 < TAMANHO){
        int podeColocar = 1;
        for(int i = 0; i < NAVIO; i++){
            if(tabuleiro[linha4 - i][coluna4 + i] != 0){
                podeColocar = 0;
                break;
            }
        }
        if(podeColocar){
            for(int i = 0; i < NAVIO; i++){
                tabuleiro[linha4 - i][coluna4 + i] = barco[i];
            }
        }
    }

    // ====== TABULEIRO =======
    printf("\n  ");
    char linha[TAMANHO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for(int c = 0; c < TAMANHO; c++){
        printf(" %c", linha[c]);
    }
    
    for(int i = 0; i < TAMANHO; i++){
        printf("\n%2i ", i + 1);
        for(int j = 0; j < TAMANHO; j++){
            printf("%i ", tabuleiro[i][j]);
        }
    }

    return 0;
}
