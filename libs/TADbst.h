//
// Created by lucassgomes on 16/03/19.
//

#ifndef BST_TADBST_H
#define BST_TADBST_H

#endif //BST_TADBST_H

typedef struct tipoNo * tipoApontador;
typedef struct tipoNo {
    int chave;
    tipoApontador left, right;
} tipoNo;

void inicializaTAD(tipoApontador *no);

void insereTAD(tipoApontador *no, int info);

void pesquisaTAD(tipoApontador *no, int info);

void ordem(tipoApontador no);

void preordem(tipoApontador no);

void posordem(tipoApontador no);