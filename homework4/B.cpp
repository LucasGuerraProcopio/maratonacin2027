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

    ll n, m1, m2; cin >> n >> m1 >> m2;


    DSU resolve_mocha(n);
    DSU resolve_diana(n);


    for(int i=0; i<m1; i++){
        int a, b; cin >> a >> b;
        resolve_mocha.join(a, b);
    }
    for(int i=0; i<m2; i++){
        int a, b; cin >> a >> b;
        resolve_diana.join(a, b);
    };

    ll total = 0;
    vector<pair<int, int>> pares;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(resolve_mocha.find(i) != resolve_mocha.find(j) && resolve_diana.find(i) != resolve_diana.find(j)){
                total += 1;
                pares.push_back({i, j});
                resolve_mocha.join(i, j); resolve_diana.join(i, j);
            }
        }
    }
    
    cout << total << "\n";
    for(int i=0; i<total; i++){
        cout << pares[i].first << " " << pares[i].second << "\n";
    }

    return 0;

}