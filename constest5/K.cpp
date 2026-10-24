#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    string nome; cin >> nome;
    vector<char> correto(nome.begin(), nome.end());
    deque<char> funcionamento;
    bool inverteu = false;
    for(int i=0; i<k; i++){
        if(correto[i] != correto[n-i-1]){
            if(inverteu){inverteu = false;}else{inverteu = true;}
        };
    }
    if(!inverteu){
        for(int i=k; i<n-k; i++){
            cout << correto[i];
        };
    }
    else{
        for(int i=n-k-1; i>k-1; i--){
            cout << correto[i];
        }
    }


    return 0;

}