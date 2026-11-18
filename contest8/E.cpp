#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        int n; cin >> n;

        vector<ll> todos;
        for(int i=0; i<n; i++){
            ll a; cin >> a;
            todos.push_back(a);
        }

        ll maior = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                maior = max(maior, todos[i] ^ todos[j]);
            }
        }

        cout << maior << "\n";


    }

    return 0;

}