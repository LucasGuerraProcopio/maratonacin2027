#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll p1 = 0;
    ll p2 = 0;
    ll p3 = 0;
    string pri, sec, ter; cin >> pri >> sec >> ter;
    pri += '0';
    sec += '0';
    ter += '0';
    for(int i=0; i<pri.size(); i++){
        if(pri[i] == '2'){p2++;}
        else if(pri[i] == '3'){p3++;}
    }
    for(int i=0; i<sec.size(); i++){
        if(sec[i] == '1'){p1++;}
    };

    ll total = p1 + p2 + p3;

    ll r1 = 0;
    ll r2 = 0;
    ll r3 = 0;
    for(int i=0; i<total; i++){
        if(pri[r1] == sec[r2]){cout << pri[r1]; r1++; r2++;}
        else if(pri[r1] == ter[r3]){cout << ter[r3]; r1++; r3++;}
        else if(sec[r2] == ter[r3]){cout << sec[r2]; r2++; r3++;}
    }

    return 0;

}