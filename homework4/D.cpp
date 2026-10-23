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
    vector<pair<aresta, int>> lados;
    vector<bool> funciona(q);

    for(int i=0; i<m; i++){
        ll a,b,c; cin >> a >> b >> c;
        pair<aresta, int> novo;
        novo.first = {a,b,c};
        novo.second = -1;
        lados.push_back(novo);
    };

    for(int i=0; i<q; i++){
        ll a,b,c; cin >> a >> b >> c;
        pair<aresta,int> novo;
        novo.first = {a,b,c};
        novo.second = i;
        lados.push_back(novo);
    }

    sort(lados.begin(), lados.end(), [](const pair<aresta, int>& a, const pair<aresta, int>& b) {return a.first.custo < b.first.custo;});

    DSU reslvedor(n);
    for(int i=0; i<m+q; i++){
        auto[u, v, c] = lados[i].first;
        if(lados[i].second == -1){
            reslvedor.join(u, v);
        }
        else{
            if(reslvedor.find(u) != reslvedor.find(v)){
                funciona[lados[i].second] = true;
            }
            else{
                funciona[lados[i].second] = false;
            }
        }
    }

    for(int i=0; i<q; i++){
        if(funciona[i]){cout << "Yes\n";}else{cout << "No\n";}
    }

    return 0;

}