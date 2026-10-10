#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    long long soma = 0;
    bool foi = false;
    vector<long long> casas;
    vector<long long> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };

    for(int mask = 0; mask < (1 << n); mask++){
        if(__builtin_popcount(mask) != 3){continue;};
        soma = 0;
        casas.clear();
        for(int bit = 0; bit < n; bit++){
            if(mask & (1 << (bit))) {
                casas.push_back(bit + 1);
                soma += lista[bit];
            };
            };
        if(soma == k){
            cout << casas[0] << " " << casas[1] << " " << casas[2]; 
            foi = true;
            break;
        }
    }

    if(foi == false){
        cout << "IMPOSSIBLE";
    }

    return 0;
}