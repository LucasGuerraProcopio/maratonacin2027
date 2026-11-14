#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<bool> foram(n, false);
    int total = 0;
    vector<string> palavras;
    for(int i=0; i<n; i++){
        string palavra; cin >> palavra;
        palavras.push_back(palavra);
    }

    for(int i = 0; i<n; i++){
        if(foram[i]){continue;}
        total++; foram[i] = true;
        vector<string> variacoes;
        int comeco = -1;
        for(int j=0; j<palavras[i].size(); j++){
            comeco++;
            string nova = "";
            for(int w=comeco; w<palavras[i].size(); w++){
                nova += palavras[i][w];
            }
            for(int w=0; w<comeco; w++){
                nova += palavras[i][w];
            }
            variacoes.push_back(nova);
        };
        for(int j=i+1; j<n; j++){
            for(int w=0; w<variacoes.size(); w++){
                if(palavras[j] == variacoes[w]){foram[j] = true; break;}
            }
        }

    }

    cout << total;

    return 0;

}