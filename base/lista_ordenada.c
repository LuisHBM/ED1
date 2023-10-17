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
    Nodo *novo, *ant, *atual;

    novo = (Nodo*)malloc(sizeof(Nodo));
    if(!novo) exit(1);
    novo->info = n;

    if(*inicio == NULL)
    {
        novo->prox = NULL;
        *inicio = novo;
        return;
    }

    ant = NULL;
    atual = *inicio;

    while((atual != NULL) && (novo->info > atual->info))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        ant->prox = novo;
        novo->prox = NULL;
    }
    else if (atual == (*inicio))
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

int retira(int n, Nodo **inicio)
{
    Nodo *ret, *ant, *atual;
    int num;

    ant = NULL;
    atual = *inicio;
    while((atual != NULL) && (n != atual->info))
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) 
    {
        printf("\nNumero não existe\n");
        return 0;
    }
    if (atual == (*inicio))
    {
        ret = *inicio;
        *inicio = (*inicio)->prox;
    }
    else
    {
        ret = atual;
        ant->prox = atual->prox;
    }

    num = ret->info;
    free(ret);

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