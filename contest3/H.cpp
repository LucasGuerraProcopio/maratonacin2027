#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    vector<pair<long long, long long>> numeros;
    for(int i=0; i<n; i++){
        pair<long long, long long> linha;
        cin >> linha.first;
        linha.second = i + 1;
        numeros.push_back(linha);
    };
    sort(numeros.begin(), numeros.end());

    for(int i=0; i<n; i++){
        long long menor = i+1;
        long long maior = n-1;
        while(menor < maior){
            if(numeros[i].first + numeros[menor].first + numeros[maior].first == k){
                vector<long long> resposta;
                resposta.push_back(numeros[i].second);
                resposta.push_back(numeros[menor].second);
                resposta.push_back(numeros[maior].second);
                sort(resposta.begin(), resposta.end());
                cout << resposta[0] << " " << resposta[1] << " " << resposta[2];
                return 0;
            }
            else if(numeros[i].first + numeros[menor].first + numeros[maior].first > k){
                maior--;
            }
            else{
                menor++;
            };
        };
    }

    cout << "IMPOSSIBLE";

    return 0;
}