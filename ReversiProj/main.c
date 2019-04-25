#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
#include "botfunction.h"
int main() {
    char c1,c2;
    char linha[50];
    int x, y;
    int contaX=2,contaO=2;
    int resultado = 0;
    int state = 0;
    int line,col;
    int nivel = 0;
    VALOR piece = VAZIA; // auxiliar p/ bot
    ESTADO *e = malloc(sizeof(struct estado));

        do {
            if (e->peca == VAZIA) printf("Reversi ? => ");
            else if (e->peca == VALOR_O) printf("Reversi O => ");
            else printf("Reversi X => ");

            fgets(linha, 50, stdin);
            switch (toupper(linha[0])) {
                case 'T' :
                {
                    sscanf(linha,"%c %c %d",&c1,&c2,&nivel);
                    if (nivel < 1);
                    else {
                        novoEstado(e, linha);
                        piece = e->peca;
                        state = 1;
                        resultado = 0;
                        e->modo = 3;
                        e->nivel = nivel;
                    }
                    break;
                }
                case '?' :
                    {
                        interface ();
                        break;
                }
                case 'N' :
                    { // cria novo jogo
                    novoEstado(e,linha);
                    state = 1;
                    resultado = 0;
                    break;
                }
                case 'A' : {
                    sscanf(linha,"%c %c %d",&c1,&c2,&nivel);
                    if (nivel < 1);
                    else {
                        novoEstado(e, linha);
                        piece = e->peca;
                        state = 1;
                        resultado = 0;
                        e->modo = 1;
                        e->nivel = nivel;
                    }
                    break;
                }
                case 'E' : {
                    if (state == 1) guardajogo(e, linha);
                    break;
                }
                case 'J' : {
                    if (state == 1 && resultado == 0) {


                        // modo manual-automatico
                        if (e->modo == 0 || e->modo == 1) {
                            if (e->peca != VAZIA) {
                                sscanf(linha, "%c %d %d", &c1, &x, &y);
                                if (verificajogada(e, x - 1, y - 1)) {

                                    //avançar o estado
                                    ESTADO *aux = malloc(sizeof(struct estado));

                                    copyEstado(e, aux);
                                    aux->ant = e;
                                    e = aux;
                                    // -----------
                                    joga(e, x - 1, y - 1);
                                    printa(*e, &contaX, &contaO);
                                    printf("\n#X = %d   #O = %d\n", contaX, contaO);

                                    if (!oppPlayable(e) && playerPlayable(e)) {
                                        if (e->peca == VALOR_X) printf("Jogador O sem jogadas válidas!\n");
                                        else printf("Jogador X sem jogadas válidas!\n");
                                    } else if (oppPlayable(e)) trocapeca(e);
                                    else resultado = gameOver(e, &contaX, &contaO);


                                } else printf("Jogada inválida. Introduza uma jgoada válida.\n");
                                // modo automático
                                if (resultado == 0) {
                                    if (e->modo == 1 && piece != e->peca) { // é certo que o bot pode jogar
                                        do {
                                            // as funções do bot vão aqui
                                            printf("%d\n",
                                                   maxplay(e, &line, &col, 2 * nivel + 1, 2 * nivel +
                                                                                          1)); // a line e a col ficam com as posições onde deve jogar

                                            joga(e, line, col);
                                            printa(*e, &contaX, &contaO);
                                            printf("\n#X = %d   #O = %d\n", contaX, contaO);

                                        } while (!oppPlayable(e) && playerPlayable(e));
                                        if (oppPlayable(e)) trocapeca(e);
                                        else resultado = gameOver(e, &contaX, &contaO);

                                        // -----------------
                                        // se o jogador não puder jogar

                                    }
                                }
                            }
                            // ---------------------------------------------------------------

                        }
                        else if (e->modo == 3) {
                            do {
                                if (!playerPlayable(e) && oppPlayable(e)) {
                                    if (e->peca == VALOR_X) printf("Jogador X sem jogadas válidas!\n");
                                    else printf("Jogador O sem jogadas válidas!\n");
                                    trocapeca(e);
                                } else if (playerPlayable(e)) {
                                    do {
                                        // as funções do bot vão aqui
                                        printf("%d\n",
                                               maxplay(e, &line, &col, 2 * nivel + 1, 2 * nivel + 1)); // a line e a col ficam com as posições onde deve jogar

                                        joga(e, line, col);
                                        printa(*e, &contaX, &contaO);
                                        printf("\n#X = %d   #O = %d\n", contaX, contaO);

                                    } while (playerPlayable(e) && !oppPlayable(e));
                                    if (oppPlayable(e)) trocapeca(e);
                                    else resultado = gameOver(e, &contaX, &contaO);

                                    // -----------------
                                    // se o jogador não puder jogar

                                }
                            }while (resultado == 0);
                        }
                    }
                    else printf("Jogo ainda não criado // N <peça>\n");
                    break;
                }

                case 'P' : {
                    if (state == 1) {
                        printa(*e, &contaX, &contaO);
                        printf("\n#X = %d   #O = %d\n", contaX, contaO);
                    } else printf("Jogo ainda não criado // N <peça>\n");
                    break;
                }
                case 'S' : { // coloca pontos nos sítios de jogadas válidas
                    if (state == 1) whereCanIPut(e);
                    else printf("Jogo ainda não criado // N <peça>\n");
                    break;
                }
                case 'U' : { // desfaz a jogada anterior
                    if (state == 1) {
                        if (e->ant == NULL);
                        else {
                            ESTADO *aux;
                            aux = e;
                            e = e->ant;
                            free(aux);
                            resultado = 0;
                        }
                    }
                    else printf("Jogo ainda não criado // N <peça>\n");
                    break;
                }

                case 'H' : { // coloca pontos de interrogação em locais sugeridos para jogar
                    if (state != 1) printf("Jogo ainda não criado // N <peça>\n");
                    else if (playerPlayable(e)) giveHint(e);
                    else printf("Jogador sem jogadas válidas");
                    break;
                }
                case 'L' :
                    {
                    readGame(e,linha);
                    piece = e->peca;
                    state = 1;
                    resultado = gameOver(e, &contaX, &contaO);;
                    break;
                }
            }
        } while (toupper(linha[0] != 'Q'));
    }
