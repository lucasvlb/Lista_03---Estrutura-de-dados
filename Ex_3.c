#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 50

typedef struct {
    char texto[100];
} Acao;

typedef struct {
    Acao dados[TAM];
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

void push(Pilha *p, Acao valor) {
    if (isFull(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

Acao pop(Pilha *p) {
    Acao vazia = {"<vazio>"};
    if (isEmpty(p)) {
        return vazia;
    }
    return p->dados[p->topo--];
}


void limpar(Pilha *p) {
    p->topo = -1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha desfazer, refazer;
    inicializar(&desfazer);
    inicializar(&refazer);

    int opcao;
    Acao acao;

    do {
        printf("\nMenu:\n");
        printf("[1] Nova ação\n");
        printf("[2] Desfazer\n");
        printf("[3] Refazer\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Digite a ação: ");
                fgets(acao.texto, sizeof(acao.texto), stdin);
                acao.texto[strcspn(acao.texto, "\n")] = '\0'; 

                push(&desfazer, acao);
                limpar(&refazer); 
                printf("Ação '%s' registrada.\n", acao.texto);
                break;

            case 2:
                if (!isEmpty(&desfazer)) {
                    Acao a = pop(&desfazer);
                    push(&refazer, a);
                    printf("Desfez a ação: '%s'\n", a.texto);
                } else {
                    printf("Nada para desfazer.\n");
                }
                break;

            case 3:
                if (!isEmpty(&refazer)) {
                    Acao a = pop(&refazer);
                    push(&desfazer, a);
                    printf("Refez a ação: '%s'\n", a.texto);
                } else {
                    printf("Nada para refazer.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

