#include <iostream>
#include <vector>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    long long total = 0;
    int coordenada;
    vector<vector<int>> matriz;
    for(int i=0; i<n; i++){
        vector<int> linha(n);
        for(int j=0; j<n; j++){
            cin >> linha[j];
        };
        matriz.push_back(linha);
    };

    for(int i=0; i + k -1 < n; i++){
        for(int j=0; j + k -1 < n; j++){
            coordenada = matriz[i][j];
            if(matriz[i + k - 1][j] == coordenada  && matriz[i][j + k - 1] == coordenada && matriz[i + k - 1][j + k - 1] == coordenada){
                total += 1;
            }
        };
    };


    cout << total;

    return 0;
}