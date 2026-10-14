#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<long long> adj[MAXN];
bool visitado[MAXN];

void verificador(int l){
    visitado[l] = true;
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

    vector<long long> ilhas;

    for(int i=1; i<=n; i++){
        if(!visitado[i]){
            verificador(i);
            ilhas.push_back(i);
        }
    }

    cout << ilhas.size() - 1 << "\n";

    for(int i=0; i < ilhas.size() - 1; i++){
        cout  << ilhas[i] << " " << ilhas[i+1] << "\n";
    };

    return 0;

}

