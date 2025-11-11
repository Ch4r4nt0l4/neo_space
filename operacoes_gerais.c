#include <stdio.h> 
#include <stdlib.h>
#include "operacoes_gerais.h"


void init1(void) {
    printf("\n");
    printf("************************************************************\n");
    printf("*                                                          *\n");
    printf("*              SISTEMA DE GERENCIAMENTO ESPACIAL           *\n");
    printf("*                                                          *\n");
    printf("************************************************************\n");
    printf("\n");
}


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




void menu_principal(asteroide *lista_asteroides, missao *lista_missoes){

     int opcao_selecionada;


    printf("=============== Menu Principal =============== \n");
    printf("1 - Gerenciar Asteroides \n");
    printf("2 - Gerenciar Missoes \n");
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
    
            default:
                printf("\n Opcao invalida, tente novamente!");
                break;
        }

         printf("=============== Menu Principal =============== \n");
         printf("1 - Gerenciar Asteroides \n");
         printf("2 - Gerenciar Missoes \n");
         printf("0 - Encerrar Programa \n");
         printf("Informe o numero da opcao desejada: ");
         scanf("%d", &opcao_selecionada);

     }


     /* Aqui salva os dados em arquivo antes de encerrar o programa*/
     salva_asteroides_arquivo(lista_asteroides);

}
