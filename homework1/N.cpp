#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool avaliamenor(const string &a, const string &b){
    return (a + b) < (b + a);
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string palavra;
    vector<string> lista;
    string formado = "";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> palavra;
        lista.push_back(palavra);
    };
    sort(lista.begin(), lista.end(), avaliamenor);    
    for(int j=0; j<n; j++){
        formado += lista[j];
    };
    cout << formado;
}