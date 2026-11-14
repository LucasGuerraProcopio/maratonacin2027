#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int matriz[1001][1001];
int xizes[4] = {-1, 0, 1, 0};
int ypsolons[4] = {0, 1, 0, -1};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        memset(matriz, 1e18, sizeof matriz);
        int k, c, l; cin >> k >> c >> l;
        int coi, lini;

        map<char, int> precos;
        for(int i=0; i<k; i++){
            char canto; cin >> canto;
            int valor; cin >> valor;
            precos[canto] = valor;
        }

        for(int i=1; i<=l; i++){
            for(int j=1; j<=c; j++){
                char no; cin >> no;
                matriz[i][j] = precos[no];
                if(no == 'E'){coi = j; lini = i;}
            }
        };

        vector<vector<ll>> dist(l+1, vector<ll>(c+1, 1e18));
        priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<>> pq;
        dist[lini][coi] = 0;
        pq.push({0, {lini, coi}});

        while(!pq.empty()){
            auto[valor, coordenada] = pq.top(); pq.pop();
            if(valor > dist[coordenada.first][coordenada.second]){continue;}
            for(int i=0; i<4; i++){
                if(!((1 <= (coordenada.first + xizes[i])) && (1 <= (coordenada.second + ypsolons[i])) && ((coordenada.first + xizes[i]) <= l) && ((coordenada.second + ypsolons[i]) <= c))){continue;}
                int vi1, vi2; vi1 = coordenada.first + xizes[i]; vi2 = coordenada.second + ypsolons[i];
                int custo = matriz[vi1][vi2];
                if(dist[vi1][vi2] > custo + valor){
                    dist[vi1][vi2] = custo + valor;
                    pq.push({dist[vi1][vi2], {vi1, vi2}});
                }
            }
        }

        ll menor = 1e18;
        for(int i=1; i<=l; i++){
            menor = min(menor, dist[i][1]);
        }
        for(int i=1; i<=l; i++){
            menor = min(menor, dist[i][c]);
        }
        for(int i=1; i<=c; i++){
            menor = min(menor, dist[1][i]);
        }
        for(int i=1; i<=c; i++){
            menor = min(menor, dist[l][i]);
        }
        
        cout << menor << "\n";

    }



    return 0;

}