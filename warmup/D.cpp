#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a; cin >> n;
    vector<long long> dinos;
    vector<long long> copia;
    for(int i=0; i<n; i++){
        cin >> a;
        dinos.push_back(a);
    };
    long long resultado = 0;

    while(dinos.size() != 1){
        for(int i=0; i<dinos.size() - 1; i +=2){
            if(dinos[i] >= dinos[i+1]){
                copia.push_back(dinos[i]);
                if(dinos[i] - dinos[i+1] > resultado){resultado = dinos[i] - dinos[i+1];}
            }
            else{
                copia.push_back(dinos[i+1]);
                if(dinos[i+1] - dinos[i] > resultado){resultado = dinos[i+1] - dinos[i];}
            };
        };
        if(dinos.size()%2 == 1){copia.push_back(dinos[dinos.size() - 1]);};
        dinos = copia;
        copia.clear();
    };

    cout << resultado;
    

    return 0;

}