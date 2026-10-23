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
        return true;
    };
};


struct aresta {int u, v; ll custo;};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, q; cin >> n >> m >> q;
    vector<aresta> lados(m);
    for(int i=0; i<m; i++){
        cin >> lados[i].u >> lados[i].v >> lados[i].custo;
    };

    sort(lados.begin(), lados.end(), [](const aresta& a, const aresta& b) {return a.custo < b.custo;});

    DSU reslvedor(n);
    ll preco = 0;
    ll feitas = 0;
    for(auto [u, v, c] : lados){
        if(reslvedor.join(u, v)){
            preco += c;
            feitas++;
        }
    }



    return 0;

}