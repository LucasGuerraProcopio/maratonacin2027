#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(string provas){
    int a, b, c, d, e;
    a = b = c = d = e = 0;
    for(int i=0; i<provas.size(); i++){
        if(provas[i] == 'A'){a++;}else if(provas[i] == 'B'){b++;}else if(provas[i] == 'C'){c++;}else if(provas[i] == 'D'){d++;}else if(provas[i] == 'E'){e++;}
    };
    if(a > 0 && b > 0 && c > 0 && d > 0 && e > 0){return true;}
    if(provas.size() <= 6){return false;}
    if(a > 2){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b+1; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && b > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c+1; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && c > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && d > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d-1; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(b > 2){
        string nova = "";
        for(int i=0; i<a; i++){nova += 'A';}for(int i=0; i<b-2; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(b > 1 && c > 1){
        string nova = "";
        for(int i=0; i<a; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 3 && b >= 1){
        string nova = "";
        for(int i=0; i<a-3; i++){nova += 'A';}for(int i=0; i<b; i++){nova += 'B';}for(int i=0; i<c+1; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 3 && c > 1){
        string nova = "";
        for(int i=0; i<a-3; i++){nova += 'A';}for(int i=0; i<b+1; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 2 && b >= 2){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 2 && b > 1 && c >= 1){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && b > 3){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b-3; i++){nova += 'B';}for(int i=0; i<c+1; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 3 && d > 1){
        string nova = "";
        for(int i=0; i<a-3; i++){nova += 'A';}for(int i=0; i<b+1; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d-1; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 2 && b>= 1 && c > 1){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 2 && b>1 && d>1){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c+1; i++){nova += 'C';}for(int i=0; i<d-1; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && b > 2 && c > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b-2; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 2 && c > 1 && d >= 1){
        string nova = "";
        for(int i=0; i<a-2; i++){nova += 'A';}for(int i=0; i<b; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(b > 2 && d>= 1 && a > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b-2; i++){nova += 'B';}for(int i=0; i<c; i++){nova += 'C';}for(int i=0; i<d; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(a > 1 && c > 2 && b > 1){
        string nova = "";
        for(int i=0; i<a-1; i++){nova += 'A';}for(int i=0; i<b-1; i++){nova += 'B';}for(int i=0; i<c-2; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    }
    if(b > 3 && c > 1){
        string nova = "";
        for(int i=0; i<a; i++){nova += 'A';}for(int i=0; i<b-3; i++){nova += 'B';}for(int i=0; i<c-1; i++){nova += 'C';}for(int i=0; i<d+1; i++){nova += 'D';}for(int i=0; i<e+1; i++){nova += 'E';}
        if(solve(nova)){return true;}
    };
    
    return false;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        string provas; cin >> provas;
        if(solve(provas)){cout << "YES\n";}
        else{cout << "NO\n";}

    }

    return 0;

}