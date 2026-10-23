#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> adj(n + 1);
    for(int i=0; i<m; i++){
        ll a, b, c;  cin >> a >> b >> c;
        adj[a].push_back({b,c});
    };

    vector<priority_queue<ll>> dist(n+1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1].push(0);
    pq.push({0,1});

    while(!pq.empty()){
        auto[total, atual] = pq.top(); pq.pop();
        if(dist[atual].size() == k  && total > dist[atual].top()){continue;};
        for(auto[proximo, custo] : adj[atual]){
            ll novo_custo = custo + total;
            if(dist[proximo].size() < k){
                dist[proximo].push(novo_custo);
                pq.push({novo_custo, proximo});
            }
            else if(novo_custo < dist[proximo].top()){
                dist[proximo].pop();
                dist[proximo].push(novo_custo);
                pq.push({novo_custo, proximo});
            }
        }
    };

    vector<ll> resposta;
    while(!dist[n].empty()){
        resposta.push_back(dist[n].top());
        dist[n].pop();
    }

    for(int i=k-1; 0<=i; i--){
        if(i==0){
            cout << resposta[i];
        }
        else{
            cout << resposta[i] << " "; 
        }
    }

    return 0;

}