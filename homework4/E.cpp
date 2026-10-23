#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int Total_cupons = 1;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for(int i=0; i<m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    };

    vector<vector<ll>> dist(n+1, vector<ll> (Total_cupons + 1, INF));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto [total, atual, cupons] = pq.top();pq.pop();
        if(total > dist[atual][cupons]){continue;}

        for(auto [destino, custo] : adj[atual]){
            if(dist[destino][cupons] > total +  custo){
                dist[destino][cupons] = total + custo;
                pq.push({dist[destino][cupons], destino, cupons});
            };
            if(cupons < Total_cupons && dist[destino][cupons + 1] > total + custo / 2){
                dist[destino][cupons + 1] = total + custo / 2;
                pq.push({dist[destino][cupons + 1], destino, cupons + 1});
            }
        }
    }

    ll resposta = INF;
    for(int i=0; i<=Total_cupons; i++){resposta = min(resposta, dist[n][i]);}
    cout << resposta;


    return 0;

}