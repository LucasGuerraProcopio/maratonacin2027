#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAWN = 1e5+5;
ll dp[MAWN];
vector<ll> w, v;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m; cin >> n >> m;
    ll soma = 0;
    for(int i=0; i<n; i++){
        ll a,b; cin >> a >> b;
        w.push_back(a); v.push_back(b);
        soma += b;
    };
    
    fill(dp, dp + MAWN, INF);

    dp[0] = 0;
    for(int i=0; i<n; i++){
        for(int j = soma; j>= v[i]; j--){
            if(dp[j - v[i]] != INF){
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    for(int i=soma; i>=0; i--){
        if(dp[i] <= m){
            cout << i; return 0;
        }
    }

    return 0;

}