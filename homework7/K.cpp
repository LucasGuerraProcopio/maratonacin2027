#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int MAXN = 2e6 + 5;
ll fact[MAXN], invfact[MAXN];

ll multiplica(ll a, ll b){return ((a % mod) * (b % mod)) % mod;}

ll binomial(int n, int k){
    return multiplica(multiplica(fact[n], invfact[k]), invfact[n - k]);
}

void precompute(){
    fact[0] = 1;
    invfact[MAXN-1] = 588829888;
    for(int i = 1; i<MAXN; i++){
        fact[i] = multiplica(fact[i-1], i);
    };
    for(int i=MAXN-1; i>= 1; i--){
        invfact[i-1] = multiplica(invfact[i], i);
    }


}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    ll n, m; cin >> n >> m;
    n--;
    ll total = n + m;

    cout << binomial(total, m);

    return 0;

}