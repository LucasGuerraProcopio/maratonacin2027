#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using u128 = __uint128_t;
    int n;
    vector<ll> primos;
    vector<ll> todos;

ll multmod(ll a, ll b, ll mod){
    return (u128)a * b % mod;
}

ll exprapida(ll a, ll b, ll mod){
    ll valor = 1;
    while(b){
        if(b & 1){valor = multmod(valor, a, mod);}
        a = multmod(a, a, mod);
        b >>= 1;
    }
    return valor;
};


bool millerRabin(ll nu){
    ll bases[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ll d = nu-1; ll s = 0;
    if(nu == 2 || nu == 3){return true;}
    if(nu < 2 || nu%2 == 0){return false;}
    while(d % 2 == 0){d /= 2; s++;}
    
    for(ll b : bases){

        if(b % nu == 0){continue;};

        ll rodada = exprapida(b % nu, d, nu);
        if(rodada == 1 || rodada == nu - 1){continue;}

        bool eprimo = false;

        for(int i = 1; i<s; i++){
            rodada = multmod(rodada, rodada, nu);

            if(rodada % nu == nu - 1){eprimo = true; break;}

            if(rodada % nu == 1){break;}

        };
        if(!eprimo){return false;}
    }
    return true;
}

bool verificador(ll x, vector<ll>& todos){

    for(ll numero : todos){
        if(x % numero != 0){return false;}
    }
    return true;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++){
        ll a; cin >> a;
        todos.push_back(a);
    };

    sort(todos.begin(), todos.end());
    ll maior = todos[n-1];

    if(todos[0] != 1){
        cout << maior << " " << 1;
        return 0.
    };

    if(n==1){
        cout << '*';
        return 0;
    };

    for(int i=0; i<n; i++){
        if(todos[i] >= 2){
            if(millerRabin(todos[i])){
                primos.push_back(todos[i]);
            }
        }
    };

    


    return 0;

}