#include "estado.h"

int contaPontos (ESTADO *e,int x, int y) {
    int soma = 0;
    int i, k;
    // cria um estado auxiliar e simula as peças alteradas
    ESTADO *aux = malloc(sizeof(struct estado));
    copyEstado(e, aux);
    joga(aux, x, y);
    int flag = 1;
    // ----------------------------


    // dependendo das posições em que se encontram as suas peças, é feito um somatório
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) {
                if ((i == 0 || i == 7) && (k == 0 || k == 7)) soma += 10000;
                else if ((i == 1 && k == 1) || (i == 1 && k == 6) || (i == 6 && k == 1) || (i == 6 && k == 6)) soma -= 5000;
                else if ((i == 1 && k == 0) || (i == 0 && k == 1) || (i == 0 && k == 6) || (i == 1 && k == 7) || (i == 6 && k == 0) || (i == 7 && k == 1) || (i == 6 && k == 7) || (i == 7 && k == 6))
                    soma -= 3000;
                else if ((i == 0 && k == 2) || (i == 0 && k == 5) || (i == 7 && k == 2) || (i == 7 && k == 5) ||
                         (i == 2 && k == 0) || (i == 2 && k == 7) || (i == 5 && k == 0) || (i == 5 && k == 7))
                    soma += 1000;
                else if ((i == 0 && k == 3) || (i == 0 && k == 4) || (i == 7 && k == 3) || (i == 7 && k == 4) ||
                         (i == 3 && k == 0) || (i == 3 && k == 7) || (i == 4 && k == 0) || (i == 4 && k == 7))
                    soma += 800;
                else if ((i == 1 && k == 3) || (i == 1 && k == 4) || (i == 6 && k == 3) || (i == 6 && k == 4) ||
                         (i == 3 && k == 1) || (i == 3 && k == 6) || (i == 4 && k == 1) || (i == 4 && k == 6))
                    soma -= 500;
                else if ((i == 1 && k == 2) || (i == 2 && k == 1) || (i == 1 && k == 5) || (i == 2 && k == 6) ||
                         (i == 5 && k == 1) || (i == 6 && k == 2) || (i == 5 && k == 6) || (i == 6 && k == 5))
                    soma -= 450;
                else if ((i == 2 && k == 2) || (i == 2 && k == 5) || (i == 5 && k == 2) || (i == 5 && k == 5))
                    soma += 30;
                else if ((i == 2 && k == 3) || (i == 2 && k == 4) || (i == 5 && k == 3) || (i == 5 && k == 4) ||
                         (i == 3 && k == 2) || (i == 3 && k == 5) || (i == 4 && k == 2) || (i == 4 && k == 5))
                    soma += 10;
                else soma += 50;
            }
        }
    }
    for (i=0,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 100000;
    flag = 1;

    for (i=7,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 100000;
    flag = 1;

    for (i=0,k=0;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 100000;
    flag = 1;

    for (i=0,k=7;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 100000;
    flag = 1;
    trocapeca(aux);


    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) {
                if ((i == 0 || i == 7) && (k == 0 || k == 7)) soma -= 10000;
                else if ((i == 1 && k == 1) || (i == 1 && k == 6) || (i == 6 && k == 1) || (i == 6 && k == 6)) soma += 5000;
                else if ((i == 1 && k == 0) || (i == 0 && k == 1) || (i == 0 && k == 6) || (i == 1 && k == 7) || (i == 6 && k == 0) || (i == 7 && k == 1) || (i == 6 && k == 7) || (i == 7 && k == 6))
                    soma += 3000;
                else if ((i == 0 && k == 2) || (i == 0 && k == 5) || (i == 7 && k == 2) || (i == 7 && k == 5) ||
                         (i == 2 && k == 0) || (i == 2 && k == 7) || (i == 5 && k == 0) || (i == 5 && k == 7))
                    soma -= 1000;
                else if ((i == 0 && k == 3) || (i == 0 && k == 4) || (i == 7 && k == 3) || (i == 7 && k == 4) ||
                         (i == 3 && k == 0) || (i == 3 && k == 7) || (i == 4 && k == 0) || (i == 4 && k == 7))
                    soma -= 800;
                else if ((i == 1 && k == 3) || (i == 1 && k == 4) || (i == 6 && k == 3) || (i == 6 && k == 4) ||
                         (i == 3 && k == 1) || (i == 3 && k == 6) || (i == 4 && k == 1) || (i == 4 && k == 6))
                    soma += 500;
                else if ((i == 1 && k == 2) || (i == 2 && k == 1) || (i == 1 && k == 5) || (i == 2 && k == 6) ||
                         (i == 5 && k == 1) || (i == 6 && k == 2) || (i == 5 && k == 6) || (i == 6 && k == 5))
                    soma += 450;
                else if ((i == 2 && k == 2) || (i == 2 && k == 5) || (i == 5 && k == 2) || (i == 5 && k == 5))
                    soma -= 30;
                else if ((i == 2 && k == 3) || (i == 2 && k == 4) || (i == 5 && k == 3) || (i == 5 && k == 4) ||
                         (i == 3 && k == 2) || (i == 3 && k == 5) || (i == 4 && k == 2) || (i == 4 && k == 5))
                    soma -= 10;
                else soma -= 50;
            }
        }
    }


    for (i=0,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 100000;
    flag = 1;

    for (i=7,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 100000;
    flag = 1;

    for (i=0,k=0;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 100000;
    flag = 1;

    for (i=0,k=7;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 100000;
    trocapeca(aux);

    free(aux);
    return soma;
}

/*
int maxbot (ESTADO *e, int *x, int *y) {
    int i, k;
    int temp, max = -99999;
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (verificajogada(e, i, k)) {
                temp = contaPontos(e, i, k);
                if (temp >= max) {
                    max = temp;
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
                trocapeca(aux);
                temp = maxbot(aux,x,y);
                trocapeca(aux);
                if (temp <= min){
                    min = temp;
                }
            }
        }
    }
    return min;
}
*/


int maxplay (ESTADO *e, int *x, int *y,int nivel, int orig) {
    int result;
    if (nivel == 1) {
        int i, k;
        int temp, max = -99999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (verificajogada(e, i, k)) {
                    temp = contaPontos(e, i, k);
                    if (temp >= max) {
                        max = temp;
                        if (nivel == orig) {
                            *x = i;
                            *y = k;
                        }
                    }
                }
            }
        }
        result = max;
    }
    else if (nivel % 2 == 0) {
        int i,k;
        int temp, min = 99999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (verificajogada(e, i, k)){

                    ESTADO *aux = malloc(sizeof(struct estado));
                    copyEstado(e, aux);
                    joga(aux, i, k);
                    trocapeca(aux);
                    temp = maxplay(aux,x,y,nivel-1,orig);
                    trocapeca(aux);
                    if (temp <= min){
                        min = temp;
                        if (nivel == orig) {
                            *x = i;
                            *y = k;
                        }
                    }
                }
            }
        }
        result = min;
    }
    else {
        int i, k;
        int temp, max = -99999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (verificajogada(e, i, k)) {


                    ESTADO *aux = malloc(sizeof(struct estado));
                    copyEstado(e, aux);
                    joga(aux, i, k);
                    trocapeca(aux);
                    temp = maxplay(aux, x, y,nivel-1,orig);
                    trocapeca(aux);
                    if (temp >= max) {
                        max = temp;
                        if (nivel == orig) {
                            *x = i;
                            *y = k;
                        }
                    }
                }
            }
        }
        result = max;
    }


    return result;

}