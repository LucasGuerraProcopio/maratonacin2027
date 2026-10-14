#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200009;
vector<long long> adj[MAXN];

vector<long long> bfs(int s, int n){
    vector<long long> dist(n + 1, -1);
    queue<long long> fila;
    dist[s] = 0;
    fila.push(s);
    while(!fila.empty()){
        long long u = fila.front(); fila.pop();
        for(int v: adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                fila.push(v);
            }
        }
    }
    return dist;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b; cin >> n;
    vector<long long> distancias;

    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    vector<long long> distancia1 = bfs(1, n);

    long long A=0; 
    for(int i=1; i<distancia1.size(); i++){
        if(distancia1[i] > distancia1[A]){
            A = i;
        };
    };

    vector<long long> distanciaA = bfs(A, n);
    long long B=0;
        for(int i=1; i<distanciaA.size(); i++){
        if(distanciaA[i] > distanciaA[B]){
            B = i;
        };
    };

    vector<long long> distanciaB = bfs(B, n);

    for(int i=1; i<=n; i++){
        if(i==1){
            cout << max(distanciaA[i], distanciaB[i]);
        }
        else{
            cout << " " << max(distanciaA[i], distanciaB[i]);
        }
    }



    return 0;

}

