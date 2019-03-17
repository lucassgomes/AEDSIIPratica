/**
 * Criado em 17/01/2019 por Lucas Soares
 * AEDSII - Gláucia Braga e Silva
 */
 //Definições do CLION
#ifndef BST_TADBST_H
#define BST_TADBST_H

#endif //BST_TADBST_H

// Definindo a estrutura de dados para a árvore, ou seja, o nó
typedef struct tipoNo * tipoApontador;
typedef struct tipoNo {
    int chave;
    tipoApontador left, right;
} tipoNo;

/**
 * Função que inicializa movendo um ponteiro de um nó (tipoNo) qualquer para NULL
 * @param no Endereço do apontador para esse nó
 */
void inicializaTAD(tipoApontador *no);

/**
 * Função que insere valores (int) no nó da árvore
 * @param no Endereço do apontador para esse no
 * @param info Informação a ser inserida
 */
void insereTAD(tipoApontador *no, int info);

/**
 * Função que pesquisa um valor e retorna mensagem caso encontre o mesmo
 * @param no Endereço do apontador para esse no
 * @param info Informação a ser inserida
 */
void pesquisaTAD(tipoApontador *no, int info);

/**
 * Função que exibe a árvore de forma ordenada
 * @param no Endereço do apontador para esse no
 */
void ordem(tipoApontador no);

/**
 * Função que exibe a árvore de forma pré-ordenada
 * @param no Endereço do apontador para esse no
 */
void preordem(tipoApontador no);

/**
 * Função que exibe a árvore de forma pós-ordenada
 * @param no
 */
void posordem(tipoApontador no);