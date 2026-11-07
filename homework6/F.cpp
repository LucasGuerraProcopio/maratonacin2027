#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maximo = 960;
int n, m, p;
vector<pair<int, int>> adj[200005];

vector<int> dijkstra(int inicio){
    vector<int> caminhos(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;
    caminhos[inicio] = 0;
    pq.push({0, inicio});
    while(!pq.empty()){
        auto[valor, atual] = pq.top(); pq.pop();
        if(valor > caminhos[atual]){continue;}
        for(auto[proximo, custo] : adj[atual]){
            if(caminhos[proximo] > valor + custo){
                caminhos[proximo] = valor + custo;
                pq.push({caminhos[proximo], proximo});
            }
        }
    };
    return caminhos;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> p;
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    };

    vector<int> feliz(p);
    vector<int> tempo(p);
    for(int i=0; i<p; i++){cin >> feliz[i];}
    for(int i=0; i<p; i++){cin >> tempo[i];}

    vector<vector<int>> distancias(p, vector<int>(p));
    vector<int> dhotel(p);

    for(int i=0; i<p; i++){
        auto saida = dijkstra(i + 1);
        for(int j=0; j< p; j++){distancias[i][j] = saida[j+1];}
            dhotel[i] = saida[n];
    };

    int total = 1<<p;
    const int INF = 1e9;
    vector<int> dp(total * p, INF);

    for(int i=0; i<p; i++){
        int d = dhotel[i] + tempo[i];
        if(d <= maximo){dp[(1<<i) * p + i] = d;}
    };

    ll melhor = 0;
    for(int mask = 1; mask<total; mask++){
        ll felicidade = 0;
        bool valido = false;
        for(int i=0; i<p; i++){
            if(!(mask & (1<<i))){continue;}
            felicidade += feliz[i];
            int atual = dp[mask * p + i];
            if(atual > maximo){continue;}
            valido = true;
            for(int j=0; j<p; j++){
                if(mask & (1<<j)){continue;}
                int nova = atual + distancias[i][j] + tempo[j];
                if(nova > maximo){continue;}
                if(nova < dp[(mask | 1<<j)*p + j]){dp[(mask | 1<<j)*p + j] = nova;}
            }
        };
        if(valido){melhor = max(melhor, felicidade);}
    };

    cout << melhor;

    return 0;

}