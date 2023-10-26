#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
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

void insere(int n, Nodo **inicio)
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

    if (atual == *inicio)
    {
        novo->prox = atual;
        *inicio = novo;
    }
    else if (atual == NULL)
    {
        ant->prox = novo;
    }
    else
    {
        ant->prox = novo;
        novo->prox = atual;
    }
    
}

int retira(int n, Nodo **inicio)
{
    if (*inicio == NULL) return 0;

    Nodo *atual = *inicio, *ant;
    while ((atual != NULL) && (atual->info != n))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) exit(1);

    if (atual == *inicio)
    {
        *inicio = atual->prox;
    }
    else 
    {
        ant->prox = atual->prox;
    }

    int num = atual->info;
    free(atual);

    return num;
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