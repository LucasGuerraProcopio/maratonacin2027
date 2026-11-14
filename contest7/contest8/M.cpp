#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<ll>> dist;
    vector<ll> mudalador = {1,2}; dist.push_back(mudalador);
    for(int i=1; i<=26; i++){
        vector<ll> numeros (27, INF);
        dist.push_back(numeros);
    }

    for(int i=1; i<=26; i++){
        dist[i][i] = 0;
    }

    for(int i=1; i<=26; i++){
        for(int j=1; j<=26; j++){
            ll a; cin >> a;
            dist[i][j] = min(dist[i][j], a);
        }
    }

    for(int k=1; k<=26; k++){
        for(int u=1; u<=26; u++){
            for(int v=1; v<=26; v++){
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }



    string nome; cin >> nome;
    ll atual = 0;
    ll custo = 0;
    ll total = nome.size();
    total /= 2;
    while(atual < total){
        if(nome[atual] == nome[nome.size() - atual - 1]){atual++; continue;}
        int p, q;
        ll minimo = INF;
        if(nome[atual] == 'a'){p = 1;}else if(nome[atual] == 'b'){p = 2;}else if(nome[atual] == 'c'){p = 3;}else if(nome[atual] == 'd'){p = 4;}else if(nome[atual] == 'e'){p = 5;}else if(nome[atual] == 'f'){p = 6;}else if(nome[atual] == 'g'){p = 7;}else if(nome[atual] == 'h'){p = 8;}else if(nome[atual] == 'i'){p = 9;}else if(nome[atual] == 'j'){p = 10;}else if(nome[atual] == 'k'){p = 11;}else if(nome[atual] == 'l'){p = 12;}else if(nome[atual] == 'm'){p = 13;}else if(nome[atual] == 'n'){p = 14;}else if(nome[atual] == 'o'){p = 15;}else if(nome[atual] == 'p'){p = 16;}else if(nome[atual] == 'q'){p = 17;}else if(nome[atual] == 'r'){p = 18;}else if(nome[atual] == 's'){p = 19;}else if(nome[atual] == 't'){p = 20;}else if(nome[atual] == 'u'){p = 21;}else if(nome[atual] == 'v'){p = 22;}else if(nome[atual] == 'w'){p = 23;}else if(nome[atual] == 'x'){p = 24;}else if(nome[atual] == 'y'){p = 25;}else if(nome[atual] == 'z'){p = 26;}
        if(nome[nome.size() - atual - 1] == 'a'){q = 1;}else if(nome[nome.size() - atual - 1] == 'b'){q = 2;}else if(nome[nome.size() - atual - 1] == 'c'){q = 3;}else if(nome[nome.size() - atual - 1] == 'd'){q = 4;}else if(nome[nome.size() - atual - 1] == 'e'){q = 5;}else if(nome[nome.size() - atual - 1] == 'f'){q = 6;}else if(nome[nome.size() - atual - 1] == 'g'){q = 7;}else if(nome[nome.size() - atual - 1] == 'h'){q = 8;}else if(nome[nome.size() - atual - 1] == 'i'){q = 9;}else if(nome[nome.size() - atual - 1] == 'j'){q = 10;}else if(nome[nome.size() - atual - 1] == 'k'){q = 11;}else if(nome[nome.size() - atual - 1] == 'l'){q = 12;}else if(nome[nome.size() - atual - 1] == 'm'){q = 13;}else if(nome[nome.size() - atual - 1] == 'n'){q = 14;}else if(nome[nome.size() - atual - 1] == 'o'){q = 15;}else if(nome[nome.size() - atual - 1] == 'p'){q = 16;}else if(nome[nome.size() - atual - 1] == 'q'){q = 17;}else if(nome[nome.size() - atual - 1] == 'r'){q = 18;}else if(nome[nome.size() - atual - 1] == 's'){q = 19;}else if(nome[nome.size() - atual - 1] == 't'){q = 20;}else if(nome[nome.size() - atual - 1] == 'u'){q = 21;}else if(nome[nome.size() - atual - 1] == 'v'){q = 22;}else if(nome[nome.size() - atual - 1] == 'w'){q = 23;}else if(nome[nome.size() - atual - 1] == 'x'){q = 24;}else if(nome[nome.size() - atual - 1] == 'y'){q = 25;}else if(nome[nome.size() - atual - 1] == 'z'){q = 26;}
        for(int i=1; i<=26; i++){
            ll a = dist[p][i];
            ll b = dist[q][i];
            minimo = min(minimo, a + b);
        }
        custo += minimo;
        atual++;
    }

    cout << custo;


    return 0;

}