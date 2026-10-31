#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        int a,b,c; cin >> a >> b >> c;
        int resultado = min(a,b);
        int res = min(resultado,c);
        cout << n-res << "\n";


    }

    return 0;

}