#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int n, q;
vector<ll> a;
ll seg[1000005];

ll join(ll x, ll y){return min(x, y);}

void build(int l = 0, int r = n-1, int idx = 0){
    if(l == r){seg[idx] = a[l]; return;}
    int mid = (l + r)/2;
    build(l, mid, 2 * idx + 1);
    build(mid + 1, r, 2 * idx + 2);
    seg[idx] = join(seg[2 * idx + 1], seg[2 * idx + 2]);
};

ll query(int L, int R, int l = 0, int r = n - 1, int idx = 0){
    if(R < l || L > r){return INF;}
    if(L <= l && r <= R){return seg[idx];}
    int mid = (l + r) / 2;
    return join(query(L, R, l, mid, 2 * idx + 1), query(L, R, mid + 1, r, 2 * idx + 2));
};

void update(int i, ll val, int l = 0, int r = n-1, int idx = 0){
    if(l == r){seg[idx] = val; return;}
    int mid = (l + r) / 2;
    if(i <= mid){update(i, val, l, mid, 2 * idx + 1);}
    else{update(i, val, mid+1, r, 2 * idx + 2);}
    seg[idx] = join(seg[2*idx + 1], seg[2 * idx + 2]);
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=0; i<n; i++){
        ll b; cin >> b;
        a.push_back(b);
    };

    fill(seg, seg + 1000005, INF);
    build();

    for(int i = 0; i<q; i++){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int k; ll u;
            cin >> k >> u;
            update(k-1, u);
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << query(x-1, y-1) << "\n";
        }
    }

    return 0;

}