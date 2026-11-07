#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char elas[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    string palavra; cin >> palavra;
    map<char, int> letra;
    for(int i=0; i<26; i++){
        letra[elas[i]] = 0;
    };

    int impares = 0;
    for(int i=0; i<palavra.size(); i++){
        letra[palavra[i]]++;
    };

    for(int i=0; i<26; i++){
        if(letra[elas[i]]%2 == 1){impares++;};
    };

    if(impares > 1){cout << "NO SOLUTION"; return 0;}

    for(int i=0; i<26; i++){
        if(letra[elas[i]] % 2 == 1){continue;}
        for(int j=0; j<(letra[elas[i]]/2); j++){
            cout << elas[i];
        }
    };

    for(int i=0; i<26; i++){
        if(letra[elas[i]] % 2 == 1){
            for(int j=0; j<letra[elas[i]]; j++){
                cout << elas[i];
            }
        }
    };

    for(int i=25; i>=0; i--){
        if(letra[elas[i]] % 2 == 1){continue;}
        for(int j=0; j<(letra[elas[i]]/2); j++){
            cout << elas[i];
        };
    };

    return 0;

}