#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, q; cin >> n >> m >> q;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    vector<vector<ll>> dist;
    vector<ll> mudalador = {1,2}; dist.push_back(mudalador);
    for(int i=1; i<=n; i++){
        vector<ll> numeros (n + 1, INF);
        dist.push_back(numeros);
    }

    for(int i=1; i<=n; i++){
        dist[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for(int k=1; k<=n; k++){
        for(int u=1; u<=n; u++){
            for(int v=1; v<=n; v++){
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    };

    for(int i=0; i<q; i++){
        ll x, y; cin >> x >> y;
        if(dist[x][y] == 1e18){dist[x][y] = -1;}
        cout << dist[x][y] << "\n";
    }

    return 0;

}

