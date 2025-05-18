#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int isFull(Pilha *p) {
    return p->topo == TAM - 1;
}

void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--];
}

void mostrar(Pilha *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void removerPares(Pilha *original) {
    Pilha aux;
    inicializar(&aux);

    
    while (!isEmpty(original)) {
        int valor = pop(original);
        if (valor % 2 != 0) {
            push(&aux, valor);
        }
    }

    
    while (!isEmpty(&aux)) {
        push(original, pop(&aux));
    }
}

int main() {
    Pilha p;
    inicializar(&p);

    
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    printf("Antes:\n");
    mostrar(&p);

    removerPares(&p);

    printf("Depois (pares removidos):\n");
    mostrar(&p);

    return 0;
}

