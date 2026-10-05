#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);



    long long n, qrelevantes, maior, inico, fim;
    cin >> n;
    vector<pair<long long, long long>> horarios;
    vector<long long> relevantes;
    for(int i=0; i<n; i++){
        pair<long long, long long> dupla;
        cin >> dupla.first >> dupla.second;
        horarios.push_back(dupla);
        relevantes.push_back(dupla.first);
        relevantes.push_back(dupla.second);
    };

    sort(relevantes.begin(), relevantes.end());
    relevantes.erase(unique(relevantes.begin(), relevantes.end()), relevantes.end());
    qrelevantes = relevantes.size();
    vector<long long> contador(qrelevantes, 0);
    vector<long long> somas(qrelevantes, 0);
    for(int j=0; j<n; j++){
        inico = lower_bound(relevantes.begin(), relevantes.end(), horarios[j].first) - relevantes.begin();
        fim = lower_bound(relevantes.begin(), relevantes.end(), horarios[j].second) - relevantes.begin();
        contador[inico]++;
        contador[fim]--;
    }

    for(int c=0; c<qrelevantes; c++){
        if(c==0){
            somas[c] = contador[c];
        }
        else{
            somas[c] = somas[c-1] + contador[c];
        }
    };

    maior = 0;

    for(int h=0; h<qrelevantes; h++){
        if(somas[h] > maior){
            maior = somas[h];
        }
    }

    cout << maior;

    return 0;
}