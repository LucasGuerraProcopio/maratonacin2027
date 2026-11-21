#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> sequencia;

int custo(int k){
    if(k <= 1){return 0;}
    int esquerda = (k-1)/2;
    int direita = (k-1)-esquerda;
    return (k-1) + custo(esquerda) + custo(direita);
}

void ordem(int L, int R){
    if(L > R){return;}
    int mid = L + ((R-L)/2);
    ordem(L, mid-1);
    ordem(mid+1, R);
    sequencia.push_back(mid);


}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c; cin >> n >> c;
    int vazio = n - c;
    int grupos = min(vazio + 1, c);
    int tamanho = c/grupos;
    int extras = c%grupos;

    int custon = (grupos - extras) * custo(tamanho);
    int custoe = extras * custo(tamanho+1);
    cout << custon + custoe << "\n";

    int posicao = 1;
    for(int i=0; i<grupos; i++){
        if(i < extras){ordem(posicao, posicao + tamanho); posicao += tamanho + 2;}
        else{ordem(posicao,posicao + tamanho-1); posicao += tamanho + 1;}
    };

    for(int i=0; i<sequencia.size(); i++){
        if(i==0){cout << sequencia[i];}
        else{cout << " " << sequencia[i];}
    }

    return 0;

}