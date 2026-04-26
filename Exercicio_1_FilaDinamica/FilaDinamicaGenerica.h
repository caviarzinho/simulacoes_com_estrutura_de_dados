#ifndef FILADINAMICAGENERICA_H_INCLUDED
#define FILADINAMICAGENERICA_H_INCLUDED

#include <iostream>

using namespace std;

// Estrutura do Nó que compõe a fila
template <typename T>
struct No
{
    T dado;
    No<T> *proximo;
};

// Estrutura da Fila Dinâmica
template <typename T>
struct FilaDinamicaGenerica
{
    int cardinalidade;
    No<T> *inicio;
    No<T> *fim;
};

// --- Operações ---

template <typename T>
void cria(FilaDinamicaGenerica<T> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

template <typename T>
bool ehVazia(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade == 0;
}

/** * Em filas dinâmicas, teoricamente sempre há espaço
 * até que a memória do sistema se esgote.
 */
template <typename T>
bool temEspaco(FilaDinamicaGenerica<T> fila)
{
    return true;
}

template <typename T>
int numeroDeElementos(FilaDinamicaGenerica<T> fila)
{
    return fila.cardinalidade;
}

template <typename T>
bool existeElemento(FilaDinamicaGenerica<T> fila, T elemento)
{
    No<T> *aux = fila.inicio;
    while (aux != nullptr)
    {
        if (aux->dado == elemento)
            return true;
        aux = aux->proximo;
    }
    return false;
}

template <typename T>
bool existePosicao(FilaDinamicaGenerica<T> fila, int posicao)
{
    return (posicao >= 1) && (posicao <= fila.cardinalidade);
}

template <typename T>
T umElemento(FilaDinamicaGenerica<T> fila, int posicao)
{
    if (posicao < 1 || posicao > fila.cardinalidade)
    {
        throw "POSICAO INVALIDA";
    }
    No<T> *aux = fila.inicio;
    for (int i = 1; i < posicao; i++)
    {
        aux = aux->proximo;
    }
    return aux->dado;
}

template <typename T>
int posicao(FilaDinamicaGenerica<T> fila, T elemento)
{
    No<T> *aux = fila.inicio;
    int cont = 1;
    while (aux != nullptr)
    {
        if (aux->dado == elemento)
            return cont;
        aux = aux->proximo;
        cont++;
    }
    throw "ELEMENTO NAO ESTA NA FILA";
}

template <typename T>
T primeiro(FilaDinamicaGenerica<T> fila)
{
    if (ehVazia(fila))
        throw "FILA VAZIA";
    return fila.inicio->dado;
}

template <typename T>
T ultimo(FilaDinamicaGenerica<T> fila)
{
    if (ehVazia(fila))
        throw "FILA VAZIA";
    return fila.fim->dado;
}

template <typename T>
void insere(FilaDinamicaGenerica<T> &fila, T elemento)
{
    No<T> *novo = new No<T>;
    novo->dado = elemento;
    novo->proximo = nullptr;

    if (ehVazia(fila))
    {
        fila.inicio = novo;
    }
    else
    {
        fila.fim->proximo = novo;
    }

    fila.fim = novo;
    fila.cardinalidade++;
}

template <typename T>
void retira(FilaDinamicaGenerica<T> &fila)
{
    if (ehVazia(fila))
    {
        throw "UNDERFLOW";
    }
    No<T> *aux = fila.inicio;
    fila.inicio = fila.inicio->proximo;

    // Se a fila ficou vazia, o fim também deve ser nulo
    if (fila.inicio == nullptr)
    {
        fila.fim = nullptr;
    }

    delete aux;
    fila.cardinalidade--;
}

template <typename T>
void mostra(FilaDinamicaGenerica<T> fila)
{
    No<T> *aux = fila.inicio;
    while (aux != nullptr)
    {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

#endif // FILADINAMICAGENERICA_H_INCLUDED