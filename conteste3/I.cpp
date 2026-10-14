#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k; cin >> n >> k;
    if(k*2 >= n){
        cout << 10;
        return 0;
    };

    long long resposta;
    resposta = (n / k) * 5;
    if(n % k != 0){
        resposta += 5;
    }
    if(resposta < 10){
        resposta = 10;
    };

    cout << resposta;
    return 0;


}