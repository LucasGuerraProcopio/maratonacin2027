#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF =2e18;
const int T = 101;
int n;

struct MATRIZ{

    ll matriz[T][T];

};

MATRIZ matmul(const MATRIZ &a, const MATRIZ &b){
    MATRIZ ans; int w;
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            ans.matriz[i][j] = INF;
        }
    }

    for(int i=0; i<T; i++){
        for(int w=0; w<T; w++){
            if(a.matriz[i][w] == INF){continue;}
            for(int j=1; j<T; j++){
                if(b.matriz[w][j] == INF){continue;}
                ans.matriz[i][j] = min(ans.matriz[i][j], a.matriz[i][w] + b.matriz[w][j]);
            }
        }
    }
    return ans;
};

MATRIZ matPow(MATRIZ base, ll p){
    MATRIZ ans; 
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            if(i == j){ans.matriz[i][j] = 0;}
            else{ans.matriz[i][j] = INF;}
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

    int m; cin >> n >> m;
    ll k; cin >> k;

    MATRIZ grafo;
    for(int i=0; i<T; i++){
        for(int j=0; j<T; j++){
            grafo.matriz[i][j] = INF;
        }
    }


    for(int i=0; i<m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        grafo.matriz[a][b] = min(grafo.matriz[a][b], c);
    };

    MATRIZ R = matPow(grafo, k);
    if(R.matriz[1][n] == INF){cout << -1; return 0;}
    cout << R.matriz[1][n];

    return 0;

}