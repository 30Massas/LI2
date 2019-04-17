#include "estado.h"

int contaPontos (ESTADO *e,int x, int y) {
    int soma = 0;
    int i, k;
    // cria um estado auxiliar e simula as peças alteradas
    ESTADO *aux = malloc(sizeof(struct estado));
    copyEstado(e, aux);
    joga(aux, x, y);
    poepeca(aux, x, y);
    // ----------------------------


    // dependendo das posições em que se encontram as suas peças, é feito um somatório
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) {
                if ((x == 0 || x == 7) && (y == 0 || y == 7)) soma += 10000;
                else if ((x == 1 && y == 1) || (x == 1 && y == 6) || (x == 6 && y == 1) || (x == 6 && y == 6))
                    soma -= 5000;
                else if ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 0 && y == 6) || (x == 1 && y == 7) ||
                         (x == 6 && y == 0) || (x == 7 && y == 1) || (x == 6 && y == 7) || (x == 7 && y == 6))
                    soma -= 3000;
                else if ((x == 0 && y == 2) || (x == 0 && y == 5) || (x == 7 && y == 2) || (x == 7 && y == 5) ||
                         (x == 2 && y == 0) || (x == 2 && y == 7) || (x == 5 && y == 0) || (x == 5 && y == 7))
                    soma += 1000;
                else if ((x == 0 && y == 3) || (x == 0 && y == 4) || (x == 7 && y == 3) || (x == 7 && y == 4) ||
                         (x == 3 && y == 0) || (x == 3 && y == 7) || (x == 4 && y == 0) || (x == 4 && y == 7))
                    soma += 800;
                else if ((x == 1 && y == 3) || (x == 1 && y == 4) || (x == 6 && y == 3) || (x == 6 && y == 4) ||
                         (x == 3 && y == 1) || (x == 3 && y == 6) || (x == 4 && y == 1) || (x == 4 && y == 6))
                    soma -= 500;
                else if ((x == 1 && y == 2) || (x == 2 && y == 1) || (x == 1 && y == 5) || (x == 2 && y == 6) ||
                         (x == 5 && y == 1) || (x == 6 && y == 2) || (x == 5 && y == 6) || (x == 6 && y == 5))
                    soma -= 450;
                else if ((x == 2 && y == 2) || (x == 2 && y == 5) || (x == 5 && y == 2) || (x == 5 && y == 5))
                    soma += 30;
                else if ((x == 2 && y == 3) || (x == 2 && y == 4) || (x == 5 && y == 3) || (x == 5 && y == 4) ||
                         (x == 3 && y == 2) || (x == 3 && y == 5) || (x == 4 && y == 2) || (x == 4 && y == 5))
                    soma += 10;
                else soma += 50;
            }
        }
    }
    free(aux);
    return soma;
}


int maxbot (ESTADO *e, int *x, int *y) {
    int i, k;
    int temp, max = -99999;
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (verificajogada(e, i, k)) {
                temp = contaPontos(e, i, k);
                if (temp >= max) {
                    max = temp;
                    *x = i;
                    *y = k;
                }

            }
        }
    }
    return max;
}

int minbot (ESTADO *e, int *x, int *y){
    int i,k;
    int temp, min = 99999;
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (verificajogada(e, i, k)){
                temp = maxbot(e,x,y);
                if (temp <= min){
                    min = temp;
                    *x = i;
                    *y = k;
                }
            }
        }
    }
    return min;
}

int maxplay (ESTADO *e, int *x, int *y) {
    int i, k;
    int temp, max = -99999;
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (verificajogada(e, i, k)) {
                temp = minbot(e, x, y);
                if (temp >= max) {
                    max = temp;
                    *x = i;
                    *y = k;
                }
            }
        }
    }
    return max;
}