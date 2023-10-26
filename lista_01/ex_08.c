#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
}Nodo;

void inserir(Nodo**, int);
void print(Nodo**, Nodo**);
void print_interssecao(Nodo**);
void interssecao(Nodo**, Nodo**, Nodo**);

int main()
{
    Nodo *a = NULL, *b = NULL, *c = NULL;
    int num;

    while(1)
    {
        print(&a, &b);
        printf("\nLISTA A: Digite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else inserir(&a, num);
    }
    while(1)
    {
        print(&a, &b);
        printf("\nLISTA B: Digite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else inserir(&b, num);
    }

    interssecao(&a, &b, &c);
    print_interssecao(&c);

    return 0;
}

void inserir(Nodo **inicio, int n)
{
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if(!novo) exit(1);

    novo->info = n;
    novo->prox = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }

    Nodo *atual = *inicio;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
}

void print(Nodo **a, Nodo **b)
{
    Nodo *atual;

    printf("\nLista A: ");
    atual = *a;
    while (atual != NULL)
    {
       printf("%d ", atual->info);
       atual = atual->prox;
    }

    printf("\nLista B: ");
    atual = *b;
    while (atual != NULL)
    {
       printf("%d ", atual->info);
       atual = atual->prox;
    }
}

void print_interssecao(Nodo **c)
{
    Nodo *atual;

    printf("\nInterssecao: ");
    atual = *c;
    while (atual != NULL)
    {
       printf("%d ", atual->info);
       atual = atual->prox;
    }

}

void interssecao(Nodo **a, Nodo **b, Nodo **c)
{
    if ((*a == NULL) || (*b == NULL))
    {
        *c = NULL;
        return;
    }

    Nodo *atual = *a;
    while(atual != NULL)
    {
        Nodo *atual2 = *b;
        while (atual2 != NULL)
        {
            if (atual->info == atual2->info)
            {
                Nodo *verifar = *c;
                while (verifar != NULL)
                {
                    if (atual->info == verifar->info) break;
                    verifar = verifar->prox;
                }
                if (verifar == NULL)
                {
                    inserir(c, atual->info);
                    break;
                }
            }
            atual2 = atual2->prox;
        }
        atual = atual->prox;
    }
}