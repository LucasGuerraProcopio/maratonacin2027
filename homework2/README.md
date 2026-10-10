Aula 2 — Buscas e Backtracking

SELETIVA · Material baseado nos slides de Lua Guimarães <lgf> e Marina <mrs5> (rev. 1.1)

Este repositório reúne o conteúdo da aula sobre técnicas de busca em programação competitiva, com a explicação de cada tópico e exemplos de código em C++.

📑 Sumário
Binary Search (Busca Binária)
Busca linear
Busca binária
Funções do C++
Lower Bound x Upper Bound
Funções monótonas
Problema: Factory Machines (BS na resposta)
Two Pointers
Sweep Line
Compressão de coordenadas
Busca Exaustiva (Complete Search)
Backtracking
Estados e transições
Poda (Pruning)
Receita de bolo
Complexidade
Exemplo: Sudoku
Resumo rápido
Próximo passo
1. Binary Search (Busca Binária)
1.1 Busca linear

Problema: dada uma lista de N números, descubra se o número X está ou não nela.

Uma solução é percorrer a lista inteira:

Caso	Complexidade	Quando acontece
Melhor caso	O(1)	X é o primeiro da lista
Pior caso	O(N)	X não está na lista

Em programação competitiva nos preocupamos com o pior caso, então a busca linear é tratada como O(N).

⚠️ A maioria dos problemas pede que N buscas sejam feitas. N × N = N², e o problema provavelmente não passa no tempo limite.

1.2 Busca binária

Como melhorar? Se a lista estiver ordenada, podemos olhar o item do meio. Se ele for maior ou menor que X, descartamos uma metade da lista. A cada iteração, metade da lista é descartada → complexidade O(log N).

Passo a passo:

Ordene a lista com um sort: O(N log N).
Defina o intervalo de busca [Left, Right] e calcule Mid.
Com base em Mid, reduza o espaço de busca:
Se v[Mid] < X, continue em [Mid+1, Right].
Se v[Mid] > X, continue em [Left, Mid-1].
Repita até v[Mid] == X ou até o intervalo ficar inválido (Left > Right).

Complexidade total para realizar N buscas:

O(N log N) [sort] + O(N log N) [N buscas] = O(N log N)

Boa complexidade até aproximadamente N = 5 × 10⁶.

Código (Binary Search básico):

cpp
#include <bits/stdc++.h>
using namespace std;

// Retorna o índice de x em v (ordenado), ou -1 se não existir
int binary_search_idx(const vector<int>& v, int x) {
    int l = 0, r = (int)v.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;      // evita overflow
        if (v[mid] == x) return mid;
        if (v[mid] < x) l = mid + 1;    // descarta metade esquerda
        else            r = mid - 1;    // descarta metade direita
    }
    return -1;
}

int main() {
    vector<int> v = {1, 3, 5, 7, 9, 11};
    sort(v.begin(), v.end());           // a lista PRECISA estar ordenada
    cout << binary_search_idx(v, 7) << "\n";   // 3
    cout << binary_search_idx(v, 4) << "\n";   // -1
}
1.3 Funções do C++

A biblioteca padrão já traz funções de busca binária (a lista precisa estar ordenada):

Função	O que retorna
binary_search(v.begin(), v.end(), x)	true/false: o valor existe na lista?
lower_bound(v.begin(), v.end(), x)	Ponteiro (iterador) para o primeiro item >= x
upper_bound(v.begin(), v.end(), x)	Ponteiro (iterador) para o primeiro item > x
cpp
vector<int> v = {1, 2, 3, 3, 3, 4, 5};

bool existe = binary_search(v.begin(), v.end(), 3);        // true
int lo = lower_bound(v.begin(), v.end(), 3) - v.begin();   // 2
int up = upper_bound(v.begin(), v.end(), 3) - v.begin();   // 5

int quantidade_de_3 = up - lo;                              // 3
1.4 Lower Bound x Upper Bound
	Lower Bound (limite inferior)	Upper Bound (limite superior)
O que faz?	Encontra o primeiro elemento que não é menor que o alvo	Encontra o primeiro elemento estritamente maior que o alvo
Em outras palavras	Primeiro elemento >= alvo	Primeiro elemento > alvo

Exemplo com alvo 3 na lista [1, 2, 3, 3, 3, 4, 5]:

índice:       0  1  2  3  4  5  6
valor:        1  2  3  3  3  4  5
                    ^           ^
              lower_bound   upper_bound
                (idx 2)       (idx 5)
1.5 Funções monótonas

Uma função monótona é aquela cujo valor só cresce ou só decresce conforme o argumento aumenta.

Queremos saber, por exemplo, o maior x tal que f(x) < k.

✅ Todo problema que envolve uma função monótona pode ser resolvido com busca binária.

1.6 Problema: Factory Machines (BS na resposta)

Ideia: o problema se resume a descobrir o menor x tal que F(x) >= t, onde F(x) é a quantidade de brinquedos produzidos em x segundos.

Como F(x) é monótona, podemos transformá-la em um booleano: se é possível construir t brinquedos em x segundos, também é possível em x+1, x+2, x+3...

x:        1  2  3  4  5  6 ...
possível: N  N  N  S  S  S ...   ← queremos o primeiro S

Resolução:

Defina l como o menor valor possível e r como o máximo.
Se a função de checagem roda em tempo linear, a complexidade é O(N × log(r)).
Com r = 10¹⁸ temos log(r) ≈ 60, então: 60 × 2×10⁵ = 1,2×10⁷ operações. Roda em menos de 1 segundo!

Código:

cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll t;
vector<ll> k;   // k[i] = segundos que a máquina i leva para fazer 1 produto

// Em "tempo" segundos, dá para fazer pelo menos t produtos?
bool ok(ll tempo) {
    ll total = 0;
    for (int i = 0; i < n; i++) {
        total += tempo / k[i];
        if (total >= t) return true;   // evita overflow
    }
    return false;
}

int main() {
    cin >> n >> t;
    k.resize(n);
    for (auto& x : k) cin >> x;

    ll l = 1, r = (ll)1e18, ans = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (ok(mid)) { ans = mid; r = mid - 1; }   // tenta menor
        else         { l = mid + 1; }              // precisa de mais tempo
    }
    cout << ans << "\n";
}

Padrão "BS na resposta": sempre que a pergunta for "qual o menor/maior valor tal que alguma condição é verdadeira?" e a condição é monótona, faça a busca binária sobre o valor da resposta, não sobre um array.

2. Two Pointers

Problema: dado um array com N inteiros (positivos) e um valor S, qual o maior segmento contínuo do array com soma <= S?

Exemplo: N = 7, S = 20, v = [2, 6, 4, 3, 6, 8, 9]

Como resolver em tempo linear?

Ideia

Usamos dois ponteiros, l (esquerda) e r (direita), ambos começando no primeiro elemento, e guardamos a soma atual (Sum) e o tamanho do melhor intervalo (Ans).

Se a soma ainda é <= S: movemos r para a direita e adicionamos v[r] à soma.
Se a soma supera S: retiramos v[l] da soma e movemos l para a direita.
Continuamos até r sair do array.
Simulação do exemplo
Passo	l	r	Sum	Ans	O que acontece
1	0	0	2	1	começa
2	0	1	8	2	soma ≤ 20, avança r
3	0	2	12	3	soma ≤ 20, avança r
4	0	3	15	4	soma ≤ 20, avança r
5	0	4	21	4	soma > 20, remove v[l]
6	1	4	19	4	soma ≤ 20
7	1	5	27	4	soma > 20, remove v[l]
8	2	5	21	4	ainda > 20, remove v[l]
9	3	5	17	4	soma ≤ 20
...				4	continua até r sair do array

Resposta: 4.

Código
cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; ll S;
    cin >> n >> S;
    vector<ll> v(n);
    for (auto& x : v) cin >> x;

    int l = 0, ans = 0;
    ll sum = 0;

    for (int r = 0; r < n; r++) {
        sum += v[r];                       // expande para a direita
        while (sum > S && l <= r) {        // encolhe pela esquerda
            sum -= v[l];
            l++;
        }
        ans = max(ans, r - l + 1);         // tamanho do segmento válido
    }
    cout << ans << "\n";
}

Complexidade: O(N), pois cada ponteiro percorre o array no máximo uma vez.

💡 Essa técnica funciona porque os valores são positivos: aumentar o intervalo só aumenta a soma, e diminuí-lo só diminui.

3. Sweep Line

Problema: dados N intervalos e Q queries, descubra, para cada query, em quantos intervalos ela se encontra.

Exemplo:

N = 3
intervalos: [1, 5)  [3, 7)  [4, 10)
Q = 3
queries: 6, 2, 4
Força bruta: para cada query, procurar em todos os intervalos → O(N × Q). Costuma estourar o tempo limite.
3.1 A ideia da Sweep Line

Atravessamos todo o range com uma linha vertical, somando as intersecções. Guardamos essas contagens para responder cada query rapidamente.

Passo a passo:

Armazene os intervalos (por exemplo, em um vector<pair<int,int>>).
Crie um vetor de contagem: some +1 na posição onde um intervalo começa e -1 na posição onde ele termina.
Aplique Prefix Sum (soma de prefixos) nesse vetor. Agora prefix[i] diz em quantos intervalos o ponto i está.

Exemplo:

índice:    0  1  2  3  4  5   6  7  8  9  10
contagem:  0  1  0  1  1 -1   0 -1  0  0  -1
prefix:    0  1  1  2  3  2   2  1  1  1   0

Respostas das queries: query 6 → 2, query 2 → 1, query 4 → 3. Tudo em tempo linear.

Código (valores pequenos):

cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    const int MAXV = 1000000;
    vector<int> cnt(MAXV + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;      // intervalo começa
        cnt[r]--;      // intervalo termina (r exclusivo)
    }

    for (int i = 1; i <= MAXV; i++) cnt[i] += cnt[i - 1];   // prefix sum

    cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << cnt[x] << "\n";
    }
}

⚠️ Esse código usa vetores do tamanho do maior valor possível. Vetores só aguentam por volta de 1 milhão de posições. O que fazer se MAXN = 10⁹? → Compressão de coordenadas.

3.2 Compressão de coordenadas

Em muitos problemas os valores chegam até 10⁹, mas a quantidade de valores é de apenas 10⁵ ou 10⁶. Então guardamos só os valores que realmente aparecem:

Coloque todos os valores relevantes em um vetor.
Ordene (sort).
Remova duplicatas com erase + unique.
cpp
sort(coords.begin(), coords.end());
coords.erase(unique(coords.begin(), coords.end()), coords.end());

Usando Lower e Upper Bound:

Para alterar o vetor de contagem → use o lower_bound (posição exata do valor).
Para consultar uma query → use o upper_bound - 1 (último ponto comprimido que é <= à query).
coords:  1  3  5  6  7  8  9

Código completo com compressão:

cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<pair<int,int>> iv(n);
    vector<int> coords;

    for (auto& [l, r] : iv) {
        cin >> l >> r;
        coords.push_back(l);
        coords.push_back(r);
    }

    // compressão de coordenadas
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    vector<int> cnt(coords.size() + 1, 0);

    for (auto& [l, r] : iv) {
        int il = lower_bound(coords.begin(), coords.end(), l) - coords.begin();
        int ir = lower_bound(coords.begin(), coords.end(), r) - coords.begin();
        cnt[il]++;
        cnt[ir]--;
    }

    for (size_t i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];   // prefix sum

    cin >> q;
    while (q--) {
        int x; cin >> x;
        int idx = upper_bound(coords.begin(), coords.end(), x) - coords.begin() - 1;
        cout << (idx < 0 ? 0 : cnt[idx]) << "\n";
    }
}

Complexidade: O((N + Q) log N).

4. Busca Exaustiva (Complete Search)
4.1 O que é?

Complete search, busca completa ou força bruta é a técnica de procurar uma resposta testando todos os cenários possíveis e escolhendo o melhor (ou qualquer um) deles.

Analogia: quebrar uma senha de 4 números.

Você testa um valor (0000).
Se conseguiu, para.
Se não, testa outro (0001)...

Objetivo: explorar sistematicamente todas as soluções candidatas até encontrar uma solução (ou a melhor).

4.2 Quando usar?

Só é viável quando o espaço de busca (número total de cenários) é pequeno o suficiente.

O fator decisivo são as constraints (limites de entrada):

Um computador moderno executa cerca de 10⁸ operações por segundo.
A busca deve ter menos casos que esse limite.
Complexidade	Limite de N	Exemplo de problema
O(N!)	N ≤ 11	Permutações (ex.: Caixeiro Viajante — TSP)
O(N × 2ᴺ)	N ≤ 22	Subconjuntos (ex.: Problema da Mochila)
O(Nᴷ)	N ≤ 464 (para K = 3)	Loops aninhados (ex.: achar uma tripla)
O(Kᴺ)	Depende de K e N	Backtracking geral (ex.: Sudoku)
4.3 Permutações

Como gerar? Com next_permutation, que transforma uma sequência na próxima permutação lexicograficamente.

Retorna true se encontrou a próxima permutação.
Retorna false se a sequência já está na maior permutação possível (ex.: [3, 2, 1]).

Complexidade: O(N) por chamada, O(N!) no loop do-while inteiro.

cpp
vector<int> v = {1, 2, 3};
sort(v.begin(), v.end());       // comece da menor permutação!

do {
    for (int x : v) cout << x << " ";
    cout << "\n";
} while (next_permutation(v.begin(), v.end()));

Saída: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1.

4.4 Subconjuntos

Como gerar? Com bitmasks: cada número de 0 a 2ᴺ - 1 representa uma combinação de "pegar" ou "não pegar" cada item.

Exemplo: i = 5 (binário 101) significa "pegar o item 0" e "pegar o item 2".

Complexidade: O(N × 2ᴺ), pois precisamos iterar pelos bits para ver quais estão ligados.

cpp
int n = v.size();
for (int mask = 0; mask < (1 << n); mask++) {
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {      // o bit i está ligado?
            soma += v[i];           // então pegamos o item i
        }
    }
    // use "soma" / o subconjunto como precisar
}
4.5 Loops aninhados

Como gerar? Pares, triplas, etc., com loops aninhados. Use quando o número de escolhas é fixo e pequeno.

Complexidade: O(Nᴷ), onde N é o número de elementos do conjunto e K é quantos serão escolhidos. Mais especificamente, C(N, K) operações se não houver repetição.

cpp
// todas as triplas i < j < k  →  C(N, 3) operações
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
            // testa a tripla (v[i], v[j], v[k])
        }
5. Backtracking
5.1 O que é?

Backtracking é uma técnica de força bruta "inteligente".

Analogia: resolver um labirinto.

Você avança por um caminho (constrói uma solução parcial).
Chega em uma bifurcação (tem várias escolhas).
Escolhe um caminho.
Se bater em um beco sem saída (solução inválida), volta atrás (backtrack) até a última bifurcação e tenta o outro caminho.

Objetivo: explorar todas as soluções candidatas, mas descartando (podando) caminhos que já sabemos que não levam a uma resposta.

Como pensar? Todo backtracking é uma função recursiva seguindo, mais ou menos, este modelo:

cpp
void backtrack(estado) {
    if (solução_completa(estado)) {   // 1. testa se a solução está certa
        // registra / retorna
        return;
    }
    for (cada decisão possível) {     // 2. para cada decisão:
        faz_escolha();                //    - faz uma escolha
        backtrack(novo_estado);       //    - chama para o novo estado
        desfaz_escolha();             //    - desfaz a escolha
    }
}
5.2 Estados e transições
Estados
Pergunta-chave: "O que eu preciso saber agora para tomar a próxima decisão?"
Definição: um estado é uma "foto" da solução parcial — as informações mínimas necessárias para continuar a busca.
Como definir: geralmente, são os parâmetros da função recursiva.

Exemplos:

Problema	Estado
N-Rainhas	(int linha_atual, vector<vector<bool>>& board)
Subset Sum	(int idx, int soma_atual)
Transições
Pergunta-chave: "Quais são minhas próximas escolhas a partir do estado atual?"
Definição: a ação ou escolha que leva de um estado ao próximo.
Como definir: geralmente, é o loop for dentro da função recursiva.

Exemplos:

Problema	Transição
N-Rainhas	"Onde posso colocar a rainha nesta linha?"
Subset Sum	"Para o elemento v[idx], tenho duas escolhas: incluir ou não incluir na soma."
A mágica: fazer e desfazer
Fazer (aplicar a transição) é o que modifica o estado.
Desfazer (backtrack) restaura o estado exatamente como era antes.

Por que desfazer? Para que na próxima iteração do loop (ex.: tentar (linha, col+1)) o estado esteja limpo, como se a tentativa anterior nunca tivesse acontecido.

5.3 Poda (Pruning)

É o que torna o backtracking inteligente e não apenas uma força bruta cega.

Conceito: "cortar" galhos da árvore de busca que nunca levarão a uma solução.

Exemplo — Subset Sum (com números positivos):

Estado: (index, soma_atual)
Poda: if (soma_atual > K) return;
Por quê? Se a soma já passou de K e só temos números positivos para adicionar, é impossível voltar a K. Parar agora economiza tempo exponencial.
cpp
#include <bits/stdc++.h>
using namespace std;

int n, K;
vector<int> v;

// Existe subconjunto de v com soma exatamente K?
bool subset_sum(int idx, int soma_atual) {
    if (soma_atual == K) return true;            // caso base: sucesso
    if (soma_atual > K)  return false;           // PODA
    if (idx == n)        return false;           // caso base: falha

    // Transição 1: incluir v[idx]
    if (subset_sum(idx + 1, soma_atual + v[idx])) return true;
    // Transição 2: não incluir v[idx]
    return subset_sum(idx + 1, soma_atual);
}

Aqui o "fazer/desfazer" é implícito: soma_atual é passada por valor, então não precisa ser desfeita manualmente.

5.4 Receita de bolo
Identifique: o problema pede para "gerar todos...", "encontrar um caminho...", "verificar se é possível..."? As restrições são pequenas (ex.: N <= 20)? → Provavelmente é backtracking.
Defina o Estado: "Quais parâmetros minha função backtrack() precisa?" (ex.: index, soma_atual, linha_atual).
Defina as Transições: "Quais são minhas escolhas em cada estado?" (ex.: tentar todas as colunas, incluir ou não o item, tentar todos os vizinhos no grafo). Isso vira seu for ou suas chamadas recursivas.
Defina a Poda: "Quando uma escolha é obviamente inválida?" (ex.: coluna já usada, soma atual > alvo). É o if (é_valida(...)) antes da recursão.
Defina o Caso Base: "Quando eu paro?"
Sucesso: encontrei uma solução completa (ex.: linha == N nas N-Rainhas, soma_atual == alvo).
Falha: cheguei ao fim sem solução (ex.: index == N no Subset Sum, mas soma != alvo).
5.5 Complexidade

Pergunta: "Meu backtracking é rápido o suficiente?"

Depende do número total de estados que a recursão pode visitar.
Raramente é polinomial; quase sempre é exponencial ou fatorial.
É ditada pela forma da árvore de estados.
Complexidade ≈ (Número Total de Estados na Árvore) × (Custo por Transição)
Custo por transição: custo de "Fazer" e "Desfazer".
✅ Ideal: O(1) (ex.: usado[i] = true, soma += valor).
❌ Ruim: O(N) (ex.: copiar um vetor inteiro a cada chamada). Evite!
Número total de estados: é o que realmente domina — o número de nós da árvore de recursão.
Padrão 1 — Decisão binária (gerar subconjuntos)
Estado: (int index) — "estou decidindo sobre o elemento index".
Transições: 2 escolhas (incluir ou não incluir).
Nível 0 (raiz): 1 estado
Nível 1:        2 estados
Nível 2:        4 estados
...
Nível N:        2^N estados (folhas)

Total: 1 + 2 + 4 + ... + 2^N ≈ 2^(N+1) - 1 = O(2^N)

Complexidade: O(2ᴺ) estados × O(1) por transição = O(2ᴺ).

Moral: se em cada um dos N passos você tem k escolhas independentes, a complexidade é da ordem de O(kᴺ).

Padrão 2 — Escolha e reduza (gerar permutações)
Estado: (int k) — "estou escolhendo o k-ésimo elemento da permutação".
Transições: o número de escolhas diminui a cada nível.
Nível 1 (raiz): N   escolhas
Nível 2:        N-1 escolhas
Nível 3:        N-2 escolhas
...
Folhas: N × (N-1) × ... × 1 = N!

O total de nós é 1 + N + N(N-1) + ... + N!, dominado pelo número de folhas. Complexidade: O(N!).

cpp
int n;
vector<int> perm;
vector<bool> usado;

void gerar(int k) {
    if (k == n) {                          // caso base: permutação completa
        for (int x : perm) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (usado[i]) continue;            // PODA: já usado
        usado[i] = true;                   // faz
        perm.push_back(i);
        gerar(k + 1);                      // recursão
        perm.pop_back();                   // desfaz
        usado[i] = false;
    }
}
// chamada: usado.assign(n + 1, false); gerar(0);
Análise: complexidade x poda
No pior caso, a poda pode não ajudar (ex.: alvo gigante). A complexidade teórica continua O(2ᴺ).
Na prática, a poda corta galhos inteiros da árvore de estados — é isso que torna o backtracking viável.

Conclusão:

Pense na complexidade do pior caso (sem poda) para saber se a ideia geral é relativamente viável.
Use a poda para otimizar o caso médio e passar nos testes. Experiência com problemas semelhantes ajuda a ter o feeling.
5.6 Exemplo: Sudoku

Problema: você recebe um tabuleiro de Sudoku parcialmente preenchido. Responda se é possível completá-lo.

Ideia naive (força bruta): para cada quadrado não preenchido (até n × n), tente cada uma das 9 possibilidades.

Complexidade: 9^(n×n) — só passa para n até 3.

Ideia com backtracking: para cada quadrado não preenchido, tente uma possibilidade e veja se o jogo continua possível. Se não, volte ao último estado válido e tente outra escolha.

Complexidade teórica: 9^(n×n).
Na prática: cada corte economiza 9^(n×n - 1) estados!

Entrada de exemplo (. = vazio, 9 linhas):

....4....
....8....
..57.34..
..4.2.5..
92.1.4.87
..1.3.2..
..84.69..
....1....
....9....

Código:

cpp
#include <bits/stdc++.h>
using namespace std;

char g[9][9];

// Posso colocar o dígito d na posição (r, c)?
bool valido(int r, int c, char d) {
    for (int i = 0; i < 9; i++) {
        if (g[r][i] == d) return false;        // mesma linha
        if (g[i][c] == d) return false;        // mesma coluna
    }
    int br = (r / 3) * 3, bc = (c / 3) * 3;    // canto do bloco 3x3
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (g[br + i][bc + j] == d) return false;
    return true;
}

// Estado: pos = índice da célula atual (0..80)
bool resolve(int pos) {
    if (pos == 81) return true;                // caso base: tabuleiro completo

    int r = pos / 9, c = pos % 9;
    if (g[r][c] != '.') return resolve(pos + 1);   // já preenchida

    for (char d = '1'; d <= '9'; d++) {        // transições: tentar 1..9
        if (!valido(r, c, d)) continue;        // PODA
        g[r][c] = d;                           // faz a escolha
        if (resolve(pos + 1)) return true;
        g[r][c] = '.';                         // desfaz (backtrack)
    }
    return false;                              // beco sem saída
}

int main() {
    for (int i = 0; i < 9; i++) {
        string s; cin >> s;
        for (int j = 0; j < 9; j++) g[i][j] = s[j];
    }

    if (resolve(0)) {
        cout << "POSSIVEL\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << g[i][j];
            cout << "\n";
        }
    } else {
        cout << "IMPOSSIVEL\n";
    }
}
📌 Resumo rápido
Técnica	Quando usar	Complexidade típica
Busca linear	Poucas buscas, lista pequena ou desordenada	O(N) por busca
Busca binária	Lista ordenada ou função monótona	O(log N) por busca
BS na resposta	"Menor/maior x tal que..." com condição monótona	O(N log R)
Two Pointers	Segmentos contínuos com valores positivos	O(N)
Sweep Line	Contar intervalos que cobrem pontos (queries)	O((N+Q) log N)
Compressão de coordenadas	Valores grandes (10⁹) mas poucos elementos	O(N log N)
Permutações	N ≤ 11	O(N!)
Subconjuntos (bitmask)	N ≤ 22	O(N × 2ᴺ)
Loops aninhados	Número fixo e pequeno de escolhas	O(Nᴷ)
Backtracking	Restrições pequenas + dá para podar	O(Kᴺ) (menos com poda)
🎯 Próximo passo

Fazer o Homework!

Material de apoio da SELETIVA · Aula 2 — Buscas e Backtracking.