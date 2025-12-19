/************************************************
2 * *
3 * Nome do(a) estudante: Willian Charantola da Costa*
4 * Trabalho Prático *
5 * Disciplinas: Algoritmos e Programação II *
6 * Laboratório de Algoritmos e Programação II *
7 * Professores: Ivone e Ronaldo *
8 * Data: 14/11/2025 *
9 * Versão:   *
10 * Descrição:Nesse arquivo sao realizadas todas as 
operacoes especificas do struct asteroide, como criação, 
verificação de codigo, atualização e exclusao*
11 * *
12 *************************************************/


#include <stdio.h> 
#include <stdlib.h>
#include "operacoes_asteroide.h"







void menu_asteroides(asteroide *lista_asteroides){

     int opcao_selecionada; 
     asteroide novo_elemento;
     minerio novo_minerio; 

    

    printf("\n=============== Menu Asteroides =============== \n");
    printf("1 - Inserir novo asteroide \n");
    printf("2 - Atualizar Asteroide \n");
    printf("3 - Excluir Asteroide\n");
    printf("4 - Listar Asteroides\n");
    printf("5 - Adicionar minerio a um asteroide \n");
    printf("0 - Voltar ao menu inicial \n");
    printf("Informe o numero da opcao desejada: ");
    scanf("%d", &opcao_selecionada);

    while (opcao_selecionada != 0 ) {


        switch (opcao_selecionada){

        case 1:

            printf(" Inserir asteroide selecionado\n");
            novo_elemento = cria_novo_asteroide();
            insere_asteroide(lista_asteroides, novo_elemento);
            break;

        case 2:

             printf(" Atualizar asteroide selecionado\n");
             atualiza_campos_asteroide(lista_asteroides);
             break;

        case 3:

             printf(" Excluir asteroide selecionado\n");
             excluir_asteroide(lista_asteroides);
             break;

        case 4: 

             imprime_lista_asteroides(lista_asteroides);
             break;

        case 5:

            novo_minerio = cria_novo_minerio();
            insere_minerio(lista_asteroides, novo_minerio);
            break;

        default:

            printf("\n Opcao invalida");
            break;

        }

         printf("\n=============== Menu Asteroides =============== \n");
         printf("1 - Inserir novo asteroide \n");
         printf("2 - Atualizar Asteroide \n");
         printf("3 - Excluir Asteroide\n");
         printf("4 - Listar Asteroides\n");
         printf("5 - Adicionar minerio a um asteroide \n");
         printf("0 - Voltar ao menu inicial \n");
         printf("Informe o numero da opcao desejada: ");
         scanf("%d", &opcao_selecionada);
    }
 
   
}


asteroide cria_novo_asteroide(void){

    asteroide novo_asteroide; 

    printf(" Insira Codigo, distancia, diametro do asteroide \n");
    scanf("%d %f %d", &novo_asteroide.codigo, &novo_asteroide.distancia, &novo_asteroide.diametro);
    strcpy(novo_asteroide.status, "Livre");
    return novo_asteroide; 


}

void insere_asteroide(asteroide *lista_asteroide, asteroide novo_asteroide){

      


      asteroide *p, *novo_elemento;
      int  verificador;
   


       printf(" ============== Inserir asteroide ==============\n");
       


       verificador = verifica_codigo_asteroide(lista_asteroide, novo_asteroide.codigo); 


       if(verificador != -1){


            novo_elemento = (asteroide*) malloc(sizeof(asteroide));

             p = lista_asteroide; 

             if(novo_elemento != NULL){

           



                 novo_elemento->codigo = novo_asteroide.codigo;
                 novo_elemento->diametro = novo_asteroide.diametro;
                 novo_elemento->distancia = novo_asteroide.distancia; 
                 novo_elemento->qtd_minerios = 0;
                 strcpy(novo_elemento->status, novo_asteroide.status); 
                 novo_elemento->lista_minerios = NULL;



                 novo_elemento->prox = p->prox; 
                 p->prox = novo_elemento; 

                 printf("Elemento adicionado com sucesso!\n");
     

              } else{

                 printf("ERRO: Elemento nao adicionado a lista!\n");

            }

      
       } else {

        printf("\n ERRO: O codigo informado ja existe!"); 
       }
}

minerio cria_novo_minerio(void){

     minerio novo_minerio;

      printf("\n Informe o codigo do minerio: ");
      scanf("%d", &novo_minerio.codigo_minerio);

       printf("\n Informe o nome do minerio: ");
       scanf("%s", novo_minerio.nome_minerio);

       printf("\n Informe a quantidade de minerio: ");
        scanf("%d", &novo_minerio.quantidade_minerio);

        return novo_minerio; 

}

void insere_minerio(asteroide *lista_asteroides,  minerio novo_minerio){

   

   
    minerio *novo_elemento;
    minerio *p, *verificador_minerio; 
    int codigo_asteroide; 
    asteroide *asteroide_encontrado; 

     printf("\n ========== Adicionar mais minerio==========");
  

    printf("\n Informe o codigo do asteroide: ");
    scanf("%d", &codigo_asteroide);


    asteroide_encontrado = encontra_asteroide(lista_asteroides, codigo_asteroide);

    

    if(asteroide_encontrado != NULL){

        if(strcmp(asteroide_encontrado->status, "Ocupado") == 0 ){


             p = asteroide_encontrado->lista_minerios; 
             verificador_minerio = encontra_minerio(p, novo_minerio.codigo_minerio); 

             if(verificador_minerio == NULL){

                 novo_elemento = (minerio*) malloc(sizeof(minerio));

                 if(novo_elemento != NULL){

                     novo_elemento->codigo_minerio = novo_minerio.codigo_minerio;
                     strcpy(novo_elemento->nome_minerio, novo_minerio.nome_minerio);
                     novo_elemento->quantidade_minerio = novo_minerio.quantidade_minerio;

                     /* insere no inicio da lista de minerios do asteroide */
                     novo_elemento->prox = asteroide_encontrado->lista_minerios;
                     asteroide_encontrado->lista_minerios = novo_elemento;

                     asteroide_encontrado->qtd_minerios++;

                     printf("\n Minerio adicionado com sucesso!");

                 } else{

                     printf("\n ERRO: Nao foi possivel alocar memoria para o novo minerio!");
                 }

                
             } else{

                printf("\n ERRO: O minerio informado ja existe!"); 
             }

        }else{

            printf("\n ERRO: Só é possivel adicionar minerio a um asteroide que esteja ocupado!");

        }


        


    } else{

        printf("\n O asteroide informado nao existe! Tente novamente");
    }

}

minerio* encontra_minerio(minerio *lista_minerios, int codigo_minerio){

    minerio *p; 

    p = lista_minerios; 

    while(p != NULL){

        if(p->codigo_minerio == codigo_minerio){

            return p; 
        }

        p = p->prox;
    }

    return NULL; 
}


/*Encontra o asteroide com base no codigo e retorna um ponteiro pra ele*/
asteroide* encontra_asteroide(asteroide *lista_asteroides, int codigo_inserido){

    asteroide *p; 

    p = lista_asteroides->prox; 

    while (p != NULL){

        if(p->codigo == codigo_inserido){

            return p;
        }

        p = p->prox;
    }

    return NULL;
    
}


void imprime_minerios(asteroide *asteroide_selecionado){

    minerio *p; 

    if(asteroide_selecionado != NULL){

          printf(" \n ==========================================");
          printf(" \n Codigo: %d", asteroide_selecionado->codigo);
          printf(" \n Distancia: %.2f", asteroide_selecionado->distancia);
          printf(" \n Diametro: %d", asteroide_selecionado->diametro);
          printf(" \n Status: %s", asteroide_selecionado->status);
          printf(" \n Quantidade de minerios: %d", asteroide_selecionado->qtd_minerios);

          p = asteroide_selecionado->lista_minerios;

    if (p == NULL){

        printf(" \n Nao ha minerios cadastrados neste asteroide.\n");

    } else{

        printf(" \n -------- Minerios cadastrados --------");

        while (p != NULL){

            printf(" \n Codigo do minerio: %d", p->codigo_minerio);
            printf(" \n Nome do minerio: %s", p->nome_minerio);
            printf(" \n Quantidade de minerio: %d", p->quantidade_minerio);
            printf(" \n --------------------------------------");

            p = p->prox;
        }

       
    }


    } else {

        printf("\n Asteroide Inexistente!");
    }
}



void imprime_lista_asteroides(asteroide *lista_asteroide){

    asteroide *p; 

    p = lista_asteroide->prox; 


    while (p != NULL) {
       
        printf(" \n =========================================="); 
        printf(" \n Codigo: %d", p->codigo);
        printf(" \n Distancia: %.2f", p->distancia);
        printf(" \n Diametro: %d", p->diametro); 

        p = p->prox;
    }
    
}


int verifica_codigo_asteroide(asteroide *lista_asteroides, int codigo_inserido){


    asteroide *p; 

    p = lista_asteroides->prox; 

    while (p != NULL){

        if(p->codigo == codigo_inserido){

            return -1; 
        }

        p = p->prox;
    }

    return 0;
    
}

void atualiza_campos_asteroide(asteroide *lista_asteroides){

    /* d para diametro e s para distancia */
    char campo_atualizado; 
    float distancia;  
    int diametro, codigo;
    asteroide *p; 

    p = lista_asteroides; 

    printf("\n Informe o codigo do asteroide a ser atualizado e o campo(d para diametro e s para distancia):");
    scanf("%d %c", &codigo, &campo_atualizado);

    switch (campo_atualizado){

    case 'd':
        printf("\n Infome o valor atualizado de diametro");
        scanf("%d", &diametro);

        while(p != NULL){

            if(p->codigo == codigo){

                p->diametro = diametro;
            }

            p = p->prox; 
        }

        break;

    case 's':
        printf("\n Infome o valor atualizado de distancia");
        scanf("%f", &distancia);

          while(p != NULL){

            if(p->codigo == codigo){

                p->distancia = distancia;
            }

             p = p->prox; 
        }
        
        break;
    
    default:

        printf("\n ERRO: Opcao invalida, tente novamente!");
        break;
    }
}



 asteroide excluir_asteroide(asteroide *lista_asteroide){

    int codigo_asteroide; 
    asteroide *p, *q, celula_removida;

    q = lista_asteroide;
    p = lista_asteroide->prox;

    printf("\n==========EXCLUIR ASTEROIDE==========");
    printf("\n Informe o codigo do asteroide: ");
    scanf("%d", &codigo_asteroide);
    
    
    while (p != NULL){

        if(p->codigo == codigo_asteroide){

            celula_removida = *p; 
            q->prox = p->prox; 
            free(p);
        }

        q = p;
        p = p->prox; 

    }


    
    return celula_removida; 

 }

void salva_asteroides_arquivo(asteroide *lista_asteroides){

    FILE *arquivo;
    asteroide *p;
    minerio *m;

    arquivo = fopen("asteroides.txt", "w");

    p = lista_asteroides->prox; 

    if(arquivo != NULL){

        while(p != NULL){

            /* linha do asteroide: codigo, distancia, diametro, status, qtd_minerios */
            fprintf(arquivo, "%d, %f, %d, %s, %d\n",
                    p->codigo,
                    p->distancia,
                    p->diametro,
                    p->status,
                    p->qtd_minerios);

            /* linhas dos minerios desse asteroide */
            m = p->lista_minerios;

            while(m != NULL){

                fprintf(arquivo, "%d, %s, %d\n",
                        m->codigo_minerio,
                        m->nome_minerio,
                        m->quantidade_minerio);

                m = m->prox;
            }

            p = p->prox;
        }

        printf("\n Asteroides salvos com sucesso!");

        fclose(arquivo);

    } else{

        printf("\n ERRO na abertura do arquivo");
    }
}


 void busca_asteroides_arquivo(asteroide *lista_asteroides){

    FILE *arquivo; 
    asteroide novo_asteroide, *asteroide_recem_inserido; 
    int qtd_minerios_lidos, i;
    int leitura_minerio;
    minerio novo_minerio;

    arquivo = fopen("asteroides.txt", "r");


    if(arquivo != NULL){

         while ( fscanf(arquivo, "%d, %f, %d, %s, %d",
                            &novo_asteroide.codigo,
                            &novo_asteroide.distancia,
                            &novo_asteroide.diametro,
                            novo_asteroide.status,
                            &qtd_minerios_lidos) == 5){





    
             insere_asteroide(lista_asteroides, novo_asteroide);


             asteroide_recem_inserido = encontra_asteroide(lista_asteroides, novo_asteroide.codigo);


             if(asteroide_recem_inserido != NULL){



                   asteroide_recem_inserido->lista_minerios = NULL;
                   asteroide_recem_inserido->qtd_minerios = 0;
                   i = 0;


                 while (i < qtd_minerios_lidos){

                      leitura_minerio = fscanf(arquivo, "%d, %49s, %d",
                                             &novo_minerio.codigo_minerio,
                                             novo_minerio.nome_minerio,
                                             &novo_minerio.quantidade_minerio);

                    if(leitura_minerio == 3){

                        insere_minerio(asteroide_recem_inserido, novo_minerio);

                        i = i + 1;

                    } else {

                        /* se der erro de leitura, força saida do while */
                        i = qtd_minerios_lidos;
                    }


                  }





             }


        
            
          

         }

         fclose(arquivo);

        
    } else{

        printf("\n ERRO na abertura do arquivo!");
    }

   

   
}
