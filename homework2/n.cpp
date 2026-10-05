#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int contador = 1;
    string texto;
    vector<string> lista;
    cin >> texto;
    sort(texto.begin(), texto.end());
    lista.push_back(texto);

    while(next_permutation(texto.begin(), texto.end())){
        contador += 1;
        lista.push_back(texto);
    }

    cout << contador << "\n";

    for(int i=0; i<lista.size(); i++){
        cout << lista[i] << "\n";
    };

    return 0;
}