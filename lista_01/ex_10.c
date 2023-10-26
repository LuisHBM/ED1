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
    if (!novo) exit(1);

    novo->info = n;
    novo->ant = NULL;
    novo->prox = NULL;

    if(*inicio == NULL)
    {
        *inicio == novo;
        return;
    }

    Nodo *atual = *inicio;
    while ((atual->prox != NULL) && (atual->info < novo->info))
    {
        atual = atual->prox;
    }

    if(atual->info != novo->info) exit(1);

    if (atual == *inicio)
    {
        novo->prox = *inicio;
        if (*inicio) (*inicio)->ant = novo;
        *inicio = novo;
    }
    else if (atual->prox != NULL)
    {
        novo->ant = atual;
        novo->prox = atual->prox;
        atual->prox->ant = novo;
        atual->ant->prox = novo;
    }
    else
    {
        atual->prox = novo;
        novo->ant = atual;
    }
    
}

int retirar(Nodo **inicio, int n)
{

}