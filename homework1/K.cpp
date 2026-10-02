#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string rodada;
    long long t, n, sequencia_atual, zeros, uns, resultado0, resultado1, resultado_final;
    long long maior_sequencia1;
    long long maior_sequencia0;
    maior_sequencia1 = 0;
    maior_sequencia0 = 0;
    cin >> t;
    sequencia_atual = 0;
    for(int i=0; i<t; i++){
        cin >> n;
        cin >> rodada;
        sequencia_atual = 1;
        zeros = 0;
        uns = 0;
        maior_sequencia1 = 0;
        maior_sequencia0 = 0;
        for(int c=0; c<n; c++){
            if(rodada[c] == '0'){
                zeros += 1;
            }
            else{
                uns += 1;
            };
        };
        for(int j=1; j<n; j++){
            if(rodada[j] == rodada[j-1]){
                sequencia_atual += 1;
            }
            if(rodada[j] != rodada[j-1] || j == n-1){
                if(rodada[j-1] == '0' && sequencia_atual > maior_sequencia0){
                    maior_sequencia0 = sequencia_atual;
                }
                else if(rodada[j-1] == '1' && sequencia_atual > maior_sequencia1){
                    maior_sequencia1 =sequencia_atual;
                }
                sequencia_atual = 1;
            }
        };
        resultado0 = uns + (zeros - maior_sequencia0)*2;
        resultado1 = zeros + (uns - maior_sequencia1)*2;
        if(resultado0 <resultado1){
            resultado_final = resultado0;
        }
        else{
            resultado_final = resultado1;
        }
        cout << resultado_final << "\n";
    };
    return 0;
    }
    
