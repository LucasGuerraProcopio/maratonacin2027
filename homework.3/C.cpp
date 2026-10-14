#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<long long> adj[MAXN];
string visitado[MAXN];

bool dfs(int u){
    for(int v: adj[u]){
        if(visitado[v] == ""){
            if(visitado[u] == "saco1"){
                visitado[v] = "saco2";
            }
            else{
                visitado[v] = "saco1";
            }
            if(!dfs(v)){return false;};
        }
        else if(visitado[u] == visitado[v]){return false;};
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    long long n, m, a, b; cin >> n >> m;
    bool possivel = true;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    for(int i=1; i<=n; i++){
        if(visitado[i] == ""){
            visitado[i] = "saco1";
        };
        possivel = dfs(i);
        if(possivel == false){
            cout << "IMPOSSIVEL";
            return 0;
        };
    };

    vector<long long> pedras1;
    vector<long long> pedras2;
    for(int i=1; i<=n; i++){
        if(visitado[i] == "saco1"){
            pedras1.push_back(i);
        }
        else{
            pedras2.push_back(i);
        };
    };

    cout << "POSSIVEL\n";
    cout << pedras1.size() << " " << pedras2.size() << "\n";
    for(int i=0; i<pedras1.size(); i++){
        if(i==0){
            cout << pedras1[i];
        }
        else{
            cout << " " << pedras1[i];
        }
        if(i == pedras1.size() - 1){
            cout << "\n";
        }
    };

    for(int i=0; i<pedras2.size(); i++){
        if(i==0){
            cout << pedras2[i];
        }
        else{
            cout << " " << pedras2[i];
        }
    };
    return 0;
}