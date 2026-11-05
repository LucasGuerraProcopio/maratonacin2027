#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
vector<long long> adj[MAXN];
char visitado[MAXN];

bool dfs(int u){
    for(int v: adj[u]){
        if(visitado[v] == '.'){
            if(visitado[u] == 'o'){
                visitado[v] = 'i';
            }
            else{
                visitado[v] = 'o';;
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

    return 0;

    int n, m; cin >> n >> m;
    for(int i=1; i<=m; i++){
        visitado[i] = '.';
    };

    vector<pair<int, int>> ruas;
    for(int i=0; i<m; i++){
        pair<int, int> atual;
        cin >> atual.first >> atual.second;
        ruas.push_back(atual);
    };

    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            if(i==j){continue;};
            if(ruas[i-1].first <= ruas[i-1].second){
                if(ruas[j-1].first <= ruas[j-1].second){
                    if(ruas[j-1].first < ruas[i-1].first && ruas[j-1].second < ruas[i-1].second && ruas[j-1].second > ruas[i-1].first){adj[i].push_back(j);};
                }
            }
        }
    }






}