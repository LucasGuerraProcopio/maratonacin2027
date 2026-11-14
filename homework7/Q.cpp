#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        ll n; cin >> n;
        ll resposta;

        while(true){
            n++;
            bool foi = true;
            if(n == 2){resposta = 2; break;}
            if(n % 2 == 0){continue;}

            for(ll i=3; i * i<=n; i += 2){
                if(n%i == 0){foi = false; break;}
            }
            if(foi){resposta = n; break;}
        }
        cout << resposta << "\n";
    }

    return 0;

}