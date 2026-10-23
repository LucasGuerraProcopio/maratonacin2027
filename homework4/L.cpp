#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
vector<long long> adj[MAXN];
bool visitado[MAXN];
ll amigos = 0;


void verificador(int l){
    visitado[l] = true;
    amigos += 1;
    for(int v : adj[l]){
        if(visitado[v] == false){
            verificador(v);
        };
    };
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, a, b; cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    long long maior = 1;
    for(int i=1; i<=n; i++){
        amigos = 0;
        if(!visitado[i]){
            verificador(i);
            if(amigos > maior){
                maior = amigos;
            };
        };
    };

    cout << maior;
    return 0;
}