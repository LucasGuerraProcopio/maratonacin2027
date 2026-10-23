#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
    vector<ll> tamanho, pai;
    DSU(int n) : pai(n + 1), tamanho(n + 1, 1) {
        for(int i=0; i<=n; i++){pai[i] = i;};
    }

    int find(int u){
        if (pai[u] == u)return u;
        return pai[u] = find(pai[u]);
    }

    bool join(int u, int v){
        u = find(u); v = find(v);
        if(u == v){return false;}
        if(tamanho[v] > tamanho[u]){swap(u, v);}
        pai[v] = u;
        tamanho[u] += tamanho[v];
        tamanho[v] = 0;
        return true;
    };

    ll valor(int x){
        vector<ll> copia = tamanho;
        sort(copia.begin(), copia.end());
        ll soma = 0;
        for(int i=0; i<x; i++){
            soma += copia[copia.size()-i-1];
        }
        return soma;
    }

};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    DSU amigos(n);
    int creditos = 1;

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        bool juntou = amigos.join(a, b);
        if(!juntou){creditos++;};
        ll resposta = amigos.valor(creditos);
        cout << resposta - 1 << "\n";
    }
    return 0;

}