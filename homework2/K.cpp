#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t, maior, atual, soma, quantidade;
    cin >> n >> t;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };
    soma = lista[0];
    maior = 0;
    atual = 0;

    for(int j=0; j<n; j++){
        while(soma <= t  && atual != n-1){
            atual++;
            if(soma + lista[atual] <= t){
                soma += lista[atual];
            }
            else{
                soma += lista[atual];
                break;
            };
        };
        quantidade = atual - j;
        if(atual == n-1 && soma <= t){
            quantidade += 1;
        }
        if(quantidade > maior){
            maior = quantidade;
        }
        soma -= lista[j];
        if(atual <= j){
            atual = j+1;
            if(atual <= n-1){
                soma += lista[atual];
            }
        }
    };

    cout << maior;
    return 0;
};