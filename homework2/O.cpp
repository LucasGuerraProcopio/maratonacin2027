#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long l, r, x, casos, soma, menor, maior;
    bool invalido = false;
    cin >> n >> l >> r >> x;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };
    
    casos = 0;
    soma = 0;


    for(unsigned int mask=0; mask < (1 << n); mask++){
        soma = 0;
        menor = 1e12;
        maior = 0;
        invalido = false;
        if(__builtin_popcount(mask) < 2){
            continue;
        }
        for(int bit=0; bit<n; bit++){
            if(mask & (1 << (bit))){
                soma += lista[bit];
                if(lista[bit] < menor){
                    menor = lista[bit];
                }
                if(lista[bit] > maior){
                    maior = lista[bit];
                }
                
            }
        };
        if(soma < l || soma > r){
            invalido = true;
            }
        if(maior - menor < x){
            invalido = true;
                }
        if(invalido){
            continue;
        }
        else{
            casos += 1;
        };
    };

    cout << casos;

    return 0;
}