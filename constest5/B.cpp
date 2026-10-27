#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m; cin >> n >> m;
    vector<ll> numeros(n);
    for(int i=0; i<n; i++){
        cin >> numeros[i];
    };

    if(n > m){cout << 0; return 0;}

    ll resposta = 1;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            resposta *= abs((numeros[i] - numeros[j]));
            if(resposta >= m){
                resposta = resposta%m;
            }
        }
    }
    cout << resposta;

    return 0;

}