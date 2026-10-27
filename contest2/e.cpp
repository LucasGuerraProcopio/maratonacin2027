#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >> n;
    vector<ll> casa(200005, 0);
    ll maximo = 0;

    for(int i=0; i<n; i++){
        ll a; cin >> a;
        casa[0]++;
        casa[a]--;
        maximo = max(maximo, a);
    };

    vector<ll> uns(maximo+1, 0);
    ll unzes = 0;
    for(int i=0; i<=maximo; i++){
        unzes += casa[i];
        uns[i] = unzes;
    };

    string resposta;
    ll extra = 0;

    for(int j=0; j < maximo || extra > 0; j++){
        int soma = extra;
        if(j < maximo){soma += uns[j];};
        extra = soma / 10;
        int novo = soma%10;
        resposta += to_string(novo);
    };

    reverse(resposta.begin(), resposta.end());
    cout << resposta;


    return 0;
}