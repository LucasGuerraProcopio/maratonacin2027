#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, k, total, anos;
    cin >> n >> k;
    total = n;
    anos = 0;
    while(total < k){
        n += 1;
        total += n;
        anos += 1;
    };
    cout << anos << endl;
    return 0;
    
};