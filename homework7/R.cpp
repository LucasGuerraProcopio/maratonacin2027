#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e7 + 5;
bool primos[MAXN];
vector<ll> valores;
ll total = 0;
ll atual = 0;
ll maximo;

void solve(){
    memset(primos, true , sizeof primos);
    primos[0] = false; primos[1] = false;
    for(int i=2; i<MAXN; i++){
        if(primos[i]){
            if(i <= maximo){valores.push_back(i);}
            for(int j=i; j<MAXN; j += i){
                primos[j] = false;
            }
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a; cin >> a >> maximo;
    solve();

    while(a != 1 && atual < valores.size()){
        if(a % valores[atual] == 0){a /= valores[atual]; total++;}
        else{atual++;}
    };

    if(a == 1){cout << total;}
    else{cout << "Que es Obo?";}

    return 0;

}