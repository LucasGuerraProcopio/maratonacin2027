#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e3 + 5;
const ll modulo = 1e9 + 7;
vector<vector<char>> mapa;
ll opcoes[MAXN][MAXN];



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        string linha; cin >> linha;
        vector<char> nova(linha.begin(), linha.end());
        mapa.push_back(nova);
    };
    opcoes[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mapa[i-1][j-1] == '*'){opcoes[i][j] = 0; continue;};
            if(i==1 && j==1){continue;}
            else if(i==1){opcoes[i][j] = opcoes[i][j-1];}
            else if(j==1){opcoes[i][j] = opcoes[i-1][j];}
            else{opcoes[i][j] = (opcoes[i-1][j] + opcoes[i][j-1]) % modulo;}
        }
    }

    cout << opcoes[n][n];

    return 0;

}