#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll solve(ll c, ll d){
    if(d == 1){return c;}
    bool impar = false;
    if(d%2 == 1){impar = true; d--;}
    ll resposta = solve(c, d/2);
    ll retornado = (resposta * resposta) % mod;
    if(impar){retornado = (retornado * c) % mod;}
    return retornado;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    while(n--){
        ll a, b; cin >> a >> b;
        if(a == 0 && b != 0){cout << 0 << "\n"; continue;}
        if(b == 0){cout << 1 << "\n"; continue;}
        cout << solve(a, b) << "\n";
    }

    return 0;

}