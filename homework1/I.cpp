#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    vector<int> lista;
    vector<long long> somas;
    int n, q, c;
    int a, b;
    long long d, resultado;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> c;
        lista.push_back(c);
    };
    somas.push_back(lista[0]);
    for(int j=1; j<n; j++){
        d = lista[j] + somas[j-1];
        somas.push_back(d);
    };
    for(int y=0; y < q; y++){
        cin >> a >> b;
        a -= 1;
        b -= 1;
        if(a==b){
            cout << lista[a] << "\n";
        }
        else{
            if(a!=0){
                resultado = somas[b] - somas[a-1];
                cout << resultado << "\n";
            }
            else{
                resultado = somas[b];
                cout << resultado << "\n";
            };

        };
    };
    return 0;
};