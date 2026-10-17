#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, a; cin >> n >> k;
    vector<long long> numeros;
    vector<long long> importantes;
    long long meio = n/2;
    for(int i=0; i<n; i++){
        cin >> a;
        numeros.push_back(a);
    };
    sort(numeros.begin(), numeros.end());
    for(int i=meio; i<n; i++){
        importantes.push_back(numeros[i]);
    }

    vector<long long> iguais;

    iguais.push_back(importantes[0]);

    for(int i=1; i<importantes.size(); i++){
        if(importantes[i] == iguais[i-1]){iguais.push_back(importantes[i]); continue;};
        if((importantes[i] - iguais[i-1]) * iguais.size() <= k ){
            k -= (importantes[i] - iguais[i-1]) * iguais.size();
            iguais.push_back(importantes[i]);
        }
        else{
            long long extra = k/iguais.size();
            cout << iguais[i-1] + extra;
            return 0;
        }
    }

    long long extra = k/iguais.size();

    cout << iguais[iguais.size() - 1] + extra;


    return 0;

}