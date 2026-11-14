#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin >> n >> k;
    int resultado = 0;
    int repetidos = 0;
    int ultimo = n-1;
    vector<ll> casos;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        casos.push_back(a);
    };
    sort(casos.begin(), casos.end());
    map<int,bool> tem;
    for(int i=0; i<n; i++){
        if(tem[casos[i]]){repetidos++;}
        tem[casos[i]] = true;
    };

    for(int i=0; i<n; i++){
        if(tem[i]){continue;}
        if(k > 0){
            k--;
            tem[i] = true;
            if(repetidos > 0){repetidos--;}
            else{
                tem[casos[ultimo]] = false;
                ultimo--;
            }    
        }
        else{
            break;
        }
    };

    for(int i=0; i<n; i++){
        if(tem[i]){resultado++;}
        else{break;}
    };

    cout << resultado;

    return 0;

}