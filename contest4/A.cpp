#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    long long n, m; cin >> n >> m;
    string palavra; cin >> palavra;
    vector<pair<long long, long long>> posicoes;
    for(int i=0; i<n-1; i++){
        if(palavra[i] == 'A' && palavra[i+1] == 'C'){
            pair<long long, long long> posicao;
            posicao.first = i;
            posicao.second = i+1;
            posicoes.push_back(posicao);
        };
    };

    vector<long long> fins(n);
    for(int i=0; i<posicoes.size(); i++){
        fins[posicoes[i].second] = 1;
    }

    vector<long long> somatorio(n);
    somatorio[0] = 0;
    for(int i=1; i<n; i++){
        somatorio[i] = somatorio[i-1] + fins[i];
    };

    vector<pair<long long, long long>> intervalos;
    for(int i=0; i<m; i++){
        pair<long long, long long> atual;
        cin >> atual.first >> atual.second;
        atual.first--; atual.second--;
        intervalos.push_back(atual);
    };

    for(int i=0; i<m; i++){
        cout << somatorio[intervalos[i].second] - somatorio[intervalos[i].first] << "\n";
    }

    return 0;
}