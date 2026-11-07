#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
bool numeros[20];
int n, a;
int qrcodes[18][21][21];
int inicio[18];
int custos[20][20];
char transicoes[20][20];
int dp[20][1<<20];

int solve(int i, int mask){
    if(mask == (1<<n) - 1)return 0;
    int &ans = dp[i][mask];
    if(ans != -1){return ans;}
    ans = INF;
    for(int j=0; j<n; j++){
        if(mask & (1<<j)){continue;}
        ans = min(ans, custos[i][j] + solve(j, mask | (1<<j)));
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a;
    memset(inicio, 0, sizeof inicio);
    memset(dp, -1, sizeof dp);
    memset(transicoes, '.', sizeof transicoes);
    for(int i=0; i<n; i++){
        for(int j=0; j<21; j++){
            string linha; cin >> linha;
            for(int w=0; w<21; w++){
                if(linha[w] == '0'){qrcodes[i][j][w] = 0;}else{qrcodes[i][j][w] = 1;};
                if(qrcodes[i][j][w] == 1){inicio[i]++;}
            }
        }
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){continue;}
            int unzes = 0;
            int custo = 0;
            for(int w=0; w<21; w++){
                for(int y=0; y<21; y++){
                    if(qrcodes[i][w][y] ^ qrcodes[j][w][y]){custo++;}
                    if(qrcodes[j][w][y] == 1){unzes++;}
                }
            }
            if(unzes + a < custo){transicoes[i][j] = '*';}
            custos[i][j] = min(custo, unzes + a);
        }
    };

    int melhor = INF;
    int comeco = 0;
    for(int i=0; i<n; i++){
        int copia = melhor;
        melhor = min(melhor, solve(i, 1<<i) + inicio[i]);
        if(copia != melhor){comeco = i;}
    };

    vector<int> caminho;
    caminho.push_back(comeco);
    int copia = comeco;

    int mascara = 1<<comeco;
    while(mascara != (1<<n) - 1){
        for(int j=0; j<n; j++){
            if(mascara & (1<<j)){continue;}
            if(solve(copia, mascara) == custos[copia][j] + solve(j, mascara | (1<<j))){
                if(transicoes[copia][j] == '*'){caminho.push_back(100);}
                caminho.push_back(j);
                copia = j;
                mascara |= (1<<j);
                break;
            }
        }
    };

    cout << melhor << "\n";
    for(int i=0; i<caminho.size(); i++){
        if(caminho[i] == 100){cout << '*' << "\n";}else{cout << caminho[i] + 1 << "\n";}
    }
    


    return 0;

}