#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> numeros(n);
    vector<ll> distancias;
    for(int i=0; i<n; i++){
        cin >> numeros[i];
        distancias.push_back(numeros[i] - i);
    };

    sort(distancias.begin(), distancias.end());
    ll mediana = distancias[n/2];
    ll resposta = 0;
    for(int i=0; i<n; i++){
        resposta += abs(distancias[i] - mediana);
    };

    cout << resposta;

    return 0;

}