#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> tristes;
    vector<queue<int>> filas(q+1);
    queue<pair<int,int>> ordem;
    vector<int> retirados(q+1, 0);
    int a,b,c;

    for(int i=0; i<n*2; i++){
        cin >> a >> b;
        if(a==1){
            cin >> c;
            ordem.push({b,c});
            filas[c].push(b);
        }
        else{
            if(retirados[b] == 0){
                int saiu = filas[b].front();
                while(saiu != ordem.front().first){
                    tristes.push_back(ordem.front().first);
                    filas[ordem.front().second].pop();
                    retirados[ordem.front().second]++;
                    ordem.pop();
                };
                filas[b].pop();
                ordem.pop();
            }
            else{retirados[b]--;}
        }
    }


    cout << tristes.size() << "\n";
    for(int i=0; i<tristes.size(); i++){
        if(i==0){cout << tristes[i];}else{cout << " " << tristes[i];}
    }
    return 0;

}