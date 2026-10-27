#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 500005;
ll dp[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    ll ultimo_zero = 0;
    for(int i=1; i<MAXN; i++){
        ll nova_janela = i - ((i+1)/2);
        if(ultimo_zero >= nova_janela){
            dp[i] = 1;
        }
        else{
            dp[i] = 0;
            ultimo_zero = i;
        }
    }

    int t; cin >> t;

    while(t--){
        ll n; cin >> n;
        if(dp[n] == 1){
            cout << "mastermei\n";
        }
        else{
            cout << "the greatest\n";
        }
    }

    return 0;

}