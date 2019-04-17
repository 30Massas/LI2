#include "estado.h"

int contaPontos (ESTADO *e,int x, int y) {
    int soma = 0;
    int i, k;
    // cria um estado auxiliar e simula as peças alteradas
    ESTADO *aux = malloc(sizeof(struct estado));
    copyEstado(e, aux);
    joga(aux, x, y);
//    poepeca(aux, x, y);
    // ----------------------------


    // dependendo das posições em que se encontram as suas peças, é feito um somatório
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) {
                if ((i == 0 || i == 7) && (k == 0 || k == 7)) soma += 10000;
                else if ((i == 1 && k == 1) || (i == 1 && k == 6) || (i == 6 && k == 1) || (i == 6 && k == 6)) soma = soma - 5000;
                else if ((i == 1 && k == 0) || (i == 0 && k == 1) || (i == 0 && k == 6) || (i == 1 && k == 7) || (i == 6 && k == 0) || (i == 7 && k == 1) || (i == 6 && k == 7) || (i == 7 && k == 6))
                    soma = soma - 3000;
                else if ((i == 0 && k == 2) || (i == 0 && k == 5) || (i == 7 && k == 2) || (i == 7 && k == 5) ||
                         (i == 2 && k == 0) || (i == 2 && k == 7) || (i == 5 && k == 0) || (i == 5 && k == 7))
                    soma += 1000;
                else if ((i == 0 && k == 3) || (i == 0 && k == 4) || (i == 7 && k == 3) || (i == 7 && k == 4) ||
                         (i == 3 && k == 0) || (i == 3 && k == 7) || (i == 4 && k == 0) || (i == 4 && k == 7))
                    soma += 800;
                else if ((i == 1 && k == 3) || (i == 1 && k == 4) || (i == 6 && k == 3) || (i == 6 && k == 4) ||
                         (i == 3 && k == 1) || (i == 3 && k == 6) || (i == 4 && k == 1) || (i == 4 && k == 6))
                    soma = soma - 500;
                else if ((i == 1 && k == 2) || (i == 2 && k == 1) || (i == 1 && k == 5) || (i == 2 && k == 6) ||
                         (i == 5 && k == 1) || (i == 6 && k == 2) || (i == 5 && k == 6) || (i == 6 && k == 5))
                    soma = soma -450;
                else if ((i == 2 && k == 2) || (i == 2 && k == 5) || (i == 5 && k == 2) || (i == 5 && k == 5))
                    soma += 30;
                else if ((i == 2 && k == 3) || (i == 2 && k == 4) || (i == 5 && k == 3) || (i == 5 && k == 4) ||
                         (i == 3 && k == 2) || (i == 3 && k == 5) || (i == 4 && k == 2) || (i == 4 && k == 5))
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
                    //   *x = i;
                    //   *y = k;
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

                ESTADO *aux = malloc(sizeof(struct estado));
                copyEstado(e, aux);
                joga(aux, i, k);
         //       poepeca(aux, i, k);
                trocapeca(aux);
                temp = maxbot(aux,x,y);
                trocapeca(aux);
                if (temp <= min){
                    min = temp;
                    //  *x = i;
                    //  *y = k;
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


                ESTADO *aux = malloc(sizeof(struct estado));
                copyEstado(e, aux);
                joga(aux, i, k);
           //     poepeca(aux, i, k);
                trocapeca(aux);
                temp = minbot(aux, x, y);
                trocapeca(aux);
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