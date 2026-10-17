#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    long long t, a, b, c;
    cin >> t;

    while(t--){

        cin >> a >> b >> c;

        if(a >= b){
            cout << a + c - b << "\n";
        }

        else{
            if(b - a > a + c - b){
                cout << b - a << "\n";
            }
            else{
                cout << a + c - b << "\n";
            }

        }

    }

    return 0;

}