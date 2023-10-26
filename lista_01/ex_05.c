#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void insereOrdemCrescente(Nodo**, int);
void eliminarAntSuc(Nodo**, int);
void retira(Nodo**, int);
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
        else insereOrdemCrescente(&inicio, num);
    }

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

void insereOrdemCrescente(Nodo **inicio, int n)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (!novo) exit(1);

    novo->info = n;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio, *ant;
    while ((atual != NULL) && (atual->info < n))
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
        novo->prox = *inicio;
        *inicio = novo;
    }
    else
    {
        ant->prox = novo;
        novo->prox = atual;
    }
}

void retira(Nodo **inicio, int n)
{
    if(!*inicio) exit(1);

    Nodo *atual = *inicio, *ant;
    while ((atual != NULL) && (atual->info != n))
    {
        ant = atual;
        atual = atual->prox;        
    }
    
    if (atual == NULL)
    {
        printf("Não encontrado");
        return;
    }
    else if (atual == *inicio)
    {
        *inicio = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }

    free(atual);
}

void eliminarAntSuc(Nodo **inicio, int n)
{
    if (!*inicio) exit(1);

    Nodo *atual = *inicio, *ant= NULL, *ant2 = NULL;
    while ((atual != NULL) && (atual->info != n))
    {
        ant2 = ant;
        ant = atual;
        atual = atual->prox;
    }
}
