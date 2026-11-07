#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> grupos;

const int MAXN = 100005;
vector<long long> adj[MAXN];
bool visitado[MAXN];
bool foi[MAXN];
int total = 0;
int atual = -1;

void verificador(int l){
    visitado[l] = true;
    foi[l] = true;
    total++;
    grupos[atual].push_back(l);
    for(int v : adj[l]){
        if(visitado[v] == false){
            verificador(v);
        };
    };
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    };
    vector<pair<ll, ll>> duplas;
    memset(foi, false, sizeof foi);
    int ultimo = 0;

    while(total != n){
        vector<int> novo;
        grupos.push_back(novo);
        atual++;
        memset(visitado, false, sizeof visitado);
        while(true){
            if(!foi[ultimo]){
                verificador(ultimo);
                ultimo++;
                break;
            }
            else{ultimo++;}
        }
    }

    for(int i=0; i<grupos.size(); i++){
        for(int j=0; j<grupos[i].size(); j++){
            for(int w=i+1; w<grupos.size(); w++){
                for(int c=0; c<grupos[w].size(); c++){
                    pair<int, int> nova;
                    if(grupos[i][j] < grupos[w][c]){nova.first = grupos[i][j]; nova.second = grupos[w][c];}
                    else{nova.first = grupos[w][c]; nova.second = grupos[i][j];}
                    duplas.push_back(nova);
                }
            }
        }
    };

    cout << duplas.size() << "\n";
    for(int i=0; i<duplas.size(); i++){
        cout << duplas[i].first << " " << duplas[i].second << "\n";
    }

    return 0;

}