#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
const ll modulo = 1e9 + 7;
ll opcoes[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    opcoes[0] = 1;
    for(int i=1; i<=n; i++){
        for(int dado=1; dado<=6; dado++){
            if(dado<=i){
                opcoes[i] = (opcoes[i] + opcoes[i-dado]) % modulo;
            }
        }
    };

    cout << opcoes[n];



    return 0;

}