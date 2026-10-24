#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    while(cin >> a >> b){
        int le1, nu1, le2, nu2, dif1, dif2, resposta;
        if(a[0] == 'a'){le1 = 1;}
        if(a[0] == 'b'){le1 = 2;}
        if(a[0] == 'c'){le1 = 3;}
        if(a[0] == 'd'){le1 = 4;}
        if(a[0] == 'e'){le1 = 5;}
        if(a[0] == 'f'){le1 = 6;}
        if(a[0] == 'g'){le1 = 7;}
        if(a[0] == 'h'){le1 = 8;}
        if(b[0] == 'a'){le2 = 1;}
        if(b[0] == 'b'){le2 = 2;}
        if(b[0] == 'c'){le2 = 3;}
        if(b[0] == 'd'){le2 = 4;}
        if(b[0] == 'e'){le2 = 5;}
        if(b[0] == 'f'){le2 = 6;}
        if(b[0] == 'g'){le2 = 7;}
        if(b[0] == 'h'){le2 = 8;}
        if(a[1] == '1'){nu1 = 1;}
        if(a[1] == '2'){nu1 = 2;}
        if(a[1] == '3'){nu1 = 3;}
        if(a[1] == '4'){nu1 = 4;}
        if(a[1] == '5'){nu1 = 5;}
        if(a[1] == '6'){nu1 = 6;}
        if(a[1] == '7'){nu1 = 7;}
        if(a[1] == '8'){nu1 = 8;}
        if(b[1] == '1'){nu2 = 1;}
        if(b[1] == '2'){nu2 = 2;}
        if(b[1] == '3'){nu2 = 3;}
        if(b[1] == '4'){nu2 = 4;}
        if(b[1] == '5'){nu2 = 5;}
        if(b[1] == '6'){nu2 = 6;}
        if(b[1] == '7'){nu2 = 7;}
        if(b[1] == '8'){nu2 = 8;}
        dif1 = abs(nu1 - nu2);
        dif2 = abs(le1 - le2);
        resposta = dif1 + dif2;
        cout << "To get from " << a << " to" << b << " takes " << resposta << " night moves\n";

    }

    return 0;

}