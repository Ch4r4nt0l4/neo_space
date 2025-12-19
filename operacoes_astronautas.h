#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_ASTRONAUTAS 40 

struct astronauta{

    int codigo; 
    char nome[50];
    char especialidade[30]; 
    
};

typedef struct astronauta astronauta; 

void menu_astronautas(astronauta fila_astronautas[], int *inicio, int *fim);
astronauta cadastrar_novo_astronauta(astronauta fila_astronauta[], int *inicio, int *fim);
void contratar_astronauta(astronauta fila_astronauta[], int *inicio, int *fim, astronauta novo_astronauta);
int verifica_codigo_astronaura(astronauta fila_astronauta[], int codigo, int inicio, int fim);
void imprime_lista_astronauta(astronauta fila_astronauta[], int inicio, int fim); 
astronauta seleciona_astronauta_para_missao(astronauta fila_astronauta[], int *inicio, int *fim);
int tamanho_fila_astronauta(int *inicio, int *fim);
void demitir_astronauta(astronauta fila_astronauta[], int *inicio, int *fim );
void salva_astronautas_arquivo(astronauta fila_astronauta[], int *inicio, int *fim);
void busca_astronautas_arquivo(astronauta fila_astronauta[], int *inicio, int *fim);
void atualizar_dados_astronauta(astronauta fila_astronauta[], int *inicio, int *fim);
