#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c; cin >> n >> m;
    int total = 0;
    vector<vector<int>> listas;
    vector<int> comparador;
    for(int i=0; i<m; i++){
        cin >> c;
        vector<int> atual(c);
        for(int j=0; j<c; j++){
            cin >> atual[j];
        };
        listas.push_back(atual);
    };

    for(int mask=0; mask < (1 << m); mask++){
        comparador.clear();
        for(int bit=0; bit < m; bit++){
            if(mask & (1 << (bit))){
                for(int y=0; y<listas[bit].size(); y++){
                    comparador.push_back(listas[bit][y]);
                };
            };
        };
        sort(comparador.begin(), comparador.end());
        comparador.erase(unique(comparador.begin(), comparador.end()), comparador.end());
        if(comparador.size() == n){
            total += 1;
        };
    };

    cout << total;

    return 0;
}