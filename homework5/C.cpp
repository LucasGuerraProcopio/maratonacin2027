#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll opcoes[MAXN][4];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<ll>> valores(n+1);
    for(int i=1; i<=n; i++){
        int a,b,c; cin >> a >> b >> c;
        valores[i].push_back(0);
        valores[i].push_back(a);valores[i].push_back(b);valores[i].push_back(c);
    };

    opcoes[1][1] = valores[1][1];
    opcoes[1][2] = valores[1][2];
    opcoes[1][3] = valores[1][3];

    for(int i=2; i<=n; i++){
        opcoes[i][1] = valores[i][1] + max(opcoes[i-1][2], opcoes[i-1][3]);
        opcoes[i][2] = valores[i][2] + max(opcoes[i-1][1], opcoes[i-1][3]);
        opcoes[i][3] = valores[i][3] + max(opcoes[i-1][1], opcoes[i-1][2]);
    }

    ll resposta = max(opcoes[n][1], opcoes[n][2]);
    ll respostaS = max(resposta, opcoes[n][3]);
    cout << respostaS;

    return 0;

}