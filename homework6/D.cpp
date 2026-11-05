#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[32];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        memset(dp, 0, sizeof dp);
        vector<ll> numeros(n);
        for(int i=0; i<n; i++){
            cin >> numeros[i];
        };

        for(int i=0; i<n; i++){
            for(int bit=0; bit < 31; bit++){
                if((numeros[i] & (1LL << (bit)))){
                    dp[bit]++;
                }
            }            
        };

        ll resposta = 0;
        for(int i=30; i>=0; i--){
            int necessidade = n - dp[i];
            if(necessidade <= k){
                k -= necessidade;
                resposta = resposta | (1LL<<i);
            }
        };

        cout << resposta << "\n";
    }

    return 0;

}