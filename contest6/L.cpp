#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){

        int c,p; cin >> c >> p;
        map<string, vector<int>> cafezes;

        for(int i=0; i<c; i++){
            int a,b,c;
            string nome; cin >> nome;
            cin >> a >> b >> c;
            cafezes[nome] = {a,b,c};
        };

        for(int i=0; i<p; i++){
            string pessoa; cin >> pessoa;
            int cafe;
            string tamanho; cin >> tamanho;
            if(tamanho == "small"){cafe = 0;}else if(tamanho == "medium"){cafe = 1;}else{cafe = 2;}
            string pedido; cin >> pedido;
            int custo = 100/p;
            custo += cafezes[pedido][cafe];
            if(custo%5 == 4){custo++;}else if(custo%5 == 1){custo--;};
            cout << pessoa << " " << custo << "\n";
        }

    }

    return 0;

}