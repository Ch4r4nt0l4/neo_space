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
operacoes especificas do struct astronauta, como criação, 
verificação de codigo, atualização e exclusao*
11 * *
12 *************************************************/



#include "operacoes_astronautas.h"



void menu_astronautas(astronauta fila_astronautas[], int *inicio, int *fim){

    

    int opcao_selecionada; 
    astronauta novo_astronauta;

    printf("\n =========== Menu Astronautas ==========");
    printf("\n 1 - Contratar novo astronauta");
    printf("\n 2 - Atualizar dados de um astronauta");
    printf("\n 3 - Demitir astronauta");
    printf("\n 4 - Listar todos os astronautas");
    printf("\n 0 - Voltar ao menu principal");
    printf("\n Insira a opcao desejada:  "); 
    scanf("%d", &opcao_selecionada);

    while(opcao_selecionada != 0){

        switch (opcao_selecionada)
        {
        case 1:

            novo_astronauta = cadastrar_novo_astronauta(fila_astronautas, inicio, fim); 
            /* Contratar novo astronauta */
            contratar_astronauta(fila_astronautas, inicio, fim, novo_astronauta); 
            break;

        case 2: 
            atualizar_dados_astronauta(fila_astronautas, inicio, fim);
            break;

        case 3: 
            demitir_astronauta(fila_astronautas, inicio, fim);
            break;

        case 4: 

            imprime_lista_astronauta(fila_astronautas, *inicio, *fim);
        
        default:
            break;
        }

        printf("\n =========== Menu Astronautas ==========");
        printf("\n 1 - Contratar novo astronauta");
        printf("\n 2 - Atualizar dados de um astronauta");
        printf("\n 3 - Demitir astronauta");
        printf("\n 4 - Listar todos os astronautas");
        printf("\n 0 - Voltar ao menu principal");
        printf("\n Insira a opcao desejada:  "); 
        scanf("%d", &opcao_selecionada);

    }


}


astronauta cadastrar_novo_astronauta(astronauta fila_astronauta[], int *inicio, int *fim){


    astronauta novo_astronauta;
    int verificador; 

    printf("\n Insira o codigo do astronauta: ");
    scanf("%d", &novo_astronauta.codigo);
    printf("\n Insira o nome do Astronauta: ");
    scanf(" %[^\n]", novo_astronauta.nome);
     printf("\n Insira a especialidade do astronauta: ");
    scanf(" %[^\n]", novo_astronauta.especialidade);
   

   


    verificador = verifica_codigo_astronaura(fila_astronauta, novo_astronauta.codigo, *inicio, *fim);

    if(verificador != 1){

        return novo_astronauta; 
    }

    printf("\n O codigo cadastrado ja existe!");
    novo_astronauta.codigo = -1;
    return novo_astronauta; 
}


void contratar_astronauta(astronauta fila_astronauta[], int *inicio, int *fim, astronauta novo_astronauta){

   

    if(*fim != *inicio || *fim == -1){

        if(*fim == -1 ){

            *inicio = 0;
            *fim = 0; 
        }

        fila_astronauta[*fim].codigo = novo_astronauta.codigo;
       

        strcpy(fila_astronauta[*fim].nome, novo_astronauta.nome);
        strcpy(fila_astronauta[*fim].especialidade, novo_astronauta.especialidade);

        *fim = (*fim + 1) % MAX_ASTRONAUTAS;

    } else{

        printf("\n A Folha de pagamento ja esta lotada!"); 
    }


}


void atualizar_dados_astronauta(astronauta fila_astronauta[], int *inicio, int *fim){

    int codigo_astronauta, tamanho_fila, i;
    char dado_atualizado;
    char nome[50], especialidade[15];
    

    astronauta aux;

    printf("\n ========== Atualizar dados do Astronauta ==========\n");
    printf("Digite o codigo do astronauta que deseja atualizar: ");
    scanf("%d", &codigo_astronauta);

    printf("\nDigite 'N' para atualizar o NOME ou 'E' para a ESPECIALIDADE: ");
    scanf(" %c", &dado_atualizado);  


    if(verifica_codigo_astronaura(fila_astronauta, codigo_astronauta, *inicio, *fim) == 1){

         tamanho_fila = tamanho_fila_astronauta(inicio, fim);

          for (i = 0; i < tamanho_fila; i++) {

             aux = seleciona_astronauta_para_missao(fila_astronauta, inicio, fim);

             if (aux.codigo == codigo_astronauta && (dado_atualizado == 'N' || dado_atualizado == 'n' )) {

                printf("\nDigite o NOVO nome: ");
                scanf(" %[^\n]", nome); 
                strcpy(aux.nome, nome);

            } else if ( aux.codigo == codigo_astronauta && (dado_atualizado == 'E' || dado_atualizado == 'e')) {

                printf("\nDigite a nova ESPECIALIDADE: ");
                scanf(" %[^\n]", especialidade);
                strcpy(aux.especialidade, especialidade);
            }


             contratar_astronauta(fila_astronauta, inicio, fim, aux);

          
        } 

       

    } else{

        printf("\nNenhum astronauta com esse codigo foi encontrado!\n");


    }


    }



astronauta seleciona_astronauta_para_missao(astronauta fila_astronauta[], int *inicio, int *fim){

    astronauta astronauta_escolhido; 


    astronauta_escolhido.codigo = -1;

    if(*inicio != -1){

        astronauta_escolhido.codigo = fila_astronauta[*inicio].codigo;
        
        strcpy(astronauta_escolhido.nome, fila_astronauta[*inicio].nome);
        strcpy(astronauta_escolhido.especialidade, fila_astronauta[*inicio].especialidade);

        *inicio = (*inicio + 1) % MAX_ASTRONAUTAS;

        if(*inicio == *fim){

            *inicio = -1;
            *fim = -1;
        }

       
       
    } else{

        printf("\n Nao existem astronautas disponiveis");

        
    }

    return astronauta_escolhido; 
}

int verifica_codigo_astronaura(astronauta fila_astronauta[], int codigo, int inicio, int fim){

    int i;

    i = inicio; 

    while(i != fim){

        if(fila_astronauta[i].codigo == codigo){ /*Encontrei o codigo*/

            return 1;


        }

        i = (i + 1) % MAX_ASTRONAUTAS;
    }

     return 0; /*percorrri tudo e nao encontrei*/

}


void imprime_lista_astronauta(astronauta fila_astronauta[], int inicio, int fim){

    int i;

    i = inicio;

    printf("\n ========== Lista de astronautas ==========");

    while(i != fim){



        printf("\n -----------------------------------");
        printf("\n Codigo: %d", fila_astronauta[i].codigo);
        printf("\n Nome: %s", fila_astronauta[i].nome);
        printf("\n Especialidade: %s", fila_astronauta[i].especialidade);
        printf("\n -----------------------------------");

        i = (i + 1) % MAX_ASTRONAUTAS;
    }

}

void demitir_astronauta(astronauta fila_astronauta[], int *inicio, int *fim ){

    int codigo_astronauta_demitido, verificador_codigo, tamanho_fila, i; 
    astronauta auxiliar; 
   
    printf("\n ==========Demitir Astronauta==========");
    printf("\n Informe o codigo do astronauta");
    scanf("%d", &codigo_astronauta_demitido);

    verificador_codigo = verifica_codigo_astronaura( fila_astronauta, codigo_astronauta_demitido, *inicio, *fim);

    if(verificador_codigo == 1){

        tamanho_fila = tamanho_fila_astronauta(inicio, fim);

        for(i = 0; i < tamanho_fila; i++){

            auxiliar = seleciona_astronauta_para_missao(fila_astronauta, inicio, fim);

            if(auxiliar.codigo == codigo_astronauta_demitido){

                printf("\n--------------------------------------------------");
                printf("\n O astronauta %s foi desligado da Neo Space", auxiliar.nome);
                printf("\n Especialidade: %s", auxiliar.especialidade);
                i = tamanho_fila;



            } else{

                 contratar_astronauta(fila_astronauta, inicio, fim, auxiliar);
            }


        }




    } else{

        printf("\n O codigo informado nao existe!");
    }


}
int tamanho_fila_astronauta(int *inicio, int *fim){

    if(*inicio == -1){

        return 0;
    }

    if(*fim >= *inicio){

        return *fim - *inicio +1;
    }

    return (MAX_ASTRONAUTAS - *inicio) + (*fim + 1);
}

void salva_astronautas_arquivo(astronauta fila_astronauta[], int *inicio, int *fim) {

    FILE *arquivo;
    int i;

    arquivo = fopen("astronautas.txt", "w");

    if (arquivo != NULL) {

        if (*fim != -1) {  

            i = *inicio;

            while (1) {

                fprintf(arquivo, "%d, %s, %s\n",
                        fila_astronauta[i].codigo,
                        fila_astronauta[i].nome,
                        fila_astronauta[i].especialidade);

                if (i == *fim) {
                    break; 
                }

                i = (i + 1) % MAX_ASTRONAUTAS;
            }
        }

        printf("\n Astronautas salvos com sucesso!");
        fclose(arquivo);

    } else {
        printf("\n ERRO na abertura do arquivo!");
    }
}

void busca_astronautas_arquivo(astronauta fila_astronauta[], int *inicio, int *fim) {

    FILE *arquivo;
    astronauta novo;

    arquivo = fopen("astronautas.txt", "r");

    if (arquivo != NULL) {

        *inicio = -1; 
        *fim = -1;   


        
        while (fscanf(arquivo,
                      " %d, %49s, %29s",
                      &novo.codigo,
                      novo.nome,
                      novo.especialidade) == 3) {

                       
            
            contratar_astronauta(fila_astronauta, inicio, fim, novo);
        }

        fclose(arquivo);
        printf("\n Astronautas carregados com sucesso!");

    } else {
        printf("\n ERRO na abertura do arquivo!");
    }
}


