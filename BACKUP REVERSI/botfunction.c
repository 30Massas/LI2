#include "estado.h"

int contaPontos (ESTADO *e,int x, int y) {
    int soma = 0;
    int i, k;
    int pontos[8][8]= { {1000, -300, 100, 80,   80,    100, -300,  1000},
                        {-300, -500, -45, -50, -50,    -45, -500,  -300},
                        {100,  -45,  3,   1,    1,      3,  -45,   100},
                        {80,   -50,  1,   5,    5,      1,  -50,   80},
                        {80,   -50,  1,   5,    5,      1,  -50,   80},
                        {100,  -45,  3,   1,    1,      3,  -45,   100},
                        {-300, -500, -45, -50, -50,    -45, -500,  -300},
                        {1000, -300, 100, 80,   80,    100, -300,  1000}};
    // cria um estado auxiliar e simula as peças alteradas
    ESTADO *aux = malloc(sizeof(struct estado));
    copyEstado(e, aux);
    joga(aux, x, y);
    int flag = 1;

    // ----------------------------


    // dependendo das posições em que se encontram as suas peças, é feito um somatório
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) soma+= pontos[i][k];
        }
    }


    for (i=0,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 8000;

    flag = 1;

    for (i=7,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 8000;

    flag = 1;

    for (i=0,k=0;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 8000;
    flag = 1;

    for (i=0,k=7;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma+= 8000;

    flag = 1;


    //troca peça
    if (aux->peca == VALOR_X) aux->peca = VALOR_O;
    else aux->peca = VALOR_X;




    for (i = 0; i < 8; i++) {
        for (k = 0; k < 8; k++) {
            if (aux->grelha[i][k] == aux->peca) soma -= pontos[i][k];
        }
    }


    for (i=0,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 8000;
    flag = 1;

    for (i=7,k=0;k<8;k++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 8000;
    flag = 1;

    for (i=0,k=0;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 8000;
    flag = 1;

    for (i=0,k=7;i<8;i++) {
        if (aux->grelha[i][k] != aux->peca) flag = 0;
    }
    if (flag == 1) soma-= 8000;


    free(aux);
    return soma;
}


int maxplay (ESTADO *e, int *x, int *y,int nivel, int orig) {
    int result;
    if (nivel <= 0);
    else if (nivel == 1) {
        int i, k;
        int temp, max = -999999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (e->validade[i][k]) {
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
        int temp, min = 999999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (e->validade[i][k]){

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
        int temp, max = -999999;
        for (i = 0; i < 8; i++) {
            for (k = 0; k < 8; k++) {
                if (e->validade[i][k]) {


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