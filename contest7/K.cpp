#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    ll w; cin >> w;
    vector<vector<ll>> ondas;
    for(int i=0; i<n; i++){
        char ponto; cin >> ponto;
        if(ponto == '!'){
            ll a, b, c; cin >> a >> b >> c;
            ondas.push_back({a, a+b-1, c});
        }
        else{
            ll altura = 0;
            ll local; cin >> local;
            for(int j=0; j<ondas.size(); j++){
                if(local > ondas[j][1] || local < ondas[j][0]){continue;}
                if((local - ondas[j][0]) % 4 == 1 || (local - ondas[j][0]) % 4 == 3){continue;}
                if((local - ondas[j][0]) % 4 == 2){altura -= ondas[j][2];}
                else{altura += ondas[j][2];}
            };
            cout << altura << "\n";
        }
    }

    return 0;

}