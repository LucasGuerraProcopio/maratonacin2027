#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100005;
const ll INF = 1e18;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    
vector<vector<pair<ll, double>>> adj(n+1);    for(int i=0; i<m; i++){
        ll a,b,c; cin >> a >> b >> c;
        double peso;
        peso = log(c)/log(7);
        adj[a].push_back({b, peso});
        adj[b].push_back({a, peso});
    };

    vector<double> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<double,ll>, vector<pair<double,ll>>, greater<>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto[total, atual] = pq.top(); pq.pop();
        if(dist[atual] == INF){continue;};
        for(auto[proximo, custo] : adj[atual]){
            if(dist[proximo] > dist[atual] + custo){
                dist[proximo] = dist[atual] + custo;
                pq.push({dist[proximo], proximo});
            }
        }
    }

    cout << fixed << setprecision(15) << dist[n];

    return 0;

}