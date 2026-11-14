#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll multmod(ll a, ll b){
    return (a * b) % mod;
}

ll exprapida(ll a, ll b){
    ll valor = 1;
    while(b){
        if(b & 1){valor = multmod(valor, a);}
        a = multmod(a, a);
        b >>= 1;
    }
    return valor;
};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a; cin >> n >> k >> a;
    if(n == 1 && k == 0){cout << a; return 0;}
    if(n == 1){cout << 0;return 0;} 
    if(k > n-2){cout << 0; return 0;}


    int m = n-2;
    vector<ll> fact(m + 1);
    vector<ll> inv(m + 1);
    fact[0] = 1;
    for(int i = 1; i<=m; i++){fact[i] = multmod(fact[i-1], i);}
    inv[m] = exprapida(fact[m], mod-2);
    for(int i = m; i>0; i--){inv[i-1] = multmod(inv[i], i);}

    ll C = multmod(multmod(fact[m], inv[k]), inv[m-k]);

    ll resposta = multmod(multmod(a, a), multmod(C, exprapida(a-1, m-k)));
    cout << resposta;




    return 0;

}