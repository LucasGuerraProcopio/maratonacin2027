#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string palavra; 
char letras[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll solve(int l, int r, int vez){
    if(l >= r){if(palavra[l] == letras[vez]){return 0;}else{return 1;}}
    int m = (l+r)/2;
    
    ll mudaEsquerda = 0; ll mudaDireita = 0;
    for(int i=l; i<=m; i++){if(palavra[i] != letras[vez]){mudaEsquerda++;};}
    for(int i=m+1; i<=r; i++){if(palavra[i] != letras[vez]){mudaDireita++;};}

    mudaEsquerda += solve(m+1, r, vez+1);
    mudaDireita += solve(l, m, vez+1);

    return min(mudaEsquerda, mudaDireita);

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cin >> palavra;

        ll resposta = solve(0, n-1, 0);
        cout << resposta << "\n";
    }

    return 0;

}