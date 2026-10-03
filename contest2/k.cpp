#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, soma_atual, dormitorio, a, b;
    cin >> n >> k;
    vector<long long> quartos;
    vector<long long> somas;
    vector<long long> cartas;
    for(int i=0; i<n; i++){
        cin >> b;
        quartos.push_back(b);
    };
    somas.push_back(0);
    for(int t=1; t<=n; t++){
        soma_atual = somas[t-1] + quartos[t-1];
        somas.push_back(soma_atual);
    };

    dormitorio = 1;
    for(int p=0; p<k; p++){
        cin >> b;
        cartas.push_back(b);
    };

    for(int r=0; r<k; r++){
        while(cartas[r] > somas[dormitorio]){
            dormitorio += 1;
        };
        a = cartas[r] - somas[dormitorio - 1];
        cout << dormitorio << " " << a << "\n";
    };

    return 0;


}