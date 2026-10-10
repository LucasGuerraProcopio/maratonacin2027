#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long l, r;  cin >> l >> r;

    long long inicio = 0;
    long long atual = 0;
    long long resultado = 0;

    while(inicio < r){
        atual += 1;
        inicio += atual;
        if(inicio >= l){
            if(inicio <= r){
                resultado += 1;
            };
        };
    };

    cout << resultado;

    return 0;
}