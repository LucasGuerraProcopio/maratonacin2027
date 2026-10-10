#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


vector<string> possibilidades;

void fazedor(string comparacao, string atual, int n, int iguais, int posicao, int limite){
    if(atual[posicao] == comparacao[posicao]){
        iguais += 1;
    };
    if(iguais > limite){return;};

    if(atual.length() == n){
        if(iguais == limite){
            possibilidades.push_back(atual);
        };
    }
    else{
        fazedor(comparacao, atual +'0', n, iguais, posicao+1, limite);
        fazedor(comparacao, atual +'1', n, iguais, posicao+1, limite);
    }
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    long long resposta = 0;
    long long igualdades = 0;
    bool valido;
    vector<pair<string, int>> pares;
    for(int i=0; i<m; i++){
        pair<string, int> rodada;
        cin >> rodada.first >> rodada.second;
        pares.push_back(rodada);
    };

    fazedor(pares[0].first, "0", n, 0, 0, pares[0].second);
    fazedor(pares[0].first, "1", n, 0, 0, pares[0].second);

    for(int i=0; i<possibilidades.size(); i++){
        valido = true;
        for(int j=1; j<m; j++){
            igualdades = 0;
            if(possibilidades[i] != pares[j].first){
                for(int r=0; r<n; r++){
                    if(possibilidades[i][r] == pares[j].first[r]){
                        igualdades += 1;
                    };
                };
                if(igualdades != pares[j].second){valido = false;}
            }
            else{
                valido = false;
            };
        };
        if(valido){resposta += 1;}
    }

    cout << resposta;

    return 0;
}