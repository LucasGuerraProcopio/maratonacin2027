#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll resposta = 0;
int n;

vector<ll> merge(vector<ll> &a, vector<ll> &b){
    vector<ll> c;
    int l=0; int r=0;
    while(l < a.size() && r < b.size()){
        if(a[l] < b[r]){
            c.push_back(a[l]);
            l++;
        }
        else{
            c.push_back(b[r]);
            r++;
        }
    };
    while(l < a.size()){c.push_back(a[l]); l++;}
    while(r < b.size()){c.push_back(b[r]); r++;}
    return c;

}

void merge_sort(int l, int r){
    if(l >= r){return;}
    int m = (l+r)/2;
    merge_sort(l, m);
    merge_sort(m+1, r);
    
    vector<ll> esquerda, direita;
    for(int i=l; i<=m; i++){
        esquerda.push_back(a[i]);
    };
    for(int i=m+1; i<=r; i++){
        direita.push_back(a[i]);
    };

    int R = 0;
    for(int x : esquerda){
        while(R < direita.size() && direita[R] < x){R++;}
        resposta += R;
    };

    vector<ll> c = merge(esquerda, direita);
    for(int i=l; i<=r; i++){
        a[i] = c[i-l];
    }




}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while(true){
        cin >> n;
        if(n == 0){break;}
        for(int i=0; i<n; i++){
            cin >> a[i];
        };
        resposta = 0;
        merge_sort(0, n-1);
        cout << resposta << "\n";
    }

    return 0;

}