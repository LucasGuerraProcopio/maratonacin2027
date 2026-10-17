#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
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
    if(n != m+1){
        cout << "NO";
        return 0;
    };

    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    verificador(1);

    for(int i=1; i<=n; i++){
        if(visitado[i] == false){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";





    return 0;

}