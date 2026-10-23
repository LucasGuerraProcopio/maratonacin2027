#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h; cin >> n >> h;
    vector<tuple<int, int, int>> sombrinhas;
    for(int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;
        tuple<int, int, int> sobra = {a, b, c};
        sombrinhas.push_back(sobra);
    };


    vector<vector<pair<int, double>>> distancias;



    vector<pair<int, double>> margem;
    margem.push_back({0,0});
    for(int i=1; i<=n; i++){
        double p = get<1>(sombrinhas[i-1]) - get<2>(sombrinhas[i-1]);
        if(p < 0){p=0;}
        margem.push_back({i, p});
    };
    margem.push_back({n+1, h});
    distancias.push_back(margem);



    for(int i=0; i<n; i++){
        vector<pair<int, double>> andada;
        double g = get<1>(sombrinhas[i]) - get<2>(sombrinhas[i]);
        if(g < 0){g=0;}
        andada.push_back({0, g});
        for(int j=0; j<n; j++){
            double dx = get<0>(sombrinhas[i]) - get<0>(sombrinhas[j]);
            double dy = get<1>(sombrinhas[i]) - get<1>(sombrinhas[j]);
            double d = sqrt(dx*dx + dy*dy) - get<2>(sombrinhas[i]) - get<2>(sombrinhas[j]);
            if(d < 0){d=0;};
            andada.push_back({j+1, d});
        };
        double f = h - get<1>(sombrinhas[i]) - get<2>(sombrinhas[i]);
        if(f < 0) f = 0;
        andada.push_back({n+1, f});
        distancias.push_back(andada);
    };



    vector<pair<int, double>> fim;
    fim.push_back({0, h});
    for(int i=0; i<n; i++){
        double g = h - get<1>(sombrinhas[i]) - get<2>(sombrinhas[i]);
        if(g < 0){g=0;}
        fim.push_back({i+1, g});
    };
    fim.push_back({n+1 , 0});
    distancias.push_back(fim);



    vector<double> dist(n + 2, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0, 0});



    while(!pq.empty()){
        auto[total, atual] = pq.top();pq.pop();
        if(total > dist[atual]){continue;};
        for(auto[proximo, custo] : distancias[atual]){
            if(dist[proximo] > total + custo){
                dist[proximo] = total + custo;
                pq.push({dist[proximo], proximo});
            }
        }
    };

    int ijdoowhd =0;
    cout << fixed << setprecision(10) << dist[n+1];
    return 0;
}