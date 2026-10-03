#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int b, t, n, resultado;
    cin >> n;
    while(n--){
        cin >> b >> t;
        resultado = b*t;
        cout << resultado << "\n";
    };
    return 0;
}