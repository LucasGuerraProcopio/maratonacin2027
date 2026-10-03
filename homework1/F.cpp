#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, tamanho, paredes, x1, x2, y;
    cin >> t;

    set<int> lasers;
    map<int, vector<pair<int, int>>> parede;
    set<int> linhas_parede;

    for(int f=0; f<t; f++){

        cin >> tamanho >> paredes;
        for(int w=1; w<=tamanho; w++){
            lasers.insert(w);
        }

        for(int v=0; v<paredes; v++){
            cin >> x1 >> x2 >> y;
            parede[y].push_back({x1, x2});
            linhas_parede.insert(y);
        }

        for(const auto& q : linhas_parede){
            for(const auto& u : parede[q]){
                auto inicio = lasers.lower_bound(u.first), fim = lasers.upper_bound(u.second);
                if(inicio != fim){
                    lasers.erase(inicio, fim);
                    lasers.insert(u.first);
                    lasers.insert(u.second);
                };
            };
        };

        cout << lasers.size() << "\n";
        lasers.clear();
        parede.clear();
        linhas_parede.clear();
    }
return 0;
}
