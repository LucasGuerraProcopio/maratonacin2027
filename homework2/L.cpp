#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t, atual;
    bool tem;
    bool nao_foi = true;
    cin >> n >> t;
    vector<long long> lista;
    map<long long, long long> passado;

    for(int i=0; i<n; i++){
        cin >> atual;
        tem = passado.count(t - atual);
        if(tem){
            cout << passado[t-atual] << " " << i+1;
            nao_foi = false;
            break;
        }
        else{
            passado[atual] = i+1;
        };
    }

    if(nao_foi){
        cout << "IMPOSSIBLE";
    };

    return 0;

}