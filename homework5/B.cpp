#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 100005;
const ll INF = 1e18;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<pair<ll, ll>>> adj(n+1);
    vector<ll> alturas(n+1);
    for(int i=1; i<=n; i++){
        cin >> alturas[i];
    };
    adj[1].push_back({2, abs(alturas[1] - alturas[2])});
    for(int i=3; i<=n; i++){
        adj[i-2].push_back({i,abs(alturas[i-2] - alturas[i])});
        adj[i-1].push_back({i,abs(alturas[i-1] - alturas[i])});
    };

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
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
    };

    cout << dist[n];

    return 0;

}