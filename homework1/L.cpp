#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, somatotal, somarodada, delecoes;
    priority_queue<long long> pilha;
    cin >> n;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };
    delecoes = 0;
    somatotal = 0;
    somarodada = lista[n-1];
    somatotal += lista[n-1];
    pilha.push(lista[n-1]);

    for(int g=n-2; g>=0; g--){
        while(pilha.size() > 0 && lista[g] < pilha.top()){
            somarodada -= pilha.top();
            somarodada += lista[g];
            pilha.pop();
            delecoes += 1;
            if(pilha.size() == 0){
                somarodada = (n - g - 1) * lista[g];
            }
            
        };
        delecoes = 0;
        pilha.push(lista[g]);
        somarodada += lista[g];
        somatotal += somarodada;
    };
    cout << somatotal;
    return 0;
}