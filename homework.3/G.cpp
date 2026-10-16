#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int caminho[MAXN];
string teleportes[MAXN];


void telestransportador(set<int> intactos, int cidade, int passos, int n, int m){

    if(cidade == n){
        for(int x : intactos) {
            if(caminho[x] == -1  || caminho[x] > passos){caminho[x] = passos;}}
    }

    else{
        intactos.erase(cidade);
        for(int i=1; i<=m; i++){
            if(teleportes[cidade][i-1] == '1'){telestransportador(intactos, cidade + i, passos + 1, n, m);};
        };
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(caminho, -1, sizeof(caminho));

    int n, m; cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> teleportes[i];
    };

    set<int> numeros;
    for(int i=1; i<n; i++){
        numeros.insert(i);
    };

    telestransportador(numeros, 1, 0, n, m);


    for(int i=2; i<n; i++){
        if(i==2){
            cout << caminho[i];
        }
        else{
            cout  << " " << caminho[i];
        }
    };

    return 0;

}