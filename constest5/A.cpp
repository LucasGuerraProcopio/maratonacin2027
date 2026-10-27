#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;
int x[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int y[8] = {-2, -2, -1, 1, 2, 2, 1, -1};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> adj(65);
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            int casa = (8 * (i-1)) + j;
            for(int w=0; w<8; w++){
                if(1 <= (i + y[w]) && (i + y[w]) <= 8  && 1 <= (j + x[w]) && (j + x[w]) <= 8){
                    int nova_casa = (8 * (i + y[w] - 1)) + j + x[w];
                    adj[casa].push_back(nova_casa);
                }
            }
        }
    };

    string a,b;

    while(cin >> a >> b){
        vector<ll> dist(65, INF);
        ll casa1, casa2;
        casa2 = 0;casa1 = 0;
        if(a[0] == 'a'){casa1 += 1;}else if(a[0] == 'b'){casa1 += 2;}else if(a[0] == 'c'){casa1 += 3;}else if(a[0] == 'd'){casa1 += 4;}else if(a[0] == 'e'){casa1 += 5;}else if(a[0] == 'f'){casa1 += 6;}else if(a[0] == 'g'){casa1 += 7;}else if(a[0] == 'h'){casa1 += 8;}
        if(b[0] == 'a'){casa2 += 1;}else if(b[0] == 'b'){casa2 += 2;}else if(b[0] == 'c'){casa2 += 3;}else if(b[0] == 'd'){casa2 += 4;}else if(b[0] == 'e'){casa2 += 5;}else if(b[0] == 'f'){casa2 += 6;}else if(b[0] == 'g'){casa2 += 7;}else if(b[0] == 'h'){casa2 += 8;}
        if(a[1] == '1'){casa1 += 0;}else if(a[1] == '2'){casa1 += 8;}else if(a[1] == '3'){casa1 += 16;}else if(a[1] == '4'){casa1 += 24;}else if(a[1] == '5'){casa1 += 32;}else if(a[1] == '6'){casa1 += 40;}else if(a[1] == '7'){casa1 += 48;}else if(a[1] == '8'){casa1 += 56;}
        if(b[1] == '1'){casa2 += 0;}else if(b[1] == '2'){casa2 += 8;}else if(b[1] == '3'){casa2 += 16;}else if(b[1] == '4'){casa2 += 24;}else if(b[1] == '5'){casa2 += 32;}else if(b[1] == '6'){casa2 += 40;}else if(b[1] == '7'){casa2 += 48;}else if(b[1] == '8'){casa2 += 56;}

        dist[casa1] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, casa1});

        while(!pq.empty()){
            pair<ll, ll> topo = pq.top(); pq.pop();
            ll custo = topo.first;
            ll atual = topo.second;
            if(dist[atual] < custo){continue;}
            for(int proximo : adj[atual]){
                if(custo + 1 < dist[proximo]){
                    dist[proximo] = custo + 1;
                    pq.push({custo + 1, proximo});
                }
            }
        };
        cout << "To get from " << a << " to " << b << " takes " << dist[casa2] << " knight moves.\n";
    }

    return 0;

}