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

    int n; cin >> n;


    while(n--){
        stack<char> pilha;
        bool valido = true;

        string ordem; cin >> ordem;

        for(int i=0; i<ordem.size(); i++){
            if(ordem[i] == '(' || ordem[i] == '[' || ordem[i] == '{'){pilha.push(ordem[i]);}
            else if(pilha.empty()){valido = false;}
            else{
                if(pilha.top() == '(' && ordem[i] != ')'){valido = false;}
                else if(pilha.top() == '[' && ordem[i] != ']'){valido = false;}
                else if(pilha.top() == '{' && ordem[i] != '}'){valido = false;}
                else{
                    pilha.pop();
                }
            }
        };
        if(!pilha.empty()){valido = false;}
        if(valido){cout << "YES\n";}else{cout << "NO\n";}

    }



}