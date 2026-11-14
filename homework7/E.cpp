#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int T = 2;

struct MATRIZ{

    ll matriz[T][T];

};

MATRIZ matmul(const MATRIZ &a, const MATRIZ &b){
    MATRIZ ans; int w;
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            for(ans.matriz[i][j] = w = 0; w<T; w++){
                ans.matriz[i][j] += (a.matriz[i][w] * b.matriz[w][j]) % mod;
                ans.matriz[i][j] %= mod;
            }
        }
    }
    return ans;
};

MATRIZ matPow(MATRIZ base, ll p){
    MATRIZ ans; 
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            if(i == j){ans.matriz[i][j] = 1;}
            else{ans.matriz[i][j] = 0;}
        }
    }

    while(p){
        if(p & 1){
            ans = matmul(ans, base);
        }
        base = matmul(base, base);
        p >>= 1;
    };

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    if(n%2 == 1){cout << "Samuell\n";}else{cout << "Lleumas\n";}


    MATRIZ m;
    ll a, b; cin >> a >> b;

    if(n==1){cout << a; return 0;}
    if(n == 2){cout << b; return 0;}

    m.matriz[0][0] = 1; m.matriz[0][1] = 1; m.matriz[1][0] = 1; m.matriz[1][1] = 0;

    MATRIZ R = matPow(m, n-2);
    ll resposta = (R.matriz[0][0] * b) % mod;
    resposta = (resposta + ((R.matriz[0][1] * a) % mod)) % mod;

    cout << resposta;

    return 0;

}