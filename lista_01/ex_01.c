#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int n;
    struct nodo *prox;
} Nodo;

void gerarLista(Nodo**);
void print_lista(Nodo*);
void retirar(Nodo**, int);

int main()
{
    Nodo *inicio, *atual;
    inicio = NULL;

    gerarLista(&inicio);
    atual = inicio;

    print_lista(inicio);

    atual = inicio;
    while(atual != NULL)
    {
        if(atual->n % 2 == 0) retirar(&inicio, atual->n);
        atual = atual->prox;
    }
    
    print_lista(inicio);

    return 0;
}

void gerarLista(Nodo **inicio)
{
    int num;
    Nodo *atual, *ant;

    while (1)
    {
        print_lista(*inicio);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;

        Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
        if (!novo) exit(1);
        novo->n = num;

        if (*inicio == NULL)
        {
            novo->prox = NULL;
            *inicio = novo;
        }
        else
        {
            atual = *inicio;
            ant = NULL;
            while((atual != NULL) && (atual->n > novo->n))
            {
                ant = atual;
                atual = atual->prox;
            }

            if (atual == NULL)
            {
                novo->prox = NULL;
                ant->prox = novo;
            }
            else if (atual == *inicio)
            {
                novo->prox = *inicio;
                *inicio = novo;
            }
            else
            {
                ant->prox = novo;
                novo->prox = atual;
            }
        }
    }  
}

void retirar(Nodo **inicio, int n)
{
    Nodo *ant, *atual;

    ant = NULL;
    atual = *inicio;
    while((atual != NULL) && (n != atual->n))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) 
    {
        printf("\nNumero não existe\n");
        return;
    }
    if (atual == (*inicio))
    {
        *inicio = (*inicio)->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }
}

void print_lista(Nodo *inicio)
{
    printf("\n Lista Ordenada: ");
    while(1)
    {
        if(inicio != NULL)
        {
            printf("%d ", inicio->n);
            inicio = inicio->prox;
        }
        else
        {
            break;
        }
    }
}