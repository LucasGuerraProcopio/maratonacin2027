#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAWN = 2e5+5;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m; cin >> n >> m;
    vector<ll> valores(MAWN, -1);
    for(int i=0; i<n; i++){
        string c; cin >> c;
        ll a = c.size();
        ll b; cin >> b;
        if(valores[a] < b){valores[a] = b;}
    };

    vector<ll> dp(m+1, 0);

    for(int i=1; i<MAWN; i++){
        if(valores[i] == -1){continue;}
            for(int c = i; c<=m; c++){
                dp[c] = max(dp[c], dp[c - i] + valores[i]);
            }
    };

    cout << dp[m];


    return 0;

}