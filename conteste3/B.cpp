#include <bits/stdc++.h>
using namespace std;

bool verificador(long long meio, vector<long long>& lista, long long K, int n){
    long long uso = 0;
    
    for(int i=1; i<=n; i++){
        if(lista[i] < meio){
            uso += (meio - lista[i] + i - 1) / i; 
            if(uso > K){return false;};
        }
    }
    return true;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    vector<long long> numeros(n + 1);
    long long menor = 2e18;
    long long maior = 2e18;
    for(int i=1; i<=n; i++){
        cin >> numeros[i];
        if(numeros[i] < menor){
            menor = numeros[i];
        };
    };
    long long resposta = menor;

    while(menor <= maior){
        long long mid = (maior + menor) / 2;
        if(verificador(mid, numeros, k, n)){
            resposta = mid;
            menor = mid + 1;
        }
        else{
            maior = mid - 1;
        }
    }

    cout << resposta;

    return 0;

}