#include <stdio.h>
#include <stdlib.h>
#include "operacoes_asteroide.h"
#include "operacoes_missoes.h"


void init2(void);
void menu_principal(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[], int  *inicio, int *fim);
void lancar_missao(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[],  int *inicio, int *fim);
void lancamento(void);
void encerrar_missao(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[],  int *inicio, int *fim);
