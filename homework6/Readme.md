Aula 6 — DP com Bitmasks

Maratona CIn · Centro de Informática (UFPE) — material de estudo baseado nos slides de helington <hwel> e João Henrique <jhmrl> (rev. 1.1).

Esta aula mostra como representar subconjuntos com um único inteiro (bitmask) e usar isso como estado de uma DP: primeiro em subconjuntos, depois em permutações (Caixeiro Viajante). No final há um problema completo resolvido.

📑 Sumário
Mapa da aula
Parte 1 — Bitmasks
1.1 Motivação: bitmask = subconjunto
1.2 Bit shifting
1.3 Operações básicas
1.4 Tricks
1.5 Subsets: iterar por todas as máscaras
1.6 Generalização: outras bases
Parte 2 — DP em subconjuntos
2.1 O problema dos sucos (Vitamins)
2.2 Generalização
Parte 3 — DP em permutações (TSP)
3.1 O Caixeiro Viajante
3.2 Força bruta
3.3 Permutação como floresta
3.4 Backtracking
3.5 Estados repetidos → memoizar
Parte 4 — Exemplo final: Gabmei, the hacker
Resumo e cola rápida
0. Mapa da aula

A aula tem três blocos, cada um apoiado no anterior:

Bitmasks: representar um subconjunto como um único inteiro e manipular seus bits.
DP em subconjuntos: o estado da DP é um conjunto (dp[mask]).
DP em permutações: o Caixeiro Viajante (TSP) com dp[last][mask].

No fim, resolvemos o problema do slide final (Gabmei, the hacker).

O que você já sabe e vamos reaproveitar:

O loop for(mask...) if(mask & (1<<bit)) que você já usou em homework2/M.cpp, O.cpp, G.cpp e conteste3/H.cpp (inclusive __builtin_popcount). Hoje você aprende por que ele funciona e como ir além.
Backtracking com faz/desfaz (Aula 2, homework2/F.cpp) e next_permutation (homework2/n.cpp).
Complexidade: ~10⁸ operações por segundo (Aula 1).

Revisão relâmpago de DP: DP é uma recursão em que subproblemas repetidos são calculados uma vez só. Receita:

estado = o mínimo que preciso saber para decidir o futuro;
transição = como passo de um estado para outro;
caso base;
ordem de cálculo ou memoização.

Complexidade = (número de estados) × (custo por transição). A novidade de hoje: o estado é um conjunto, e um conjunto pequeno cabe num inteiro.

PARTE 1 — Bitmasks
1.1 Motivação: bitmask = subconjunto

Lógica. Um conjunto de N elementos tem 2^N subconjuntos, porque cada elemento tem só duas opções: dentro ou fora. Então um subconjunto é uma sequência de N bits (1 = incluso, 0 = não incluso). Lida como número binário, essa sequência é a máscara. No slide, para {A,B,C}:

Subconjunto	Bits	Número
{}	000	0
{C}	001	1
{B}	010	2
{B,C}	011	3
{A}	100	4
{A,C}	101	5
{A,B}	110	6
{A,B,C}	111	7

Os números de 0 a 2^N − 1 listam todos os subconjuntos, sem repetir. Cabem até 64 elementos em um long long (use unsigned long long para usar os 64).

Convenção: no slide o A é o bit mais à esquerda; no código costumamos usar elemento i ↔ bit i (bit 0 é o menos significativo). Qualquer correspondência serve, desde que você seja consistente.

Que problema resolve.

Enumerar "quais itens eu escolho" quando N é pequeno (até ~20-22).
Guardar "quais itens já usei" em um número só, que serve de índice de vetor. É isso que permite a DP depois.
Operações de conjunto em O(1): união a | b, interseção a & b, diferença a & ~b, igualdade a == b.

Como codar. Percorra mask de 0 até (1 << n) - 1; o bit i da máscara diz se o elemento i está dentro.

Exemplo completo — listar todos os subconjuntos de uma string:

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;              // ex.: ABC
    int n = s.size();

    for(int mask = 0; mask < (1 << n); mask++){
        cout << mask << ' ' << '{';
        bool primeiro = true;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){     // elemento i está no subconjunto?
                if(!primeiro) cout << ',';
                cout << s[i];
                primeiro = false;
            }
        }
        cout << '}' << endl;
    }
    return 0;
}

Para a entrada ABC, a linha 5 {A,C} aparece porque 5 = 101 liga os bits 0 e 2.

1.2 Bit shifting

Lógica. Shift left por k empurra os bits para a esquerda e entra zero na direita: é multiplicar por 2^k. Shift right por k descarta os k bits da direita: é a divisão inteira por 2^k. Por isso 1 << n vale 2^n e é a máscara com só o bit n ligado. E (1 << n) - 1 é a máscara com os n primeiros bits ligados (o conjunto cheio).

Que problema resolve. Criar a máscara de um elemento (1 << i), calcular 2^n exato sem pow (que usa double), multiplicar/dividir por 2 rápido e ler o bit i de um número com (x >> i) & 1.

Como codar.

cpp
int  a = 1 << 5;         // 32
long long b = 1LL << 40; // 2^40: com n >= 31 SEMPRE use 1LL
int  c = b >> 38;        // 4  (divisão inteira por 2^38)
x <<= 1;                 // x = 2*x
x >>= 1;                 // x = x/2 (inteiro)

⚠️ Armadilha: 1 << 40 calcula em int e estoura, exatamente o bug de n*n da Aula 1. Escreva 1LL << n.

Exemplo completo — quantos subconjuntos tem um conjunto de n elementos (n ≤ 62)?

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long total = 1LL << n;     // 2^n subconjuntos
    long long cheia = total - 1;    // máscara com n bits ligados
    cout << total << ' ' << cheia << endl;
    return 0;
}
1.3 Operações básicas

Lógica. Para mexer no bit i usamos a máscara de um bit só, 1 << i, e um operador lógico:

Operação	Código	Por que funciona
checar bit i	mask & (1 << i)	o AND zera tudo, menos o bit i; resultado é 0 ou não-zero
ligar bit i	mask |= (1 << i)	OR com 1 sempre dá 1
desligar bit i	mask &= ~(1 << i)	~ inverte: tudo 1, menos o bit i; o AND zera só o bit i
inverter bit i	mask ^= (1 << i)	XOR com 1 troca 0↔1

Que problema resolve. Qualquer "estado de vários interruptores/itens usados" que muda com o tempo, e a base de toda DP em máscaras (mask | (1<<j) = "passei a ter o item j").

Cuidados.

Parênteses: mask & (1 << i) e não mask & 1 << i (a precedência confunde).
O resultado de checar não é 1, é 1 << i; use != 0 ou (mask >> i) & 1 se quiser 0/1.
Com mais de 31 bits, use 1LL.

Exemplo completo — painel de até 60 interruptores: consulta 1 i liga, 2 i desliga, 3 i inverte, 4 i imprime o estado do i. No fim, imprime quantos estão ligados.

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    long long mask = 0;
    while(q--){
        int t, i; cin >> t >> i;
        if(t == 1)      mask |= (1LL << i);
        else if(t == 2) mask &= ~(1LL << i);
        else if(t == 3) mask ^= (1LL << i);
        else            cout << ((mask >> i) & 1) << endl;
    }
    cout << __builtin_popcountll(mask) << endl;
    return 0;
}
1.4 Tricks

Lógica.

LSB (bit ligado mais baixo): mask & -mask. Em complemento de 2, -mask = ~mask + 1: os bits abaixo do menor 1 continuam zero, o menor 1 continua 1 e acima tudo se inverte. O AND deixa só o menor bit. Ex.: 12 = 1100 → 12 & -12 = 0100 = 4.
Potência de 2: !(mask & (mask - 1)). Subtrair 1 troca o menor bit 1 por 0 e liga os zeros abaixo dele; então mask & (mask-1) apaga o menor bit ligado. Se não sobrou nada, havia um bit só. ⚠️ Para mask = 0 também dá verdadeiro; teste mask > 0 && ....
Contar bits ligados: __builtin_popcount(mask) para int, __builtin_popcountll(mask) para long long. Vale O(1) na prática.
Extra útil: __builtin_ctz(mask) devolve o índice do menor bit ligado (ctzll para 64 bits). Com ele e mask &= mask - 1 você percorre só os bits ligados.

Que problema resolve. Tamanho do subconjunto (popcount), "qual o próximo elemento do conjunto" (ctz), e percorrer os elementos de um subconjunto em O(k) em vez de O(n):

cpp
for(int m = mask; m; m &= m - 1){
    int i = __builtin_ctz(m);   // i está no subconjunto
}

Exemplo completo — menor quantidade de potências de 2 que somam N: a resposta é o popcount de N (cada bit ligado é uma potência necessária). Imprimimos também quais são.

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        long long x; cin >> x;
        cout << __builtin_popcountll(x) << ':';
        for(long long m = x; m; m &= m - 1)
            cout << ' ' << (m & -m);          // LSB atual
        cout << endl;
    }
    return 0;
}

Entrada 12 → saída 2: 4 8. (Para só testar potência de 2: x > 0 && !(x & (x-1)).)

1.5 Subsets: iterar por todas as máscaras

Lógica. É o loop dos slides: para cada mask de 0 a 2^n − 1 (2^n subconjuntos), olho cada um dos n bits para saber quem está dentro. Custo O(N · 2^N).

cpp
for(int mask = 0; mask < (1 << n); mask++){
    for(int i = 0; i < n; i++){
        if(mask & (1 << i)){
            // i-ésimo elemento está no subconjunto
        }
    }
}

Que problema resolve. "Testar todas as escolhas" com N ≤ ~20: n=20 dá ~2·10⁷ operações (ok); n=25 daria ~8·10⁸ (estoura). Foi o que você fez em homework2/M.cpp (Apple Division), O.cpp e conteste3/H.cpp.

Dica que já é um gostinho de DP: dá para tirar o fator N. A soma da máscara é a soma da máscara sem o menor bit mais o valor desse bit: soma[mask] = soma[mask & (mask-1)] + a[ctz(mask)]. Cada máscara é calculada em O(1), total O(2^N).

Exemplo completo — contar subconjuntos de soma exatamente K (n ≤ 20):

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long long K; cin >> n >> K;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;

    vector<long long> soma(1 << n, 0);
    long long cont = (K == 0);               // o subconjunto vazio tem soma 0
    for(int mask = 1; mask < (1 << n); mask++){
        int i = __builtin_ctz(mask);          // menor elemento da máscara
        soma[mask] = soma[mask & (mask - 1)] + a[i];
        if(soma[mask] == K) cont++;
    }
    cout << cont << endl;
    return 0;
}

Teste: 3 5 / 2 3 5 → subconjuntos {5} e {2,3} → resposta 2.

1.6 Generalização: outras bases

Lógica. Todo número é uma soma de potências da sua base. Binário (base 2) é só o caso em que cada "dígito" tem 2 opções. Para escrever N na base b: pegue N % b (é o dígito menos significativo), divida N /= b, e repita até zerar.

Ex. do slide, 43 na base 3: 43%3=1, 14%3=2, 4%3=1, 1%3=1 → lendo de trás para frente, 1121₃. Conferindo: 1·3⁰ + 2·3¹ + 1·3² + 1·3³ = 1 + 6 + 9 + 27 = 43.

No slide a soma aparece com 3³ e 3⁴ nos dois últimos termos; é um typo, os expoentes corretos são 0, 1, 2, 3.

Que problema resolve.

Problemas que pedem conversão/propriedades em outras bases.
Máscaras ternárias: quando cada elemento tem 3 estados (ex.: não visto / visto uma vez / visto duas vezes), o estado vira um número na base 3 com 3^N estados em vez de 2^N.
cpp
// máscara base 3: dígito i = estado do elemento i
int p3[15]; p3[0] = 1;
for(int i = 1; i < 15; i++) p3[i] = p3[i-1] * 3;
int digito = (m / p3[i]) % 3;   // ler o estado do elemento i
m += p3[i];                     // subir o estado do elemento i em 1

Exemplo completo — N escrito na base b (2 ≤ b ≤ 10) e se é palíndromo:

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; int b; cin >> n >> b;
    vector<int> d;                       // d[0] = dígito menos significativo
    long long x = n;
    if(x == 0) d.push_back(0);
    while(x > 0){ d.push_back(x % b); x /= b; }

    int k = d.size();
    bool pal = true;
    for(int i = 0; i < k; i++) if(d[i] != d[k - 1 - i]) pal = false;

    for(int i = k - 1; i >= 0; i--) cout << d[i];
    cout << ' ' << pal << endl;
    return 0;
}

Entrada 43 3 → saída 1121 0.

PARTE 2 — DP em subconjuntos
2.1 O problema dos sucos (Vitamins)

Enunciado (resumo). Uma loja vende n sucos; o suco i custa c_i e contém um subconjunto das vitaminas A, B, C. Petya precisa das três vitaminas. Qual o menor custo total de sucos que cobre A, B e C? Se for impossível, imprimir −1. Limite: n ≤ 10⁶. (O slide chama de Assignment Problem, mas não confunda com o problema clássico de emparelhamento que veremos em 2.2.)

Lógica.

Estado: dp[mask] = menor custo para ter o conjunto de vitaminas mask. Só 2³ = 8 estados. Convenção do slide: bit 0 (valor 1) = A, bit 1 (valor 2) = B, bit 2 (valor 4) = C.
Resposta: dp[7] (111 = A, B e C). Se dp[7] continuar infinito, imprime −1.
Base: dp[0] = 0 (conjunto vazio custa nada); o resto começa em INF.
Transição: para cada suco com máscara m e custo c, e para cada estado atual j: comprar o suco leva de j para j | m, custando dp[j] + c. Então dp[j | m] = min(dp[j | m], dp[j] + c). O OR junta vitaminas sem duplicar as repetidas, que é exatamente a união de conjuntos.
Complexidade: O(2^BITS · N) = 8·N, trivial para 10⁶.

Exemplo 2 do slide: sucos 10 ABC, 3 BC, 2 AC, 1 C, 6 AB. Pegando 3 BC (estado 110, custo 3) e 2 AC (101): 110 | 101 = 111 por 5. Resposta 5 ✔. Exemplo 1: 4 A + 9 BC = 13 ✔.

Detalhe fino. Atualizar dp "no lugar" dentro do mesmo suco poderia, em uma mochila comum, usar o mesmo item duas vezes. Aqui é seguro porque OR é idempotente: se j | m == j, a transição só tenta dp[j] + c, que nunca melhora dp[j].

Código completo:

cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    const ll INF = 1e18;
    vector<ll> dp(8, INF);
    dp[0] = 0;                          // conjunto vazio: custo 0

    for(int i = 0; i < n; i++){
        ll cost; string s; cin >> cost >> s;
        int mask = 0;
        for(char v : s){
            if(v == 'A') mask |= 1;     // liga o bit de A
            else if(v == 'B') mask |= 2;
            else mask |= 4;
        }
        for(int j = 0; j < 8; j++){
            if(dp[j] == INF) continue;
            dp[j | mask] = min(dp[j | mask], dp[j] + cost);
        }
    }
    cout << (dp[7] == INF ? -1 : dp[7]) << endl;
    return 0;
}
2.2 Generalização

Lógica. Use DP em subconjuntos quando o que importa para decidir o futuro é quais elementos já foram usados (e não a ordem em que foram). Complexidade típica O(2^N · N), boa para N ≤ 22 (2²² · 22 ≈ 9·10⁷).

Que problemas resolve (aplicações do slide):

Qual a melhor forma de escolher determinado subconjunto?
Qual o custo mínimo de visitar/tomar exatamente esses elementos?
Qual o emparelhamento ótimo entre posições e tarefas?

Como pensar.

O que preciso lembrar? → o conjunto usado.
Quem é o "elemento atual"? Muitas vezes é deduzido do tamanho do conjunto (popcount); assim não gasto uma dimensão extra.
Transição = acrescentar um elemento (mask | (1 << t)).

Exemplo completo — Assignment Problem clássico: n pessoas, n tarefas, c[p][t] = custo de a pessoa p fazer a tarefa t. Cada pessoa faz uma tarefa e cada tarefa é feita por uma pessoa. Mínimo custo total (n ≤ 20). dp[mask] = menor custo tendo atribuído as tarefas de mask às primeiras popcount(mask) pessoas; a próxima pessoa é a de índice popcount(mask).

cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<ll>> c(n, vector<ll>(n));
    for(auto &linha : c) for(auto &x : linha) cin >> x;

    const ll INF = 1e18;
    vector<ll> dp(1 << n, INF);
    dp[0] = 0;

    for(int mask = 0; mask < (1 << n) - 1; mask++){
        if(dp[mask] == INF) continue;
        int p = __builtin_popcount(mask);        // próxima pessoa
        for(int t = 0; t < n; t++){
            if(mask & (1 << t)) continue;         // tarefa já usada
            int nova = mask | (1 << t);
            dp[nova] = min(dp[nova], dp[mask] + c[p][t]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}

Teste: 2 / 1 5 / 2 1 → opções 1+1 = 2 ou 5+2 = 7 → resposta 2. Estados: 2^N, transições: N → O(N · 2^N).

PARTE 3 — DP em permutações (TSP)
3.1 O Caixeiro Viajante

Problema. Grafo com N nós e pesos nas arestas; achar o ciclo hamiltoniano de menor custo, isto é, uma sequência que visita todos os nós exatamente uma vez (e volta ao início) minimizando a soma dos pesos. Dependendo do problema, pode ser caminho (sem a volta) ou ciclo.

Lógica: caminho = permutação. Uma rota é uma ordem dos nós, ou seja, uma permutação p, e o custo é Cost(p) = soma de W(p[i], p[i+1]). No grafo do slide (A-B 4, A-C 7, A-D 6, B-C 8, B-D 2, C-D 5): A→C→B→D custa 7+8+2 = 17 e A→B→D→C custa 4+2+5 = 11 (como caminhos).

Que problema resolve. Qualquer "melhor ordem de visitar/fazer N coisas" com N pequeno: entregas, tarefas com custo de transição, ordem de montar peças.

3.2 Força bruta: todas as permutações, O(n!)

Use next_permutation (você já fez em homework2/n.cpp). Fixamos o nó 0 na frente (todo ciclo pode começar nele), então são (n−1)! permutações. Serve para n ≤ 10 ou 11.

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;                                   // n <= 10
    vector<vector<int>> g(n, vector<int>(n));
    for(auto &l : g) for(auto &x : l) cin >> x;

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);                       // 0 1 2 ... n-1
    int best = INT_MAX;
    do{
        int custo = 0;
        for(int i = 0; i + 1 < n; i++) custo += g[p[i]][p[i+1]];
        custo += g[p[n-1]][p[0]];                      // fecha o ciclo (remova p/ caminho)
        best = min(best, custo);
    } while(next_permutation(p.begin() + 1, p.end())); // fixa o 0 na frente
    cout << best << endl;
    return 0;
}

Teste com o grafo do slide (A,B,C,D = 0..3):

4
0 4 7 6
4 0 8 2
7 8 0 5
6 2 5 0

→ ciclo mínimo 18 (A→B→D→C→A = 4+2+5+7). Como caminho a partir de A, o mínimo é 11.

3.3 Permutação como floresta

Lógica. Construímos a permutação passo a passo; cada nó da árvore é um prefixo parcial. A raiz é o primeiro elemento escolhido e os filhos são os elementos ainda não usados. No slide (N=4) as raízes são 1, 2, 3, 4 (por isso floresta), e do prefixo 13 saem 132 e 134, depois 1324 e 1342. O nível k tem n!/(n−k)! nós e as folhas são as n! permutações. É o backtracking da Aula 2, com o "usado" marcando o que já entrou.

3.4 Backtracking (com used e com bitmask)

Lógica. Na função recursiva, i (o último nó visitado) não é necessário para gerar as permutações, mas é necessário para calcular o custo: ao ir de i para j, somo C[i][j]. Faz: marca j usado e soma o custo. Desfaz: tira o custo e desmarca.

O slide mostra duas versões: com vector<int> used (e accumulate para contar quantos já foram) e com bitmask (used ^= (1<<j) para marcar, __builtin_popcount(used) para contar, em O(1) em vez de O(n)). Em bitmask passamos used por valor, então "desfazer" é automático. Versão completa e corrigida para ciclo:

cpp
#include <bits/stdc++.h>
using namespace std;

int n, C[20][20];
int best = INT_MAX, cur = 0;

void bt(int last, int used){
    if(used == (1 << n) - 1){                   // visitou todos
        best = min(best, cur + C[last][0]);     // + volta ao início (ciclo)
        return;
    }
    for(int j = 0; j < n; j++){
        if(used & (1 << j)) continue;
        cur += C[last][j];                      // faz
        bt(j, used | (1 << j));
        cur -= C[last][j];                      // desfaz
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> C[i][j];
    bt(0, 1);                                    // começa no nó 0, já usado
    cout << best << endl;
    return 0;
}

Poda simples: if(cur >= best) return; no início. Continua O(n!) no pior caso.

3.5 Estados repetidos → memoizar

Lógica (a grande sacada da aula). No slide, compare os ramos 132 e 312 (n=5). Os dois escolheram o mesmo conjunto {1,2,3} e terminam no mesmo último nó (2). O que resta fazer (visitar 4 e 5 e voltar) não depende da ordem em que se chegou ali. Logo, as duas subárvores são idênticas e calculá-las duas vezes é desperdício. Quando há estados iguais, memoizamos.

O estado é (último nó, conjunto visitado): dp[last][mask]. São n · 2ⁿ estados, cada um com até n transições:

O(n² · 2ⁿ), contra O(n!) da força bruta. Para n = 20: 20! ≈ 2,4·10¹⁸ contra 20² · 2²⁰ ≈ 4·10⁸. Isso permite n até ~20.

Definição. solve(i, mask) = menor custo para, estando em i com mask já visitado, visitar o resto e voltar ao nó 0. Base: mask cheia → g[i][0]. Transição: min sobre j não visitado de g[i][j] + solve(j, mask | (1<<j)). A resposta é solve(0, 1).

Código completo (top-down, como no slide):

cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, g[20][20];
int dp[20][1 << 20];                     // 80 MB: ok para limite de 256 MB

int solve(int i, int mask){
    if(mask == (1 << n) - 1) return g[i][0];
    int &ans = dp[i][mask];
    if(ans != -1) return ans;            // já calculado
    ans = INF;
    for(int j = 0; j < n; j++){
        if(mask & (1 << j)) continue;
        ans = min(ans, g[i][j] + solve(j, mask | (1 << j)));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> g[i][j];
    memset(dp, -1, sizeof dp);           // -1 = não calculado
    cout << solve(0, 1) << endl;
    return 0;
}

Se o grafo puder ter arestas inexistentes, use long long e INF grande com cuidado para INF + peso não estourar.

Versão bottom-up (mesma ideia, sem recursão): dp[mask][last] = menor custo de um caminho que começa em 0, visita exatamente mask e termina em last. Vetor plano para economizar memória:

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(auto &l : g) for(auto &x : l) cin >> x;

    const int INF = 1e9;
    int cheia = (1 << n) - 1;
    vector<int> dp((1 << n) * n, INF);       // dp[mask * n + last]
    dp[1 * n + 0] = 0;                        // só o nó 0 visitado

    for(int mask = 1; mask <= cheia; mask++){
        if(!(mask & 1)) continue;             // todo caminho contém o nó 0
        for(int last = 0; last < n; last++){
            int atual = dp[mask * n + last];
            if(!(mask & (1 << last)) || atual >= INF) continue;
            for(int nxt = 0; nxt < n; nxt++){
                if(mask & (1 << nxt)) continue;
                int &alvo = dp[(mask | (1 << nxt)) * n + nxt];
                alvo = min(alvo, atual + g[last][nxt]);
            }
        }
    }
    int ans = INF;
    for(int last = 0; last < n; last++)
        ans = min(ans, dp[cheia * n + last] + g[last][0]);   // volta ao início
    cout << ans << endl;
    return 0;
}

No mesmo teste da seção 3.2 a resposta é 18.

PARTE 4 — Exemplo final: G. Gabmei, the hacker

Enunciado (resumo). Há n balões (1 ≤ n ≤ 20) em pontos de coordenadas inteiras do plano, com |x|, |y| ≤ 10⁶, todos distintos. Cada dardo é lançado de qualquer posição e segue infinitamente na sua direção, estourando todos os balões da sua trajetória: ou seja, cada dardo é uma reta infinita. Qual o mínimo de dardos (retas) para estourar todos os balões?

Por que é DP em subconjuntos. n ≤ 20 grita bitmask. O que importa é quais balões já foram estourados, não por qual reta.

Lógica.

Retas candidatas. Uma reta que passa por 2 ou mais balões fica definida por dois deles. Uma reta que passa por um só balão pode ser qualquer uma (cobre só ele). Então, para cada par (i, j), calculo linha[i][j] = máscara de todos os balões colineares com i e j. Três pontos estão alinhados quando o produto vetorial é zero: (xj−xi)·(yk−yi) − (yj−yi)·(xk−xi) == 0. As coordenadas diferem até 2·10⁶, então o produto chega a 4·10¹²: precisa de long long. Para a reta de um balão só, linha[i][i] = 1 << i.
Estado. dp[mask] = mínimo de retas para cobrir (pelo menos) os balões de mask. dp[0] = 0; resposta dp[(1<<n)-1].
Transição com um truque. Se eu tentasse qualquer reta a partir de qualquer estado, teria 2ⁿ · n² transições. Mas a ordem das retas não importa, então posso sempre exigir que a próxima reta cubra o menor balão ainda descoberto i (__builtin_ctz(~mask), o menor bit 0 de mask). Em uma solução ótima, alguma reta cobre i; basta ordenar as retas dessa forma. Daí: para cada j, dp[mask | linha[i][j]] = min(..., dp[mask] + 1).
Complexidade. Pré-cálculo O(n³); DP O(n · 2ⁿ) ≈ 2·10⁷ para n = 20.

Código completo:

cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    // linha[i][j] = máscara dos balões na reta que passa por i e j
    vector<vector<int>> linha(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        linha[i][i] = 1 << i;                     // reta só com o balão i
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            for(int k = 0; k < n; k++){
                ll cruz = (x[j] - x[i]) * (y[k] - y[i])
                        - (y[j] - y[i]) * (x[k] - x[i]);
                if(cruz == 0) linha[i][j] |= (1 << k);   // k está na reta
            }
        }
    }

    const int INF = 1e9;
    int cheia = (1 << n) - 1;
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    for(int mask = 0; mask < cheia; mask++){
        if(dp[mask] == INF) continue;
        int i = __builtin_ctz(~mask);             // menor balão ainda descoberto
        for(int j = 0; j < n; j++){
            int nova = mask | linha[i][j];        // j == i: reta só com i
            dp[nova] = min(dp[nova], dp[mask] + 1);
        }
    }
    cout << dp[cheia] << endl;
    return 0;
}

Testes para conferir: (0,0),(1,1),(2,2) → 1 dardo. Quadrado (0,0),(1,0),(0,1),(1,1) → 2. Três pontos não alinhados → 2. Um balão → 1.

Resumo e cola rápida
Preciso de...	Código
conjunto vazio / cheio	0 / (1 << n) - 1
elemento i está?	mask & (1 << i)
adicionar i	mask |= 1 << i
remover i	mask &= ~(1 << i)
alternar i	mask ^= 1 << i
tamanho do conjunto	__builtin_popcount(mask)
menor elemento (valor / índice)	mask & -mask / __builtin_ctz(mask)
remover o menor elemento	mask &= mask - 1
menor elemento fora do conjunto	__builtin_ctz(~mask)
iterar elementos do conjunto	for(m = mask; m; m &= m-1)

Receita da DP em máscaras: estado dp[mask] (ou dp[mask][last]); base dp[0] = 0 (ou o nó inicial); transição acrescentando um elemento com mask | (1 << j); a ordem crescente de mask funciona porque mask | x >= mask; resposta em dp[cheia].

Erros comuns:

1 << n com n ≥ 31: use 1LL << n (e __builtin_popcountll).
Esquecer parênteses: mask & (1 << i).
dp[..] + custo com INF perto do limite do tipo: use 1e18 em long long, ou teste dp == INF antes.
Memoização com -1 quando -1 pode ser resposta válida; ou esquecer o memset.
Memória: dp[20][1<<20] de int = 80 MB; de long long = 160 MB. Confira o limite.
Escolher bitmask com N grande: 2ᴺ · N com N = 25 já passa de 8·10⁸.

Conexões com o que você já resolveu:

homework2/M.cpp (soma de metades): hoje roda em O(n · 2ⁿ); com soma[mask] incremental (seção 1.5) vira O(2ⁿ).
homework2/G.cpp: em vez de juntar vetores, ordenar e usar unique para cada máscara, represente cada lista como uma máscara dos elementos que cobre e una com |; compare com a máscara cheia (se n couber em um inteiro).
conteste3/H.cpp: o popcount == 3 já é "escolher exatamente 3". Com N maior, vira uma DP.
homework2/F.cpp (damas) e n.cpp (permutações): são as árvores da seção 3.3. A DP em permutações é o que falta para podar repetições.

Para praticar (ordem sugerida):

Codeforces 1042B Vitamins (versão original do problema do slide).
CSES Apple Division (você já fez; refaça em O(2ⁿ)).
CSES Elevator Rides (DP em subconjuntos com dp[mask] = (corridas, peso)).
CSES Hamiltonian Flights (a variante de contar caminhos do TSP).
Gabmei, the hacker acima, com seus próprios testes.

📝 Material de apoio da Maratona CIn · Aula 6 — DP com Bitmasks.