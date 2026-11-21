#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll seg[40000005];


void build(int l = 0, int r = n-1, int idx = 0){
    if(l == r){seg[idx] = 1; return;}
    int mid = (l + r)/2;
    build(l, mid, 2 * idx + 1);
    build(mid + 1, r, 2 * idx + 2);
    seg[idx] = seg[ 2 * idx + 1] + seg[2 * idx + 2];
};

int posicao(int p,int l=0, int r=n-1, int idx=0){
    if(l>=r){seg[idx] = 0; return l;}
    int esquerda = seg[2*idx+1];
    int mid = (l+r)/2;
    int resposta;
    if(esquerda>=p){
        resposta = posicao(p, l, mid, 2*idx +1);
    }
    else{
        resposta = posicao(p-esquerda, mid+1, r, 2*idx +2);
    }
    seg[idx] = seg[2*idx + 1] + seg[2*idx + 2]; 
    return resposta;

}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> primeiro(n/2); vector<int> segundo(n/2);
    for(int i=0; i<n/2; i++){
        cin >> primeiro[i];
    }
    for(int i=0; i<n/2; i++){
        cin >> segundo[i];
    }
    build();

    vector<int> resposta1;
    vector<int> resposta2;
    for(int i=0; i<primeiro.size(); i++){
        resposta1.push_back(posicao(primeiro[i]) + 1);
        resposta2.push_back(posicao(segundo[i]) + 1);
    };

    for(int i=0; i<resposta1.size(); i++){
        if(i==0){cout << resposta1[i];}
        else{cout << " " << resposta1[i];}
    }
    cout << "\n";

    for(int i=0; i<resposta2.size(); i++){
        if(i==0){cout << resposta2[i];}
        else{cout << " " << resposta2[i];}
    }

    return 0;

}