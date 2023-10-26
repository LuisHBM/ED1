#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void inserir(Nodo**, int);
void inserirOrdenado(Nodo**, int);
void retirar(Nodo**, int);
void ordenar(Nodo**);
void print(Nodo*);

int main()
{
    Nodo *inicio = NULL;
    int num;

    while(1)
    {
        print(inicio);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else inserir(&inicio, num);
    }

    ordenar(&inicio);
    print(inicio);

    return 0;
}

void print(Nodo *inicio)
{
    printf("\n Lista: ");
    while(1)
    {
        if(inicio != NULL)
        {
            printf("%d ", inicio->info);
            inicio = inicio->prox;
        }
        else
        {
            break;
        }
    }
}

void inserir(Nodo **inicio, int n)
{
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) exit(1);

    novo->info = n;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio;
    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo;
}

void inserirOrdenado(Nodo **inicio, int n)
{
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) exit(1);

    novo->info = n;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio, *ant;
    while ((atual != NULL) && (atual->info < novo->info))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        ant->prox = novo;
    }
    else if (atual == *inicio)
    {
        novo->prox = atual;
        *inicio = novo;
    }
    else
    {
        novo->prox = atual;
        ant->prox = novo;
    }

}

void ordenar(Nodo **inicio)
{
}

void ordenarParImpar(Nodo **inicio)
{
    Nodo *par, *impar, *aux, *atual, *ant;

    if (*inicio == NULL)
    {
        return;
    }

    atual = *inicio;
    while (atual != NULL)
    {
        ant = atual;
        atual = atual->prox;
    }
}
