#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void insere(int, Nodo**, Nodo**);
int retira(Nodo**);
void print_fila(Nodo*);

int main()
{
    char opcao;
    int valor;
    Nodo *inicio = NULL;
    Nodo *fim = NULL;

    while(1)
    {
        if (inicio)
        {
            print_fila(inicio);
        }
        printf("\n[1] Inserir / [2] Retirar: ");
        scanf(" %c", &opcao);
        switch (opcao)
        {
        case '1':
            printf("Digite o valor: ");
            scanf("%d", &valor);
            insere(valor, &inicio, &fim);
            break;
        case '2':
            valor = retira(&inicio);
            printf("\nValor retirado = %d", valor);
            break;
        default:
            printf("\nSaindo.\n");
            exit(1);
        }
    }

    return 0;
}

void insere(int n, Nodo **inicio, Nodo **fim)
{
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) exit(1);

    novo->info = n;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        (*fim)->prox = novo;
    }
    *fim = novo;
}

int retira(Nodo **inicio)
{
    Nodo *aux;
    int n;

    if (*inicio == NULL)
    {
        printf("\nERRO: Fila vazia!");
        exit(1);
    }

    n = (*inicio)->info;
    aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);

    return n;
}

void print_fila(Nodo *inicio)
{
    printf("\n Fila: ");
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

