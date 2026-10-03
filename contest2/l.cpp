#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, soma_total;
    cin >> n >> k;
    soma_total = 0;
    for(int i=1; i<=n; i++){
        soma_total += i;
        if(soma_total - (n-i) == k){
            cout << n-i;
            break;
        }
    };

    return 0;


}