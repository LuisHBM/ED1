#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox, *ant;
} Nodo;

void insere(int, Nodo**);
int retira(int, Nodo**);
void print_lista(Nodo*);

int main()
{
    char opcao;
    int valor;
    Nodo *inicio = NULL;

    while(1)
    {
        if (inicio)
        {
            print_lista(inicio);
        }
        printf("\n[1] Inserir / [2] Retirar: ");
        scanf(" %c", &opcao);
        switch (opcao)
        {
        case '1':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            insere(valor, &inicio);
            break;
        case '2':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            valor = retira(valor, &inicio);
            printf("\nValor retirado = %d", valor);
            break;
        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }

    return 0;
}

int retira(int n, Nodo **inicio)
{   
    Nodo *atual, *ret;
    int num;
    atual = *inicio;
    if (*inicio == NULL) exit(1);

    while((atual->prox != NULL) && (atual->info != n))
    {
        atual = atual->prox;
    }

    if (atual->info != n) return 0;
    if (atual == *inicio)
    {
        ret = *inicio;
        *inicio = (*inicio)->prox;
        if ((*inicio) != NULL)
        {
            (*inicio)->ant = NULL;
        }
    }
    else if (atual->prox != NULL)
    {
        ret = atual;
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    else
    {
        ret = atual;
        atual->ant->prox = NULL;
    }

    num = ret->info;
    free(ret);

    return num;
}

void insere(int n, Nodo **inicio)
{
    Nodo *novo, *atual;

    novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) exit(1);
    novo->info = n;

    if (*inicio == NULL)
    {
        novo->prox = NULL;
        novo->ant = NULL;
        *inicio = novo;
        return;
    }

    atual = *inicio;
    while((atual->prox != NULL) && (novo->info > atual->info))
    {
        atual = atual->prox;
    }

    if ((atual->prox == NULL) && (novo->info > atual->info))
    {
        atual->prox = novo;
        novo->ant = atual;
        novo->prox = NULL;
    }
    else if (atual == *inicio)
    {
        novo->prox = *inicio;
        novo->ant = NULL;
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

void print_lista(Nodo *inicio)
{
    printf("\n Lista Ordenada: ");
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