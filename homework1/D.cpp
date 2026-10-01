#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> lista(n);
    priority_queue<int, vector<int>, greater<>> pior;
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };

    long long soma_total, pocoes;
    soma_total = 0;
    pocoes = 0;
    for(int e=0; e<n; e++){
        pior.push(lista[e]);
        soma_total = soma_total + lista[e];
        pocoes += 1;
        if(soma_total < 0){
            soma_total -= pior.top();
            pocoes = pocoes - 1;
            pior.pop();
        };
    };
    cout << pocoes;
    return 0;
}