#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> numeros(n+1);
        int ultimo = 0;
        bool tem = false;
        for(int i=1; i<=n; i++){
            cin >> numeros[i];
            if(numeros[i] == 1){tem = true; numeros[ultimo] = 0;}
            if(numeros[i] == -1 && !tem){numeros[i] = 1; tem = true;}
            else if(numeros[i] == -1 && tem){numeros[ultimo] = 0; ultimo = i;}         
        };
        if(numeros[ultimo] == -1){numeros[ultimo] = 1;};
        for(int i=1; i<=n; i++){
            if(i==1){cout << numeros[i];}else{cout << " " << numeros[i];}
        }
        cout << "\n";

    };

    return 0;

}