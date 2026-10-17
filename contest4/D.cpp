#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long alturas[MAXN];
bool adj[MAXN];



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n, a, b; cin >> n >> m;
    long long resultado = 0;

    for(int i=1; i<=n; i++){
        cin >> alturas[i];
    }

    for(int i=1; i<=n; i++){
        adj[i] = true;
    }

    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(alturas[a] > alturas[b]){
            adj[b] = false;
        }
        else if(alturas[a] < alturas[b]){
            adj[a] = false;
        }
        else{
            adj[a] = false;
            adj[b] = false;
        }
    }

    for(int i=1; i<=n; i++){
        if(adj[i]){
            resultado++;
        }
    }

    cout << resultado;



    return 0;

}