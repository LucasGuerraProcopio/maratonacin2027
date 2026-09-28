#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    long long a, b, busca;
    long long resultado = 0;
    vector<long long> lista;
    vector<long long> somas;
    map<long long, long long> passadas;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a;
        lista.push_back(a);
    };
    somas.push_back(lista[0]);
    for(int i=0; i <n-1; i++){
        b = lista[i+1] + somas[i];
        somas.push_back(b);
    };
    for(int p=0; p<n; p++){
        busca = somas[p] - k;
        if(busca==0){
            resultado += 1;
        }
        if(passadas.count(busca)){
            resultado += passadas[busca];
        };
        try{
            passadas[somas[p]] += 1;
        }
        catch (...) {
            passadas[somas[p]] = 1;
        }       
    };

    cout << resultado;
}