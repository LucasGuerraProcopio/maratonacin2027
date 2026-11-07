#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
ll dp[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, c, k; cin >> n >> c >> k;
    vector<ll> dias;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        dias.push_back(a);
    };

    dp[dias[0]] = k + c;

    for(int i = 1; i<dias.size(); i++){
        ll e = dp[dias[i-1]] + k + c;
        ll b = dp[dias[i-1]] + (c*(dias[i] - dias[i-1]));
        dp[dias[i]] = min(e,b);
    };

    cout << dp[dias[dias.size()-1]];

    return 0;

}