#include <bits/stdc++.h>
using namespace std;


long long casos = 0;

bool checador(const vector<vector<char>>& tabuleiro, int fileira, int coluna){
    for(int i=0; i<8; i++){
        if(tabuleiro[fileira][i] == 'D'){return false;};
        if(tabuleiro[i][coluna] == 'D'){return false;};
        if(fileira + i < 8  && coluna + i < 8){if(tabuleiro[fileira+i][coluna+i] == 'D'){return false;};}
        if(fileira - i >= 0 && coluna - i >= 0){if(tabuleiro[fileira-i][coluna-i] == 'D'){return false;};}
        if(fileira + i < 8 && coluna - i >= 0){if(tabuleiro[fileira+i][coluna-i] == 'D'){return false;};}
        if(fileira - i >= 0 && coluna + i < 8){if(tabuleiro[fileira-i][coluna+i] == 'D'){return false;};}
    };
    return true;
};


bool resolvedor(const vector<vector<char>>& mapa, int damas, int i, int j){

}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<char>> tabuleiro;
    for(int i=0; i<8; i++){
        vector<char> linha(8);
        for(int j=0; j<8; j++){
            cin >> linha[j];
        };
        tabuleiro.push_back(linha);
    };





    return 0;
}