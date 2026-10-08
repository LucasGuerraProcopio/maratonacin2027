#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>> t;
    for(int i=0; i<t; i++){

        int n, c; cin>> n >> c;
        long long intervalo;
        vector<long long> lista(n);
        priority_queue<long long, vector<long long>, greater<>> intervalos;
        for(int j=0; j<n; j++){
            cin >> lista[j];
        }
        sort(lista.begin(), lista.end());
        for(int r=0; r<n-1; r++){
            intervalo = lista[r+1] - lista[r];
            intervalos.push(intervalo);
            if(intervalos.size() == c){
                intervalos.pop();
            };
        };
        cout << intervalos.top() << "\n";
    }





    return 0;
}