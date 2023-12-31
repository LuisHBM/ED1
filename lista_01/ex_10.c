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
void eliminar_impar(Nodo**);

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
        printf("\n[1] Inserir / [2] Retirar / [3] Eliminar ímpares: ");
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
            eliminar_impar(&inicio);
            break;
        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }
    return 0;
}

void print(Nodo *inicio)
{
    printf("\nLista Crescente: ");
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
    novo->ant = NULL;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio;
    while((atual->prox != NULL) && (atual->info < novo->info))
    {
        atual = atual->prox;
    }

    if ((atual->prox == NULL) && (atual->info < novo->info))
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
    if (*inicio == NULL)
    {
        return 0;
    }

    Nodo *atual = *inicio;
    while((atual->prox != NULL) && (atual->info != n))
    {
        atual = atual->prox;
    }

    if (atual->info != n) return 0;

    if (atual == *inicio)
    {
        *inicio = atual->prox;
        if (atual->prox != NULL)
        {
            atual->prox->ant = NULL;
        }
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

    int num = atual->info;
    free(atual);
    
    return num;
}

void eliminar_impar(Nodo **inicio)
{
    Nodo *atual = *inicio, *aux;
    while (atual != NULL)
    {

        if ((atual->info % 2) != 0)
        {
            aux = atual;
            atual = atual->prox;
            retirar(inicio, aux->info);
        }
        else
        {
            atual = atual->prox;
        }
    }
}