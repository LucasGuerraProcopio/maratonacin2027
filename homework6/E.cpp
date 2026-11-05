#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = (1<<21) + 5;
const ll INF = 1e18;
pair<int,ll> dp[MAXN];
ll pessoas[22];
int n;
ll m;




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> pessoas[i];
    };

    fill(dp, dp + MAXN, pair<int, ll> {22, 1e10});

    for(int i=1; i<=n; i++){
        dp[1<<i] = {1, pessoas[i]};
    };

    ll total = (1<<(n+1));

    for(int mask=2; mask<total; mask++){

        for(int bit=1; bit <= n; bit++){

            if(!(mask & (1 << (bit)))){

                int subidas = dp[mask].first;
                ll peso = dp[mask].second;
                peso += pessoas[bit];

                if(peso > m){
                    subidas++;
                    peso = pessoas[bit];
                };

                if(dp[mask | 1<<(bit)].first > subidas){dp[mask | 1<<(bit)] = {subidas, peso};}
                else if(dp[mask | 1 << (bit)].first == subidas && dp[mask | 1 << (bit)].second > peso){dp[mask | 1<<(bit)] = {subidas, peso};}
            }
        }
    };

    cout << dp[(1<<(n+1)) - 2].first;



    return 0;

}