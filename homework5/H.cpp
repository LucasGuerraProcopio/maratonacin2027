#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b; cin >> a >> b;
    vector<vector<int>> dp(5005, vector<int>(5005));

    for(int i=1; i<=a.size(); i++){dp[i][0] = i;};
    for(int j=1; j<=b.size(); j++){dp[0][j] = j;};

    for(int i=1; i<=a.size(); i++){
        for(int j =1; j<=b.size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j]= 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }

    cout << dp[a.size()][b.size()];

    return 0;

}