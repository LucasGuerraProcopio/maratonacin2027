#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 2e5 + 5;
const long long INF = 1e15;
int dp[MAXN][2];
int n,q;
vector<long long> v(MAXN);

long long solve(int i, bool comecei){
    if(i==n){
        if(!comecei){
            return -INF;
        }
        else{return 0;}
    }

    if(dp[i][comecei] != -1){return dp[i][comecei];}

    long long peguei = v[i] + solve(i+1, 1);
    if(!comecei){
        long long ignorei = solve(i+1, comecei);
        return dp[i][comecei] = max(peguei, ignorei);
    }
    else{
        dp[i][comecei] = peguei;
        return dp[i][comecei];
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    memset(dp, -1, sizeof dp);

    ll resposta = solve(1, 0);
    dp[n][0] = v[n];
    dp[n][1] = v[n];
    for(int i=0; i<=MAXN; i++){
        if(dp[i][0] == 0){dp[i][0] = v[i];}
    }


    for(int i=0; i<q; i++){
        int a; cin >> a;
        cout << max(dp[a+1][0], dp[a+1][0]) << "\n";
    }


    return 0;

}