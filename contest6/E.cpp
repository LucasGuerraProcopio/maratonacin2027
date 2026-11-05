#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5; 
ll dp[MAXN];



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

        int n,q; cin >> n >> q;
        vector<ll> numeros(n+1);
        for(int i=1; i<=n; i++){
            cin >> numeros[i];
        };

        dp[n] = numeros[n];
        ll atual = numeros[n];
        ll resposta = numeros[n];
        for(int i=n-1; i>=1; i--){
            atual = max(numeros[i], atual + numeros[i]);
            resposta = max(resposta, atual);
            dp[i] = resposta;
        };

        for(int i=0; i<q; i++){
            int a; cin >> a;
            cout << dp[a+1] << "\n";
        }




    return 0;

}