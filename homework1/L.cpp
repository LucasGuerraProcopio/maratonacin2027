#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    long long n, somatotal, somarodada, a;
    stack<pair<long long, long long>> pilha;
    cin >> n;
    vector<pair<long long, long long>> lista(n);
    pair<long long, long long> par;
    for(int i=0; i<n; i++){
        cin >> a;
        par = {a, 1};
        lista[i] = par;
    };

    somatotal = 0;
    somarodada = lista[n-1].first;
    somatotal += somarodada;
    pilha.push(lista[n-1]);

    for(int g=n-2; g>=0; g--){

        while(pilha.size() > 0 && lista[g].first < pilha.top().first){
            somarodada -= pilha.top().first * pilha.top().second;
            somarodada += lista[g].first * pilha.top().second;
            lista[g].second += pilha.top().second;
            pilha.pop();
        };
        somarodada += lista[g].first;
        pilha.push(lista[g]);
        somatotal += somarodada;
    };
    cout << somatotal;
    return 0;
}