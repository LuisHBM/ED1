#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *prox;
} Nodo;

void insere(Nodo**, int);
void print(Nodo*);
void retira(Nodo**, int);
void eliminaRepetido(Nodo**);

int main()
{
    Nodo *inicio = NULL;
    int num;

    while(1)
    {
        print(inicio);
        printf("\nDigite o número ([0]-Sair): ");
        scanf("%d", &num);
        if (num == 0) break;
        else insere(&inicio, num);
    }

    eliminaRepetido(&inicio);
    print(inicio);

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

void retira(Nodo **inicio, int n)
{
    if(!*inicio) exit(1);

    Nodo *atual = *inicio, *ant;
    while ((atual != NULL) && (atual->info != n))
    {
        ant = atual;
        atual = atual->prox;        
    }
    
    if (atual == NULL)
    {
        printf("Não encontrado");
        return;
    }
    else if (atual == *inicio)
    {
        *inicio = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }

    free(atual);
}

void eliminaRepetido(Nodo **inicio)
{
    Nodo *atual = *inicio;
    while (atual != NULL)
    {
        Nodo *auxProx = atual->prox;

        Nodo *atual2 = atual->prox;
        while (atual2 != NULL)
        {
            if (atual2->info == atual->info)
            {
                retira(inicio, atual->info);
            }

            atual2 = atual2->prox;
        }
        
        atual = auxProx;
    } 
}