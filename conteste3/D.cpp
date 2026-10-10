#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n; cin >> n;
    long long meio;
    long long resultado = 0;

    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };
    meio = (n/2);
    sort(lista.begin(), lista.end());

    for(int i=0; i<n; i++){
        resultado += abs(lista[meio] - lista[i]);
    };

    cout << resultado;


    return 0;

}