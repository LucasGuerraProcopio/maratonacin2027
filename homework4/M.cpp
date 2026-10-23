#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> caminhos;
    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        caminhos.push_back({a, b, c});
    };

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    bool tem_ciclo = false;
    vector<int> Mim_de_papai(n + 1, -1);
    int ultimo;




    for(int i=1; i<=n; i++){
        bool mudou = false;
        for(auto [inicio, fim, custo] : caminhos){
            if(dist[fim] > dist[inicio] + custo){
                dist[fim] = dist[inicio] + custo;
                Mim_de_papai[fim] = inicio;
                ultimo = fim;
                mudou = true;
            }
        };
        if(i == n && mudou){tem_ciclo = true;};
    }

    if(!tem_ciclo){cout << "NO";}

    else{
        for(int i=0; i<n; i++){
            ultimo = Mim_de_papai[ultimo];
        }
        vector<int> resposta;
        int atual = ultimo;
        resposta.push_back(atual);
        do{
            atual = Mim_de_papai[atual];
            resposta.push_back(atual);
        } while (atual != ultimo);

        cout  << "YES\n";

        for(int i=resposta.size()-1; i>=0; i--){
            if(i == resposta.size()-1){
                cout << resposta[i];
            }
            else{
                cout << " " << resposta[i];
            }
        }
    }


    return 0;

}