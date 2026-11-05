#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
vector<int> dependentes[MAXN];
int dependencias[MAXN];


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> nomes;
    for(int i=0; i<n; i++){
        string nome; cin >> nome;
        vector<char> correto(nome.begin(), nome.end());
        vector<int> numerados;
        for(int i=0; i<correto.size(); i++){
            if(correto[i] == 'a'){numerados.push_back(1);}else if(correto[i] == 'b'){numerados.push_back(2);}else if(correto[i] == 'c'){numerados.push_back(3);}else if(correto[i] == 'd'){numerados.push_back(4);}else if(correto[i] == 'e'){numerados.push_back(5);}else if(correto[i] == 'f'){numerados.push_back(6);}else if(correto[i] == 'g'){numerados.push_back(7);}else if(correto[i] == 'h'){numerados.push_back(8);}else if(correto[i] == 'i'){numerados.push_back(9);}else if(correto[i] == 'j'){numerados.push_back(10);}else if(correto[i] == 'k'){numerados.push_back(11);}else if(correto[i] == 'l'){numerados.push_back(12);}else if(correto[i] == 'm'){numerados.push_back(13);}else if(correto[i] == 'n'){numerados.push_back(14);}else if(correto[i] == 'o'){numerados.push_back(15);}else if(correto[i] == 'p'){numerados.push_back(16);}else if(correto[i] == 'q'){numerados.push_back(17);}else if(correto[i] == 'r'){numerados.push_back(18);}else if(correto[i] == 's'){numerados.push_back(19);}else if(correto[i] == 't'){numerados.push_back(20);}else if(correto[i] == 'u'){numerados.push_back(21);}else if(correto[i] == 'v'){numerados.push_back(22);}else if(correto[i] == 'w'){numerados.push_back(23);}else if(correto[i] == 'x'){numerados.push_back(24);}else if(correto[i] == 'y'){numerados.push_back(25);}else if(correto[i] == 'z'){numerados.push_back(26);};
        }
        nomes.push_back(numerados);
    };

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(nomes[i][0] != nomes[j][0]){
                dependentes[nomes[j][0]].push_back(nomes[i][0]);
            }
            else{
                int a = 0; int b = 0;
                int tamanhoA = nomes[j].size(); int tamanhoB = nomes[i].size();
                while(nomes[j][a] == nomes[i][b]){
                    a++; b++;
                    if(a == tamanhoA){break;};
                    if(b == tamanhoB){cout << "Impossible";return 0;};
                    if(nomes[j][a] != nomes[i][b]){dependentes[nomes[j][a]].push_back(nomes[i][b]);};
                }
            }
        }
    }

    for(int i=1; i<=26; i++){
        sort(dependentes[i].begin(), dependentes[i].end());
        dependentes[i].erase(unique(dependentes[i].begin(), dependentes[i].end()), dependentes[i].end());
        for(int v : dependentes[i]){dependencias[v]++;};
    };

    queue<int> fila;
    for(int u=1; u<=26; u++){
        if(dependencias[u] == 0){fila.push(u);};
    };

    vector<int> ordem;

    while(!fila.empty()){
        int x = fila.front(); fila.pop();
        ordem.push_back(x);
        for(int v : dependentes[x]){
            dependencias[v]--;
            if(dependencias[v] == 0){fila.push(v);};
        };
    }


    if(ordem.size() != 26){
        cout << "Impossible";
    }
    else{
        for(int i=0; i<ordem.size(); i++){
                if(ordem[i]==1){cout << 'a';}else if(ordem[i]==2){cout << 'b';}else if(ordem[i]==3){cout << 'c';}else if(ordem[i]==4){cout << 'd';}else if(ordem[i]==5){cout << 'e';}else if(ordem[i]==6){cout << 'f';}else if(ordem[i]==7){cout << 'g';}else if(ordem[i]==8){cout << 'h';}else if(ordem[i]==9){cout << 'i';}else if(ordem[i]==10){cout << 'j';}else if(ordem[i]==11){cout << 'k';}else if(ordem[i]==12){cout << 'l';}else if(ordem[i]==13){cout << 'm';}else if(ordem[i]==14){cout << 'n';}else if(ordem[i]==15){cout << 'o';}else if(ordem[i]==16){cout << 'p';}else if(ordem[i]==17){cout << 'q';}else if(ordem[i]==18){cout << 'r';}else if(ordem[i]==19){cout << 's';}else if(ordem[i]==20){cout << 't';}else if(ordem[i]==21){cout << 'u';}else if(ordem[i]==22){cout << 'v';}else if(ordem[i]==23){cout << 'w';}else if(ordem[i]==24){cout << 'x';}else if(ordem[i]==25){cout << 'y';}else if(ordem[i]==26){cout << 'z';};
        }
    };

    return 0;

}