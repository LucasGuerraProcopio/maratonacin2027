#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<numeric>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    vector<long long> lista(n);
for(int i=0; i<n; i++){
    cin >> lista[i];
}

    long long soma, atual, menor, resultado;
    soma = accumulate(lista.begin(), lista.end(), 0LL);
    menor = 999999999999;
    atual = 0;
    resultado = 0;

    for(int mask = 0; mask < (1 << n); mask++){
        atual = 0;
        resultado = 0;
        for(int bit=0; bit < n; bit++){
            if(mask & (1 << (bit))) {
            atual += lista[bit];
            };
        }
    resultado = abs(soma - 2*atual);
    if(resultado < menor){
        menor = resultado;
    };
    };

    cout << menor;

    return 0;
}