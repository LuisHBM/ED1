#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox, *ant;
} Nodo;

void inserir(Nodo**, int);
int retirar(Nodo**, int);
void print(Nodo*);

int main()
{
    char opcao;
    int valor;
    Nodo *inicio = NULL;

    while(1)
    {
        if (inicio)
        {
            print(inicio);
        }
        printf("\n[1] Inserir / [2] Retirar / [3] Qtd de nodos: ");
        scanf(" %c", &opcao);
        switch (opcao)
        {
        case '1':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir(&inicio, valor);
            break;
        case '2':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            valor = retirar(&inicio, valor);
            printf("\nValor retirado = %d", valor);
            break;
        case '3':

        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }
    return 0;
}

void print(Nodo *inicio)
{
    printf("\n Lista Crescente: ");
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
    if(!novo) exit(1);

    novo->info = n;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio;
    while ((atual->prox != NULL) && (atual->info > novo->info))
    {
        atual = atual->prox;
    }

    if ((atual->prox == NULL) && (atual->info > novo->info))
    {
        atual->prox = novo;
        novo->ant = atual;
    }
    else if (atual == *inicio)
    {
        novo->prox = *inicio;
        (*inicio)->ant = novo;
        *inicio = novo;
    }
    else
    {
        atual->ant->prox = novo;
        novo->ant = atual->ant;
        novo->prox = atual;
        atual->ant = novo;
    }
}

int retirar(Nodo **inicio, int n)
{
    if (*inicio == NULL)
    {
        printf("Empty nodes.");
        return 0;
    }
    int num;

    Nodo *atual = *inicio;
    while((atual->prox != NULL) && (atual->info != n))
    {
        atual = atual->prox;
    }

    if (atual->info != n) printf("Not found.");
    
    if (atual == *inicio)
    {
        *inicio = atual->prox;
        if (*inicio) (*inicio)->ant = NULL;
    }
    else if (atual->prox != NULL)
    {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    else
    {
        atual->ant->prox = NULL;
    }

    num = atual->info;
    free(atual);
    return num;
    
}