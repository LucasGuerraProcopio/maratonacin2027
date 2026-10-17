#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string palavra; cin >> palavra;
    vector<long long> letras(26);
    int impares = 0;
    for(int i=0; i<palavra.length(); i++){
        if(palavra[i] == 'a'){letras[0] += 1;}else if(palavra[i] == 'b'){letras[1] += 1;}else if(palavra[i] == 'c'){letras[2] += 1;}else if(palavra[i] == 'd'){letras[3] += 1;}else if(palavra[i] == 'e'){letras[4] += 1;}else if(palavra[i] == 'f'){letras[5] += 1;}else if(palavra[i] == 'g'){letras[6] += 1;}else if(palavra[i] == 'h'){letras[7] += 1;}else if(palavra[i] == 'i'){letras[8] += 1;}else if(palavra[i] == 'j'){letras[9] += 1;}else if(palavra[i] == 'k'){letras[10] += 1;}else if(palavra[i] == 'l'){letras[11] += 1;}else if(palavra[i] == 'm'){letras[12] += 1;}else if(palavra[i] == 'n'){letras[13] += 1;}else if(palavra[i] == 'o'){letras[14] += 1;}else if(palavra[i] == 'p'){letras[15] += 1;}else if(palavra[i] == 'q'){letras[16] += 1;}else if(palavra[i] == 'r'){letras[17] += 1;}else if(palavra[i] == 's'){letras[18] += 1;}else if(palavra[i] == 't'){letras[19] += 1;}else if(palavra[i] == 'u'){letras[20] += 1;}else if(palavra[i] == 'v'){letras[21] += 1;}else if(palavra[i] == 'w'){letras[22] += 1;}else if(palavra[i] == 'x'){letras[23] += 1;}else if(palavra[i] == 'y'){letras[24] += 1;}else if(palavra[i] == 'z'){letras[25] += 1;}
    }
    for(int i=0; i<26; i++){
        if(letras[i] % 2 == 1){
            impares += 1;
        }
    }

    if(impares > 1){
        cout << "no";
    }
    else{
        cout << "yes";
    }

    return 0;
    return 0;

}