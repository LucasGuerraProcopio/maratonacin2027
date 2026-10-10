#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>> n;
    vector<int> lista(n);
    for(int i=0; i<n; i++){
        cin >> lista[i];
    };

    int tempo = 0;
    bool periodo1 = true;
    bool periofo2 = true;
    for(int i=0; i<n; i++){
        if(tempo + lista[i] > 120  && periodo1 == true){
            tempo += 180;
            periodo1 = false;
        }
        if(tempo + lista[i] > 720 && periofo2 == true){
            tempo += 180;
            periofo2 = false;
        }

        tempo += lista[i];
    };

    cout << tempo;

    return 0;

}