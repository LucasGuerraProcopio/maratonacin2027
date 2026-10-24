#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w; cin >> h >> w;

    if(h == 1 && w == 1){cout << 0; return 0;}
    else if(h == 1){
        cout << 1;
        for(int i=2; i<w; i++){
            cout << " " << 2;
        };
        cout << " " << 1;
        return 0;
    }
    else if(w==1){
        cout << 1 << "\n";
        for(int i=2; i<h; i++){
            cout << 2 << "\n";
        }
        cout << 1;
        return 0;
    }

    for(int i=0; i<w; i++){
        if(i==0){
            cout << 2;
        }
        else if(i == w-1){
            cout << " " << 2 << "\n";
        }
        else{
            cout << " " << 3;
        }
    }

    for(int i=2; i<h; i++){
    for(int i=0; i<w; i++){
        if(i==0){
            cout << 3;
        }
        else if(i == w-1){
            cout << " " << 3 << "\n";
        }
        else{
            cout << " " << 4;
        }
    }
    };

    for(int i=0; i<w; i++){
        if(i==0){
            cout << 2;
        }
        else if(i == w-1){
            cout << " " << 2 << "\n";
        }
        else{
            cout << " " << 3;
        }
    }

    return 0;

}