#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1005;
vector<long long> adj[MAXN];
bool visitado[MAXN];

void verificador(int l){
    visitado[l] = true;
    for(int v : adj[l]){
        if(visitado[v] == false){
            verificador(v);
        };
    };
}


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

    ll n; cin >> n;
    vector<aresta> lados(n-1);
    for(int i=0; i<n-1; i++){
        cin >> lados[i].u >> lados[i].v; lados[i].custo = 1;
    };

    sort(lados.begin(), lados.end(), [](const aresta& a, const aresta& b) {return a.custo < b.custo;});
    
    vector<pair<int, int>> fracassos;

    DSU reslvedor(n);
    ll mudancas = 0;
    for(auto [u, v, c] : lados){
        if(reslvedor.join(u, v)){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            mudancas++;
            pair<int,int> loop = {u, v};
            fracassos.push_back(loop);
        }
    }

    vector<int> novas;
    for(int i=1; i<=n; i++){
        if(!visitado[i]){
            verificador(i);
            if(i != 1){
                novas.push_back(i);
            }
        }
    }

    cout << mudancas << "\n";
    for(int i=0; i<mudancas; i++){
        cout << fracassos[i].first << " " << fracassos[i].second << " " << 1 << " " << novas[i] << "\n";
    }

    return 0;

}