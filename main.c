/************************************************
2 * *
3 * Nome do(a) estudante: Willian Charantola da Costa*
4 * Trabalho Prático *
5 * Disciplinas: Algoritmos e Programação II *
6 * Laboratório de Algoritmos e Programação II *
7 * Professores: Ivone e Ronaldo *
8 * Data: 14/11/2025 *
9 * Versão:   *
10 * Descrição: main *
11 * *
12 *************************************************/

#include <stdio.h> 
#include <stdlib.h>

#include "operacoes_gerais.h"










int main(void){

    asteroide cabeca_asteroide,  *lista_asteroides;
    missao cabeca_missao, *lista_missoes;
    astronauta fila_astronauta[MAX_ASTRONAUTAS]; 
    int inicio, fim;

    inicio = -1;
    fim = -1;

    cabeca_asteroide.prox = NULL; 
    cabeca_missao.prox = NULL;

    lista_asteroides = &cabeca_asteroide; 
    lista_missoes = &cabeca_missao;
    
    busca_asteroides_arquivo(lista_asteroides);
    busca_missoes_arquivo(lista_missoes);
    busca_astronautas_arquivo(fila_astronauta, &inicio, &fim);
    init2(); 
    menu_principal(lista_asteroides, lista_missoes, fila_astronauta, &inicio, &fim);

    return -1;
}
