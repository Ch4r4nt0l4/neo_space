/************************************************
2 * *
3 * Nome do(a) estudante: Willian Charantola da Costa*
4 * Trabalho Prático *
5 * Disciplinas: Algoritmos e Programação II *
6 * Laboratório de Algoritmos e Programação II *
7 * Professores: Ivone e Ronaldo *
8 * Data: 14/11/2025 *
9 * Versão:   *
10 * Descrição: Nesse arquivo sao realizadas todas as 
operacoes especificas do struct missao, como criação, 
verificação de codigo, atualização e exclusao *
11 * *
12 *************************************************/

#include "operacoes_missoes.h"

void menu_missoes(missao *lista_missoes){

    int opcao_selecionada; 
    missao nova_missao; 

    printf("=============== Menu de Missoes =============== \n");
    printf("1 - Planejar nova missao \n");
    printf("2 - Atualizar missao \n");
    printf("3 - Excluir missao\n");
    printf("4 - Listar todas as missoes\n");
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
            
        case 4: 

           imprime_lista_missoes(lista_missoes);
           break;

        
        default:
            printf("\n Opcao invalida, tente novamente!");
            break;
        }

        printf("=============== Menu de Missoes =============== \n");
        printf("1 - Planejar nova missao \n");
        printf("2 - Atualizar missao \n");
        printf("3 - Excluir missao\n");
        printf("4 - Listar todas as missoes\n");
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
        
        strcpy(novo_elemento->nome_missao, nova_missao.nome_missao);
        
        strcpy(novo_elemento->status_missao, nova_missao.status_missao);
    
       

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

    printf("\n Informe a prioridade da missao (De 1 a 10): ");
    scanf("%d", &nova_missao.prioridade);

    printf("\n Informe a duracao em dias da missao: ");
    scanf("%d", &nova_missao.duracao_dias);

    strcpy(nova_missao.status_missao, "Montagem");

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
        printf("Duracao (dias): %d\n", p->duracao_dias);
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

    int codigo_missao, verificador; 
    missao *p, *q, celula_removida;


    q = lista_missoes;
    p = lista_missoes->prox;

    printf("\n==========EXCLUIR MISSAO==========");
    printf("\n Informe o codigo da missao: ");
    scanf("%d", &codigo_missao);

    verificador = verifica_codigo_missao(lista_missoes, codigo_missao);
     
    

    if(verificador != 0){ 


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

        
    } else{

        printf("\n A missao informada nao existe!"); 
        celula_removida.codigo_missao = -1;
        return celula_removida;
    }
    
    

}


void salva_missoes_arquivo(missao *lista_missoes){

    FILE *arquivo;
    missao *p;
    int i;

    arquivo = fopen("missoes.txt", "w");

    if(arquivo != NULL){

        p = lista_missoes->prox; 

        while(p != NULL){

            fprintf(arquivo, "%d, %s, %s, %d, %d\n",
                    p->codigo_missao,
                    p->nome_missao,
                    p->status_missao,
                    p->prioridade,
                    p->duracao_dias);
            
            for (i = 0; i < QTD_MAX_TRIPULANTES; i++) {
                fprintf(arquivo, "%d %s %s\n",
                        p->tripulantes[i].codigo,
                        p->tripulantes[i].nome,
                        p->tripulantes[i].especialidade); 
            }

            p = p->prox;
        }

        printf("\n Missoes salvas com sucesso!");
        fclose(arquivo);

    } else { 
        printf("\n ERRO na abertura do arquivo");
    }
}



void busca_missoes_arquivo(missao *lista_missoes) {

    FILE *arquivo;
    missao nova_missao; 
    int i;
    int lidos;

    arquivo = fopen("missoes.txt", "r");

    if (arquivo != NULL) {

        /* 
           Lê enquanto conseguir ler TODAS as 5 informações do cabeçalho.
           fscanf retorna a quantidade de itens convertidos com sucesso.
        */
        while ( (lidos = fscanf(arquivo,
                                " %d, %49s, %9s, %d, %d",
                                &nova_missao.codigo_missao,
                                nova_missao.nome_missao,
                                nova_missao.status_missao,
                                &nova_missao.prioridade,
                                &nova_missao.duracao_dias)) == 5 ) {

            /* Lê os QTD_MAX_TRIPULANTES tripulantes */
            for (i = 0; i < QTD_MAX_TRIPULANTES; i++) {

                lidos = fscanf(arquivo,
                               " %d %49s %49s",
                               &nova_missao.tripulantes[i].codigo,
                               nova_missao.tripulantes[i].nome,
                               nova_missao.tripulantes[i].especialidade);

                if (lidos != 3) {
                    printf("\nERRO: Ao ler tripulantes.\n");
                    fclose(arquivo);
                    return;
                }
            }

            nova_missao.prox = NULL;
            insere_missao_ordenada(lista_missoes, nova_missao);
        }

        /* Se saiu do while por EOF (lidos == EOF), tudo bem.
           Se saiu por lidos != 5 e != EOF, o arquivo estava mal formatado. 
        */

        printf("\n Missoes carregadas com sucesso!");
        fclose(arquivo);

    } else { 
        printf("\n ERRO na abertura do arquivo");
    }
}



/*essa funcao procura a missao com base no status e retorna o ponteiro para ela*/
missao *procura_missao(missao *lista_missao, char parametro_busca[]){

    missao *missao_selecionada, *p;
    
    p = lista_missao; 

    while(p != NULL){

        if( strcmp(p->status_missao, parametro_busca) == 0){

            missao_selecionada = p;
            return missao_selecionada; 
        }

        p = p->prox; 
    }

    return NULL; 


}

