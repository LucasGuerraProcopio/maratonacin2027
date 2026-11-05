#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
bool numeros[20];
int n;
int busco = 0;
int custos[20][20];
int dp[20][1<<20];


int solve(int i, int mask){
    if(mask == busco){return 0;};

    int &resposta = dp[i][mask];
    if(resposta != -1){return resposta;}
    resposta = 0;
    for(int bit = 0; bit<20; bit++){
        if(mask & (1<<bit)){continue;}
        if(!numeros[bit]){continue;}
        resposta = max(resposta, custos[i][bit] + solve(bit, mask | (1<<bit)));
    };
    return resposta;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);
    cin >> n;
    ll extra = 0;
    
    for(int i=0; i<n; i++){
        int a; cin >> a;
        a--;
        if(numeros[a]){extra += a+1;}
        else{
            numeros[a] = true;
            for(int i=0; i<20; i++){
                if(numeros[i]){
                    custos[a][i] = gcd(a+1, i+1);
                    custos[i][a] = gcd(a+1, i+1);
                }
            }
            busco = busco | (1<<(a));
        }
    };

    int melhor = 0;
    for(int i=0; i<20; i++){
        if(numeros[i]){
            melhor = max(melhor, solve(i, 1<<(i)));
        }
    };

    cout << melhor + extra;



    return 0;

}