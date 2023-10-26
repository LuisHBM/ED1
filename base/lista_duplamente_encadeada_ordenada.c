#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox, *ant;
} Nodo;

void inserir(Nodo**, int);
int retirar(Nodo**, int);
void print(Nodo**);

int main()
{
    char opcao;
    int valor;
    Nodo *inicio = NULL;

    while(1)
    {
        if (inicio)
        {
            print(&inicio);
        }
        printf("\n[1] Inserir / [2] Retirar: ");
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
        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }

    return 0;
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
    while((atual->prox != NULL) && (novo->info > atual->info)) atual = atual->prox;

    if ((atual->prox == NULL) && (novo->info > atual->info))
    {
        atual->prox = novo;
        novo->ant = atual;
    }
    else if (atual == *inicio)
    {
        novo->prox = atual;
        atual->ant = novo;
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
    if (*inicio == NULL) return 0;

    Nodo *atual = *inicio;
    while((atual->prox != NULL) && (atual->info != n)) atual = atual->prox;

    if (atual->info != n) return 0;

    if (atual == *inicio)
    {
        *inicio = atual->prox;
        if (atual->prox != NULL) (*inicio)->ant = NULL;
    }
    else if(atual->prox == NULL)
    {
        atual->ant->prox = NULL;
    }
    else
    {
        atual->prox->ant = atual->ant;
        atual->ant->prox = atual->prox;
    }

    int num = atual->info;
    free(atual);

    return num;
}

void print(Nodo **inicio)
{
    Nodo *atual = *inicio;

    printf("\nLista: ");
    while(atual != NULL)
    {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
}
