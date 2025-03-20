#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5


// cone:
void habilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int LinhaCone, int ColunaCone) {
    for(int i = 0; i < 3; i++){
        for(int j = -i; j <= i; j++){
            int x = LinhaCone + i;
            int y = ColunaCone + j;
            if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO){
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// cruz
void habilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int LinhaCruz, int ColunaCruz){
    for(int i = -1; i <= 1; i++){
        for(int j = -2; j <= 2; j++){  
            if(i == 0  || j == 0){
                int x = LinhaCruz + i;
                int y = ColunaCruz + j;
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}

// octaedro
void habilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int LinhaOcta, int ColunaOcta){
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){  
            if(i == 0  || j == 0){
                int x = LinhaOcta + i;
                int y = ColunaOcta + j;
                tabuleiro[x][y] = HABILIDADE;
            }
        }
    }
}


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

    habilidadeCone(tabuleiro, 7, 7);
    habilidadeCruz(tabuleiro, 1, 3);
    habilidadeOctaedro(tabuleiro, 8, 3);


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
