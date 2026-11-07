#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1<<17];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    for(int mask = 1; mask<(1<<17); mask++){
        int tem = 0;
        int num = __builtin_popcount(mask);
        if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17){
            tem++;
        };
        dp[mask] = dp[mask - 1] + tem;
    }

    int t; cin >> t;

    while(t--){
        int a, b; cin >> a >> b;
        cout << dp[b] - dp[a-1] << "\n";
    }

    return 0;

}