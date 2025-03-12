#include <stdio.h>
#include <stdlib.h>

#define ALFABETO 26
#define letraA 65

struct rway {
    struct rway *filho[ALFABETO];
    int valor;
};

typedef struct rway *noRway;

typedef struct {
    noRway raiz;
}arvoreRway;

noRway criar_no(){
    noRway aux = (noRway) malloc(sizeof(struct rway));
    aux->valor = -1;
    for(int i = 0; i < ALFABETO; i++){
        aux->filho[i] = NULL;

    return aux;
    }
}

arvoreRway *criar_arvore(){
    arvoreRway* aux = (arvoreRway*) malloc(sizeof(arvoreRway));
    aux->raiz = NULL;
    return aux;
}

void inserir(arvoreRway* arv, char* str, int valor){
    noRway aux = arv->raiz;

    while(*str){
        if(aux == NULL){
            aux = criar_no();
            aux->filho[*str - letraA] = criar_no();
            arv->raiz = aux;
        }
        else {
            if(aux->filho[*str - letraA] == NULL){
                aux->filho[*str - letraA] = criar_no();
            }
            aux = aux->filho[*str - letraA];
            str++;
        }
    }
    aux->valor = valor;
}