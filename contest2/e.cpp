#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long maior, soma_total;
    cin >> n;
    map<long long, long long> valores;
    vector<long long> pedidos(n);
    for(int i=0; i<n; i++){
        cin >> pedidos[i];
    }

    maior = 0;
    for(int o=0; o<n; o++){
        if(pedidos[o] > maior){
            maior = pedidos[o];
        };
    };

    for(int c=1; c<maior+1; c++){
        if(c==1){
            valores[c] = 1;
        }
        else{
            valores[c] = valores[c-1]*10 + 1;
        }
    }

    soma_total = 0;
    for(int h=0; h<n; h++){
        soma_total += valores[pedidos[h]];
    };

    cout << soma_total;
    return 0;
}