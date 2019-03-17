#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs/TADbst.h"
int main() {
    tipoApontador no;
    int info, opcao, valor;
    inicializaTAD(&no);
    printf("Digite um valor a ser inserido na árvore: (int) ");
    scanf("%d", &info);
    while(info > 0){
        insereTAD(&no, info);
        printf("Digite um valor a ser inserido na árvore: (int) ");
        scanf("%d%*[^\n]", &info);
    }
    printf("Escolha uma forma de exibição: (int)");
    scanf("%d", &opcao);
    while(opcao != 0){
        if(opcao == 1){
            preordem(no);
            printf("Escolha uma forma de exibição: (int)");
            scanf("%d", &opcao);
        } else if(opcao == 2){
            ordem(no);
            printf("Escolha uma forma de exibição: (int)");
            scanf("%d", &opcao);
        } else if(opcao == 3){
            posordem(no);
            printf("Escolha uma forma de exibição: (int)");
            scanf("%d", &opcao);
        } else {
            printf("Opção inválida!");
            return 0;
        }
    }
    printf("Digite um número para pesquisa: (int)");
    scanf("%d", &valor);
    while(valor != 0){
        pesquisaTAD(&no, valor);
        return 0;
    }
    return 0;
}