#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<ll> impares;
        vector<ll> pares;
        for(int i=0; i<n; i++){
            ll a; cin >> a;
            if(a > 0){
                if(i%2 == 0){pares.push_back(a);}
                else{impares.push_back(a);}
            }
            else{
                if(i%2==1){pares.push_back(abs(a));}
                else{impares.push_back(abs(a));}
            }
        };

        int pa, im;
        pa = n/2;
        im = n/2;
        if(n%2 == 1){pa++;}
        sort(pares.begin(), pares.end());
        sort(impares.begin(), impares.end());
        ll maximo = 0;
        for(int i=0; i<pares.size(); i++){
            if(i < (int)pares.size() - pa){
                maximo -= pares[i];
            }
            else{
                maximo += pares[i];
            }
        };
        for(int i=0; i<impares.size(); i++){
            if(i < (int)impares.size() - im){
                maximo -= impares[i];
            }
            else{
                maximo += impares[i];
            }
        };

        cout << maximo << "\n";
    };

    return 0;

}