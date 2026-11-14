#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 6;

ll solve(ll c, ll d){
    if(d == 1){return c;}
    bool impar = false;
    if(d%2 == 1){impar = true; d--;}
    ll resposta = solve(c, d/2);
    ll retornado = (resposta * resposta) % mod;
    if(impar){retornado = (retornado * c) % mod;}
    return retornado;
}

ll solve2(ll c, ll d){
    if(d == 1){return c;}
    bool impar = false;
    if(d%2 == 1){impar = true; d--;}
    ll resposta = solve2(c, d/2);
    ll retornado = (resposta * resposta) % mod2;
    if(impar){retornado = (retornado * c) % mod2;}
    return retornado;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    while(n--){

    ll a, b, c; cin >> a >> b >> c;
    ll expoente;
    if(b == 0 && c == 0){expoente = 1;}
    else if(b == 0){expoente = 0;}
    else if(c == 0){expoente = 1;}
    else{expoente = solve2(b, c);}
    
    if(a == 0 && expoente != 0){cout << 0 << "\n"; continue;}
    if(expoente == 0){cout << 1 << "\n"; continue;}
    cout << solve(a, expoente) << "\n";
    }

    return 0;

}