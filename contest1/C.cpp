#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> teamA;
    vector<int> teamB;
    int a, b, c, d, contadorA, contadorB;
    string ordem = "";
    contadorA = 0;
    contadorB = 0;
    cin >> a >> b >> c;

    for(int i=0; i < a; i++){
        cin >> d;
        teamA.push_back(d);
    };

    for(int j=0; j < b; j++){
        cin >> d;
        teamB.push_back(d);
    };

    for(int p=0; p < c; p++){
        if(teamA.size() == contadorA && teamB.size() != contadorB){
            ordem += 'B';
            continue;
        }
        else if(teamA.size() != contadorA && teamB.size() == contadorB){
            ordem += 'A';
            continue;
        };
        if(teamA[contadorA] < teamB[contadorB]){
            ordem += 'A';
            contadorA += 1;
        }
        else{
            ordem += 'B';
            contadorB += 1;
        };  
    };
    cout << ordem << endl;
    return 0;
};





