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

    if(n==1){cout << 0; return 0;}
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
        while(true){
            if(!foi[ultimo]){
                verificador(ultimo);
                ultimo++;
                break;
            }
            else{ultimo++;}
        }
    }

    if(grupos.size() == 1){cout << 0; return 0;}

    sort(grupos.begin(), grupos.end(), [](const vector<int>& x, const vector<int> & y){return x.size() > y.size();});

    vector<int> todos;
    for(int i=0; i<grupos.size(); i++){
        for(int x : grupos[i]){todos.push_back(x);}
    };

    int maior = grupos[0].size();

    if(maior <= n/2){
        for(int i = 0; i<n/2; i++){
            pair<int, int> nova;
            nova.first = todos[i]; nova.second = todos[i + n/2];
            if(nova.first > nova.second){swap(nova.first, nova.second);}
            duplas.push_back(nova);
        }
    }
    else{
        for(int i=0; i<n-maior; i++){
            pair<int, int> nova;
            nova.first = todos[i]; nova.second = todos[i + maior];
            if(nova.first > nova.second){swap(nova.first, nova.second);}
            duplas.push_back(nova);
        }
    }

    cout << duplas.size() << "\n";
    for(int i=0; i<duplas.size(); i++){
        cout << duplas[i].first << " " << duplas[i].second << "\n";
    }

    return 0;

}