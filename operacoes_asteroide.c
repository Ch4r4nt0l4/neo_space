#include <stdio.h> 
#include <stdlib.h>
#include "operacoes_asteroide.h"







void menu_asteroides(asteroide *lista_asteroides){

     int opcao_selecionada; 
     asteroide novo_elemento;

    

    printf("=============== Menu Asteroides =============== \n");
    printf("1 - Inserir novo asteroide \n");
    printf("2 - Atualizar Asteroide \n");
    printf("3 - Excluir Asteroide\n");
    printf("0 - Encerrar Sessao \n");
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

        
        
        default:

            printf("\n Opcao invalida");
            break;

        }

         printf("\n =============== Menu de Opcoes =============== \n");
         printf("1 - Inserir novo asteroide \n");
         printf("2 - Atualizar Asteroide \n");
         printf("3 - Excluir Asteroide\n");
         printf("0 - Encerrar Sessao \n");
         printf("Informe o numero da opcao desejada: ");
         scanf("%d", &opcao_selecionada);
    }
    salva_asteroides_arquivo(lista_asteroides);
    imprime_lista_asteroides(lista_asteroides);
}


asteroide cria_novo_asteroide(void){

    asteroide novo_asteroide; 

    printf(" Insira Codigo, distancia, diametro do asteroide \n");
    scanf("%d %f %d", &novo_asteroide.codigo, &novo_asteroide.distancia, &novo_asteroide.diametro);
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

           


               /*chamar função para inserir vetor de minérios*/ 

                 novo_elemento->codigo = novo_asteroide.codigo;
                 novo_elemento->diametro = novo_asteroide.diametro;
                 novo_elemento->distancia = novo_asteroide.distancia; 
                 novo_elemento->qtd_minerios = 0;


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


void insere_minerais(asteroide *lista_asteroides){

    int codigo_asteroide, verificador, i; 
    asteroide *p, *asteroide_escolhido; 

    p = lista_asteroides;



    printf("\n ========== Inserir novos minerios ==========: ");
    printf("\n Insira o codigo do asteroide que vai adicionar novos minerios: ");
    scanf("%d", &codigo_asteroide);


    verificador = verifica_codigo_asteroide(lista_asteroides, codigo_asteroide);


    if(verificador != -1){

         while(p != NULL){

              if(p->codigo == codigo_asteroide){

                  asteroide_escolhido = p; 
              }
        }




        /*MELHORAR ISSO AQUIaqui adicionar os minerais percorrendo o vetor do asteroide escolhido*/

        for(i = 0; i < QTD_MAX_MINERIOS; i++){

           

                printf("\n Insira o codigo do minerio: ");
                scanf("%d", &asteroide_escolhido->minerios[i].codigo_minerio);
                printf("\n Nome do minerio: ");
                scanf("%s", asteroide_escolhido->minerios[i].nome_minerio);
                printf("\n Quantidade do minerio: ");
                scanf("%d", &asteroide_escolhido->minerios[i].quantidade_minerio);
                
                asteroide_escolhido->qtd_minerios += 1;
                
            
        }

    } else{

        printf("\n Codigo inserido invalido, tente novamente!");


    }
}

void imprime_lista_asteroides(asteroide *lista_asteroide){

    asteroide *p; 

    p = lista_asteroide->prox; /* VERIFICAR SE É ASSIM MESMO QUE DEVO FAZER1*/


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

/*melhorar essa função para verificar se a variavel de retorno 
não esta vazia e adicionar mensagem de erro ou de sucesso*/


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

    arquivo = fopen("asteroides.txt", "w");

    p = lista_asteroides->prox; 

    if(arquivo != NULL){

         while(p != NULL){

             fprintf(arquivo, " %d, %f, %d", p->codigo, p->distancia, p->diametro ); 
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
    asteroide novo_asteoide; 

    arquivo = fopen("asteroides.txt", "r");


    if(arquivo != NULL){

         while ( fscanf(arquivo, "%d, %f, %d", &novo_asteoide.codigo, &novo_asteoide.distancia, &novo_asteoide.diametro) == 3){

    
             insere_asteroide(lista_asteroides, novo_asteoide);

         }

         fclose(arquivo);

        
    } else{

        printf("\n ERRO na abertura do arquivo!");
    }

   

   
}
