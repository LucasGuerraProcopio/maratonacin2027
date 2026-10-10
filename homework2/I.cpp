#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;


bool verificador(vector<long long>& sequencia, long long meio, long long meta){
    long long vacas = 1;
    long long posicao = 0;
    auto proximo = lower_bound(sequencia.begin(), sequencia.end(), 0);
    posicao = *proximo;
    for(int i=1; i<meta; i++){
        posicao += meio;
        auto proximo = lower_bound(sequencia.begin(), sequencia.end(), posicao);
        if(proximo == sequencia.end()){return false;}
        else{
            posicao = *proximo;
            vacas += 1;
            if(vacas == meta){return true;};
        };
    };
};




int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>> t;
    for(int i=0; i<t; i++){

        long long n, c, menor, maior, mid; cin>> n >> c;
        long long melhor_resultado = 0;
        bool tentativa;
        vector<long long> lista(n);
        for(int j=0; j<n; j++){
            cin >> lista[j];
        };
        sort(lista.begin(), lista.end());
        menor = lista[0];
        maior = lista[n-1];
        while(menor <= maior){
            mid = (maior + menor)/2;
            tentativa = verificador(lista, mid, c);
            if(tentativa){
                melhor_resultado = mid;
                menor = mid + 1;
            }
            else{
                maior = mid - 1;
            };
        };

        cout << melhor_resultado << "\n";
    }

    return 0;
}