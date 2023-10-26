#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

typedef struct nodo
{
    char palavra[TAM];
    struct nodo *prox;
    struct nodo *ant;
} Nodo;

void print_lista(Nodo*, Nodo*);
void inserir(Nodo**, Nodo**, Nodo**);
void editar(Nodo**);
void eliminar(Nodo**, Nodo**, Nodo**);
void palavraAnt(Nodo**);
void palavraProx(Nodo**);

int main()
{
    Nodo *inicio = NULL;
    Nodo *fim = NULL;
    Nodo *atual = NULL;

    inserir(&inicio, &fim, &atual);

    while (1)
    {
        char resposta;
        print_lista(inicio, fim);
        if (atual != NULL) printf("\nPalavra atual: %s", atual->palavra);
        printf("\n       E: Editar palavra atual");
        printf("\n       D: Inserir (depois da palavra atual)");
        printf("\n       S: Eliminar palavra atual");
        printf("\n       <: Palavra anterior");
        printf("\n       >: Palavra posterior");
        printf("\n       X: Sair\n");
        scanf(" %c", &resposta);

        switch (resposta)
        {
            case 'E': editar(&atual);
            break;
            case 'D': inserir(&inicio, &fim, &atual);
            break;
            case 'S': eliminar(&inicio, &fim, &atual);
            break;
            case '<': palavraAnt(&atual);
            break;
            case '>': palavraProx(&atual);
            break;
            case 'X': exit(1);
            default: exit(1);
        }
    }
}

void print_lista(Nodo *inicio, Nodo *fim)
{
    printf("\nLista Circular: ");
    if (inicio != NULL)
    {
        while(1)
        {
            printf("%s ", inicio->palavra);
            if (inicio == fim) break;
            inicio = inicio->prox;
        }
    }
}

void inserir(Nodo **inicio, Nodo **fim, Nodo **atual)
{
    char palavra[TAM];
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) exit(1);

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    if (*inicio == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        *inicio = *fim = *atual = novo;
    }
    else if (*fim == *atual)
    {
        novo->ant = *fim;
        novo->prox = *inicio;
        (*fim)->prox = novo;
        (*inicio)->ant = novo;
        *fim = novo;
    }
    else
    {
        novo->ant = *atual;
        novo->prox = (*atual)->prox;
        (*atual)->prox->ant = novo;
        (*atual)->prox = novo;
    }

    strcpy(novo->palavra, palavra);
}

void eliminar(Nodo **inicio, Nodo **fim, Nodo **atual)
{

    if (*inicio == NULL)
    {
        printf("Sem palavras para excluir!");
        return;
    }

    if (*fim == *atual && *inicio == *atual)
    {
        *inicio = *fim = *atual = NULL;
        free(*atual);
        return;
    }

    Nodo *aux = (*atual)->prox;
    if (*fim == *atual || *inicio == *atual)
    {
        (*inicio)->ant = *fim;
        (*fim)->prox = *inicio;
        if (*inicio == *atual) *inicio = (*inicio)->prox;
        else *fim = (*fim)->ant;
    }
    else
    {
        (*atual)->ant->prox = (*atual)->prox;
        (*atual)->prox->ant = (*atual)->ant;
    }
    
    
    free(*atual);
    *atual = aux;
}

void editar(Nodo **atual)
{
    char palavra[TAM];
    printf("Digite a nova palavra: ");
    scanf("%s", palavra);

    strcpy((*atual)->palavra, palavra);
}

void palavraAnt(Nodo **atual)
{
    *atual = (*atual)->ant;
}

void palavraProx(Nodo **atual)
{
    *atual = (*atual)->prox;
}