#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int linhas, colunas, inicio;
    string linha;
    vector<vector<char>> matriz;
    vector<vector<bool>> visitado;
    vector<pair<int, int>> caminho;

    while(2 + 2 == 4){
        cin >> linhas >> colunas >> inicio;
        if(linhas == 0 && colunas == 0 && inicio == 0){
            return 0;
        }
        matriz.clear();
        visitado.clear();
        caminho.clear();
        for(int i=0; i<linhas; i++){
            cin >> linha;
            vector<char> correto(linha.begin(), linha.end());
            vector<bool> nao(colunas, false);
            matriz.push_back(correto);
            visitado.push_back(nao);
        };
        int linha_atual = 0;
        inicio -= 1;
        while(3 + 2 == 5){

            pair<int, int> localidade;
            localidade.first = linha_atual; localidade.second = inicio;
            caminho.push_back(localidade);
            visitado[linha_atual][inicio] = true;

            if(matriz[linha_atual][inicio] == 'N'){linha_atual -= 1;}
            else if(matriz[linha_atual][inicio] == 'S'){linha_atual += 1;}
            else if(matriz[linha_atual][inicio] == 'W'){inicio -= 1;}
            else if(matriz[linha_atual][inicio] == 'E'){inicio += 1;};
            
            if(linha_atual < 0 || linha_atual >= linhas  || inicio < 0  || inicio >= colunas){
                cout << caminho.size() << " step(s) to exit\n"; 
                break;
            };

            if(visitado[linha_atual][inicio] == true){
                int passos = 0;
                for(int i=0; i<caminho.size(); i++){
                    if(linha_atual != caminho[i].first || inicio != caminho[i].second){passos += 1;}
                    else{
                        cout << passos << " step(s) before a loop of " << caminho.size() - passos << " step(s)\n";
                        break;
                    };
                };
                break;
            };
        };
    };


    return 0;

}