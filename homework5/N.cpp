#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3001][3001];
vector<ll> numeros(3001);

ll solve(int i, int j){
    if(i == j){return numeros[i];}
    if(dp[i][j] != -1){return dp[i][j];};

    ll a = numeros[i] - solve(i+1, j);
    ll b = numeros[j] - solve(i, j-1);
    dp[i][j] = max(a, b);
    return dp[i][j];
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    memset(dp, -1, sizeof dp);

    for(int i=1; i<=n; i++){
        cin >> numeros[i];
    };
    
    ll resposta = solve(1, n);
    cout << resposta;

    return 0;

}