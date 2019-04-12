#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
int main() {
    char c1;
    char linha[50];
    int x, y;
    int contaX=2,contaO=2;
    int resultado = 0;
    int state = 0;
    ESTADO *e = malloc(sizeof(struct estado));

        do {
            if (e->peca == VAZIA) printf("Reversi ? => ");
            else if (e->peca == VALOR_O) printf("Reversi O => ");
            else printf("Reversi X => ");

            fgets(linha, 50, stdin);
            switch (toupper(linha[0])) {
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
                case 'E' : {
                    if (state == 1) guardajogo(e, linha);
                    break;
                }
                case 'J' : {
                    if (state == 1 && resultado == 0) {
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
                                poepeca(e, x - 1, y - 1);
                                printa(*e, &contaX, &contaO);
                                printf("\n#X = %d   #O = %d\n", contaX, contaO);
                                trocapeca(e);

                                if (!playerPlayable(e)) {
                                    if (e->peca == VALOR_X) printf("Jogador X sem jogadas válidas!\n");
                                    else printf("Jogador O sem jogadas válidas!\n");
                                    trocapeca(e);
                                }
                            } else printf("Jogada inválida. Introduza uma jgoada válida.\n");
                        resultado = gameOver(e, &contaX, &contaO);
                        }
                        else printf("Jogo ainda não criado // N <peça>\n");
                    }
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
                    break;
                }
            }
        } while (toupper(linha[0] != 'Q'));
    }
