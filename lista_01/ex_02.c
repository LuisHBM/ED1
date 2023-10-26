#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void print_lista(Nodo*);
void insere(Nodo**, int);
int retira(Nodo**, int);
Nodo* ordena(Nodo*);

int main()
{
    Nodo *inicio = NULL, *ordenada;

    int num;
    while(1)
    {
        print_lista(inicio);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else insere(&inicio, num);
    }

    print_lista(inicio);

    ordenada = ordena(inicio);
    printf("\n ORDENANDO...");
    print_lista(ordenada);

    return 0;
}

void print_lista(Nodo *inicio)
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

void insere(Nodo **inicio, int n)
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
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
}

Nodo* ordena(Nodo *inicio)
{
    if(!inicio) return NULL;

    Nodo *atual = inicio, *ant;
    int n;
    while(atual != NULL)
    {
        Nodo *atual2 = atual, *ant2;
        while (atual2 != NULL)
        {
            if (atual2->info < atual->info)
            {
                n = atual->info;
                atual->info = atual2->info;
                atual2->info = n;
            }

            ant2 = atual2;
            atual2 = atual2->prox;
        }

        ant = atual;
        atual = atual->prox;
    }

    return inicio;
}