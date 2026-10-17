#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;

    vector<vector<string>> nomes;

    for(int i=0; i<n; i++){
        int m; cin >> m;
        vector<string> pessoa;
        for(int i=0; i<m; i++){
            string atual; cin >> atual;
            pessoa.push_back(atual);
        };
        sort(pessoa.begin(), pessoa.end());
        nomes.push_back(pessoa);
    };

    vector<int> posicoes;
    bool rodada;

    posicoes.push_back(0);

    for(int i=1; i<n; i++){
        rodada = false;
        for(int j=0; j<nomes[i].size(); j++){
            if(nomes[i][j] >= nomes[i-1][posicoes[i-1]]){
                posicoes.push_back(j);
                rodada = true;
                break;
            }
        }
        if(rodada == false){cout << "impossible"; return 0;};
    };

    for(int i=0; i<posicoes.size(); i++){
        cout << nomes[i][posicoes[i]] << "\n";
    }

    return 0;

}