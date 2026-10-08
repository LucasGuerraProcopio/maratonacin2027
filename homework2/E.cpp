#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, q, inicio, fim;
    cin >> n >> m >> q;
    long long contador = 0;
    long long atual = 0;
    vector<long long> lampadas;
    vector<long long> parametro;
    vector<pair<long long, long long>> duplas;
    vector<long long> salas(m);
    for(int i=0; i<m; i++){
        cin >> salas[i];
    };
    sort(salas.begin(), salas.end());
    for(int j=0; j<q; j++){
        pair<long long, long long> rodada;
        cin >> rodada.first >> rodada.second;
        rodada.second += 1;
        duplas.push_back(rodada);
        lampadas.push_back(rodada.first);
        lampadas.push_back(rodada.second);
    }
    sort(lampadas.begin(), lampadas.end());
    lampadas.erase(unique(lampadas.begin(), lampadas.end()), lampadas.end());
    for(int w=0; w<lampadas.size(); w++){
        parametro.push_back(0);
    };

    for(int t=0; t<q; t++){
        inicio = lower_bound(lampadas.begin(), lampadas.end(), duplas[t].first) - lampadas.begin();
        fim = lower_bound(lampadas.begin(), lampadas.end(), duplas[t].second) - lampadas.begin();
        parametro[inicio]++;
        if(fim <= lampadas.size() - 1){
            parametro[fim]--;
        }
    };

    vector<long long> somatorio(parametro.size());
    for(int g=0; g<parametro.size(); g++){
        if(g==0){
            somatorio[g] = parametro[0];
        }
        else{
            somatorio[g] = somatorio[g-1] + parametro[g];
        }
    }

    for(int u=0; u<m; u++){
        while(atual < lampadas.size() && salas[u] >= lampadas[atual] ){
            atual++;
        }
        if(atual > 0){
            if(somatorio[atual-1] % 2 == 1){
                contador += 1;
            };
        };
    };

    cout << contador;

    return 0;
}
