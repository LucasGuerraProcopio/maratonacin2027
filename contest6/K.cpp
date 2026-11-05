#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1e9 + 7;
const ll MAXN = 1e5 + 5;
vector<ll> adj[MAXN];
ll dp[MAXN][2];

ll solve(int i, int j, int pai){
    if(dp[i][j] != -1){return dp[i][j];}
    if(adj[i].size() == 1 && adj[i][0] == pai){dp[i][j] = 1; return dp[i][j];}
    ll resposta = 1;
    if(j == 1){
        for(int v : adj[i]){
            if(v != pai){
                resposta *= solve(v, 0, i);
                resposta = resposta % modulo;
            }
        }
    }
    else{
        for(int v : adj[i]){
            if(v != pai){
                ll a = solve(v, 0, i) + solve(v, 1, i);
                resposta *= a;
                resposta = resposta % modulo;
            }
        }
    };
    dp[i][j] = resposta;
    return resposta;
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    memset(dp, -1, sizeof dp);

    ll resposta = 0;
    resposta = solve(1, 0, 0);
    resposta = solve(1, 1, 0);

    cout << (dp[1][0] + dp[1][1])  % modulo;

    return 0;

}