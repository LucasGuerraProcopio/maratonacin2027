#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<ll> seises;
        vector<ll> doises;
        vector<ll> nada;
        vector<ll> treises;
        for(int i=0; i<n; i++){
            ll a; cin >> a;
            if(a % 6 == 0){seises.push_back(a); continue;}
            else if(a % 2 == 0){doises.push_back(a); continue;}
            else if(a % 3 == 0){treises.push_back(a); continue;}
            else{nada.push_back(a); continue;}
        };

        for(int i=0; i<seises.size(); i++){
            if(i == 0){cout << seises[i];}
            else{cout << " " << seises[i];}
        };

        for(int i=0; i<doises.size(); i++){
            if(i == 0 && seises.size() == 0){cout << doises[i];}
            else{cout << " " << doises[i];}
        };

        for(int i=0; i<nada.size(); i++){
            if(i == 0 && seises.size() == 0 && doises.size() == 0){cout << nada[i];}
            else{cout << " " << nada[i];}
        }

        for(int i=0; i<treises.size(); i++){
            if(i == 0 && seises.size() == 0 && doises.size() == 0 && nada.size() == 0){cout << treises[i];}
            else{cout << " " << treises[i];}
        }

        cout << "\n";
    }

    return 0;

}