#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    vector<int> estacaoA;
    vector<int> estacaoB;
    vector<int> estacaoC;
    vector<string> acoes;
    bool deu = true;
    int atual = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        estacaoA.push_back(a);
    };
    while ((estacaoC.size() != n)){
        if(estacaoA.size() != 0){
            if(estacaoA[estacaoA.size() - 1] == atual){
                estacaoC.push_back(estacaoA[estacaoA.size() - 1]);
                estacaoA.pop_back();
                atual += 1;
                acoes.push_back("A C");
                continue;
            }
            else{
                if(estacaoB.size() == 0){
                    estacaoB.push_back(estacaoA[estacaoA.size() - 1]);
                    estacaoA.pop_back();
                    acoes.push_back("A B");
                    continue;
                }
                else{
                    if(estacaoA[estacaoA.size() - 1] < estacaoB[estacaoB.size() - 1] && estacaoB[estacaoB.size() - 1] != atual){
                        estacaoB.push_back(estacaoA[estacaoA.size() - 1]);
                        estacaoA.pop_back();
                        acoes.push_back("A B");
                        continue;
                    }
                    else if(estacaoB[estacaoB.size() - 1] != atual){
                        deu = false;
                        cout << -1;
                        break;
                    }
                }
            }
        }
        if(estacaoB.size() != 0){
            if(estacaoB[estacaoB.size() - 1] == atual){
                estacaoC.push_back(estacaoB[estacaoB.size() - 1]);
                estacaoB.pop_back();
                atual += 1;
                acoes.push_back("B C");
                continue;
            };
        };
    };

    if(deu){
        cout << acoes.size() << "\n";
        for(int i=0; i<acoes.size(); i++){
            cout << acoes[i] << "\n";
        };
    };
    return 0;
}