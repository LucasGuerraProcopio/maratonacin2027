#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
const int MAWN = 1e9+5;
ll dp[MAXN][MAWN];
vector<ll> w, v;

ll solve(int i, ll cap){
    if(i == v.size()){return 0;};
    if(dp[i][cap] != -1){return dp[i][cap];};

    ll nao_pega = solve(i+1, cap);
    ll pega = 0;
    if(cap >= w[i]){pega = v[i] + solve(i+1, cap - w[i]);};
    dp[i][cap] = max(pega, nao_pega);
    return max(pega, nao_pega);
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    for(int i=0; i<n; i++){
        ll a,b; cin >> a >> b;
        w.push_back(a); v.push_back(b);
    };
    memset(dp, -1, sizeof dp);
    cout << solve(0,m);

    return 0;

}