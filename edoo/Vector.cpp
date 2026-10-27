#include <iostream>
using namespace std;

template <typename T>
class vector {
private:
    T* dados;
    int tamanho;
    int capacidade;

    void realocar(int novaCapacidade) {
        T* novo = new T[novaCapacidade];
        for (int i = 0; i < tamanho; i++) {
            novo[i] = dados[i];
        }
        delete[] dados;
        dados = novo;
        capacidade = novaCapacidade;
    }

public:
    vector() : dados(nullptr), tamanho(0), capacidade(0) {}

    vector(const vector& outra) : dados(nullptr), tamanho(outra.tamanho), capacidade(outra.tamanho) {
        if (capacidade > 0) {
            dados = new T[capacidade];
            for (int i = 0; i < tamanho; i++) {
                dados[i] = outra.dados[i];
            }
        }
    }

    vector& operator=(const vector& outra) {
        if (this != &outra) {
            delete[] dados;
            tamanho = outra.tamanho;
            capacidade = outra.tamanho;
            dados = nullptr;
            if (capacidade > 0) {
                dados = new T[capacidade];
                for (int i = 0; i < tamanho; i++) {
                    dados[i] = outra.dados[i];
                }
            }
        }
        return *this;
    }

    ~vector() {
        delete[] dados;
    }

    bool empty() const { return tamanho == 0; }
    int  size()  const { return tamanho; }
    int  capacity() const { return capacidade; }

    T& operator[](int i) { return dados[i]; }
    const T& operator[](int i) const { return dados[i]; }

    T& front() { return dados[0]; }
    T& back()  { return dados[tamanho - 1]; }

    void push_back(const T& v) {
        if (tamanho == capacidade) {
            realocar(capacidade == 0 ? 1 : capacidade * 2);
        }
        dados[tamanho++] = v;
    }

    void pop_back() {
        if (tamanho == 0) return;
        tamanho--;
    }

    void clear() {
        tamanho = 0;
    }
};