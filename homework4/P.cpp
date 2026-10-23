#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<int> adj[2505];
bool visitados[2505];


void verificador(int l){
    visitados[l] = true;
    for(int v : adj[l]){
        if(visitados[v] == false){
            verificador(v);
        };
    };
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> caminhos;
    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        c = c *(-1);
        adj[b].push_back(a);
        caminhos.push_back({a, b, c});
    };

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    bool tem_ciclo = false;

    verificador(n);



    for(int i=1; i<=n; i++){
        bool mudou = false;
        for(auto [inicio, fim, custo] : caminhos){
            if(dist[inicio] == INF){continue;}
            if(dist[fim] > dist[inicio] + custo){
                dist[fim] = dist[inicio] + custo;
                if(visitados[inicio]){mudou = true;}
            }
        };
        if(i == n && mudou){tem_ciclo = true;};
    }

    if(tem_ciclo){cout << -1;}
    else{
        cout << dist[n] * (-1);
    }


    return 0;

}