#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double dp[301][301][301];
bool visitado[301][301][301];
int n; 

double solve(int s1, int s2, int s3){
    int m = s1 + s2 + s3;
    if(m == 0){return 0;}
    if(visitado[s1][s2][s3]){return dp[s1][s2][s3];};
    visitado[s1][s2][s3] = true;

    double S = 0;
    if(s1 > 0){S += s1 * solve(s1-1, s2, s3);}
    if(s2 > 0){S += s2 * solve(s1+1, s2-1, s3);}
    if(s3 > 0){S += s3 * solve(s1, s2+1, s3-1);};
    double resposta = (S + n)/m;
    dp[s1][s2][s3] = resposta;
    return resposta;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int p1, p2, p3;p1 = p2 = p3 = 0;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(a==1){p1++;}
        else if(a==2){p2++;}
        else{p3++;}
    };

    cout << fixed << setprecision(10) << solve(p1, p2, p3);


    return 0;

}