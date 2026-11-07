#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int matriz[51][51];
vector<pair<int,int>> adj[51][51];
bool visitado_ini[51][51];
bool visitado_fim[51][51];

void verificador1(int i, int j){
    visitado_ini[i][j] = true;
    for(auto[a, b] : adj[i][j]){
        if(visitado_ini[a][b] == false){
            verificador1(a, b);
        };
    };
}

void verificador2(int i, int j){
    visitado_fim[i][j] = true;
    for(auto[a, b] : adj[i][j]){
        if(visitado_fim[a][b] == false){
            verificador2(a, b);
        };
    };
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int r1, c1; cin >> r1 >> c1;
    int r2, c2; cin >> r2 >> c2;
    memset(visitado_ini, false, sizeof visitado_ini);
    memset(visitado_fim, false, sizeof visitado_fim);
    for(int i=1; i<=n; i++){
        string linha; cin >> linha;
        for(int j=1; j<=n; j++){
            if(linha[j-1] == '0'){matriz[i][j] = 0;}else{matriz[i][j] = 1;}
        }
    };

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(matriz[i][j] == 1){continue;};
            if(i > 1 && matriz[i-1][j] == 0){adj[i][j].push_back({i-1, j});}
            if(j > 1 && matriz[i][j-1] == 0){adj[i][j].push_back({i, j-1});}
            if(i < n && matriz[i+1][j] == 0){adj[i][j].push_back({i+1, j});}
            if(j < n && matriz[i][j+1] == 0){adj[i][j].push_back({i, j+1});}
        }
    };

    verificador1(r1, c1);
    verificador2(r2, c2);

    if(visitado_ini[r1][c1] && visitado_ini[r2][c2]){cout << 0; return 0;}

    ll custo = 1e18;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!visitado_ini[i][j]){continue;}
            for(int w=1; w<=n; w++){
                for(int z=1; z<=n; z++){
                    if(i == w && j==z){continue;}
                    if(!visitado_fim[w][z]){continue;}
                    int ma = abs(w-i);
                    int me = abs(z-j);
                    ll preco = (ma*ma) + (me*me);
                    custo = min(custo, preco);
                }
            }
        }
    }

    cout << custo;
    return 0;

}