#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, maior, intervalo, atual;
    cin >> n;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };

    sort(lista.begin(), lista.end());

    atual = 1;
    maior = 1;
    for(int r=0; r<n; r++){
        while(lista[r] >= lista[atual] - 5  && atual != n-1){
            atual++;
        }
        intervalo = atual - r;
        if(atual == n-1  && lista[r] >= lista[atual] - 5){
            intervalo += 1;
        }
        if(intervalo > maior){
            maior = intervalo;
        };
    };

    cout << maior;

    return 0;
}