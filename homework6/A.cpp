#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> dp(8, INF);
    dp[0] = 0;

    for(int i=0; i<n; i++){
        ll preco; cin >> preco;
        string vitaminas; cin >> vitaminas;
        int mask = 0;
        for(char v : vitaminas){
            if(v == 'A'){mask |= 1;}
            else if(v == 'B'){mask |= 2;}
            else{mask |= 4;};
        };

        for(int j=0; j<8; j++){
            if(dp[j] == INF){continue;}
            dp[mask | j] = min(dp[mask | j], dp[j] + preco);
        }
    };

    if(dp[7] == INF){dp[7] = -1;}

    cout << dp[7];




    return 0;

}