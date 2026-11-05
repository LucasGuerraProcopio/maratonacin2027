#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[32];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){

    int n; cin >> n;
    memset(dp, 0, sizeof dp);
    vector<ll> numeros(n);
    for(int i=0; i<n; i++){
        cin >> numeros[i];
    };

    for(int i=0; i<n; i++){
            for(int bit=0; bit < 30; bit++){
                if((numeros[i] & (1LL << (bit)))){
                    dp[bit]++;
                }
            }            
        };

    ll maior = 0;
    for(int i=0; i<n; i++){
        ll total = 0;
        for(int bit=0; bit<30; bit++){
            if(numeros[i] & (1<<bit)){
                total += (ll)(n - dp[bit]) * (1LL<<bit);
            }
            else{
                total += (ll)dp[bit] * (1LL<<bit);
            };
        };
        if(total > maior){maior = total;}
    };

    cout << maior << "\n";

    }

    return 0;

}