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
operacoes que envolvem todos os structs do programa *
11 * *
12 *************************************************/


#include <stdio.h> 
#include <stdlib.h>
#include "operacoes_gerais.h"




void menu_principal(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[],  int *inicio, int *fim){

     int opcao_selecionada;


    printf("\n=============== Menu Principal =============== \n");
    printf("1 - Gerenciar Asteroides \n");
    printf("2 - Gerenciar Missoes \n");
    printf("3 - Gerenciar Astronautas \n");
    printf("4 - Lancar missao \n");
    printf("5 - Encerrar missao \n");
    printf("0 - Encerrar Programa \n");
    printf("Informe o numero da opcao desejada: ");

    scanf("%d", &opcao_selecionada);


    while (opcao_selecionada != 0) {
        

        switch (opcao_selecionada) {
             case 1:
                menu_asteroides(lista_asteroides);
                break;
            case 2:
                 menu_missoes(lista_missoes);
                  break;
            
            case 3: 
                menu_astronautas(fila_astronauta, inicio, fim);
                break;

            case 4: 

                lancar_missao(lista_asteroides,lista_missoes, fila_astronauta, inicio, fim);
                 break;

            case 5:

                encerrar_missao(lista_asteroides, lista_missoes, fila_astronauta, inicio, fim);
                break;

            
    
            default:
                printf("\n Opcao invalida, tente novamente!");
                break;
        }

         printf("\n =============== Menu Principal =============== \n");
         printf("1 - Gerenciar Asteroides \n");
         printf("2 - Gerenciar Missoes \n");
         printf("3 - Gerenciar Astronautas \n");
         printf("4 - Lancar missao \n");
         printf("5 - Encerrar missao \n");
         printf("0 - Encerrar Programa \n");
         printf("Informe o numero da opcao desejada: ");
         scanf("%d", &opcao_selecionada);

     }


     /* Aqui salva os dados em arquivo antes de encerrar o programa*/
     salva_asteroides_arquivo(lista_asteroides);
     salva_missoes_arquivo(lista_missoes);
     salva_astronautas_arquivo(fila_astronauta, inicio, fim);
}



void lancar_missao(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[],  int *inicio, int *fim){

    
    int codigo_asteroide, contagem_astronautas,i; 
    missao *missao_escolhida;
    astronauta astronauta_escolhido; 
    asteroide *asteroide_escolhido; 

    /*Informa o codigo do asteroide a ser enviada a missao*/

    printf("\n Informe o codigo do asteroide que deseja enviar a sua missao: " );
    scanf("%d", &codigo_asteroide );

    asteroide_escolhido = encontra_asteroide(lista_asteroides, codigo_asteroide);
   

   

    if(asteroide_escolhido != NULL){

        

          /*procuro a primeira missao que não foi lançada e copio o ponteiro pra ela*/ 
        missao_escolhida = procura_missao(lista_missoes, "Montagem"); 

      

        if(missao_escolhida != NULL){

              printf("\n A missao escolhida: %d", missao_escolhida->codigo_missao);


            /*Faço 3 desemfileiras colocando os astronautas dentro da missao */

         contagem_astronautas = tamanho_fila_astronauta(inicio, fim);
         printf("\n Contagem de astronautas: %d", contagem_astronautas);

         if(contagem_astronautas >= 3){

            


            for(i = 0; i < 3; i++ ){

                    astronauta_escolhido = seleciona_astronauta_para_missao(fila_astronauta, inicio, fim);
                    printf("\n Astronauta Selecionado: %s", astronauta_escolhido.nome);
                    missao_escolhida->tripulantes[i] = astronauta_escolhido;
              }


              missao_escolhida->codigo_asteroide = codigo_asteroide; 
              strcpy(missao_escolhida->status_missao, "Lancada"); 
              strcpy(asteroide_escolhido->status, "Ocupado");  


              /*enviar missao*/
              lancamento();
              printf("\n Missao enviada com sucesso!");
         } else{

            printf("\n Missao cancelada: nao existem astronautas suficientes!");
         }


        } else{

            printf("\n Nao existem missoes disponiveis!");
        }

         

         
    } else{

         printf("\n O asteroide inserido nao existe"); 
    }
}



void encerrar_missao(asteroide *lista_asteroides, missao *lista_missoes, astronauta fila_astronauta[],  int *inicio, int *fim){

    int i;
     missao *missao_escolhida;
     asteroide *asteroide_escolhido; 
    

    missao_escolhida = procura_missao(lista_missoes, "Lancada" ); 


    if(missao_escolhida != NULL){

        asteroide_escolhido = encontra_asteroide(lista_asteroides, missao_escolhida->codigo_asteroide);



        for(i = 0; i < 3; i++ ){



            contratar_astronauta(fila_astronauta, inicio, fim, missao_escolhida->tripulantes[i]);

            printf("\n Astronauta %s reinserido na fila de lancamento", missao_escolhida->tripulantes[i].nome );


        }

        strcpy(missao_escolhida->status_missao, "Encerrada");
        strcpy(asteroide_escolhido->status, "Livre");

        imprime_minerios(asteroide_escolhido);


    } else{

        printf("\n Nenhuma missao em execucao no momento!");
    }


}



/*As funçoes abaixo são apenas decorativas e 
são usadas na inicialização do programa e 
quando alguma missao é lançada*/

void init2(void) {
    printf("\n");
    printf("||=====/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\=======||\n");
    printf("||====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\======||\n");
    printf("||===//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\=====||\n");
    printf("||==//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\====|| \n");
    printf("||=================================================           ==================================================||\n");
    printf("||================================================= NEO SPACE ==================================================||\n");
    printf("||=================================================           ==================================================||\n");
    printf("||==\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //====||\n");
    printf("||===\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //=====||\n");
    printf("||====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//======||\n");
    printf("||=====\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/=======||\n");
    
   
   
    printf("\n");
  
    printf("\n");
}


void lancamento(void) {
    printf("\n");
    printf("||=====/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\======/\\=======||\n");
    printf("||====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\====//\\\\======||\n");
    printf("||===//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\==//  \\\\=====||\n");
    printf("||==//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\//    \\\\====||\n");
    printf("||=================================================           ==================================================||\n");
    printf("||================================================= Lancamento Realizado ===============================================||\n");
    printf("||=================================================           ==================================================||\n");

    
    printf("||                                                                                                              ||\n");
    printf("||                                                     /\\                                                       ||\n");
    printf("||                                                    /  \\                                                      ||\n");
    printf("||                                                   /____\\                                                     ||\n");
    printf("||                                                   | /\\ |                                                     ||\n");
    printf("||                                               ___ | || | ___                                                 ||\n");
    printf("||                                              /   \\| || |/   \\                                                ||\n");
    printf("||                                             /_____|_||_|_____\\                                               ||\n");
    printf("||                                             |  ___  ||  ___  |                                               ||\n");
    printf("||                                             | |   | || |   | |                                               ||\n");
    printf("||                          ___________________| |   | || |   | |___________________                            ||\n");
    printf("||                         /___________________| |   | || |   | |___________________\\                           ||\n");
    printf("||                         \\\\===================| |___| || |___| |===================//                         ||\n");
    printf("||                          \\\\__________________\\_______||_______/__________________//                          ||\n");
    printf("||                                       __/\\__________________________/\\__                                      ||\n");
    printf("||                                      /_/  \\______________________/  \\_\\                                     ||\n");
    printf("||                                     /_/    \\____________________/    \\_\\                                    ||\n");
    printf("||                                                                                                              ||\n");

    
    printf("||                                      ====     ====     ====     ====                                         ||\n");
    printf("||                                     /\\\\  \\   /  //\\   /\\\\  \\   /  //\\                                        ||\n");
    printf("||                                     \\\\ \\\\ /\\_/ // /   \\\\ \\\\ /\\_/ // /                                        ||\n");
    printf("||                                      \\\\_/  \\_/  //_     \\\\_/  \\_/  //_                                       ||\n");
    printf("||                                       \\_         _/       \\_         _/                                       ||\n");

   
    printf("||==\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //\\\\    //====||\n");
    printf("||===\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //==\\\\  //=====||\n");
    printf("||====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//====\\\\//======||\n");
    printf("||=====\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/======\\/=======||\n");
    printf("\n");
}



