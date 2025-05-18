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
    if (!isFull(p)) {
        p->dados[++(p->topo)] = valor;
    }
}

int pop(Pilha *p) {
    if (!isEmpty(p)) {
        return p->dados[(p->topo)--];
    }
    return -1; 
}

int topo(Pilha *p) {
    if (!isEmpty(p)) {
        return p->dados[p->topo];
    }
    return -1;
}

void mostrar(Pilha *p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void ordenarPilha(Pilha *orig) {
    Pilha aux;
    inicializar(&aux);

    while (!isEmpty(orig)) {
        int temp = pop(orig);

        while (!isEmpty(&aux) && topo(&aux) > temp) {
            push(orig, pop(&aux));
        }

        push(&aux, temp);
    }

    
    while (!isEmpty(&aux)) {
        push(orig, pop(&aux));
    }
}

int main() {
    Pilha p;
    inicializar(&p);

    
    push(&p, 4);
    push(&p, 1);
    push(&p, 3);
    push(&p, 2);

    printf("Antes de ordenar:\n");
    mostrar(&p);

    ordenarPilha(&p);

    printf("Depois de ordenar:\n");
    mostrar(&p);

    return 0;
}
