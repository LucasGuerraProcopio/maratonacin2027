#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e7 + 5;
bool primos[MAXN];
vector<ll> valores;
ll maximo = 1e18;

void solve(){
    memset(primos, true , sizeof primos);
    primos[0] = false; primos[1] = false;
    for(int i=2; i<MAXN; i++){
        if(primos[i]){
            if(i <= maximo){valores.push_back(i);}
            for(int j=i; j<MAXN; j += i){
                primos[j] = false;
            }
        }
    }
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> numeros;
        numeros.push_back(2);
        for(int i=1; i<n; i++){
            ll novo = valores[i] * valores[i-1];
            numeros.push_back(novo);
        }

        for(int i=0; i<n; i++){
            if(i == 0){cout << numeros[i];}
            else{cout << " " << numeros[i];}
        }

        cout << "\n";

    }

    return 0;

}