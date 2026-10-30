#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[501][501];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==j){dp[i][j] = 0; continue;}
            dp[i][j] = 10000;
            for(int a = 1; a < j; a++){
                dp[i][j] = min(dp[i][j], dp[i][j-a] + dp[i][a] + 1);
            }
            for(int b = 1; b < i; b++){
                dp[i][j] = min(dp[i][j], dp[i-b][j] + dp[b][j] + 1);
            };
        }
    };

    cout << dp[n][m];
    return 0;

}