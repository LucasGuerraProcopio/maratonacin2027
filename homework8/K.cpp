#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<ll> numeros;
vector<int> BIT;
vector<int> BIT2;
ll comps[1000005][2];

void update(int x){
    while(x<=n){
        BIT[x]++;
        x += (x & -x);
    }
};

void update2(int x){
    while(x<=n){
        BIT2[x]++;
        x += (x & -x);
    }
};

int query(int x){
    int total = 0;
    while(x > 0){
        total += BIT[x];
        x -= (x & -x);
    }
    return total;
};

int query2(int x){
    int total = 0;
    while(x > 0){
        total += BIT2[x];
        x -= (x & -x);
    }
    return total;
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        numeros.push_back(a);
    };

    vector<ll> copia = numeros;
    sort(copia.begin(), copia.end());

    for(int i=0; i<n; i++){
        int valor = lower_bound(copia.begin(), copia.end(), numeros[i]) - copia.begin();
        valor++;
        numeros[i] = valor;
    };
    for(int i=0; i<=n; i++){
        BIT.push_back(0);
    }

    for(int i=0; i<=n; i++){
        BIT2.push_back(0);
    }

    ll resposta = 0;
    for(int i = n-1; i>= 0; i--){
        comps[i][0] = query(numeros[i]-1);
        update(numeros[i]);
    };

    for(int i=0; i<n; i++){
        comps[i][1] = i - query2(numeros[i]-1);
        update2(numeros[i]);
    };

    for(int i=0; i<n; i++){
        resposta += comps[i][0] * comps[i][1];
    }

    cout << resposta;





    return 0;

}