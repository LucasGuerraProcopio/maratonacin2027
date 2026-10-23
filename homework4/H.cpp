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


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    DSU Grafo(n);

    for(int i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        Grafo.join(a, b);
    };

    set<pair<ll, ll>> proibidos;
    ll k; cin >> k;
    for(int i=0; i<k; i++){
        ll w, r; cin >> w >> r;
        w = Grafo.find(w);
        r = Grafo.find(r);
        proibidos.insert({w, r});
    }
    ll q; cin >> q;

    for(int i=0; i<q; i++){
        ll x, y; cin >> x >> y;
        x = Grafo.find(x); y = Grafo.find(y);
        if(proibidos.count({x, y}) || proibidos.count({y, x})){cout << "No\n";}else{cout << "Yes\n";}
    }

    return 0;

}