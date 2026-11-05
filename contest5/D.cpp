#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
            ll n, k; cin >> n >> k;
            ll espacos = n-1;
            if(k%espacos == 0){
                cout << n * (k / espacos) - 1 << "\n";
                continue;
            }

            ll pulos = k/espacos;
            ll resposta = n * pulos;
            resposta += k - ((n-1)*pulos);
            cout << resposta << "\n";
    }

    return 0;

}