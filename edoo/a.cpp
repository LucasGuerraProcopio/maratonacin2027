#include <iostream>
using namespace std;

template <typename T>
class queue {
private:
    struct No {
        T valor;
        No* prox;
        No(const T& v) : valor(v), prox(nullptr) {}
    };

    No* inicio;
    No* fim;
    int tamanho;

public:
    queue() : inicio(nullptr), fim(nullptr), tamanho(0) {}

    queue(const queue& outra) : inicio(nullptr), fim(nullptr), tamanho(0) {
        No* p = outra.inicio;
        while (p != nullptr) {
            push(p->valor);
            p = p->prox;
        }
    }

    queue& operator=(const queue& outra) {
        if (this != &outra) {
            while (!empty()) pop();
            No* p = outra.inicio;
            while (p != nullptr) {
                push(p->valor);
                p = p->prox;
            }
        }
        return *this;
    }

    ~queue() {
        while (!empty()) pop();
    }

    bool empty() const { return tamanho == 0; }
    int  size()  const { return tamanho; }

    T& front() { return inicio->valor; }
    T& back()  { return fim->valor; }

    void push(const T& v) {
        No* novo = new No(v);
        if (fim == nullptr) {
            inicio = fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        tamanho++;
    }

    void pop() {
        if (inicio == nullptr) return;
        No* temp = inicio;
        inicio = inicio->prox;
        if (inicio == nullptr) fim = nullptr;
        delete temp;
        tamanho--;
    }
};

int main() {
    int c;
    cin >> c;
    while (c--) {
        int l, m;
        cin >> l >> m;
        l *= 100;

        queue<int> esq, dir;
        for (int i = 0; i < m; i++) {
            int tam;
            string lado;
            cin >> tam >> lado;
            if (lado == "left") esq.push(tam);
            else                dir.push(tam);
        }

        int travessias = 0;
        bool noEsquerdo = true;

        while (!esq.empty() || !dir.empty()) {
            queue<int>& atual = noEsquerdo ? esq : dir;

            int usado = 0;
            while (!atual.empty() && usado + atual.front() <= l) {
                usado += atual.front();
                atual.pop();
            }

            travessias++;
            noEsquerdo = !noEsquerdo;
        }

        cout << travessias << "\n";
    }
    return 0;
}