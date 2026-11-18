#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Key, typename E>
class BSTNo {
public:
    Key chave;
    E elemento;
    BSTNo* esquerda;
    BSTNo* direita;

    BSTNo(const Key& k, const E& e)
        : chave(k), elemento(e), esquerda(nullptr), direita(nullptr) {}
};

typedef BSTNo<int, int> No;


void trocador(No* raiz, int profundidade, int k) {
    if (raiz == nullptr) return;                  
    if (profundidade % k == 0) swap(raiz->esquerda, raiz->direita);
    trocador(raiz->esquerda, profundidade + 1, k);
    trocador(raiz->direita, profundidade + 1, k);
}

void inorder(No* rt, vector<int>& saida) {
    if (rt == nullptr) return;
    inorder(rt->esquerda, saida);
    saida.push_back(rt->chave);
    inorder(rt->direita, saida);
}

void liberar(No* rt) {
    if (rt == nullptr) return;
    liberar(rt->esquerda);
    liberar(rt->direita);
    delete rt;
}

int main() {

    int n;
    cin >> n;
    vector<No*> nos(n + 1, nullptr);
    for (int i = 1; i <= n; i++) nos[i] = new No(i, i);

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a != -1) nos[i]->esquerda = nos[a];
        if (b != -1) nos[i]->direita = nos[b];
    }
    No* raiz = nos[1];

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        trocador(raiz, 1, k);

        vector<int> saida;
        inorder(raiz, saida);
        for (size_t i = 0; i < saida.size(); i++) {
            if (i == 0){cout << saida[i];}
            else{cout << " " << saida[i];}
            
        }
        cout << "\n";
    }

    return 0;
}