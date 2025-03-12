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
    }
    return aux;
}

arvoreRway *criar_arvore(){
    arvoreRway* aux = (arvoreRway*) malloc(sizeof(arvoreRway));
    aux->raiz = NULL;
    return aux;
}

void inserir(arvoreRway* arv, char* str, int valor){
    noRway aux = arv->raiz;

    while(*str){
        if(aux == NULL){ // raiz eh nula
            aux = criar_no();
            aux->filho[*str - letraA] = criar_no();
            arv->raiz = aux; // raiz aponta para o no criado
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

int busca(arvoreRway* arv, char *str){
    noRway aux = arv->raiz;

    while(*str){ // str != \0
        if(aux == NULL) return -1;

        aux = aux->filho[*str - letraA];
        str++;
    }

    if(aux != NULL){
        return aux->valor;
    }

    return -1;
}

void imprime_dicionario_aux(noRway raiz, char *base, char *str){
    if(raiz != NULL){
        if(raiz->valor != -1){
            *str = '\0';
            printf("%s\n", base);
        }
        for(int i = 0; i < ALFABETO; i++){
            if(raiz->filho[i] != NULL){
                *str = letraA + i;
                imprime_dicionario_aux(raiz->filho[i], base, str+1);
            }
        }
    }
}

void imprime_dicionario(arvoreRway *arv){
    char str[50] = "\0";
    imprime_dicionario_aux(arv->raiz, str, str);
}


int main(){
    arvoreRway *arv = criar_arvore();

    inserir(arv, "TWICE", 9);
    inserir(arv, "NAYEON", 95);
    inserir(arv, "JEONGYEON", 0);
    inserir(arv, "MOMO", 64);
    inserir(arv, "SANA", 12);
    inserir(arv, "JIHYO", 21);
    inserir(arv, "MINA", 37);
    inserir(arv, "DAHYUN", 7);
    inserir(arv, "CHAEYOUNG", 29);
    inserir(arv, "TZUYU", 25);

    //imprime_dicionario(arv);

    printf("valor da string TWICE eh %d\n", busca(arv, "TWICE"));
}