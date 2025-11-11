
#include "operacoes_missoes.h"

void menu_missoes(missao *lista_missoes){

    int opcao_selecionada; 
    missao nova_missao; 

    printf("=============== Menu de Missoes =============== \n");
    printf("1 - Planejar nova missao \n");
    printf("2 - Atualizar missao \n");
    printf("3 - Excluir missao\n");
    printf("0 - Voltar ao menu principal \n");
    printf("Informe o numero da opcao desejada: ");
    scanf("%d", &opcao_selecionada);

    while (opcao_selecionada != 0 ) {

        switch (opcao_selecionada)
        {
        case 1:
            /* Função para planejar nova missão*/
            printf(" Planejar nova missao selecionado\n");
            nova_missao = cria_nova_missao();
            insere_missao_ordenada(lista_missoes, nova_missao);
            break;

        case 2:
            /* Função para atualizar missão */
            printf(" Atualizar missao selecionado\n");
            break;
        case 3:
            /* Função para excluir missão */
            printf(" Excluir missao selecionado\n");
            excluir_missao(lista_missoes);
            break;              

        
        default:
            printf("\n Opcao invalida, tente novamente!");
            break;
        }

        printf("=============== Menu de Missoes =============== \n");
        printf("1 - Planejar nova missao \n");
        printf("2 - Atualizar missao \n");
        printf("3 - Excluir missao\n");
        printf("0 - Voltar ao menu principal \n");
        printf("Informe o numero da opcao desejada: ");
        scanf("%d", &opcao_selecionada);

    }

}


void insere_missao_ordenada(missao *lista_missoes, missao nova_missao){

    missao *p, *novo_elemento; 

    novo_elemento = (missao*) malloc (sizeof(missao));

    if(novo_elemento != NULL){

        novo_elemento->codigo_missao = nova_missao.codigo_missao;
        novo_elemento->prioridade = nova_missao.prioridade;
        novo_elemento->duracao_dias = nova_missao.duracao_dias;
        novo_elemento->qtd_tripulantes = nova_missao.qtd_tripulantes;
        strcpy(novo_elemento->nome_missao, nova_missao.nome_missao);
        strcpy(novo_elemento->data_lancamento, nova_missao.data_lancamento);
        /* Copiar tripulantes se necessário */

        p = lista_missoes;

        while(p->prox != NULL && p->prox->prioridade <= nova_missao.prioridade){

            p = p->prox; 
        }

        novo_elemento->prox = p->prox; 
        p->prox = novo_elemento; 

    } else{

        printf("\n Erro ao alocar memoria para nova missao!");

    }

}
missao cria_nova_missao(void){

    missao nova_missao; 

    printf("\n Informe o codigo da missao: ");
    scanf("%d", &nova_missao.codigo_missao);

    printf("\n Informe o nome da missao: ");
    scanf(" %[^\n]", nova_missao.nome_missao);

    printf("\n Informe a prioridade da missao (1- alta, 2- media, 3- baixa): ");
    scanf("%d", &nova_missao.prioridade);

    printf("\n Informe a data de lancamento (DD/MM/AAAA): ");
    scanf(" %[^\n]", nova_missao.data_lancamento);

    printf("\n Informe a duracao em dias da missao: ");
    scanf("%d", &nova_missao.duracao_dias);

    printf("\n Informe a quantidade de tripulantes: ");
    scanf("%d", &nova_missao.qtd_tripulantes);

    /*Aqui poderia haver código para inserir os tripulantes, se necessário*/

     return nova_missao;


}   

void imprime_lista_missoes(missao *lista_missoes){

    missao *p; 

    p = lista_missoes->prox; 

    printf("\n ======== Lista de Missoes ======== \n");

    while (p != NULL){

        printf("Codigo Missao: %d\n", p->codigo_missao);
        printf("Nome Missao: %s\n", p->nome_missao);
        printf("Prioridade: %d\n", p->prioridade);
        printf("Data Lancamento: %s\n", p->data_lancamento);
        printf("Duracao (dias): %d\n", p->duracao_dias);
        printf("Quantidade Tripulantes: %d\n", p->qtd_tripulantes);
        printf("-------------------------------\n");

        p = p->prox;
    }
    
}

int verifica_codigo_missao(missao *lista_missoes, int codigo_inserido){

    missao *p; 

    p = lista_missoes->prox; 

    while (p != NULL){

        if(p->codigo_missao == codigo_inserido){

            return -1; 
        }

        p = p->prox;
    }

    return 0;
    
}

/* adicionar uma função para atualizar missão */

missao excluir_missao(missao *lista_missoes){

    int codigo_missao; 
    missao *p, *q, celula_removida;

    q = lista_missoes;
    p = lista_missoes->prox;

    printf("\n==========EXCLUIR MISSAO==========");
    printf("\n Informe o codigo da missao: ");
    scanf("%d", &codigo_missao);
    
    
    while (p != NULL){

        if(p->codigo_missao == codigo_missao){

            celula_removida = *p; 
            q->prox = p->prox; 
            free(p);
        }

        q = p;
        p = p->prox; 

    }

    return celula_removida;

}

void salva_missoes_arquivo(missao *lista_missoes){

    FILE *arquivo;
    missao *p;

    arquivo = fopen("missoes.txt", "w");

    p = lista_missoes->prox; 

    if(arquivo != NULL){

         while(p != NULL){

             fprintf(arquivo, " %d, %s, %d, %s, %d, %d\n", p->codigo_missao, p->nome_missao, p->prioridade, p->data_lancamento, p->duracao_dias, p->qtd_tripulantes ); 
             p = p->prox;
         }

          printf("\n Missoes salvas com sucesso!");

          fclose(arquivo);

    } else{ 

        printf("\n ERRO na abertura do arquivo");
    }

}

void busca_missoes_arquivo(missao *lista_missoes){

    FILE *arquivo;
    missao nova_missao; 

    arquivo = fopen("missoes.txt", "r");

    if(arquivo != NULL){

         while(fscanf(arquivo, " %d, %49[^,], %d, %10[^,], %d, %d\n", &nova_missao.codigo_missao, nova_missao.nome_missao, &nova_missao.prioridade, nova_missao.data_lancamento, &nova_missao.duracao_dias, &nova_missao.qtd_tripulantes) != EOF){

             insere_missao_ordenada(lista_missoes, nova_missao);
         }

          printf("\n Missoes carregadas com sucesso!");

          fclose(arquivo);

    } else{ 

        printf("\n ERRO na abertura do arquivo");
    }

}


/* Lançar missão  */

