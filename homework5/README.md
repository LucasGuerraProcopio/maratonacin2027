Aula 5 — DP 1 (Programação Dinâmica)

Maratona CIn · Centro de Informática (UFPE) — Material baseado nos slides de palao e gui (rev. 1.1)

Esta aula apresenta a Programação Dinâmica (DP) usando só o que você já aprendeu: recursão e backtracking com estados (Aula 2), vector, map, lower_bound e prefix sum (Aulas 1 e 2). Para cada tópico do slide você encontra: 🧠 a lógica, 🎯 que tipo de problema ele resolve, ⌨️ como codar e ✅ um exemplo completo.

📑 Sumário
A ideia geral de DP
Fatorial recursivo e memoização
Fibonacci
DP em Árvore (Subordinates)
Dice Combinations
DP com probabilidade (valor esperado)
DP em Jogos (Digits Duel)
Kadane (subarray de soma máxima)
Subset Sum
Knapsack (mochila)
LCS (maior subsequência comum)
LIS (maior subsequência crescente)
Recuperação de resposta
Problema extra: Campinho
Observações sobre os slides originais
Resumo rápido e próximo passo
0. A ideia geral de DP

🧠 Lógica. Na Aula 2 você viu que a complexidade de um backtracking é (número de estados) × (custo por transição). O problema é que muitas vezes a recursão cai várias vezes no mesmo estado (mesmos parâmetros) e refaz o mesmo trabalho. DP é exatamente isto: recursão + lembrar a resposta de cada estado. Se o estado já foi calculado, devolvemos o valor guardado. Cada estado é calculado uma única vez, então a complexidade vira (número de estados distintos) × (custo por transição).

🎯 Quando suspeitar de DP? Perguntas como "de quantas formas...", "qual o máximo/mínimo...", "é possível...?", em que cada passo é uma escolha (pegar ou não pegar, avançar ou ficar) e as restrições são grandes demais para 2^N, mas o número de estados diferentes é pequeno.

Receita (parecida com a receita de bolo do backtracking):

Estado: que parâmetros descrevem a situação? (O que preciso saber agora para decidir o próximo passo?)
Transições: quais escolhas levam a outros estados?
Caso base: quando paro e quanto vale?
Recorrência: como combino as respostas dos próximos estados (soma, max, min, ou)?
Memoização (ou tabela iterativa) para nunca calcular um estado duas vezes.
Complexidade = estados × custo da transição.

Existem dois estilos de escrever:

	Top-down (memoização)	Bottom-up (iterativa)
Como é	função recursiva + vetor memo	laços que preenchem dp dos estados pequenos para os grandes
Vantagem	escreve-se direto da recorrência; só calcula o que é alcançado	sem risco de estourar a pilha; costuma ser mais rápida
Cuidado	profundidade de recursão (1e6 chamadas pode dar SIGSEGV)	é preciso achar a ordem certa de preenchimento

⌨️ Molde top-down:

cpp
int memo[MAXN];                 // -1 = ainda não calculei

int solve(int estado){
    if(/* caso base */) return /* valor */;
    if(memo[estado] != -1) return memo[estado];   // já calculado
    int ans = /* combina as transições */;
    return memo[estado] = ans;                    // guarda e devolve
}
// no main: memset(memo, -1, sizeof memo);

⚠️ memset(memo, -1, sizeof memo) funciona para int e long long (todos os bytes viram 0xFF = -1). Para double, use fill ou vector<double>(n, -1). Além disso, -1 só serve como marcador se a resposta nunca puder ser -1.

1. Fatorial recursivo e memoização

🧠 Lógica. n! = n · (n-1)! e 0! = 1. A recursão tem um caso base (n == 0) e um passo que reduz o problema. Como o resultado é pedido mod 1e9+7, aplicamos % MOD a cada multiplicação. Para uma consulta com N ≤ 1e6 isso custa O(N), tranquilo.

E se forem T ≤ 1e5 consultas? Repetir O(N) em cada uma dá 1e5 × 1e6 = 1e11. Mas repare no DAG do slide: fat(4) → fat(3) → fat(2) → fat(1) → fat(0). Todas as consultas passam pelos mesmos nós (o caminho de fat(1000) contém o de fat(500)). Com memoização, cada fat(n) é calculado só quando memo[n] == -1; as consultas seguintes reaproveitam. Total: O(MAXN + T).

🎯 Que problema resolve? Qualquer situação com muitas consultas sobre a mesma função: precomputar uma vez e responder em O(1). É a base de combinatória mod primo (fatoriais, binomiais).

⌨️ Como codar (top-down, como no slide):

cpp
const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
long long memo[MAXN];

long long fat(int n){
    if(n == 0) return 1;                        // caso base
    if(memo[n] != -1) return memo[n];           // já calculei
    return memo[n] = n * fat(n - 1) % MOD;      // calcula, guarda, devolve
}

💡 No slide o código é Python (sem overflow). Em C++ use long long: n * fat(n-1) chega a ~1e15, que cabe; com int estouraria (lembra da seção 1.5 da Aula 1?). Além disso, 1e6 chamadas recursivas aninhadas podem estourar a pilha, então na prática prefira a versão iterativa abaixo.

✅ Exemplo completo (T consultas de N! mod 1e9+7): entrada: T e depois T valores de N. Exemplo: 3 / 5 / 10 / 0 → 120, 3628800, 1.

cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
long long fat[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = fat[i-1] * i % MOD;   // precomputa tudo

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << fat[n] << '\n';                                  // O(1) por consulta
    }
    return 0;
}
Abordagem	Tempo para T consultas
Recalcular a cada consulta	O(T · N) ❌
Memoização / precomputação	O(MAXN + T) ✅
2. Fibonacci

🧠 Lógica. fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2). A recorrência é naturalmente recursiva, mas a versão ingênua é muito lenta: cada chamada gera duas chamadas, e a árvore do slide mostra o desperdício: dentro de fib(6), fib(4) é calculado 2 vezes, fib(3) 3 vezes, fib(2) 5 vezes... O número de chamadas cresce quase como 1,618^n (limitado por O(2^n)), então n = 50 já é inviável.

O truque do slide: quando poda um nó repetido, você corta a subárvore inteira dele. Com memoização, cada fib(k) é calculado uma vez (são n estados, cada transição custa O(1)) → O(N).

🎯 Que problema resolve? É o exemplo mais puro de subproblemas sobrepostos. Sempre que a árvore de recursão repete nós, memoize. O mesmo padrão aparece em escadas (de quantos jeitos subir N degraus pulando 1 ou 2), tilings e contagens parecidas.

⌨️ Como codar:

cpp
long long memo[100];

long long fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;                        // dois casos base
    if(memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

✅ Exemplo completo (imprimir fib(N), N ≤ 90): fib(90) ≈ 2,88·10^18 ainda cabe em long long (já fib(93) estoura). Exemplo: 10 → 55.

cpp
#include <bits/stdc++.h>
using namespace std;

long long memo[100];

long long fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(memo, -1, sizeof memo);
    int n; cin >> n;
    cout << fib(n) << '\n';
    return 0;
}

💡 Versão iterativa com memória O(1): como fib(i) só depende dos dois anteriores, guarde apenas duas variáveis (a, b) e avance n vezes.

3. DP em Árvore (Subordinates)

🧠 Lógica. Uma empresa é uma árvore enraizada no diretor (funcionário 1). Cada funcionário de 2 a n informa quem é seu chefe direto. Queremos, para cada funcionário, quantos subordinados ele tem (diretos e indiretos), ou seja, quantos nós estão na sua subárvore, sem contar ele mesmo.

Pense recursivamente: o tamanho da subárvore de u é 1 (o próprio u) + a soma dos tamanhos das subárvores dos filhos. Isso já é uma DP:

Estado: o nó u.
Transição: visitar cada filho v de u e somar solve(v).
Caso base: uma folha não tem filhos, então o laço não roda e a resposta é 1.
Resposta do problema: solve(u) - 1.

Na árvore, o DAG de recursão é a própria árvore, e cada nó é visitado uma vez → O(N). O memo garante que, depois de solve(1), todos os valores ficam guardados para imprimir.

🎯 Que problema resolve? Tudo que pede uma informação agregada sobre subárvores: tamanho, soma de valores, altura, maior caminho para baixo, etc. O raciocínio é sempre "a resposta de um nó é uma combinação das respostas dos filhos".

⌨️ Como codar (slide): g[u] é a lista de vizinhos, pai[u] evita voltar ao pai quando as arestas são não direcionadas:

cpp
int solve(int u){
    if(memo[u] != -1) return memo[u];
    int ans = 1;
    for(int v : g[u]) if(v != pai[u])
        ans += solve(v);
    return memo[u] = ans;
}

💡 Neste problema o chefe é dado diretamente, então basta criar a aresta dirigida chefe → funcionário; assim não precisamos de pai[]. Para uma árvore não direcionada qualquer, passe o pai como parâmetro: solve(int u, int p) e ignore v == p.

✅ Exemplo completo (CSES Subordinates): entrada 5 e 1 1 2 3 → saída 4 1 1 0 0.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;
vector<int> g[MXN];
int memo[MXN];

int solve(int u){
    if(memo[u] != -1) return memo[u];
    int ans = 1;                               // conta o próprio u
    for(int v : g[u]) ans += solve(v);         // soma as subárvores dos filhos
    return memo[u] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int chefe; cin >> chefe;
        g[chefe].push_back(i);                 // aresta chefe -> funcionário
    }

    memset(memo, -1, sizeof memo);
    solve(1);

    for(int u = 1; u <= n; u++) cout << memo[u] - 1 << ' ';   // tira o próprio nó
    cout << '\n';
    return 0;
}

⚠️ Em uma cadeia (cada um chefe do próximo) a recursão chega a 2·10^5 níveis. No CSES isso passa, mas em outros juízes pode estourar a pilha.

4. Dice Combinations

🧠 Lógica. De quantas maneiras podemos formar a soma n jogando um dado (resultados de 1 a 6) uma ou mais vezes? A ordem importa: 1+2 e 2+1 são formas diferentes.

Chame de C(N) o número de formas de somar N. Para não contar nada duas vezes, olhe para o último lançamento de cada sequência (ele é único!):

se o último lançamento foi 1, antes dele a soma era N−1 → C(N−1) jeitos;
se foi 2, antes era N−2 → C(N−2) jeitos;
... até o 6 → C(N−6) jeitos.

C(N) = C(N−1) + C(N−2) + ... + C(N−6), usando só termos com índice ≥ 0, e C(0) = 1 (a sequência vazia é uma forma). Conferindo para n = 3: C(1) = 1, C(2) = C(1)+C(0) = 2, C(3) = C(2)+C(1)+C(0) = 4 ✅ (as quatro formas do enunciado).

n	0	1	2	3	4	5	6	7
C(n)	1	1	2	4	8	16	32	63
Estados: N (valor da soma). Transições: 6. Complexidade: O(6·N) = O(N).

🎯 Que problema resolve? Contagem de formas em que cada passo escolhe entre poucas opções fixas e o resultado vem com mod. É o mesmo padrão de Coin Combinations, Climbing Stairs e contagem de caminhos.

⌨️ Como codar (top-down):

cpp
long long memo[MAXN];

long long C(int n){
    if(n == 0) return 1;
    if(memo[n] != -1) return memo[n];
    long long ans = 0;
    for(int dado = 1; dado <= 6; dado++)
        if(dado <= n) ans = (ans + C(n - dado)) % MOD;
    return memo[n] = ans;
}

✅ Exemplo completo (CSES Dice Combinations, versão iterativa): entrada 3 → saída 4. Com n até 1e6 a versão iterativa é mais segura (sem 1e6 níveis de recursão):

cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
long long dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int dado = 1; dado <= 6; dado++){
            if(dado <= i) dp[i] = (dp[i] + dp[i - dado]) % MOD;   // não esqueça o mod!
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
5. DP com probabilidade (valor esperado)

🧠 Lógica. O Pou precisa passar por N plataformas. A cada jogada, com probabilidade 1/k ele tem azar e continua na mesma plataforma; com probabilidade 1 − 1/k ele avança para a próxima. Qual o número esperado de jogadas para terminar?

Defina dp(i) = número esperado de jogadas para terminar estando na plataforma i, com dp(n) = 0. De i, uma jogada sempre acontece (custo 1) e depois:

dp(i) = 1 + (1/k)·dp(i) + (1 − 1/k)·dp(i+1)

Os três termos são, respectivamente: a jogada atual, permanecer e avançar. A regra geral é: E(estado) = custo + Σ (probabilidade × E(próximo estado)).

O problema: dp(i) aparece nos dois lados (é o self loop do slide). Se você codar direto, solve(i) chama solve(i) e a recursão nunca termina. A saída é a álgebra ("conta de padaria"): passe o termo do self loop para a esquerda e divida:

(1 − 1/k)·dp(i) = 1 + (1 − 1/k)·dp(i+1)
dp(i) = k/(k−1) + dp(i+1)

Intuição: em cada plataforma a chance de sucesso é p = (k−1)/k, e o número esperado de tentativas até o primeiro sucesso é 1/p = k/(k−1) (distribuição geométrica). Como as n plataformas custam o mesmo, vale a fórmula fechada dp(0) = n · k/(k−1) (soma de PA com termos iguais). Isso exige k ≥ 2: com k = 1 o Pou nunca avança.

🎯 Que problema resolve? Esperança em processos aleatórios com estados: dados, passeios aleatórios, "número esperado de passos/tentativas". Passos: (1) definir dp = esperança a partir do estado, (2) escrever a equação, (3) isolar self loops algebricamente, (4) codar.

⌨️ Como codar:

cpp
int n, k;
vector<double> dp;   // inicialize com -1: dp.assign(n + 1, -1)

double solve(int i){
    if(i == n) return 0;
    if(dp[i] >= 0) return dp[i];
    return dp[i] = (double)k / (k - 1) + solve(i + 1);   // k/(k-1) + dp(i+1)
}

⚠️ O código do slide tem * entre (1.0*k)/(k-1) e solve(i+1); pela fórmula derivada acima o correto é +.

✅ Exemplo completo (exemplo próprio, o slide não traz entrada/saída): entrada n k; saída o valor esperado com 6 casas. Para 3 2 a resposta é 6.000000 (cada plataforma leva em média 2 jogadas). Para 1 2, também 2.000000.

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<double> dp(n + 1, 0);
    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = dp[i + 1] + (double)k / (k - 1);   // iterativo de trás pra frente
    }
    cout << fixed << setprecision(6) << dp[0] << '\n';
    return 0;
}
6. DP em Jogos (Digits Duel)

🧠 Lógica. O problema do slide (Digits Duel): na mesa estão os números 2, 3, ..., N+1. Dois jogadores se alternam; em cada turno o jogador remove um subconjunto não vazio dos números cujo MDC seja estritamente maior que 1. Depois da remoção, os números que sobraram são renomeados para 2, 3, ..., (quantidade restante + 1). Quem não consegue jogar perde. Mastermei começa e os dois jogam otimamente: quem vence?

Observações do slide, passo a passo:

Só importa a quantidade. Como sempre renomeamos, o estado é só i = quantos números restam (e eles são sempre 2..i+1). Esse é um jogo imparcial: os dois jogadores têm as mesmas jogadas disponíveis.
Quantos podemos remover de uma vez? No máximo floor((i+1)/2): se todos os números removidos são múltiplos de p ≥ 2, existem no máximo floor((i+1)/p) deles, e o melhor caso é p = 2 (todos os pares). Qualquer quantidade j entre 1 e floor((i+1)/2) é possível (um número sozinho tem MDC igual a ele mesmo, que é > 1; j pares têm MDC ≥ 2).
Estados vencedores e perdedores. dp[0] = 0: sem números, quem deve jogar perde. Um estado é vencedor (1) se existe alguma jogada que leve o adversário a um estado perdedor (0); caso contrário é perdedor (0):

dp[i] = 1 − min dp[i−j], para 1 ≤ j ≤ floor((i+1)/2)

(se algum vizinho vale 0, o mínimo é 0 e dp[i] = 1; se todos valem 1, dp[i] = 0.) Calcular o mínimo na janela custa O(n) por estado → O(n²), lento para N até 5·10^5.

Otimização. Só queremos saber se existe um 0 na janela [i − floor((i+1)/2), i−1]. Basta guardar a posição do último estado perdedor (ultimo_zero): se existe algum zero na janela, o mais recente também está nela. Assim cada estado custa O(1) e a DP iterativa encaixa perfeitamente (cada estado depende só de estados menores).

Tabela dos primeiros estados:

i	0	1	2	3	4	5	6	7	8
dp[i]	0	1	0	1	1	1	0	1	1

Ex.: N = 2 (números {2,3}): o primeiro jogador só pode remover um número (MDC(2,3) = 1 impede levar os dois), o adversário remove o outro e o primeiro perde → the greatest.

🎯 Que problema resolve? Jogos de dois jogadores com informação completa, jogadas ótimas e estado simples: modele estados como vencedor/perdedor, comece pelo estado terminal (quem não pode jogar perde) e use a regra "vencedor se existe jogada para um perdedor". É o mesmo raciocínio de Nim e de Stone Game.

⌨️ Como codar: DP iterativa de baixo para cima, mantendo ultimo_zero.

✅ Exemplo completo (Digits Duel): entrada: T e depois T valores de N (N ≤ 5·10^5). Para cada caso imprima mastermei se o primeiro vence, ou the greatest caso contrário.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;                       // sem números: quem joga perde
    int ultimo_zero = 0;             // último estado perdedor visto
    for(int i = 1; i < MAXN; i++){
        int inicio_janela = i - (i + 1) / 2;       // menor i-j possível
        if(ultimo_zero >= inicio_janela){
            dp[i] = 1;               // existe jogada para um estado perdedor
        } else {
            dp[i] = 0;               // todas as jogadas levam a estados vencedores
            ultimo_zero = i;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(dp[n]) cout << "mastermei" << '\n';
        else cout << "the greatest" << '\n';
    }
    return 0;
}

💡 Olhando a tabela, os estados perdedores são 0, 2, 6, 14, 30, ... (i + 2 é potência de 2). Dá para confirmar com a própria DP; assim o problema também sai em O(1) por caso testando se (N+2) & (N+1) == 0. O objetivo da aula, porém, é aprender a modelar a DP de jogos.

7. Kadane (subarray de soma máxima)

🧠 Lógica. Dado um array de inteiros (possivelmente negativos), ache o subarray contíguo de soma máxima. Ex.: A = [-2, 1, -3, 4, -1, 2, 1, -5, 4] → resposta 6.

Força bruta: testar todos os pares (l, r) com prefix sum (Aula 1) dá O(n²). Com DP:

Modelagem 1 (a do slide): estado dp[i][comecei], onde i é o índice atual e comecei diz se já começamos a somar o subarray (0 ou 1).

Se ainda não comecei: posso começar aqui (v[i] + solve(i+1, 1)) ou ignorar v[i] (solve(i+1, 0)); fico com o max.
Se já comecei: posso pegar v[i] e continuar (v[i] + solve(i+1, 1)) ou parar (valor 0); fico com o max.
Caso base (i == n): se já comecei, vale 0; se nunca comecei, vale −INF (o subarray não pode ser vazio).

São 2n estados com transições O(1) → O(n).

Modelagem 2 (Kadane de verdade): só precisamos de duas variáveis:

curr: a melhor soma de um subarray que termina em i;
answ: a melhor soma vista até agora.

O melhor subarray que termina em i ou é só v[i] (recomeça aqui) ou é o melhor que terminava em i-1 mais v[i] (estende). Logo curr = max(v[i], curr + v[i]), depois answ = max(answ, curr). Se curr anterior era negativo, estender só piora, então recomeçamos.

Simulação em A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]:

i	0	1	2	3	4	5	6	7	8
v[i]	-2	1	-3	4	-1	2	1	-5	4
curr	-2	1	-2	4	3	5	6	1	5
answ	-2	1	1	4	4	5	6	6	6

💡 Conexão com Prefix Sum (Aula 1): soma(l..r) = ps[r+1] − ps[l]. Fixando r, queremos o menor prefixo à esquerda: a resposta é o max de ps[r+1] − min(ps[0..r]). É a mesma ideia vista de outro jeito.

🎯 Que problema resolve? Melhor trecho contíguo: lucro máximo em sequência de dias, melhor segmento de temperatura, etc. Também é o exemplo clássico de DP que se comprime: quando o estado só depende do anterior, guarde variáveis em vez de uma tabela.

⌨️ Como codar (Kadane, do slide):

cpp
int kadane(int n, vector<int>& v){
    int answ = v[0];             // começa com v[0] (subarray não pode ser vazio)
    int curr = v[0];
    for(int i = 1; i < n; i++){
        curr = max(v[i], curr + v[i]);
        answ = max(answ, curr);
    }
    return answ;
}

⚠️ Comece com v[0] e não com 0: se todos os números forem negativos a resposta é o maior deles. Use long long quando as somas puderem passar de 2·10^9.

✅ Exemplo completo (CSES Maximum Subarray Sum): n ≤ 2·10^5 e valores até 10^9 em módulo. Entrada 8 e -1 3 -2 5 3 -5 2 2 → saída 9 (o trecho 3 −2 5 3).

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    long long answ = v[0], curr = v[0];
    for(int i = 1; i < n; i++){
        curr = max(v[i], curr + v[i]);   // recomeça em i ou estende
        answ = max(answ, curr);
    }
    cout << answ << '\n';
    return 0;
}
8. Subset Sum

🧠 Lógica. Dado um array de inteiros não negativos e um alvo, existe um subconjunto cuja soma seja exatamente o alvo? Ex.: A = [3, 34, 4, 12, 5, 2], alvo 9 → sim (4 + 5, ou 3 + 4 + 2).

Para cada número temos duas escolhas: usar ou não usar. Testar todas as máscaras (bitmask, como no seu homework da Aula 2) custa O(2^n).

A melhoria: muitas escolhas diferentes chegam ao mesmo subproblema ("estou no elemento i e ainda falta uma soma s"). Então definimos:

Estado: dp[i][sum] = é possível formar sum usando os elementos de i em diante?
Transições: (1) não pegar: solve(i+1, sum); (2) pegar: solve(i+1, sum - v[i]).
Resposta: o ou das duas.
Casos base: sum == 0 → verdadeiro (testamos primeiro, assim funciona mesmo no fim do array); sum < 0 ou i == n → falso.
Complexidade: O(N · alvo). Diz-se pseudo-polinomial: depende do valor do alvo, não só do tamanho da entrada. Funciona se o alvo for da ordem de 10^4 ou 10^5.

Isso é o backtracking subset_sum(idx, soma_atual) da Aula 2 mais memoização.

🎯 Que problema resolve? "Dá para formar exatamente X?": troco exato, dividir itens em dois grupos de soma igual, verificar se um peso é alcançável.

⌨️ Como codar (slide):

cpp
const int MAXN = 1e3 + 5;
const int MAXS = 1e4 + 5;
int dp[MAXN][MAXS];          // memset(dp, -1, sizeof dp) no main
vector<int> v;

int solve(int i, int sum){
    if(sum == 0) return 1;
    if(sum < 0 || i == (int)v.size()) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];

    bool nao_pega = solve(i + 1, sum);
    bool pega = solve(i + 1, sum - v[i]);
    return dp[i][sum] = (pega || nao_pega);
}

✅ Exemplo completo: entrada: n alvo e depois os n números; saída SIM ou NAO. Para 6 9 / 3 34 4 12 5 2 → SIM. Para alvo 30 com o mesmo array → NAO.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXS = 1e4 + 5;
int dp[MAXN][MAXS];
vector<int> v;

int solve(int i, int sum){
    if(sum == 0) return 1;
    if(sum < 0 || i == (int)v.size()) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];

    int nao_pega = solve(i + 1, sum);
    int pega = solve(i + 1, sum - v[i]);
    return dp[i][sum] = (pega || nao_pega);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, alvo; cin >> n >> alvo;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    memset(dp, -1, sizeof dp);
    if(solve(0, alvo)) cout << "SIM" << '\n';
    else cout << "NAO" << '\n';
    return 0;
}

💡 Versão iterativa com 1 dimensão: vector<bool> pode(alvo+1); pode[0] = true; e, para cada x, for(s = alvo; s >= x; s--) pode[s] = pode[s] || pode[s-x]; (percorra de trás para frente para usar cada número uma só vez).

⚠️ O slide exige números não negativos: com negativos, o corte sum < 0 deixa de ser válido.

9. Knapsack (mochila)

🧠 Lógica. Temos N itens com peso w e valor v, e uma mochila de capacidade W. Escolher um subconjunto que maximize o valor total sem passar de W. Ex.: w = [3, 4, 2, 6], v = [4, 5, 3, 7], W = 7 → 9 (itens de peso 3 e 4).

É um Subset Sum em que cada escolha tem custo e lucro, e queremos o máximo. Testar todas as máscaras é O(2^n).

Por que não um guloso? Pegar pela maior razão valor/peso: item 3 (3/2 = 1,5), depois item 1 (4/3 ≈ 1,33) → peso 5, valor 7, e o item 2 não cabe. Só 7, mas existe 9. Guloso falha → DP.

Estado: dp[i][cap] = maior valor usando os itens de i em diante, com capacidade restante cap.
Transições: não pegar → solve(i+1, cap); pegar (somente se cap >= w[i]) → v[i] + solve(i+1, cap - w[i]).
Caso base: i == n → 0.
Complexidade: O(N · W).

🎯 Que problema resolve? Maximizar/minimizar algo com um recurso limitado (peso, tempo, dinheiro) escolhendo itens inteiros: compras com orçamento (CSES Book Shop), seleção de tarefas, etc.

⌨️ Como codar (slide):

cpp
int solve(int i, int cap){
    if(i == (int)v.size()) return 0;
    if(dp[i][cap] != -1) return dp[i][cap];

    int nao_pega = solve(i + 1, cap);
    int pega = 0;
    if(cap >= w[i]) pega = v[i] + solve(i + 1, cap - w[i]);

    return dp[i][cap] = max(nao_pega, pega);
}

✅ Exemplo completo: entrada: n W, depois os n pesos e os n valores. Para 4 7 / 3 4 2 6 / 4 5 3 7 → 9.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MAXW = 1e4 + 5;
int dp[MAXN][MAXW];
vector<int> v, w;

int solve(int i, int cap){
    if(i == (int)v.size()) return 0;
    if(dp[i][cap] != -1) return dp[i][cap];

    int nao_pega = solve(i + 1, cap);
    int pega = 0;
    if(cap >= w[i]) pega = v[i] + solve(i + 1, cap - w[i]);

    return dp[i][cap] = max(nao_pega, pega);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, W; cin >> n >> W;
    w.resize(n); v.resize(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> v[i];

    memset(dp, -1, sizeof dp);
    cout << solve(0, W) << '\n';
    return 0;
}

💡 Versão com memória O(W): vector<long long> dp(W+1, 0); e, para cada item, for(int c = W; c >= w[i]; c--) dp[c] = max(dp[c], dp[c - w[i]] + v[i]); (de trás para frente, para usar o item uma vez só). É a que cabe em problemas com W até 10^5.

10. LCS (maior subsequência comum)

🧠 Lógica. Dadas duas strings S₁ e S₂, qual o tamanho da maior subsequência que aparece nas duas? Subsequência = letras na mesma ordem, não necessariamente consecutivas. Ex.: S₁ = "ABCDGH" e S₂ = "AEDFHR" → "ADH", tamanho 3.

Gerar todas as subsequências de uma string e conferir na outra é O(2^n). Com DP:

Estado: dp[i][j] = LCS entre os sufixos s1[i..] e s2[j..].
Transições:
se s1[i] == s2[j]: essas letras casam, somamos 1 e andamos nas duas → 1 + solve(i+1, j+1) (casar nunca piora a resposta);
se são diferentes: uma delas fica de fora → max(solve(i+1, j), solve(i, j+1)).
Caso base: uma das strings acabou → 0.
Complexidade: O(|S₁| · |S₂|).

🎯 Que problema resolve? Comparar duas sequências: diff de arquivos, similaridade de DNA, e a base de Edit Distance.

⌨️ Como codar (slide):

cpp
int solve(int i, int j){
    if(i == (int)s1.size() || j == (int)s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        int iguais = 1 + solve(i + 1, j + 1);
        return dp[i][j] = iguais;
    }
    int diferentes = max(solve(i + 1, j), solve(i, j + 1));
    return dp[i][j] = diferentes;
}

✅ Exemplo completo: entrada: duas strings (uma por linha), saída o tamanho da LCS. Para ABCDGH e AEDFHR → 3.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3 + 5;
int dp[MAXS][MAXS];
string s1, s2;

int solve(int i, int j){
    if(i == (int)s1.size() || j == (int)s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(i + 1, j + 1);
    return dp[i][j] = max(solve(i + 1, j), solve(i, j + 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
    return 0;
}
11. LIS (maior subsequência crescente)

🧠 Lógica. Dado um array, qual o tamanho da maior subsequência de elementos estritamente crescentes (não precisam ser consecutivos)? Ex.: A = [10, 2, 5, 3, 7, 18] → 4 (2, 5, 7, 18).

Testar todas as máscaras e checar se estão em ordem crescente é O(2^n). Com DP, o que importa para decidir se posso pegar v[i] é qual foi o último elemento que peguei:

Estado: dp[i][prev] = maior crescente usando os elementos de i em diante, sendo prev o índice do último elemento escolhido.
Transições: não pegar → solve(i+1, prev); pegar (só se prev == -1 ou v[i] > v[prev]) → 1 + solve(i+1, i).
Caso base: i == n → 0.
Complexidade: n · (n+1) estados, O(1) cada → O(n²).

Truque do índice -1: no início ainda não escolhi ninguém, então prev = -1 (qualquer elemento pode ser o primeiro). Como não existe dp[i][-1], guardamos em dp[i][prev + 1].

🎯 Que problema resolve? Ordenação parcial: maior sequência de dias com preço subindo, empilhar caixas, e muitos problemas que se reduzem a LIS.

⌨️ Como codar (slide):

cpp
int solve(int i, int prev){
    if(i == (int)v.size()) return 0;
    if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int nao_pega = solve(i + 1, prev);
    int pega = 0;
    if(prev == -1 || v[i] > v[prev]) pega = 1 + solve(i + 1, i);

    return dp[i][prev + 1] = max(nao_pega, pega);
}

✅ Exemplo completo (O(n²), n ≤ 1000): entrada 6 e 10 2 5 3 7 18 → saída 4.

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int dp[MAXN][MAXN];
vector<int> v;

int solve(int i, int prev){
    if(i == (int)v.size()) return 0;
    if(dp[i][prev + 1] != -1) return dp[i][prev + 1];

    int nao_pega = solve(i + 1, prev);
    int pega = 0;
    if(prev == -1 || v[i] > v[prev]) pega = 1 + solve(i + 1, i);

    return dp[i][prev + 1] = max(nao_pega, pega);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    memset(dp, -1, sizeof dp);
    cout << solve(0, -1) << '\n';
    return 0;
}

🚀 Exercício do slide: LIS em O(n log n). Use o lower_bound da Aula 2. Mantenha um vetor tails em que tails[k] é o menor valor possível em que termina uma crescente de tamanho k+1. Para cada x: ache lower_bound(tails, x); se chegou ao fim, x estende a maior sequência (push_back); senão, x substitui aquele elemento (terminar em algo menor só facilita estender depois). O tamanho final de tails é a resposta. (tails em si não é a subsequência; é só o tamanho.)

cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> tails;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        auto it = lower_bound(tails.begin(), tails.end(), x);   // 1o >= x (estritamente crescente)
        if(it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    cout << tails.size() << '\n';
    return 0;
}

No exemplo [10, 2, 5, 3, 7, 18]: tails vira [10] → [2] → [2,5] → [2,3] → [2,3,7] → [2,3,7,18], tamanho 4. Para permitir iguais (não estritamente), troque por upper_bound.

12. Recuperação de resposta

🧠 Lógica. Até aqui nossas DPs devolvem o valor ótimo (tamanho da LCS, valor da mochila...). Muitos problemas pedem também a solução: qual é a subsequência? quais itens levei? A ideia do slide: para cada estado calculado, guardar qual transição gerou a resposta ótima. Depois basta partir do estado inicial e seguir essas transições salvas, sem recalcular nada, anotando as ações que importam (pegar o item, casar uma letra).

Passo a passo:

Crie transicao[i][j] (um pair<int,int>) com o próximo estado escolhido.
Em solve, na hora do max, guarde a transição do caminho vencedor.
Escreva retrieve que parte de (0, 0) e anda i, j = transicao[i][j] até o fim, registrando as ações.

🎯 Que problema resolve? Qualquer DP de otimização em que o enunciado pede a construção da resposta: imprimir a LCS, os itens da mochila, a LIS, o caminho de menor custo.

⌨️ Como codar (molde genérico do slide):

cpp
pair<int,int> transicao[MAXN][MAXN];

int solve(int i, int j){
    if(/* chegou no fim */) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int caminho_1 = op1 + solve(prox1_i, prox1_j);
    int caminho_2 = op2 + solve(prox2_i, prox2_j);

    if(caminho_1 > caminho_2){
        transicao[i][j] = {prox1_i, prox1_j};     // guarda o caminho ótimo
        return dp[i][j] = caminho_1;
    } else {
        transicao[i][j] = {prox2_i, prox2_j};
        return dp[i][j] = caminho_2;
    }
}

// depois de chamar solve(0, 0):
void retrieve(int i, int j){
    while(!chegou_no_fim(i, j)){
        auto [prox_i, prox_j] = transicao[i][j];
        if(/* a transição foi a ação válida */){ /* recupera */ }
        i = prox_i; j = prox_j;
    }
}

Como reconhecer a ação "que vale" em cada problema:

Problema	Estado	A ação foi feita quando...
LCS	(i, j)	a transição foi para (i+1, j+1): a letra s1[i] entra na resposta
Knapsack	(i, cap)	a transição foi para (i+1, cap − w[i]): o item i foi pego
LIS	(i, prev)	a transição foi para (i+1, i): o elemento v[i] entra na sequência

✅ Exemplo completo (LCS imprimindo a subsequência): entrada: duas strings; saída: o tamanho e uma LCS. Para ABCDGH e AEDFHR → 3 e ADH (se houver empate, qualquer LCS válida serve).

cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3 + 5;
int dp[MAXS][MAXS];
pair<int,int> transicao[MAXS][MAXS];
string s1, s2;

int solve(int i, int j){
    if(i == (int)s1.size() || j == (int)s2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        transicao[i][j] = {i + 1, j + 1};         // casou: anda nas duas
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    }
    int a = solve(i + 1, j);
    int b = solve(i, j + 1);
    if(a >= b){
        transicao[i][j] = {i + 1, j};
        return dp[i][j] = a;
    }
    transicao[i][j] = {i, j + 1};
    return dp[i][j] = b;
}

string retrieveLCS(int i, int j){
    string ans = "";
    while(i < (int)s1.size() && j < (int)s2.size()){
        int prox_i = transicao[i][j].first;
        int prox_j = transicao[i][j].second;
        if(prox_i == i + 1 && prox_j == j + 1){    // só o caso 'casou' anda nas duas
            ans += s1[i];
        }
        i = prox_i;
        j = prox_j;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';         // primeiro calcula a DP
    cout << retrieveLCS(0, 0) << '\n';   // depois recupera a resposta
    return 0;
}

💡 Alternativa sem transicao: durante o retrieve, refaça a decisão comparando os valores de dp dos estados vizinhos.

13. Problema extra: Campinho

🧠 Lógica. João monta um time na formação 4-3-3: 1 goleiro (G), 2 zagueiros (Z), 2 laterais (L), 3 meio-campistas (M) e 3 atacantes (A), total 11 jogadores. Cada jogador tem posição, preço e pontuação (valores com 2 casas decimais). João tem X reais. Qual a pontuação máxima possível? Se não der para montar o time, imprima −1. (N ≤ 200, X ≤ 200,00, preços e pontos ≤ 50,00.)

É um Knapsack (maximizar pontuação com orçamento limitado) com uma restrição extra: quantos jogadores por posição.

Ideia inicial (cara): uma máscara de bits com os 11 "slots" do time. São 2^11 máscaras × jogadores × orçamento: grande demais.
Ideia melhor (slide): agrupe os jogadores por posição, na ordem G, Z, L, M, A. Em vez de máscara, guarde só c = quantos jogadores já escolhi. Como os grupos são processados em ordem e cada um tem cota, o valor de c revela quantos de cada posição já levei:
Posição	Cota	Só posso pegar se...
G	1	0 ≤ c < 1
Z	2	1 ≤ c < 3
L	2	3 ≤ c < 5
M	3	5 ≤ c < 8
A	3	8 ≤ c < 11

(Ex.: só posso pegar um zagueiro se c ≥ 1, ou seja, já tenho o goleiro; e c < 3 garante no máximo 2 zagueiros.) No fim, exigir c == 11 garante exatamente 4-3-3.

O estado do slide é dp[i][c][p]: i = jogador analisado, c = jogadores já escolhidos, p = orçamento restante. Transições: ignorar ou pegar (se couber no orçamento e c estiver no intervalo do grupo dele). Caso base: i == n → 0 se c == 11, senão −∞.

⚠️ Dinheiro como inteiro: converta tudo para centavos (llround(x * 100)) para trabalhar com inteiros. Orçamento ≤ 20000 e pontuação ≤ 11 × 5000. Com dp[i][c][p] em int seriam 200 × 12 × 20001 ≈ 48 milhões de posições (~192 MB), arriscado para o limite de memória. A saída é guardar apenas os estados que importam (próximo código).

🎯 Que problema resolve? Knapsack com restrições de grupo/quantidade: escalar equipes com cotas por função, escolher itens por categoria, etc. O truque é transformar a restrição em um contador no estado.

✅ Exemplo completo: a mesma DP, escrita iterativa (como na dica da mochila 1D, a dimensão i some). best[c][g] = maior pontuação com c jogadores escolhidos gastando exatamente g centavos. Percorremos os grupos na ordem G, Z, L, M, A, e dentro de cada jogador atualizamos c de trás para frente, para não usar o mesmo jogador duas vezes.

Teste simples: 11 11.00 com um jogador de preço 1.00 e pontuação 1.00 para cada vaga (1 G, 2 Z, 2 L, 3 M, 3 A) → 11.00.

cpp
#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; double x; cin >> n >> x;
    int X = llround(x * 100);                    // orçamento em centavos

    string ordem = "GZLMA";
    int lo[5] = {0, 1, 3, 5, 8};                 // faixa de c permitida por grupo
    int hi[5] = {1, 3, 5, 8, 11};
    vector<pair<int,int>> grupo[5];              // {preço, pontos} em centavos

    for(int i = 0; i < n; i++){
        char c; double p, s; cin >> c >> p >> s;
        int g = ordem.find(c);
        grupo[g].push_back({(int)llround(p * 100), (int)llround(s * 100)});
    }

    vector<vector<int>> best(12, vector<int>(X + 1, NEG));
    best[0][0] = 0;

    for(int g = 0; g < 5; g++){
        for(auto [preco, pontos] : grupo[g]){
            for(int c = hi[g] - 1; c >= lo[g]; c--){          // de trás pra frente
                for(int gasto = X - preco; gasto >= 0; gasto--){
                    if(best[c][gasto] == NEG) continue;
                    best[c + 1][gasto + preco] = max(best[c + 1][gasto + preco],
                                                     best[c][gasto] + pontos);
                }
            }
        }
    }

    int ans = NEG;
    for(int gasto = 0; gasto <= X; gasto++) ans = max(ans, best[11][gasto]);

    if(ans == NEG) cout << -1 << '\n';
    else cout << fixed << setprecision(2) << ans / 100.0 << '\n';
    return 0;
}

Complexidade: cerca de N × 3 × X = 200 × 3 × 20000 ≈ 1,2·10^7 operações.

14. Observações sobre os slides originais

Alguns detalhes foram ajustados neste README para evitar confusão:

Slide	Detalhe	O que está neste README
Fatorial	Código em Python (sem overflow) e recursão de 1e6 níveis	Em C++ use long long e prefira a versão iterativa
Fibonacci	Complexidade ingênua perguntada	É exponencial: cerca de 1,618^n, limitada por O(2^n); com memo, O(N)
Subordinates	O código calcula o tamanho da subárvore (inclui o próprio nó)	A resposta é solve(u) - 1; memo precisa de memset(-1) e pai[]/arestas dirigidas precisam ser preenchidos
Dice	Código do slide não aplica o % MOD	Adicionei o mod; a versão iterativa evita 1e6 níveis de recursão
Probabilidade	Último código usa * entre k/(k-1) e solve(i+1), e o 1º código chama solve(i) dentro de si	A fórmula derivada é +; o primeiro código recursa infinitamente (por isso se reescreve a equação)
Probabilidade	dp[i] >= 0 como marcador de memo	dp precisa ser iniciado com -1 (não use memset em double); exige k ≥ 2
Jogos	Janela de mínimo em O(n²)	Troquei pelo ultimo_zero, O(n)
Kadane / Subset Sum / Knapsack / LCS / LIS	Códigos assumem dp preenchido com -1	Faça memset(dp, -1, sizeof dp) no main
Campinho	dp[i][c][p] consome ~192 MB	Usei a versão iterativa com apenas best[c][gasto]
15. Resumo rápido e próximo passo
Tópico	Estado	Transições	Complexidade
Fatorial com memo	n	n · fat(n−1)	O(MAXN + T)
Fibonacci	n	fib(n−1) + fib(n−2)	O(N)
Subordinates	nó u	soma dos filhos + 1	O(N)
Dice	soma n	último dado de 1 a 6	O(6N)
Probabilidade	plataforma i	k/(k−1) + dp(i+1)	O(N)
Jogos	quantidade i	remover j números	O(N) com ultimo_zero
Kadane	(i, comecei) ou só curr/answ	pegar/parar ou estender/recomeçar	O(N)
Subset Sum	(i, sum)	pegar / não pegar	O(N · alvo)
Knapsack	(i, cap)	pegar (se couber) / não pegar	O(N · W)
LCS	(i, j)	casar ou descartar uma letra	O(|S₁| · |S₂|)
LIS	(i, prev)	pegar (se crescer) / não pegar	O(n²), ou O(n log n) com lower_bound
Recuperação	mesmo da DP	guardar a transição ótima	O(caminho) extra
Campinho	(i, c, p)	pegar se cota e orçamento permitirem	O(N · 3 · X)

Checklist para atacar um problema novo de DP:

Consigo descrever uma solução recursiva (pegar/não pegar, últimas escolhas)?
Quais parâmetros bastam para descrever o estado? (índice, soma restante, último escolhido, quantos já escolhi...)
Quantos estados distintos existem? Cabe na memória e no tempo?
Qual o caso base? Preciso de um marcador "não calculado" diferente de uma resposta válida?
Preciso apenas do valor ou também da solução? (então guarde a transição)
🎯 Próximo passo

Fazer o Homework! Treine os padrões desta aula no CSES: Dice Combinations, Subordinates, Maximum Subarray Sum, Book Shop e Increasing Subsequence (o último pede o LIS em O(n log n)). Depois tente Minimizing Coins, Coin Combinations I e Edit Distance, que usam as mesmas ideias de estado e transição.

Material de apoio da Maratona CIn · Aula 5 — DP 1.