#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
const int T = 101;
int n;
ll k; 

struct MATRIZ{

    ll matriz[T][T];
    bool passou[T][T];

};

MATRIZ matmul(const MATRIZ &a, const MATRIZ &b){
    MATRIZ ans; int w;
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            ans.passou[i][j] = false;
        }
    }
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            for(ans.matriz[i][j] = w = 0; w<T; w++){
                if(a.passou[i][w] && b.passou[w][j]){ans.passou[i][j] = true;}
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
            if(i == j){ans.matriz[i][j] = 1; ans.passou[i][j] = true;}
            else{ans.matriz[i][j] = 0; ans.passou[i][j] = false;}
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

    int m; cin >> n >> m >> mod;
    cin >> k; int inicio, fim; cin >> inicio >> fim;

    MATRIZ grafo;
    memset(grafo.matriz, 0, sizeof grafo.matriz);
    memset(grafo.passou, false, sizeof grafo.passou);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        grafo.matriz[a][b]++;
        grafo.matriz[b][a]++;
        grafo.passou[a][b] = true;
        grafo.passou[b][a] = true;  
    };


    MATRIZ R = matPow(grafo, k);
    if(!R.passou[inicio][fim]){cout << "Mendes will sleep in peace."; return 0;}    
    cout << R.matriz[inicio][fim] % mod;

    return 0;

}