#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include "TADbst.h" //Inclusão do cabeçalho

/**
 * Nessa função eu aponto o ponteiro da estrutura no para NULL
 * @param no Endereço do apontador para esse no
 */
void inicializaTAD(tipoApontador *no){
    *no = NULL;
}

/**
 * Nessa função eu insiro a informação (int) em um nó da árvore seguindo a definição de árvores do tipo BST
 * @param no Endereço do apontador para esse no
 * @param info Informação a ser adicionada
 */
void insereTAD(tipoApontador *no, int info){
    //Se o nó é nulo posso alocar o espaço de um nó e apontar a esquerda e a direira para nulo,
    //inserindo também a informação recolhida na função
    if(*no == NULL){
        *no = (tipoApontador)malloc(sizeof(tipoNo)); //Alocando espaço
        (*no)->chave = info; //Armazenando
        (*no)->left = NULL; //Apontando esquerda para null
        (*no)->right = NULL; //Apontando direita para null
        return; //retorno a função com nada já que ela é void
    }
    //A função é recursiva, então sempre que quero inserir um dado eu passo pelas mesmas verificações
    //A verificação abaixo faz com que se a informação for menor ou igual ao que já tenho no nó raiz
    //posso chamar a função recursivamente e inserir a informação no nó a esquerda
    if(info <= (*no)->chave){
        insereTAD(&(*no)->left, info);
        printf("\nPreenchido a esquerda, ou seja, menor do que a raíz do nó anterior que é o %d\n", (*no)->chave);
        return;
    }
    //A verificação abaixo faz com que se a informação for maior ao que já tenho no nó raiz
    //posso chamar a função recursivamente e inserir a informação no nó a direita
    if(info > (*no)->chave){
        insereTAD(&(*no)->right, info);
        printf("\nPreenchido a direita, ou seja, maior do que a raíz do nó anterior que é o  %d\n", (*no)->chave);
        return;
    }
}

/**
 *
 * @param no
 * @param info
 */
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