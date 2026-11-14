#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int linhas, colunas; 
ll matriz[22][22];
bool usada[22][22];
ll melhor = 0;

void dfs(int casas, ll x){
    if(casas == linhas*colunas){melhor = max(melhor, x); return;}

    int i = casas / colunas + 1;
    int j = casas % colunas + 1;

    if(usada[i][j]){
        dfs(casas+1, x);
        return;
    }

    dfs(casas+1, x ^ matriz[i][j]);

    if(j < colunas && !usada[i][j+1]){
        usada[i][j] = true; usada[i][j+1] = true;
        dfs(casas + 1, x);
        usada[i][j] = false; usada[i][j+1] = false; 
    }

    if(i < linhas && ! usada[i+1][j]){
        usada[i][j] = true; usada[i+1][j] = true;
        dfs(casas + 1, x);
        usada[i][j] = false; usada[i+1][j] = false;
    }
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> linhas >> colunas;
    for(int i=1; i<=linhas; i++){
        for(int j=1; j<=colunas; j++){
            cin >> matriz[i][j];
        }
    }

    dfs(0, 0);
    cout << melhor;

    return 0;

}