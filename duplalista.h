
#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    int valor;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int tamanho;
} Lista;

Lista* criarLista();
void inserirInicio(Lista *lista, int valor);
void inserirFim(Lista *lista, int valor);
void inserirPosicao(Lista *lista, int valor, int pos);
void removerInicio(Lista *lista);
void removerFim(Lista *lista);
void removerPosicao(Lista *lista, int pos);
Node* encontrarPorValor(Lista *lista, int valor);
Node* encontrarPorPosicao(Lista *lista, int pos);
void mostrarLista(Lista *lista);
void destruirLista(Lista *lista);

#endif
