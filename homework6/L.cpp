#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = (1<<17);
ll dp[MAXN];
ll melhor[MAXN];
ll matriz[16][16];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);
    memset(matriz, 0, sizeof matriz);
    int n; cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matriz[i][j];
        }
    };

    for(int mask = 1; mask < (1<<n); mask++){
        for(int bit=0; bit<n; bit++){
            if(mask & (1<<bit)){
                for(int bite=bit+1; bite<n; bite++){
                    if(mask & (1<<bite)){dp[mask] += matriz[bit][bite];}
                }
            }
        }
    }

    for(int i=0; i<MAXN; i++){
        melhor[i] = dp[i];
    }


    for(int mask = 1; mask < (1<<n); mask ++){
        for(int submask = mask; submask > 0; submask = (submask - 1) & mask){
            melhor[mask] = max(melhor[mask], melhor[submask] + melhor[mask ^ submask]);
        };
    };

    cout << melhor[(1<<n) - 1];

    return 0;
}