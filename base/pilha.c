#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void empilha (int, Nodo**);
int desempilha (Nodo**);
void print_pilha(Nodo*);

int main()
{
    char opcao;
    int valor;
    Nodo *topo = NULL;

    while(1)
    {
        if (topo)
        {
            print_pilha(topo);
        }
        printf("\n[1] Empilha / [2] Desempilha: ");
        scanf(" %c", &opcao);
        switch (opcao)
        {
        case '1':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            empilha(valor, &topo);
            break;
        case '2':
            valor = desempilha(&topo);
            printf("\nValor desempilhado = %d", valor);
            break;
        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }

    return 0;
}

void empilha(int n, Nodo **topo)
{
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) exit(1);

    novo->info = n;
    if (*topo == NULL)
    {
        novo->prox = NULL;
    }
    else
    {
        novo->prox = *topo;
    }
    *topo = novo;
}

int desempilha(Nodo **topo)
{
    Nodo *aux;
    int n;

    if (*topo == NULL)
    {
        printf("\nERRO: Pilha vazia!\n");
        exit(1);
    }

    n = (*topo)->info;
    aux = *topo;
    *topo = (*topo)->prox;
    free(aux);

    return n;
}

void print_pilha(Nodo *topo)
{
    printf("\nPilha: ");
    while(1)
    {
        if(topo != NULL)
        {
            printf("%d ", topo->info);
            topo = topo->prox;
        }
        else
        {
            break;
        }
    }
}