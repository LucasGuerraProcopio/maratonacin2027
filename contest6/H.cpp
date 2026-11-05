#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> andar(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> andar[i];
    };

    vector<ll> menores;
    vector<ll> maiores;
    ll ultimo = 0;
    for(int i=1; i<=n; i++){
        if(i%2 == 1){
            ultimo += andar[i];
            menores.push_back(ultimo);
        }
        else{
            ultimo -= andar[i];
            maiores.push_back(ultimo);
        }
    };

    sort(menores.begin(), menores.end()); sort(maiores.begin(), maiores.end());
    ll a = menores[0]; ll b = 0; if(n!=1){b = maiores[maiores.size()-1];}
    if(b < 0){b=0;}
    ll resposta = a - b + 1;
    if(a < 0){resposta = 0;}
    if(resposta <=0){resposta = 0;}
    cout << resposta << '\n';

    return 0;

}