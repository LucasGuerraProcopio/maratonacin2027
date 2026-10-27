#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        string a, b; cin >> a >> b;

        vector<vector<int>> aparicoesA(n+1, vector<int>(26,0));
        vector<vector<int>> aparicoesB(n+1, vector<int>(26,0));

        for(int i=0; i< n; i++){
            for(int c=0; c< 26; c++){
                aparicoesA[i+1][c] = aparicoesA[i][c];
                aparicoesB[i+1][c] = aparicoesB[i][c];
            };
            aparicoesA[i+1][a[i] - 'a']++;
            aparicoesB[i+1][b[i] - 'a']++;
        };


        while(q--){
            int l, r; cin >> l >> r;
            ll resposta = 0;
            for(int i=0; i<26; i++){
                int apA = aparicoesA[r][i] - aparicoesA[l-1][i];
                int apB = aparicoesB[r][i] - aparicoesB[l-1][i];
                if(apA > apB){
                    resposta += (apA - apB);
                }
            }
            cout << resposta << "\n";
        }
    }


    return 0;

}