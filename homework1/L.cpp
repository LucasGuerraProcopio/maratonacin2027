#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
        }
        else{
            menor_numero = lista[w];
            soma_rodada = soma_rodada - lista[w-1];
            for(int k=w; k<n; k++){
                if(lista[k] < lista[w-1]){
                    break;
                }
                else{
                    if(lista[k] < menor_numero){
                        menor_numero = lista[k];
                    };
                soma_rodada += (menor_numero - lista[w-1]);    
                };
            };
            soma_total += soma_rodada;
        };
    };
    cout << soma_total;
    return 0;
}