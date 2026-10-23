#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, q; cin >> n >> q;
    vector<long long> lista(n + 1);
    vector<long long> anteriores(n + 1);
    for(int i=1; i<=n; i++){
        cin >> lista[i];
    };
    for(int i=1; i<=n; i++){
        anteriores[i] = lista[i] - i;
    };

    for (int i=0; i<q; i++){
        long long k; cin >> k;

        auto posicao = lower_bound(anteriores.begin() + 1, anteriores.end(), k);
        int idx = distance(anteriores.begin(), posicao);

        if(idx > n){
            cout << lista[n] + (k - anteriores[n]) << "\n";
        }
        else{
            cout << lista[idx - 1] + (k - anteriores[idx - 1]) << "\n";
        }
    }

    return 0;

}