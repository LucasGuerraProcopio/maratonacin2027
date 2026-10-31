#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[2028][2028];
bool visitado[2028][2028];
double n, p;
double solve(int i, int j){
    if(j > 2026){return 0;}
    if(i == j){return 0;}
    double nj;
    if(j < 2026){nj = p/100;}else{nj = 0;}
    if(visitado[i][j]){return dp[i][j];}
    visitado[i][j] = true;

    double a = ((1-nj)*i)/j;
    double S = 0;
    S += solve(i+1, j) * (1-nj) * (j-i)/j;
    S += solve(i, j+1) * nj * i/(j+1);
    S += solve(i+1, j+1) * nj * (j-i+1)/(j+1);
    dp[i][j] = (1 + S)/(1 - a);
    return dp[i][j];
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;

    cout << fixed << setprecision(12) << solve(0, n);

    return 0;

}