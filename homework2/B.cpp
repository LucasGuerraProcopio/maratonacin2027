#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checador(const vector<vector<char>>& tabuleiro, int fileira, int coluna, char c){
    for(int i=0; i<9; i++){
        if(tabuleiro[fileira][i] == c){return false;};
        if(tabuleiro[i][coluna] == c){return false;};
        if(tabuleiro[3 * (fileira / 3) + i / 3][3 * (coluna / 3) + i % 3] == c){return false;};
    }
    return true;
};

bool resolve_sudoku(vector<vector<char>>& quadro, int i = 0, int j =0){
    
    if(i==9){
        for(int a=0; a<9; a++){
            for(int b=0; b<9; b++){
                if(b==0){
                    cout << quadro[a][b];
                }
                else{
                    cout << " " << quadro[a][b];
                };
            };
        cout << "\n";
        };
    return true;
    };


    if(j==9){return resolve_sudoku(quadro, i+1, 0);}

    if(quadro[i][j] != '0'){return resolve_sudoku(quadro, i, j+1);};

    for(char e = '1'; e<='9'; e++){
        if(checador(quadro, i, j, e)){
            quadro[i][j] = e;
            if(resolve_sudoku(quadro, i, j+1)){return true;};
            quadro[i][j] = '0';
        };
    };

    return false;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int f=0; f<n; f++){
        bool foi;
        vector<vector<char>> matriz;
        matriz.clear();
        for(int i=0; i<9; i++){
            vector<char> linha(9);
            for(int j=0; j<9; j++){
                cin >> linha[j];
            };
            matriz.push_back(linha);
        };
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";

        foi = resolve_sudoku(matriz, 0, 0);

        if(foi == false){
            cout << "No solution\n";
        };
    };

    return 0;
};