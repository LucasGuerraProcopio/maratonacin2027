#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int T = 6;

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
    MATRIZ m;
    
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            if(i == 0){m.matriz[i][j] = 1;}
            else if(i == j+1){m.matriz[i][j] = 1;}
            else{m.matriz[i][j] = 0;}
        }
    }

    MATRIZ R = matPow(m, n);
    cout << R.matriz[0][0];

    return 0;

}