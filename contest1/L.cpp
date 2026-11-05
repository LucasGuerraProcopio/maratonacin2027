#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    vector<long long> numeros(n);
    for(int i=0; i<n; i++){
        cin >> numeros[i];
    };

    vector<long long> restos(n);
    for(int i=0; i<n; i++){
        restos[i] = numeros[i] % k;
    }

    sort(restos.begin(), restos.end());
    long long a, b, c;
    a = restos[n-1] - restos[0];
    b = 1e12;
    for(int i=0; i<n-1; i++){
        if(restos[i] + k - restos[i+1] < b){
            b = restos[i] + k - restos[i+1];
        }
    }

    c = min(a, b);

    cout << c;


    return 0;

}