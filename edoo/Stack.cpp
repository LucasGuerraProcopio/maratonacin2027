#include <iostream>
using namespace std;

template <typename T>
class stack {
private:
    struct No {
        T valor;
        No* prox;
        No(const T& v) : valor(v), prox(nullptr) {}
    };

    No* topo;
    int tamanho;

public:
    stack() : topo(nullptr), tamanho(0) {}

    stack(const stack& outra) : topo(nullptr), tamanho(0) {
        if (outra.topo == nullptr) return;

        // Copia preservando a ordem original (sem inverter a pilha)
        topo = new No(outra.topo->valor);
        No* atual = topo;
        No* p = outra.topo->prox;
        while (p != nullptr) {
            atual->prox = new No(p->valor);
            atual = atual->prox;
            p = p->prox;
        }
        tamanho = outra.tamanho;
    }

    stack& operator=(const stack& outra) {
        if (this != &outra) {
            while (!empty()) pop();

            if (outra.topo != nullptr) {
                topo = new No(outra.topo->valor);
                No* atual = topo;
                No* p = outra.topo->prox;
                while (p != nullptr) {
                    atual->prox = new No(p->valor);
                    atual = atual->prox;
                    p = p->prox;
                }
                tamanho = outra.tamanho;
            }
        }
        return *this;
    }

    ~stack() {
        while (!empty()) pop();
    }

    bool empty() const { return tamanho == 0; }
    int  size()  const { return tamanho; }

    T& top() { return topo->valor; }

    void push(const T& v) {
        No* novo = new No(v);
        novo->prox = topo;
        topo = novo;
        tamanho++;
    }

    void pop() {
        if (topo == nullptr) return;
        No* temp = topo;
        topo = topo->prox;
        delete temp;
        tamanho--;
    }
};