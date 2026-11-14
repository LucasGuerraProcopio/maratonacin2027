#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool passa[1000005];
int maior = 1;

void computa(int n){
    for(int i = 1; i*i<=n; i++){
        if(n % i == 0){
            if(passa[i]){maior = max(i, maior);} if(passa[n/i]){maior = max(n/i, maior);}
            passa[i] = true;
            passa[n/i] = true;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(passa , false, sizeof passa);
    int n; cin >> n;
    vector<ll> todos;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(passa[a]){maior = max(maior, a); continue;}
        computa(a);
    };


    cout << maior;

    return 0;

}