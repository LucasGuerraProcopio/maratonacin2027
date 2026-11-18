#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[300005][3];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n, k; cin >> n >> k;
    string num; cin >> num;
    ll passos = 2*k;
    ll total = passos + n;
    dp[total][0] = true;
    dp[total][1] = false;
    dp[total][2] = false;

    for(int i = total-1; i>=n; i--){
        int mais;
        if(i % 2 == 0){mais = 1;}else{mais = 2;}
        for(int restos = 0; restos < 3; restos++){
            bool op1 = dp[i+1][restos];
            bool op2 = dp[i+1][(restos + mais) % 3];
            bool op3 = dp[i+1][(restos*2) % 3];
            bool op4 = dp[i+1][(restos*2 + 1) % 3];
            if((i - n) % 2 == 0){
                dp[i][restos] = op1 && op2 && op3 && op4;
            }
            else{
                dp[i][restos] = op1 || op2 || op3 || op4;
            }
        };
    };

    ll comeco = 0;
    for(int i=0; i<n; i++){
        if(num[i] == '1'){
        if(n % 2 == 1){
            if(i%2 == 0){
                comeco++;
            }
            else{
                comeco+=2;
            }
        }
        else{
            if(i % 2 == 0){
                comeco+=2;
            }
            else{
                comeco++;
            }
        }
        }
    };

    comeco = comeco % 3;

    if(dp[n][comeco]){
        cout << "JULIA";
    }
    else{
        cout << "GIOVANA";
    }

    return 0;

}