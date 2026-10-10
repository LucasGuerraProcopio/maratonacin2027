#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool checador(vector<long long>& regua, long long meio, long long sublista){
    long long divisoes = 1;
    long long soma = 0;
    long long parametro = 0;
    while(2>1){

        if(parametro == regua.size()){break;};

        if(soma + regua[parametro] < meio){
            soma += regua[parametro];
            parametro += 1;
        }
        else{
            if(soma + regua[parametro] == meio){
                parametro += 1;
            };
            soma = 0;
            if(parametro != regua.size()){
                divisoes += 1;
            };
        };
    };
    if(divisoes <= sublista){return true;}
    else{return false;};
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, menor, maior, mid, resultado; cin >> n >> k;
    bool foi;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };

    menor = 1;
    for(int y=0; y<n; y++){
        if(lista[y] > menor){
            menor = lista[y];
        };
    };
    maior = accumulate(lista.begin(), lista.end(), 0LL);
    while(menor <= maior){
        mid = (menor + maior)/2;
        foi = checador(lista, mid, k);
        if(foi){
            resultado = mid;
            maior = mid - 1;
        }
        else{
            menor = mid + 1;
        };
    };

    cout << resultado;

    return 0;
}