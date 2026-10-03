#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, rodada_atual, rodada_passada, minimo_rodada, melhor_rodada;
    cin >> n;
    vector<int> fileira(n);
    for(int i=0; i<n; i++){
        cin >> fileira[i];
    };
    rodada_atual = 1;
    rodada_passada = 1;
    melhor_rodada = 0;

    for(int j=1; j<n; j++){
        if(fileira[j] == fileira[j-1]){
            rodada_atual += 1;
        }
        if(fileira[j] != fileira[j-1] || j == (n-1)){
            if(rodada_atual < rodada_passada){
                minimo_rodada = rodada_atual;
            }
            else{
                minimo_rodada = rodada_passada;
            }
            if(minimo_rodada > melhor_rodada){
                melhor_rodada = minimo_rodada;
            }
            rodada_passada = rodada_atual;
            rodada_atual = 1;
        };
    };
    cout << melhor_rodada*2;
    };





