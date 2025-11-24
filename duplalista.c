
#include <stdio.h>
#include <stdlib.h>
#include "duplalista.h"

Lista* criarLista() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->head = lista->tail = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserirInicio(Lista *lista, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prev = NULL;
    novo->next = lista->head;
    if (lista->head) lista->head->prev = novo;
    else lista->tail = novo;
    lista->head = novo;
    lista->tamanho++;
}

void inserirFim(Lista *lista, int valor) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;
    novo->prev = lista->tail;
    if (lista->tail) lista->tail->next = novo;
    else lista->head = novo;
    lista->tail = novo;
    lista->tamanho++;
}

void inserirPosicao(Lista *lista, int valor, int pos) {
    if (pos <= 0) { inserirInicio(lista, valor); return; }
    if (pos >= lista->tamanho) { inserirFim(lista, valor); return; }

    Node *atual = lista->head;
    for (int i = 0; i < pos; i++) atual = atual->next;

    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->prev = atual->prev;
    novo->next = atual;
    atual->prev->next = novo;
    atual->prev = novo;
    lista->tamanho++;
}

void removerInicio(Lista *lista) {
    if (!lista->head) return;
    Node *temp = lista->head;
    lista->head = temp->next;
    if (lista->head) lista->head->prev = NULL;
    else lista->tail = NULL;
    free(temp);
    lista->tamanho--;
}

void removerFim(Lista *lista) {
    if (!lista->tail) return;
    Node *temp = lista->tail;
    lista->tail = temp->prev;
    if (lista->tail) lista->tail->next = NULL;
    else lista->head = NULL;
    free(temp);
    lista->tamanho--;
}

void removerPosicao(Lista *lista, int pos) {
    if (pos < 0 || pos >= lista->tamanho) return;
    if (pos == 0) { removerInicio(lista); return; }
    if (pos == lista->tamanho - 1) { removerFim(lista); return; }

    Node *atual = lista->head;
    for (int i = 0; i < pos; i++) atual = atual->next;

    atual->prev->next = atual->next;
    atual->next->prev = atual->prev;
    free(atual);
    lista->tamanho--;
}

Node* encontrarPorValor(Lista *lista, int valor) {
    Node *atual = lista->head;
    int pos = 0;
    while (atual) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na posição %d.\n", valor, pos);
            return atual;
        }
        atual = atual->next;
        pos++;
    }
    printf("Valor %d não encontrado.\n", valor);
    return NULL;
}

Node* encontrarPorPosicao(Lista *lista, int pos) {
    if (pos < 0 || pos >= lista->tamanho) return NULL;
    Node *atual = lista->head;
    for (int i = 0; i < pos; i++) atual = atual->next;
    printf("Elemento na posição %d: %d\n", pos, atual->valor);
    return atual;
}

void mostrarLista(Lista *lista) {
    Node *atual = lista->head;
    printf("Lista: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");
}

void destruirLista(Lista *lista) {
    Node *atual = lista->head;
    while (atual) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }
    free(lista);
    printf("Lista destruída.\n");
}
