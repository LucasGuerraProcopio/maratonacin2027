#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<ll> bolos;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        bolos.push_back(a);
    }

    if(n == 1){cout << bolos[0] + k; return 0;}

    sort(bolos.begin(), bolos.end());
    ll ultimo = 0;
    ll agora = 1;

    while(agora < n){
        if((bolos[agora] - bolos[ultimo]) * agora  <= k){
            k -= (bolos[agora] - bolos[ultimo]) * agora;
            agora++;
            ultimo++;
        }
        else{
            break;
        }
    }
    
    ll resposta = k/agora;
    resposta += bolos[ultimo];

    cout << resposta;

    return 0;

}