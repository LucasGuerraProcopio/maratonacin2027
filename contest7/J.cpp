#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int index = -1;
    int AUGUSTO = n-1;
    int BRAIN = 0;
    ll atual = 0;
    bool vez_agusto = true;
    bool passou_augusto = false;
    bool passou_brian = false;
    vector<pair<ll,int>> augusto;
    vector<pair<ll,int>> brian;

    for(int i=0; i<n; i++){
        ll a; cin >> a;
        augusto.push_back({a,i});
    };

    for(int i=0; i<n; i++){
        ll a; cin >> a;
        brian.push_back({a,i});
    };

    sort(augusto.begin(), augusto.end());
    sort(brian.begin(), brian.end());
    
    while(true){
        if(vez_agusto){
            while(true){
                if(AUGUSTO < 0){passou_augusto = true; vez_agusto = false; break;}
                if(augusto[AUGUSTO].first > atual && augusto[AUGUSTO].second > index){
                    atual = augusto[AUGUSTO].first; index = augusto[AUGUSTO].second;
                    AUGUSTO--;
                    vez_agusto = false;
                    break;
                }
                else{AUGUSTO--;}
            }
        }
        else{
            while(true){
                if(BRAIN >= n){passou_brian = true; break;}
                if(brian[BRAIN].first < atual && brian[BRAIN].second > index){
                    atual = brian[BRAIN].first; index = brian[BRAIN].second;
                    BRAIN++;
                    vez_agusto = true;
                    break;
                }
                else{BRAIN++;}
            }
        }
        if(passou_augusto && passou_brian){break;}
    };

    cout << atual;

    return 0;

}