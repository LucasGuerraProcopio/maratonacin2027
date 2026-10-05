#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long l =1;
    long long r = 1e18;
    long long resposta;
    long long media = 0;
    long long comparacao = 0;

    long long t, n;
    cin >> n >> t;
    vector<long long> maquinas(n);

    for(int i=0; i<n; i++){
        cin >> maquinas[i];
    };

    while(l <= r){
        comparacao = 0;
        media = (l + r)/2;
        for(int i=0; i<n; i++){
            comparacao += (media/maquinas[i]);
            if(comparacao >= t){
                break;
            };
        }
        if(comparacao >= t){
            resposta = media;
            r = media - 1;
        }
        else{
            l = media + 1;
        }
    };

    cout << resposta;

    return 0;
}