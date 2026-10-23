#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<ll> ruas(n);
    vector<ll> somatorio(n+1);
    vector<vector<pair<int,ll>>> adj(n + 2);


    for(int i=1; i<=n; i++){
        ll a; cin >> a;
        ruas[i-1] = a;
        if(i!=n){
            adj[i].push_back({i+1, a});
            adj[i+1].push_back({i, a});
        }
        else{
            adj[n].push_back({1, a});
            adj[1].push_back({n, a});
        };
    };

    for(int i=1; i<=n; i++){
        int b; cin >> b;
        adj[i].push_back({n+1, b});
        adj[n+1].push_back({i, b});
    };

    vector<ll> dist(n + 2, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[n+1] = 0;
    pq.push({0, n+1});

    while(!pq.empty()){
        auto[total, atual] = pq.top(); pq.pop();
        if(total > dist[atual]){continue;};
        for(auto[proximo, custo] : adj[atual]){
            if(dist[proximo] > dist[atual] + custo){
                dist[proximo] = dist[atual] + custo;
                pq.push({dist[proximo], proximo});
            }
        }
    };

    somatorio[0] = 0;
    for(int i=1; i<=n; i++){
        somatorio[i] = ruas[i-1] + somatorio[i-1];
    };

    for(int i=0; i<q; i++){
        ll w, k, m, y, resposta; cin >> w >> k;
        m = dist[w] + dist[k];
        if(k > w){swap(k, w);}
        if(k == n+1 || w ==n+1){
            y = INF;
        }
        else{
            y = min(somatorio[w-1] - somatorio[k-1], somatorio[n] - somatorio[w-1] + somatorio[k-1]);
        }
        resposta = min(m,y);
        cout << resposta << "\n";
    }
    return 0;
}