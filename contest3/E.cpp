#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>> pares;
    vector<long long> posicoes;
    for(int i=0; i<n; i++){
        pair<long long, long long> aluno;
        cin >> aluno.first >> aluno.second;
        posicoes.push_back(aluno.first);
        aluno.second += 1;
        posicoes.push_back(aluno.second);
        pares.push_back(aluno);
    };

    sort(posicoes.begin(), posicoes.end());
    posicoes.erase(unique(posicoes.begin(), posicoes.end()), posicoes.end());
    vector<long long> parametro(posicoes.size(), 0);
    for(int i=0; i<pares.size(); i++){
        auto lugar1 = lower_bound(posicoes.begin(), posicoes.end(), pares[i].first) - posicoes.begin();
        auto lugar2 = lower_bound(posicoes.begin(), posicoes.end(), pares[i].second) -posicoes.begin();
        parametro[lugar1]++;
        parametro[lugar2]--;
    };

    vector<long long> somatorio(posicoes.size(), 0);

    for(int i=0; i<posicoes.size(); i++){
        if(i==0){
            somatorio[i] = parametro[i];
        }
        else{
            somatorio[i] = somatorio[i-1] + parametro[i];
        };
    };

    bool leu_primeiro;
    bool leu_ultimo;
    if(posicoes[0] == 1){
        leu_primeiro = true;
    }
    else{
        leu_primeiro = false;
    }

    if(posicoes[posicoes.size() - 1] == m+1){
        leu_ultimo = true;
    }
    else{
        leu_ultimo = false;
    }

    if(leu_primeiro == false && leu_ultimo == false){
        cout << m;
    }
    else if(leu_ultimo == false){
        long long primeiro = 0;
        for(int i=0; i<somatorio.size(); i++){
            if(somatorio[i] == 0){
                primeiro = i;
                break;
            };
        };
        cout << m - posicoes[primeiro];
    }

    else if(leu_primeiro == false){
        long long d = 1;
        for(int i=0; i<somatorio.size(); i++){
            if(somatorio[i] == 0  && i != somatorio.size() - 1){
                d = somatorio[i + 1] - 1;
            }
        };
        cout << d;
    }

    else{
        long long primeiro = 0;
        long long ultimo;
        for(int i=0; i<somatorio.size(), i++){
            if(somatorio[i] == 0  && primeiro == 0){
                primeiro = i;
            };
            if(somatorio[i] == 0 && i != )
        }
    }


    
    





    return 0;

}