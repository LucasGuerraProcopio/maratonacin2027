#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n,soma_total, soma_rodada, menor_numero;
    bool nao_registrou = true;
    cin >> n;
    vector<int> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };
    soma_total = 0;
    soma_rodada = 0;
    menor_numero = lista[0];
    soma_rodada += menor_numero;
    for(int j=1; j<n; j++){
        if(lista[j] < menor_numero){
            menor_numero = lista[j];
        };
        soma_rodada += menor_numero;
    };
    soma_total += soma_rodada;
    for(int w=1; w<n; w++){

        if(lista[w] <= lista[w-1]){
            soma_rodada = soma_rodada - lista[w-1];
            soma_total += soma_rodada;
            continue;
        };


    }

    cout << soma_total;


}