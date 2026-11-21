#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
string analise;
vector<ll> a;
ll seg[10000005][3];

vector<int> join(const vector<int> &A, const vector<int> &B){
    vector<int> retornado = {0, 0, 0};
    retornado[0] = A[0] + B[0] + min(A[1], B[2]);
    retornado[1] = A[1] + B[1] - min(A[1], B[2]);
    retornado[2] = A[2] + B[2] - min(A[1], B[2]);
    return retornado;
}

void build(int l = 0, int r = n-1, int idx = 0){

    if(l >= r){seg[idx][0] = 0;if(analise[l] == ')'){seg[idx][2] = 1; seg[idx][1] = 0;}else{seg[idx][2] = 0; seg[idx][1] = 1;}return;}

    int mid = (l+r)/2;
    build(l, mid, 2*idx + 1);
    build(mid+1, r, 2*idx +2);
    seg[idx][0] = seg[2*idx + 1][0] + seg[2*idx + 2][0] + min(seg[2*idx + 1][1], seg[2*idx + 2][2]);
    seg[idx][1] = seg[2*idx + 1][1] + seg[2*idx + 2][1] - min(seg[2*idx + 1][1], seg[2*idx + 2][2]);
    seg[idx][2] = seg[2*idx + 1][2] + seg[2*idx + 2][2] - min(seg[2*idx + 1][1], seg[2*idx + 2][2]);
}

vector<int> querie(int L, int R, int l = 0, int r = n-1, int idx = 0){
    if(R < l || L > r){return {0, 0, 0};}
    if(L <= l && r <= R){return {seg[idx][0], seg[idx][1], seg[idx][2]};}
    int mid = (l+r)/2;

    return join(querie(L, R, l, mid, 2*idx + 1), querie(L, R, mid+1, r, 2*idx + 2));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> analise;
    n = analise.size();
    cin >> m;
    build();

    while(m--){
        int x, y; cin >> x >> y;
        x--; y--;
        vector<int> resposta = querie(x, y);
        cout << resposta[0] * 2 << "\n";
    }

    return 0;

}