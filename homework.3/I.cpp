#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> dependentes[MAXN];
int dependencias[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m; cin >> n >> m;
    vector<pair<long long, long long>> duplas;
    for(int i=0; i<m; i++){
        pair<long long, long long> restricao;
        cin >> restricao.first >> restricao.second;
        duplas.push_back(restricao);
    };
    sort(duplas.begin(), duplas.end());
    duplas.erase(unique(duplas.begin(), duplas.end()), duplas.end());
    for(int i=0; i<duplas.size(); i++){
        dependentes[duplas[i].first].push_back(duplas[i].second);
        dependencias[duplas[i].second]++;
    };

    queue<long long> fila;
    for(int i=1; i<=n; i++){
        if(dependencias[i] == 0){fila.push(i);}
    };

    vector<int> ordem;

    while(!fila.empty()){
        if(fila.size() != 1){cout << "No"; return 0;};
        int x = fila.front(); fila.pop();
        ordem.push_back(x);
        for(int v : dependentes[x]){
            dependencias[v]--;
            if(dependencias[v] == 0){fila.push(v);};
        };
    };

    if(ordem.size() != n){
        cout << "No";
    }
    else{
        vector<long long> resposta(n);
        cout << "Yes\n";
        for(int i=0; i<n; i++){
            resposta[ordem[i] - 1] = i+1; 
        }
        for(int i=0; i<n; i++){
            if(i==0){cout << resposta[i];}else{cout << " " << resposta[i];}
        }
    }


    return 0;

}