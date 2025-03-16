#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct noTST{
    char letra;
    int valor;

    struct noTST *menor;
    struct noTST *igual;
    struct noTST *maior;
} noTST;

typedef noTST *arv_tst;

void insere(arv_tst* raiz, char *str, int valor){
    if(*str){
        if(*raiz == NULL){
            *raiz = (noTST*) malloc(sizeof(noTST));
            (*raiz)->letra = *str;
            (*raiz)->valor = -1;

            (*raiz)->igual = NULL;
            (*raiz)->menor = NULL;
            (*raiz)->maior = NULL;

            insere(&(*raiz)->igual, str+1, valor);
            if(*(str+1) == '\0')
                (*raiz)->valor = valor;
        }
        else {
            if(*str < (*raiz)->letra) insere(&(*raiz)->menor, str, valor);

            else if (*str > (*raiz)->letra) insere(&(*raiz)->maior, str, valor);

            else{
                insere(&(*raiz)->igual, str+1, valor);
                if(*(str+1) == '\0')
                    (*raiz)->valor = valor;
            } 
        }  
    }
}

void imprime_dicionario_aux(arv_tst raiz, char *aux, char *str){
    if(raiz != NULL){
        imprime_dicionario_aux(raiz->menor, aux, str);
        *str = raiz->letra;
        if(raiz->valor != -1){
            *(str+1) = '\0';
            printf("%s\n", aux);
        }
        imprime_dicionario_aux(raiz->igual, aux, str+1);
        imprime_dicionario_aux(raiz->maior, aux, str);
    }
}

void imprime_dicionario(arv_tst raiz){
    char aux[50] = "\0";
    imprime_dicionario_aux(raiz, aux, aux);
}

int main(){
    arv_tst raiz = NULL;

    insere(&raiz, "TWICE", 9);
    insere(&raiz, "NAYEON", 95);
    insere(&raiz, "JEONGYEON", 0);
    insere(&raiz, "MOMO", 64);  
    insere(&raiz, "SANA", 12);
    insere(&raiz, "JIHYO", 21);
    insere(&raiz, "MINA", 37);
    insere(&raiz, "DAHYUN", 7);
    insere(&raiz, "CHAEYOUNG", 29);
    insere(&raiz, "TZUYU", 25);

    imprime_dicionario(raiz);
    printf("\n");

    return 0;
}