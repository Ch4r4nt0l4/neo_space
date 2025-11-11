

#include <stdio.h> 
#include <stdlib.h>

#define QTD_MAX_MINERIOS 18

struct minerio{

    int codigo_minerio;
    char nome_minerio[50];
    int quantidade_minerio;
};

typedef struct minerio minerio;

struct asteroide{

    int codigo; 
    float distancia; 
    int diametro;
    int qtd_minerios;
    minerio minerios[QTD_MAX_MINERIOS];
    struct asteroide *prox; 
    
};

typedef struct asteroide asteroide; 

/* funcoes*/
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
