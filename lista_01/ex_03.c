#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void insere(Nodo**, int);
void print(Nodo*);
Nodo* junta(Nodo*, Nodo*);

int main()
{
    Nodo *inicioA = NULL, *inicioB = NULL;
    Nodo *inicioJunto = NULL;
    int num;

    printf("\nLISTA A");
    while(1)
    {
        print(inicioA);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else insere(&inicioA, num);
    }
    printf("\nLISTA B");
    while(1)
    {
        print(inicioB);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else insere(&inicioB, num);
    }

    inicioJunto = junta(inicioA, inicioB);
    print(inicioJunto);

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
    while (atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
}

Nodo* junta(Nodo *inicioA, Nodo *inicioB)
{
    Nodo *inicio = inicioA;
    while (inicioA->prox != NULL) inicioA = inicioA->prox;
    inicioA->prox = inicioB;
    
    Nodo *atual = inicio;
    int aux;
    
    while(atual != NULL)
    {
        Nodo *atual2 = atual;
        while (atual2 != NULL)
        {
            if (atual2->info < atual->info)
            {
                aux = atual->info;
                atual->info = atual2->info;
                atual2->info = aux;
            }
            
            atual2 = atual2->prox;
        }
        
        atual = atual->prox;
    }

    return inicio;
}