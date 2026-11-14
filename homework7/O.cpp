#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int divisores[1000005];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(divisores, 0, sizeof divisores);

    for(int i=1; i<=1000; i++){
        for(int j=i; j<=1000000; j += i){
            divisores[j]++;
            if(j / i > 1000){
                divisores[j]++;
            }
        }
    }

    int n; cin >> n;

    while(n--){
        int x; cin >> x;
        cout << divisores[x] << "\n";
    }

    return 0;

}