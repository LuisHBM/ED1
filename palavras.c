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

void menu(Nodo**, Nodo**, Nodo**);
void inserir(Nodo**, Nodo**);
void editar(Nodo**);
void eliminar(Nodo**, Nodo**, Nodo**);
void palavraAnt(Nodo**);
void palavraProx(Nodo**);
int compare(char, char);

int main()
{
    Nodo *inicio = NULL;
    Nodo *fim = NULL;
    Nodo *atual = NULL;

    inserir(&inicio, &fim);
    atual = inicio;

    while (1)
    {
        menu(&inicio, &fim, &atual);
    }
}

void menu(Nodo **inicio, Nodo **fim, Nodo** atual)
{
    char resposta;
    printf("Palavra atual: %s", (*atual)->palavra);
    printf("\n       E: Editar palavra atual");
    printf("\n       D:Inserir (depois da palavra atual)");
    printf("\n       S:Eliminar palavra");
    printf("\n       <:Palavra anterior");
    printf("\n       >:Palavra posterior");
    printf("\n       X:Sair\n");
    scanf(" %c", &resposta);

    switch (resposta)
    {
        case 'E': editar(atual);
        break;
        case 'D': inserir(inicio, fim);
        break;
        case 'S': eliminar(inicio, fim, atual);
        break;
        case '<': palavraAnt(atual);
        break;
        case '>': palavraProx(atual);
        break;
        case 'X': exit(1);
        default: exit(1);
    }
}

void inserir(Nodo **inicio, Nodo **fim)
{
    Nodo *novoNodo = (Nodo*)malloc(sizeof(Nodo));

    if (novoNodo == NULL)
    {
        printf("No memory to allocate.");
        exit(1);
    }

    novoNodo->ant = NULL;
    novoNodo->prox = NULL;

    puts("Digite a nova palavra:");
    scanf("%s", novoNodo->palavra);

    if (*inicio == NULL)
    {
        puts("tome");
        novoNodo->ant = novoNodo;
        novoNodo->prox = novoNodo;

        *inicio = novoNodo;
        *fim = novoNodo;
    }
    else
    {
        // (*fim)->prox = novoNodo;
        // novoNodo->ant = *fim;

        // novoNodo->prox = *inicio;
        // (*inicio)->ant = novoNodo;
    }

}

void editar(Nodo **atual)
{
    char palavra[TAM];

    printf("Digite a nova palavra:");
    scanf("%s", palavra);
    strcpy((*atual)->palavra, palavra);
}

void eliminar(Nodo **inicio, Nodo **fim, Nodo **atual)
{

}

void palavraAnt(Nodo **atual)
{
    (*atual)->ant = *atual;
}

void palavraProx(Nodo **atual)
{
    (*atual)->prox = *atual;
}