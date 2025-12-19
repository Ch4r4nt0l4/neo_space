#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "operacoes_astronautas.h"


#define QTD_MAX_TRIPULANTES 3


struct missao{

    int codigo_missao; 
    char nome_missao[50];
    char status_missao[10];
    int codigo_asteroide; 
    int prioridade;
    int duracao_dias;
    astronauta tripulantes[QTD_MAX_TRIPULANTES];
    struct missao *prox; 
    
};

typedef struct missao missao;


void menu_missoes(missao *lista_missoes);
void insere_missao_ordenada(missao *lista_missoes, missao nova_missao);
missao cria_nova_missao(void);
void imprime_lista_missoes(missao *lista_missoes);
int verifica_codigo_missao(missao *lista_missoes, int codigo_inserido);
missao excluir_missao(missao *lista_missoes);
void salva_missoes_arquivo(missao *lista_missoes);
void busca_missoes_arquivo(missao *lista_missoes);
missao *procura_missao(missao *lista_missao, char parametro_busca[]);
