#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, tempo_total, questoes, tempo_questoes;
    set<int> tempos;
    cin >> n >> k;
    tempo_total = 0;
    questoes = 0;
    tempo_questoes = 240 - k;
    for(int i=1; i<=n; i++){
        if(tempo_total + i*5 <= tempo_questoes){
            questoes += 1;
            tempo_total += i*5;
        }
        else{
            break;
        };
    };
    cout << questoes;
    return 0;
}