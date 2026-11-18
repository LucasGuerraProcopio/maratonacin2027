#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;

struct query{
    int l, r, idx;
};

vector<int> nuns;
int ans[200005];


void dnc(int l, int r, vector<query>& queries){
    if(l > r || queries.empty()){return;};
    int m = (l+r)/2;
    vector<query> esquerda, direita, meio;
    for(query atual : queries){
        if(atual.l <= m && m <= atual.r){meio.push_back(atual);}
        else if(atual.r < m){esquerda.push_back(atual);}
        else{direita.push_back(atual);}
    }
    dnc(l, m-1, esquerda);
    dnc(m+1, r, direita);

    vector<int> suf = {nuns[m]}, pref = {nuns[m]};
    for(int i = m-1; i>= l; i--){suf.push_back(min(nuns[i], suf.back()));}
    for(int i = m+1; i<= r; i++){pref.push_back(min(nuns[i], pref.back()));}
    for(query qr : meio){
        ans[qr.idx] = min(suf[m - qr.l], pref[qr.r - m]);
    }



}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        nuns.push_back(a);
    };



    vector<query> todas;
    for(int i=0; i<q; i++){
        query nova;
        cin >> nova.l >> nova.r;
        nova.idx = i;
        nova.l--; nova.r--;
        todas.push_back(nova);
    };

    dnc(0, n-1, todas);

    for(int i=0; i<q; i++){
        cout << ans[i] << "\n";
    }

    return 0;

}