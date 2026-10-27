#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN =1e5+5;
vector<ll> subordinados[MAXN];
ll memoria[MAXN];
const ll MOD = 998244353;

ll solve(ll u){
    if(memoria[u] != -1){return memoria[u];};
    ll valor = 1;
    for(int v : subordinados[u]){
        valor = (solve(v) + valor) % MOD;
    };
    memoria[u] = valor;
    return valor;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m; cin >> n >> m;

    for(int i=0; i<m; i++){
        ll a,b; cin >> a >> b;
        subordinados[a].push_back(b);
    };

    memset(memoria, -1, sizeof memoria);
    ll resposta = solve(1) % MOD;
    resposta--;

    cout << resposta;

    return 0;

}