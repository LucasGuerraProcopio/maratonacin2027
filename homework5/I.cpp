#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1005;
ll dp[MAXN][MAXN];
vector<ll> primeiro;
vector<ll> segundo;
vector<ll> numeros;

ll solve(int i, int j){
    if(i == primeiro.size() || j == segundo.size()){return 0;}
    if(dp[i][j] != -1){return dp[i][j];};

    if(primeiro[i] == segundo[j]){
        dp[i][j] = 1 + solve(i+1, j+1);
        return dp[i][j];
    }
    dp[i][j] = max(solve(i + 1, j), solve(i, j+1));
    return dp[i][j];
}

void faz(){
    int i,j; i = 0; j = 0;
    while(i < primeiro.size() && j < segundo.size()){
        if(primeiro[i] == segundo[j]){
            numeros.push_back(primeiro[i]); i++; j++;
        }
        else if(dp[i+1][j] > dp[i][j+1]){i++;}else{j++;};
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        ll a; cin >> a;
        primeiro.push_back(a);
    };
    for(int i=1; i<=m; i++){
        ll b; cin >> b;
        segundo.push_back(b);
    };
    memset(dp, -1, sizeof dp);

    cout << solve(0, 0) << "\n";

    faz();

    for(int i=0; i<numeros.size(); i++){
        if(i==0){
            cout << numeros[i];
        }
        else{
            cout << " " << numeros[i];
        }
    }


    return 0;

}