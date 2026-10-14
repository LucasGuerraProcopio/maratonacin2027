#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m; cin >> n >> m;
    if(n>=m){
        cout << n - m;
        return 0;
    }
    long long resposta = 0;

    while(n < m){
        bool m_impar;
        m_impar = (m%2 == 1);
        if(m_impar){
            m += 1;
        }
        else{
            m /= 2;
        }
        resposta += 1;
    }
    resposta += (n-m);

    cout << resposta;



    return 0;

}