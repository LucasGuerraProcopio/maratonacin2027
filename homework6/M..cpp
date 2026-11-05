#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MAXN = (1<<21);
ll dp[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);

    int n; cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));
    for(int i=0; i<n*n; i++){
        cin >> matriz[(i/n)][i%n];
    };

    dp[0] = 1;

    for(int mask=0; mask < (1<<n); mask++){
        if(dp[mask] == 0){continue;};
        int i = __builtin_popcount(mask);
        if(i == n){continue;};
        for(int j=0; j<n; j++){
            if(!(mask & 1<<j) && matriz[i][j] == 1){
                int nova = mask | 1<< j;
                dp[nova] += dp[mask];
                dp[nova] = dp[nova] % mod;
            }
        }
    };

    cout << dp[(1<<n) - 1];

    return 0;

}