#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> mapa;

bool valida(int i, int j, int n, int m){return i>= 0 && i < n && j >=0 && j < m  && mapa[i][j] == '.' ;}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m; cin >> n >> m;
    string linha;
    for(int i=0; i<n; i++){
        cin >> linha;
        vector<char> certo(linha.begin(), linha.end());
        mapa.push_back(certo);
    };

    int inicioI, inicioJ; cin >> inicioI >> inicioJ;
    int objetivoI, objetivoJ; cin >> objetivoI >> objetivoJ;
    inicioI -= 1; inicioJ -= 1; objetivoI -= 1; objetivoJ -= 1;

    int laterais_obj = 0;

    if(objetivoI > 0){if(mapa[objetivoI-1][objetivoJ] == '.'){laterais_obj++;};};
    if(objetivoJ > 0){if(mapa[objetivoI][objetivoJ-1] == '.'){laterais_obj++;};};
    if(objetivoI < n - 1){if(mapa[objetivoI+1][objetivoJ] == '.'){laterais_obj++;};};
    if(objetivoJ < m - 1){if(mapa[objetivoI][objetivoJ+1] == '.'){laterais_obj++;};};

    if(inicioI == objetivoI && inicioJ == objetivoJ - 1){laterais_obj++;}
    if(inicioI == objetivoI && inicioJ == objetivoJ + 1){laterais_obj++;}
    if(inicioI == objetivoI - 1 && inicioJ == objetivoJ){laterais_obj++;}
    if(inicioI == objetivoI + 1 && inicioJ == objetivoJ){laterais_obj++;}

    if(laterais_obj == 0){cout << "NO"; return 0;};
    if(mapa[objetivoI][objetivoJ] == '.' && laterais_obj < 2){cout << "NO"; return 0;}

    queue<pair<int, int>> analisados;
    analisados.push({inicioI, inicioJ});
    bool chegou = false;

    vector<int> izes = {-1, 1, 0, 0};
    vector<int> jotas = {0, 0, -1, 1};

    while(!analisados.empty()){
        auto [a, b] = analisados.front(); analisados.pop();
        for(int q=0; q<4; q++){
            int c = a + izes[q];
            int d = b + jotas[q];
            if(c == objetivoI && d == objetivoJ){cout << "YES"; return 0;};
            if(valida(c, d, n, m)){
                mapa[c][d] = 'X';
                pair<int, int> posicao = {c, d};
                analisados.push(posicao);
            }
        }
    }

    if(chegou){cout << "YES";}else{cout << "NO";};




    


    return 0;

}