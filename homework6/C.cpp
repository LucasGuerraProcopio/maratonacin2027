#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int base3[11];
    base3[0] = 1;
    for(int i=1; i<=10; i++){
        base3[i] = base3[i-1] * 3;
    };

    int t; cin >> t; 

    while(t--){

        int n; cin >> n;
        vector<ll> dp(base3[10], -1);
        dp[0] = 0;

        for(int i=0; i<n; i++){

            ll numero; cin >> numero;
            int digitos[11];
            bool valido = true;
            memset(digitos, 0, sizeof digitos);
            ll copia = numero;
            while(copia != 0){
                int digito = copia % 10; copia /=10;
                digitos[digito]++;
                if(digitos[digito] > 2){valido = false; break;}
            };

            if(!valido){continue;}

            int posicao = 0;
            for(int j=0; j<10; j++){
                posicao += base3[j] * digitos[j];
            };

            for(int S = base3[10] - 1; S>=0; S--){
                if(dp[S] == -1){continue;};
                bool pode = true;
                for(int b=0; b<10; b++){
                    int aparicoes = (S/base3[b]) % 3;
                    if(aparicoes + digitos[b] > 2){pode = false; break;}
                }
                if(!pode){continue;}
                dp[S + posicao] = max(dp[S + posicao], numero + dp[S]);
            }

        }

        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }



    return 0;

}