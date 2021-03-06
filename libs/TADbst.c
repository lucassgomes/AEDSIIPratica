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
 * Função que exibe mensagem de encontrado ou não encontrado o valor passado por parâmetro
 * @param no Endereço do apontador para esse no
 * @param info Informação a ser pesquisada
 */
void pesquisaTAD(tipoApontador *no, int info){
    //Novamente a função é recursiva, então assim que chegar ao último nó da árvore ele será null e
    //a função retornará de onde foi chamada.
    //Verifico se o nó é null
    if(*no == NULL){
        printf("Erro: Valor não encontrado!\n");
        return;
    }
    //Verifico se a informação é menor do que a informação que está no nó.
    //Em caso positivo, a pesquisa deve continuar pelo lado esquerdo da árvore.
    if(info < (*no)->chave){
        pesquisaTAD(&(*no)->left, info);
    }
    //Verifico se a informação é menor do que a informação que está no nó.
    //Em caso positivo, a pesquisa deve continuar pelo lado direito da árvore ou ela já terá chegado no fim e encontrado o valor.
    if(info > (*no)->chave){
        pesquisaTAD(&(*no)->left, info);
    } else {
        printf("Passei pelos nó: %d\n", (*no)->chave);
        printf("Encontrado!");
    }
}

/**
 * Função que exibe de forma ordenada os valores da árvore
 * @param no Endereço do apontador para esse no
 */
void ordem(tipoApontador no){
    //Se não ouver dado no nó devo parar a execução
    if(no == NULL) return;
    //A exibição em ordem começa pelo menor(esquerda)
    ordem(no->left);
    printf("%ld\n", no->chave); //Mostro o menor valor possível dessa execução
    //Chamo o nó maior daquela execução
    ordem(no->right);
}

/**
 * Função que exibe de forma pré-ordenada os valores da árvore
 * @param no Endereço do apontador para esse no
 */
void preordem(tipoApontador no){
    //Se não ouver dado no nó devo parar a execução
    if(no == NULL) return;

    printf("%ld\n", no->chave); //Mostro o valor da raíz
    //A exibição em pré-ordem continua pelo menor(esquerda)
    preordem(no->left);
    //A exibição em pré-ordem chama os valores a direita naquela execução
    preordem(no->right);
}

/**
 * Função que exibe de forma pós-ordenada os valores da árvore
 * Endereço do apontador para esse no
 * @param no
 */
void posordem(tipoApontador no){
    //Se não ouver dado no nó devo parar a execução
    if(no == NULL) return;
    //A exibição em pos-ordem começa pelo menor(esquerda)
    posordem(no->left);
    //A exibição em pos-ordem chama os valores a direita naquela execução
    posordem(no->right);
    printf("%ld\n", no->chave); //Mostro o valor da raíz
}