#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = (1<<19);
ll dp[MAXN][20];
int bonus[20][20];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof dp);

    int n, m, k; cin >> n >> m >> k;
    vector<ll> pratos(n);
    for(int i=0; i<n; i++){
        cin >> pratos[i];
    };

    if(m==1){
        auto resposta = max_element(pratos.begin(), pratos.end());
        cout << *resposta;
        return 0;
    }

    
    memset(bonus, 0, sizeof bonus);
    for(int i=0; i<k; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        cin >> bonus[a][b];
    }

    for(int i = 0; i <n; i++){
        dp[1<<i][i] = pratos[i];
    }

    ll melhor = 0;
    for(int mask=1; mask < (1<<n); mask++){
        for(int bit = 0; bit < n; bit++){
            if((mask & (1<<bit))){
                for(int bite = 0; bite < n; bite++){
                    if(!(mask & (1<<bite))){
                        dp[mask | (1<<bite)][bite] = max(dp[mask | (1<<bite)][bite], dp[mask][bit] + bonus[bit][bite] + pratos[bite]);
                        if(__builtin_popcount(mask) + 1 == m && dp[mask | (1<<bite)][bite] > melhor){melhor = dp[mask | (1<<bite)][bite];}
                    }
                }
            }
        }
    }

    cout << melhor;

    return 0;

}