#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        ll x, y; cin >> x >> y;
        ll iguais = x ^ y;
        ll resposta = 1;
        ll bit = -1;
        while(true){
            bit++;
            if(!(iguais & (1<<bit))){
                resposta *= 2;
                resposta = resposta % mod;
            }
            else{break;}
        };
        cout << resposta << "\n";
    }
    return 0;
}