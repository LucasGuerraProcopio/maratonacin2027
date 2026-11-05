#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> esquerda;
    vector<int> direita;
    map<int, int> mapa;
    for(int i=0; i<n/2; i++){
        int a; cin >> a;
        esquerda.push_back(a);
    }
    for(int i=n/2; i<n; i++){
        int a; cin >> a;
        mapa[a] = i;
        direita.push_back(a);
    };

    ll soma_esqueda = accumulate(esquerda.begin(), esquerda.end(), 0LL);
    ll soma_direita = accumulate(direita.begin(), direita.end(), 0LL);
    ll busca = abs(soma_esqueda - soma_direita);
    if(busca%2 == 1){
        cout << "NO";
        return 0;
    };
    busca /= 2;

    if(soma_esqueda <= soma_direita){
        for(int i=0; i<n/2; i++){
            int tentativa = esquerda[i];
            bool foi1;
            foi1 = mapa.count(busca + tentativa);
            if(foi1){
                cout << "YES\n";
                cout << i+1 << " " << mapa[busca + tentativa] + 1;
                return 0;
            }
        };
    }
    else{
        for(int i=0; i<n/2; i++){
            int tentativa = esquerda[i];
            bool foi1;
            foi1 = mapa.count(tentativa - busca);
            if(foi1){
                cout << "YES\n";
                cout << i+1 << " " << mapa[busca + tentativa] + 1;
                return 0;
            }
        }; 
    }

    cout << "NO";

    return 0;

}