#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a,rodadas, mediana;
    vector<int> lista;
    multiset<int> organizado;
    cin >> n >> k;
    rodadas = n-k+1;
    for(int i=0; i<n; i++){
        cin >> a;
        lista.push_back(a);
    };
    for(int g=0; g<k; g++){
        organizado.insert(lista[g]);
    };
    if(k%2==0){
        mediana = (k/2) - 1;
    }
    else{
        mediana = (k-1)/2;
    };

    auto posicao = organizado.begin();
    advance(posicao, mediana);
    cout << *posicao;
    
    for(int b=1; b<rodadas; b++){
        organizado.insert(lista[b+k-1]);
        organizado.erase(organizado.find(lista[b-1]));
        auto posicao = organizado.begin();
        advance(posicao, mediana);
        cout << " " << *posicao; 
    };
    return 0;
}