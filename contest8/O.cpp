#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){

    int pedras, tesoura, papel; cin >> pedras >> tesoura >> papel;

    int total = pedras + papel + tesoura;

    int ESpedra = tesoura - papel;
    int ESpapel = pedras - tesoura;
    int EStesoura = papel - pedras;

    string resposta = "";

    if(ESpedra >= 0){
        for(int i=0; i<total; i++){
            resposta += 'R';
        }
        cout << resposta << "\n";
        continue;
    }

    if(ESpapel >= 0){
        for(int i=0; i<total; i++){
            resposta += 'P';
        }
        cout << resposta << "\n";
        continue;
    }

    if(ESpedra >= 0){
        for(int i=0; i<total; i++){
            resposta += 'S';
        }
        cout << resposta << "\n";
        continue;
    }

    }

    return 0;

}