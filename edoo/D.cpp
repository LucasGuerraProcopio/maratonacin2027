#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int CalculaChave(string& palavra){
    ll soma = 0;
    for(int i=0; i<palavra.size(); i++){
        soma += (ll)(unsigned char)palavra[i] * (i+1);
    }
    return (soma * 19) % 101;
};

int CalculaPosicao(int chave, int j){
    return(chave + j*j + 23*j) % 101;
};

struct valores{
    string chave;
    bool ocupado = false;
};

class DicionariosHash{
    private:
        int tamanho;
        vector<valores> posicoes;

    public:
        DicionariosHash() : tamanho(0), posicoes(101) {}

        int buscar(string &essa){
            int res = CalculaChave(essa);
            for(int j=0; j<20; j++){
                int posicao = CalculaPosicao(res, j);
                if(posicoes[posicao].ocupado && posicoes[posicao].chave == essa){return posicao;}
            }
            return -1;
        };

        void inserir(string &essa){
            if(buscar(essa) != -1){return;}
            int chave = CalculaChave(essa);
            for(int j=0; j<20; j++){
                int tentativa = CalculaPosicao(chave, j);
                if(!posicoes[tentativa].ocupado){
                    posicoes[tentativa].ocupado = true;
                    posicoes[tentativa].chave = essa;
                    tamanho++;
                    return;
                }
            }
        }

        void remover(string &essa){
            int tentativa = buscar(essa);
            if(tentativa == -1){return;}
            posicoes[tentativa].ocupado = false;
            posicoes[tentativa].chave.clear();
            tamanho--;
        };

        void printador(){
            cout << tamanho << "\n";
            for(int i=0; i<101; i++){
                if(posicoes[i].ocupado){
                    cout << i << ':' << posicoes[i].chave << "\n";
                }
            }
        }

};


int main(){
    int t; cin >> t;
    while(t--){
        DicionariosHash tabela;
        int n; cin >> n;
        for(int i=0; i<n; i++){
            string linha; cin >> linha;
            string chave = linha.substr(4);
            if(linha[0] == 'A' && linha[1] == 'D' && linha[2] == 'D'){
                tabela.inserir(chave);
            }
            else{
                tabela.remover(chave);
            }
        };
        tabela.printador();
    }

    return 0;
}