#include <iostream>
using namespace std;
typedef long long ll;


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

        bool empty() const { return tamanho == 0; }
        T& top() {return topo->valor;}

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

int main(){

        int n = 1;
        while(n != 0){
            cin >> n;
            if(n != 0){
                while(true){
                    stack<int> pilha;
                    int b = 1;
                    int a;
                    for(int i=0; i<n; i++){
                        cin >> a;
                        if(a == 0){break;}
                        while(b <= n && b <=a){
                            pilha.push(b); b++;
                        };
                        if(pilha.top() == a){pilha.pop();}
                    };
                    if(a == 0){cout << "\n"; break;}
                    if(pilha.empty()){cout << "Yes\n";}else{cout << "No\n";}
                }
            }
        }
    return 0;
}