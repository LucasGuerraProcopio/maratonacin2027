#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;

}


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