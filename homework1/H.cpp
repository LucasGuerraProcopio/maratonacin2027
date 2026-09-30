#include <iostream>
#include <vector>
#include <set>;
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, rodadas;
    vector<int> lista;
    multiset<int> organizado;
    cin >> n >> k;
    rodadas = n-k;
    for(int i=0; i<n; i++){
        cin >> a;
        lista.push_back(a);
    };
    for(int g=0; g<k; g++){
        organizado.insert(lista[g]);
    }

    auto mediana = next(organizado.begin(), (k-1)/2); 
    cout << *mediana;
    
    for(int b=0; b<rodadas; b++){
        organizado.insert(lista[b+k]);
        if(lista[b+k] < *mediana){
            mediana--;
        };
        if(lista[b] <= *mediana){
            mediana++;
        };
        organizado.erase(organizado.find(lista[b]));
        cout << " " << *mediana;

    };
    return 0;
};