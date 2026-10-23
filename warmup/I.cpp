#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m; cin >> n >> m; 
    vector<long long> ultima_aparicao(n + 1, -1);
    vector<long long> gaps(n + 1, 0);

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        gaps[a] = max(gaps[a], i - ultima_aparicao[a]);
        ultima_aparicao[a] = i;
    }

    for(int i=0; i<=n; i++){
        gaps[i] = max(gaps[i], n - ultima_aparicao[i]);
        if(gaps[i] > m){
            cout << i;
            return 0;
        }
    }


    return 0;

}