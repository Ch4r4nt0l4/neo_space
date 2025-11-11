

#include <stdio.h> 
#include <stdlib.h>

#include "operacoes_gerais.h"










int main(void){

    asteroide cabeca_asteroide,  *lista_asteroides;
    missao cabeca_missao, *lista_missoes;

    cabeca_asteroide.prox = NULL; 
    cabeca_missao.prox = NULL;

    lista_asteroides = &cabeca_asteroide; 
    lista_missoes = &cabeca_missao;
    
    busca_asteroides_arquivo(lista_asteroides);
    init2(); 
    menu_principal(lista_asteroides, lista_missoes);

}
