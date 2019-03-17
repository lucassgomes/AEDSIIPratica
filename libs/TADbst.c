#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include "TADbst.h"

void inicializaTAD(tipoApontador *no){
    *no = NULL;
}

void insereTAD(tipoApontador *no, int info){
    if(*no == NULL){
        *no = (tipoApontador)malloc(sizeof(tipoNo));
        (*no)->chave = info;
        (*no)->left = NULL;
        (*no)->right = NULL;
        return;
    }
    if(info <= (*no)->chave){
        insereTAD(&(*no)->left, info);
        printf("\nPreenchido a esquerda, ou seja, menor do que a raíz do nó anterior que é o %d\n", (*no)->chave);
        return;
    }
    if(info > (*no)->chave){
        insereTAD(&(*no)->right, info);
        printf("\nPreenchido a direita, ou seja, maior do que a raíz do nó anterior que é o  %d\n", (*no)->chave);
        return;
    }
}

void pesquisaTAD(tipoApontador *no, int info){
    if(*no == NULL){
        printf("Erro: Valor não encontrado!\n");
        return;
    }
    if(info < (*no)->chave){
        pesquisaTAD(&(*no)->left, info);
    }
    if(info > (*no)->chave){
        pesquisaTAD(&(*no)->left, info);
    } else {
        printf("Encontrado!");
    }
}

void ordem(tipoApontador no){
    if(no == NULL) return;
    ordem(no->left);
    printf("%ld\n", no->chave);
    ordem(no->right);
}

void preordem(tipoApontador no){
    if(no == NULL) return;
    printf("%ld\n", no->chave);
    preordem(no->left);
    preordem(no->right);
}

void posordem(tipoApontador no){
    if(no == NULL) return;
    posordem(no->left);
    posordem(no->right);
    printf("%ld\n", no->chave);
}