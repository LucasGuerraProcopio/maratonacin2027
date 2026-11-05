#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        
        ll n, k; cin >> n >> k;
        vector<ll> numeros(n);
        for(int i=0; i<n; i++){
            cin >> numeros[i];
        };
        ll resposta = 0;
        for(int i = 0; i<n; i++){
            resposta = resposta | numeros[i];
        }

        cout << resposta << "\n";
    }

    return 0;

}