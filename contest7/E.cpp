#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll largura, g; cin >> largura >> g;
    vector<pair<ll,int>> gomba;
    for(int i=0; i<g; i++){
        pair<ll,int> novo;
        cin >> novo.first >> novo.second;
        gomba.push_back(novo);
    };

    ll maior = 0;
    for(int i=0; i<g; i++){
        ll tempo = 0;
        if(gomba[i].second == 0){
            tempo = gomba[i].first;
        }
        else{
            tempo = largura - gomba[i].first;
        }
        maior = max(tempo, maior);
    };

    cout << maior;

    return 0;

}