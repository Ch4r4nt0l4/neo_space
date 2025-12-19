

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#define QTD_MAX_MINERIOS 18

struct minerio{

    int codigo_minerio;
    char nome_minerio[50];
    int quantidade_minerio;
    struct minerio *prox; 
};

typedef struct minerio minerio;

struct asteroide{

    int codigo; 
    float distancia; 
    int diametro;
    int qtd_minerios;
    char status[10];
    minerio *lista_minerios; 
    struct asteroide *prox; 
    
};

typedef struct asteroide asteroide; 


void init2(void);
void menu_asteroides(asteroide *lista_asteroides);
void insere_asteroide(asteroide *lista_asteroide, asteroide novo_asteroide);
void imprime_lista_asteroides(asteroide *lista_asteroide);
int verifica_codigo_asteroide(asteroide *lista_asteroides, int codigo_inserido);
void atualiza_campos_asteroide(asteroide *lista_asteroides);
asteroide excluir_asteroide(asteroide *lista_asteroide);
void salva_asteroides_arquivo(asteroide *lista_asteroides);
void busca_asteroides_arquivo(asteroide *lista_asteroides);
asteroide cria_novo_asteroide(void);
minerio cria_novo_minerio(void);
void insere_minerio(asteroide *lista_asteroides, minerio novo_minerio);
asteroide* encontra_asteroide(asteroide *lista_asteroides, int codigo_inserido);
minerio* encontra_minerio(minerio *lista_minerios, int codigo_minerio);
void imprime_minerios(asteroide *asteroide_selecionado);
