Aula 1 — Warmup + STL

Maratona CIn · Centro de Informática (UFPE) Material baseado nos slides de Thawan <trs3> e Caio <cns> Licença do material original: CC BY-NC-SA

Esta aula é a base para quem vai começar em programação competitiva com C++: como configurar o ambiente, escrever o primeiro código, entender complexidade de tempo e espaço, usar a STL (Standard Template Library) e dominar a técnica de Prefix Sum. No final há dois problemas clássicos resolvidos.

📑 Sumário
Introdução ao C++
Por que C++?
Configurando o ambiente
Primeiro código
Buffer Sync (I/O rápido)
Tipagem e overflow
Escopo e Shadowing
Complexidade de uma função recursiva e referências
Memória: vector x array
Inferência de tipos (auto)
Entradas e saídas
Compilação e debugging
Truques úteis
Complexidade temporal e espacial
Biblioteca Padrão (STL)
Containers
Algoritmos
For loops (range-based)
Prefix Sum
Problemas clássicos
Subarray com soma K
Stack monotônica
Observações sobre os slides originais
Próximo passo
1. Introdução ao C++
1.1 Por que C++?
⚡ Velocidade de execução (código compilado).
📚 Poderosa biblioteca padrão — a Standard Template Library (STL).
🏆 Aceito por todas as competições de programação importantes.
🎓 Vários tutoriais e aulas de algoritmos disponíveis.
1.2 Configurando o ambiente

Linux: use o GCC que já vem na sua distribuição.

bash
# Debian / Ubuntu
sudo apt update
sudo apt install build-essential gdb

Windows: use o ambiente MSYS2 com o GCC via mingw64.

Instale o MSYS2 (https://www.msys2.org).
Abra o terminal MSYS2 MinGW64 e rode:
bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb
Adicione a pasta mingw64/bin do MSYS2 ao PATH do Windows para usar g++ em qualquer terminal.

⚠️ Não esqueça de instalar também o debugger (gdb).

Para conferir se deu certo:

bash
g++ --version
gdb --version
1.3 Primeiro código

Arquivo hello.cpp:

cpp
#include <bits/stdc++.h>   // Incluir STL (todas as bibliotecas padrão)

using namespace std;       // namespace (evita escrever std::)

int main() {               // main (sempre int)
    string name;
    cin >> name;

    cout << "Hello, " << name << "!" << endl;

    return 0;
}
Linha	Para que serve
#include <bits/stdc++.h>	Inclui toda a STL de uma vez
using namespace std;	Permite usar cin, cout, vector... sem o prefixo std::
int main()	Ponto de entrada. Sempre retorna int
1.3.1 Compilar e rodar
bash
g++ hello.cpp -o hello
./hello
1.4 Buffer Sync (I/O rápido)

Desligar a sincronização entre o C++ e o C agiliza a leitura e escrita:

cpp
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    /* code */

    return 0;
}

Regras importantes:

Uma vez desligado, use somente printf/scanf ou somente cout/cin. Nunca misture.
Evite endl: além de quebrar a linha, ele força uma sincronização (chama flush). Por isso o #define endl '\n' acima.
Ao usar '\n', o output só é impresso no final da execução (ou quando o buffer enche).
1.5 Tipagem e overflow

Qual a diferença no output destes dois códigos?

cpp
// Código A
int main() {
    int n = 1e9;
    int x = n*n;
    cout << x;
}

// Código B
int main() {
    int n = 1e9;
    long long x = n*n;
    cout << x;
}

Resposta: nenhuma! Nos dois casos n*n é calculado com int (e estoura) antes de ser convertido para long long. Declarar x como long long não resolve se a conta já aconteceu em int.

Formas corretas (todas válidas):

cpp
// 1) Variáveis já em long long
long long n = 1e9;
long long x = n*n;

// 2) Multiplicar por 1ll para promover o tipo antes da conta
int n = 1e9;
long long x = 1ll*n*n;

// 3) Cast explícito
int n = 1e9;
long long x = (long long)n*n;

Prática:

cpp
// 1) Divisão de inteiros → resultado 0
int n = 3, m = 4;
double x = n/m;            // 0

// 2) Com double → 0.75
double n = 3, m = 4;
double x = n/m;            // 0.75

// 3) Promovendo para long long antes da conta → 0.75
double n = 3, m = 4;
double x = (n*1ll)/(m*1ll);   // 0.75

// 4) Overflow! n*n é calculado em int antes do *1ll
int n = 1e9;
long long x = n*n*1ll;     // Overflow
// Correto: 1ll*n*n
1.6 Escopo e Shadowing

Cuidado com for sem chaves: só o primeiro comando pertence ao loop.

cpp
// ❌ curr++ NÃO está dentro do for
int curr = 1;
int ans = 0;

for(int i = 0; i < 500; i++)
    ans += curr;
    curr++;               // executa só uma vez, depois do loop

cout << ans;              // 500
cpp
// ✅ com chaves, os dois comandos se repetem
int curr = 1;
int ans = 0;

for(int i = 0; i < 500; i++){
    ans += curr;
    curr++;
}

cout << ans;              // 125250  (1 + 2 + ... + 500)

Shadowing: declarar uma variável com o mesmo nome em um escopo interno "esconde" a de fora.

cpp
int main() {
    int n = 100, ans = 0;
    int curr = 1;                      // curr externo

    for(int i = 0; i < n; i++){
        int curr = 10;                 // esconde o curr externo (shadowing)

        while(ans < curr){
            ans += curr;
            cout << curr << '\n';      // 10
            if((n % ans) == 0){
                int curr = 5;          // outro curr, só dentro deste if
                cout << curr << '\n';  // 5
            }
        }
        cout << curr << '\n';          // 10
    }

    cout << curr;                      // 1  (o curr externo nunca mudou)
}

💡 Compile com -Wshadow para o compilador avisar sobre shadowing (veja Compilação).

Variáveis globais: declaradas fora de qualquer função, valem para o programa todo.

cpp
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
const int maxn = 100;
int valores[maxn];

void freq(int i, int x){
    if(i >= maxn) return;

    if(valores[i] == x) ans++;

    freq(i+1, x);
}

int main() {
    for(int i = 0; i < maxn; i++) cin >> valores[i];

    freq(0, 12);
    cout << ans;
}

Em competições, arrays grandes devem ser globais (a pilha da função tem espaço limitado).

1.7 Complexidade de uma função recursiva e referências

Qual a complexidade desta função?

cpp
int soma(int i, vector<int> valores){
    int curr = valores[i] + soma(i+1, valores);
    return curr;
}

O vetor é passado por valor, então cada chamada copia o vetor inteiro (O(N)). Como há N chamadas, a complexidade total é O(N²).

(O código do slide também não tem caso base. Em um código real, adicione if(i == valores.size()) return 0;.)

Solução: passar por referência (&)

cpp
int soma(int i, vector<int> &valores){
    if(i == (int)valores.size()) return 0;      // caso base
    int curr = valores[i] + soma(i+1, valores);
    return curr;
}

Agora nada é copiado: a complexidade cai para O(N).

Referências também servem em loops, para não copiar nem perder alterações:

cpp
int main() {
    vector<vector<int>> listas;
    for(auto &v : listas){            // & evita copiar cada vetor
        sort(v.begin(), v.end());
    }
}
1.8 Memória: vector x array
cpp
vector<int> v(n);
int arr[n];

for(int i = 0; i <= n; i++){      // ⚠️ i <= n acessa o índice n (fora do limite)
    ans += v[i];
    ans2 += arr[i];
}
cout << ans << '\n';
cout << ans2 << '\n';

⚠️ Bug clássico: os índices válidos vão de 0 a n-1. Usar i <= n lê fora dos limites, o que causa lixo de memória ou Segmentation Fault. Use i < n.

1.9 Inferência de tipos (auto)

auto deixa o compilador descobrir o tipo, e permite desestruturar structs, pairs e tuples:

cpp
struct Aluno{
    string nome;
    int idade;
    double cr;
};

int main() {
    auto al = Aluno({"Joao", 18, 8.562});

    auto [nome, idade, cr] = al;      // desestruturação

    for(auto c : al.nome){            // percorre os caracteres
        cout << c;
    }
}
1.10 Entradas e saídas

Entrada: Maratona CIn

cpp
// cin >> lê até o primeiro espaço
string s;
cin >> s;
cout << s;          // "Maratona"
cpp
// getline lê a linha inteira
string s;
getline(cin, s);
cout << s;          // "Maratona CIn"

⚠️ Se você usou cin >> x antes de um getline, o \n fica no buffer. Chame cin.ignore(); antes do getline.

Saída com vários casos de teste:

cpp
int main() {
    int t; cin >> t;
    int caso = 1;
    while(t--){
        int ans = 0;     // calcule a resposta do caso aqui
        cout << "Caso " << caso << ": " << ans << "\n";
        caso++;
    }
}

No slide o código imprime t dentro do while(t--), que vai diminuindo. Se você quer numerar os casos de 1 a T, use um contador separado como acima.

1.11 Compilação e debugging

Comandos:

bash
g++ a.cpp -o a                              # compila
g++ -O2 -Wall -Wshadow a.cpp -o a           # compila com otimização e avisos
./a < entrada.in > saida.out                # roda lendo de arquivo e gravando em arquivo
Flag	O que faz
-O2	Otimiza o código (como nos juízes online)
-Wall	Ativa os avisos principais
-Wshadow	Avisa sobre variáveis que "escondem" outras
< entrada.in	Redireciona o arquivo para o cin
> saida.out	Redireciona o cout para um arquivo

Erros comuns (sinais):

Sinal	Significado
SIGTERM	Rodando infinitamente (estourou o tempo)
SIGILL	Instrução ilegal. Geralmente esqueceu de dar return em uma função não-void
SIGSEGV	Segmentation fault. Acesso indevido de memória
1.12 Truques úteis
cpp
// Permite redirecionar a entrada ou a saída para um arquivo de texto
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

// Define uma precisão obrigatória de saída para pontos flutuantes
cout << setprecision(10) << fixed;

// Definem atalhos para os tipos de dados mais comuns
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

📎 Mais truques: https://codeforces.com/blog/entry/111217

2. Complexidade temporal e espacial
2.1 Importância

Em competições não basta o código funcionar: ele precisa ser rápido o suficiente para rodar dentro do tempo limite (geralmente 1 ou 2 segundos). A análise de complexidade prevê o quão rápido um algoritmo será sem precisar executá-lo.

A notação Big O descreve como o tempo de execução cresce conforme o tamanho da entrada (N) aumenta. Focamos no pior caso e ignoramos constantes e termos de menor ordem.

Exemplo: se um algoritmo faz 3N² + 5N + 10 operações, sua complexidade é O(N²).

2.2 Regra de ouro (tempo)

Considere que um computador de competição executa cerca de 10⁸ operações por segundo em C++.

Complexidade	N máximo aproximado
O(log N)	praticamente qualquer N
O(N)	~10⁸
O(N log N)	~10⁶
O(N²)	~10⁴
O(N³)	~4×10²
O(2ᴺ)	~26
O(N!)	~11

Número de operações para cada N (✅ passa / ❌ não passa em ~1 segundo):

	N = 10	N = 100	N = 1.000	N = 10.000	N = 100.000	N = 1.000.000
O(log N)	✅ ~3	✅ ~7	✅ ~10	✅ ~13	✅ ~17	✅ ~20
O(N)	✅ 10	✅ 100	✅ 1.000	✅ 10.000	✅ 100.000	✅ 1.000.000
O(N log N)	✅ ~33	✅ ~664	✅ ~9.965	✅ ~132.877	✅ ~1.660.964	✅ ~19.931.568
O(N²)	✅ 100	✅ 10.000	✅ 1.000.000	✅ 100.000.000	❌ 10¹⁰	❌ 10¹²
O(N³)	✅ 1.000	✅ 1.000.000	❌ 10⁹	❌ 10¹²	❌ 10¹⁵	❌ 10¹⁸
O(2ᴺ)	✅ 1.024	❌ 1,26×10³⁰	❌ Muito grande	❌ Muito grande	❌ Muito grande	❌ Muito grande
O(N!)	✅ 3.628.800	❌ 9,33×10¹⁵⁷	❌ Muito grande	❌ Muito grande	❌ Muito grande	❌ Muito grande
2.3 E o espaço?

Assim como o tempo, a memória é um recurso limitado. Geralmente o limite é algo como 256 MB ou 512 MB.

Complexidade de espaço é a medida de quanta memória seu programa usa em função de N.
Escolher o tipo de dado correto é o primeiro passo para controlar a memória.
2.4 Regra de ouro (memória)

Para saber a memória usada por uma estrutura como um array, multiplique o número de elementos pelo tamanho do tipo.

Um array de 1 milhão de int: 10⁶ × 4 bytes = 4.000.000 bytes ≈ 4 MB.

Tipo	O que armazena	Tamanho típico	Intervalo de valores
int	Números inteiros	4 bytes	aprox. −2×10⁹ a 2×10⁹
long long	Inteiros muito grandes	8 bytes	aprox. −9×10¹⁸ a 9×10¹⁸
char	Um único caractere	1 byte	Caracteres ASCII
bool	Verdadeiro ou falso	1 byte	true ou false
float	Ponto flutuante	4 bytes	Precisão de ~7 dígitos
double	Ponto flutuante de dupla precisão	8 bytes	Precisão de ~15 dígitos
3. Biblioteca Padrão (STL)

A STL tem containers (estruturas de dados) e algoritmos (funções prontas, eficientes e testadas).

3.1 Containers
vector<T>
O que é? Um array dinâmico que pode crescer e diminuir.
Quando usar? Quase sempre! É a estrutura mais flexível e usada.
Observação: string é um vector<char> com operações extras.
cpp
vector<int> vec;            // Cria um vetor de inteiros                 O(1)
vector<int> vec2(10);       // Tamanho 10                                O(n)
vector<int> vec3(10, 5);    // Tamanho 10, inicializado com 5            O(n)

vec.push_back(1);           // Adiciona o elemento 1 ao final            O(1) amortizado
vec.pop_back();             // Remove o último elemento                  O(1)
vec.size();                 // Tamanho atual                             O(1)
vec.empty();                // true se estiver vazio                     O(1)
vec[0] = 10;                // Acessa o primeiro elemento e atribui 10   O(1)
string
O que é? Um vector<char>.
Quando usar? Quando precisar lidar com palavras.
cpp
// Strings usam aspas duplas; chars usam aspas simples
string s = "Meu nome é Lua";

s.substr(11, 3);                       // Substring a partir da posição 11, tamanho 3 → "Lua"
s.find("nome");                        // Posição da primeira ocorrência → 4

// Se não encontrar, find retorna string::npos
if (s.find("c++") == string::npos) {
    cout << "'c++' não foi encontrado";
}

// Converte string para inteiro e vice-versa
int n = stoi("123");
string n_str = to_string(456);

Strings e chars — observações:

Diferente de Python, existe diferença entre um caractere e uma string ('a' ≠ "a").
char é um inteiro de 1 byte.
cpp
string s;
int n = 100;
for(int i = 0; i < n; i++){
    s = s + 'a';          // O(n)   → cria uma string nova a cada vez!
    s += 'a';             // O(1)
    s += "a";             // O(1)
    s.push_back('a');     // O(1)
    s.push_back("a");     // erro (push_back espera um char)
    s.push_back('abc');   // truncamento (multi-char literal)
}
cout << s;

💡 Use s += 'a' em vez de s = s + 'a' dentro de loops.

map<Key, Value>
O que é? Pares chave-valor, onde as chaves são únicas e ordenadas.
Quando usar? Para contar frequência ou associar um valor a outro (como um dict).
Observação: diferente de um dict em Python, o map cria a chave com um valor padrão quando ela é acessada (para map<T,int> é 0).
cpp
map<int, int> m;                  // O(1)

m[5] = 1;                         // Insere/atribui           O(log n)
m.count(5);                       // Verifica se existe       O(log n)
m.find(5);                        // Encontra (iterador)      O(log n)
m[5];                             // Acessa o valor           O(log n)
m.erase(5);                       // Remove                   O(log n)

multimap<int, int> ms;            // Permite chaves repetidas O(1)
ms.insert({5, 1});                // Insere                   O(log n)
ms.count(5);                      // Quantas vezes aparece    O(log n + k)
ms.find(5);                       // Primeiro elemento 5      O(log n)
ms.erase(ms.find(5));             // Remove UMA ocorrência    O(log n)
set<T>
O que é? Coleção de elementos únicos e ordenados.
Quando usar? Para manter uma lista de itens sem repetição e sempre em ordem, ou para remover de qualquer lugar.
Observação: para permitir duplicados, use multiset. ⚠️ Cuidado com erase em multisets.
cpp
set<int> s;                       // O(1)
s.insert(5);                      // Insere                   O(log n)
s.count(5);                       // Verifica se existe       O(log n)
s.find(5);                        // Encontra                 O(log n)
s.erase(5);                       // Remove                   O(log n)

multiset<int> ms;                 // O(1)
ms.insert(5);                     // O(log n)
ms.count(5);                      // O(log n + k)
ms.find(5);                       // O(log n)
ms.erase(ms.find(5));             // Remove só a 1ª ocorrência   O(log n)

⚠️ ms.erase(5) remove TODAS as ocorrências do valor 5. Para remover só uma, use ms.erase(ms.find(5)).

stack<T> / queue<T>
Stack: estrutura LIFO (Last-In, First-Out): o último a entrar é o primeiro a sair.
Queue (fila): estrutura FIFO (First-In, First-Out): o primeiro a entrar é o primeiro a sair.
Quando usar? Problemas que precisam de uma ordem específica de tratamento dos dados.
cpp
stack<int> st;      // Cria uma pilha            O(1)
st.push(5);         // Adiciona ao topo          O(1)
st.pop();           // Remove o topo             O(1)
st.top();           // Retorna o topo            O(1)

queue<int> q;       // Cria uma fila             O(1)
q.push(5);          // Adiciona ao final         O(1)
q.pop();            // Remove do início          O(1)
q.front();          // Retorna o início          O(1)
deque<T>
O que é? Uma fila de duas pontas: permite inserção e remoção na frente e no fundo em O(1).
Quando usar? Quando precisar alterar a frente e o fundo de forma rápida.
Observação: é possível acessar por índice em O(1).
cpp
deque<int> dq;          // O(1)
dq.push_back(5);        // Adiciona ao final      O(1)
dq.pop_front();         // Remove do início       O(1)
dq.front();             // Início                 O(1)
dq.push_front(10);      // Adiciona ao início     O(1)
dq.pop_back();          // Remove do final        O(1)
dq.back();              // Final                  O(1)
priority_queue<T>
O que é? Uma fila onde o elemento de maior prioridade (por padrão, o maior valor) fica sempre na frente.
Quando usar? Em algoritmos gulosos, como Dijkstra, ou quando precisar processar sempre o "melhor" item de uma coleção.
cpp
priority_queue<int> pq;                                      // max-heap     O(1)
priority_queue<int, vector<int>, greater<>> min_pq;          // min-heap     O(1)

pq.push(5);          // Adiciona                       O(log N)
pq.pop();            // Remove o de maior prioridade   O(log N)
pq.top();            // Retorna o de maior prioridade  O(1)
pair<T, T>
O que é? Um par de elementos de tipos arbitrários, com operadores de comparação já definidos.
Quando usar? Para unir dados dentro de outra estrutura, por exemplo informações que precisam ser ordenadas juntas.
cpp
pair<int, string> p;              // O(1)
p = {5, "C++"};                   // Inicializa
p.first = 10;                     // Acessa e modifica
p.second = "Lua";
auto [num, lang] = p;             // Desestrutura em duas variáveis
tuple<T, ...>
O que é? Uma tupla de N elementos de tipos arbitrários.
Quando usar? Para unir mais de 2 dados dentro de outra estrutura.
cpp
tuple<int, string, double> t;     // O(1)
t = {5, "C++", 3.14};             // Inicializa
get<0>(t) = 10;                   // Acessa e modifica
get<1>(t) = "Lua";
get<2>(t) = 2.71;
auto [num2, lang2, val] = t;      // Desestrutura em três variáveis
3.2 Algoritmos

Além dos containers, a maior força da STL está em sua vasta coleção de algoritmos prontos, eficientes e testados. Eles operam sobre sequências de dados, geralmente definidas por um par de iteradores, como v.begin() e v.end().

Visão geral:

cpp
sort(v.begin(), v.end());                    // O(N log N)
stable_sort(v.begin(), v.end());             // O(N log N)

v.erase(v.begin(), v.begin() + 3);           // O(N)
v.erase(unique(v.begin(), v.end()), v.end()); // O(N)

binary_search(v.begin(), v.end(), 20);       // O(log N)
lower_bound(v.begin(), v.end(), 20);         // O(log N)
upper_bound(v.begin(), v.end(), 20);         // O(log N)

accumulate(v.begin(), v.end(), 0LL);         // O(N)
reverse(v.begin(), v.end());                 // O(N)

min_element(v.begin(), v.end());             // O(N)
max_element(v.begin(), v.end());             // O(N)

next_permutation(v.begin(), v.end());        // O(N)
sort
O que faz? Ordena os elementos em uma faixa. Não garante estabilidade.
Complexidade: O(N log N). A versão estável (stable_sort) é O(N log² N), ou O(N log N) se houver memória extra disponível.
Observação: para ordenar ao contrário use rbegin() e rend(), ou passe uma função customizada como 3º argumento.
cpp
vector<int> v = {4, 2, 5, 2, 1};
sort(v.begin(), v.end());
// v agora é {1, 2, 2, 4, 5}

// Para ordenar em ordem decrescente:
sort(v.rbegin(), v.rend());

vector<pair<int,int>> arr;
arr = { {2, 4}, {2, 2}, {1, 3} };

// Ordenar somente pelo primeiro elemento do par
auto f = [](auto &a, auto &b) {
    return a.first < b.first;
};

stable_sort(arr.begin(), arr.end(), f);
// arr agora é { {1, 3}, {2, 4}, {2, 2} }   (a ordem relativa dos {2,...} foi mantida)
erase
O que faz? Método padrão para remover elementos da maioria dos containers (vector, string, map, set). Remove um elemento ou uma faixa.
Complexidade: O(N) em containers de acesso contíguo (vector); O(log N) em containers ordenados (set).
cpp
vector<int> v = {10, 20, 30, 40, 50};

// Remove o terceiro elemento (índice 2, valor 30)
v.erase(v.begin() + 2);                 // O(N)
// Agora v = {10, 20, 40, 50}

// Remove os elementos do índice 1 até antes do 3 (valores 20 e 40)
v.erase(v.begin() + 1, v.begin() + 3);  // O(N)
// Agora v = {10, 50}

O intervalo é [início, fim): o fim não é removido.

unique
O que faz? Remove elementos duplicados consecutivos. A faixa precisa estar ordenada.
Atenção: é preciso usar erase para de fato remover os extras. Sem isso, eles só vão para o final.
Complexidade: O(N).
cpp
vector<int> v = {1, 2, 2, 3, 3, 3, 2, 4, 4};

// Primeiro, ordene para agrupar os duplicados
sort(v.begin(), v.end());
// v = {1, 2, 2, 2, 3, 3, 3, 4, 4}

// Aplique o padrão erase-unique
v.erase(unique(v.begin(), v.end()), v.end());

// v agora é {1, 2, 3, 4}
Buscas binárias
Função	O que faz
binary_search	Verifica se um elemento existe na faixa (true/false)
lower_bound	Iterador para o primeiro elemento não menor que o valor (>=)
upper_bound	Iterador para o primeiro elemento maior que o valor (>)

Complexidade: O(log N). A faixa precisa estar ordenada.

cpp
// Já ordenado!
vector<int> v = {10, 20, 20, 30, 40};

bool existe = binary_search(v.begin(), v.end(), 20);
// existe = true

// Pega o índice do primeiro 20
auto it_lower = lower_bound(v.begin(), v.end(), 20);
int index = it_lower - v.begin();    // index = 1

// Pega o índice do elemento após o último 20
auto it_upper = upper_bound(v.begin(), v.end(), 20);

int count = it_upper - it_lower;
// count = 2 (existem dois '20')
accumulate
O que faz? Soma todos os elementos de uma faixa, partindo de um valor inicial.
Complexidade: O(N).
cpp
vector<int> v = {1, 2, 3, 4, 5};
ll soma = accumulate(v.begin(), v.end(), 0LL);
// soma = 15

// 0LL é importante para evitar overflow se a soma for grande!
reverse
O que faz? Inverte a ordem dos elementos.
Complexidade: O(N).
cpp
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end());
// v agora é {5, 4, 3, 2, 1}
min_element / max_element
O que fazem? Encontram o menor / maior elemento da faixa (retornam um iterador, por isso o *).
Complexidade: O(N).
cpp
vector<int> v = {3, 2, 7, 1, 8};
int mn = *min_element(v.begin(), v.end());   // 1
int mx = *max_element(v.begin(), v.end());   // 8
next_permutation
O que faz? Transforma uma sequência na sua próxima permutação lexicograficamente maior.
Retorna true se encontrou a próxima e false se a sequência já está na maior permutação possível (ex.: [3, 2, 1]).
Complexidade: O(N) por chamada, O(N!) no loop do-while.
cpp
vector<int> v = {1, 2, 3};
// 1. Garanta que o vetor esteja ordenado
sort(v.begin(), v.end());

// 2. Use o loop do-while para iterar por todas as permutações
do {
    for (auto e : v) cout << e << ' ';
    cout << endl;
} while (next_permutation(v.begin(), v.end()));
3.3 For loops (range-based)

Desde o C++11, existe uma forma mais simples e legível de percorrer um container. A forma como você declara a variável muda a eficiência e o que você pode fazer dentro do loop:

cpp
vector<int> v = {1, 2, 3};

// 1) Passa pelos elementos de uma CÓPIA de v
//    Não permite modificar v
//    O(N) da cópia + O(N) do loop
for (auto x : v) {
    cout << x << ' ';
} cout << endl;

// 2) Passa pelos elementos de v (referência)
//    Somente O(N) do loop
for (auto &x : v) {
    x *= 2;            // Permite modificação
}

// 3) Referência constante
//    Não permite modificar, mas evita a cópia
//    Somente O(N) do loop
for (auto const &x : v) {
    cout << x << ' ';
} cout << endl;
Forma	Copia?	Modifica v?
auto x : v	✅ sim	❌ não
auto &x : v	❌ não	✅ sim
auto const &x : v	❌ não	❌ não
4. Prefix Sum
4.1 Importância

Imagine um problema comum: você recebe um array com N números e depois Q consultas. Cada consulta dá um intervalo [L, R] e pede a soma de todos os elementos do índice L até R.

Exemplo: array = {2, 8, 3, 5, 1, 9}

Consulta 1: soma do intervalo [1, 3] → 8 + 3 + 5 = 16
Consulta 2: soma do intervalo [0, 2] → 2 + 8 + 3 = 13
4.2 Solução ingênua

Para cada consulta, percorrer o array de L até R somando:

cpp
// Para cada consulta [L, R]
long long soma = 0;
for (int i = L; i <= R; i++) {
    soma += array[i];
}

Análise: se N e Q chegam a 10⁵, a complexidade é O(N·Q) = 10⁵ × 10⁵ = 10¹⁰ operações. Lento demais!

4.3 Forma eficiente

A ideia da Soma de Prefixos é gastar um tempo inicial O(N) para pré-calcular as somas acumuladas até cada índice. Depois, qualquer consulta é respondida em O(1).

Passo 1: construir o array de prefix sum

psum[i] guarda a soma de todos os elementos do array original do índice 0 até i-1. Usamos tamanho N+1 (com psum[0] = 0) para simplificar a fórmula.

cpp
vector<int> v = {1, 5, 3, /* ... */};
// Tamanho N+1, inicializado com 0
vector<ll> psum(N + 1, 0);

for (int i = 0; i < N; i++) {
    psum[i + 1] = psum[i] + v[i];
}

Exemplo com v = {2, 8, 3, 5, 1, 9}:

índice:  0   1   2   3   4   5   6
psum:    0   2  10  13  18  19  28
Passo 2: responder consultas em O(1)

A soma do intervalo [L, R] (inclusivo) é:

soma(L, R) = psum[R+1] - psum[L]
cpp
for (int i = 0; i < Q; i++) {
    int l, r; cin >> l >> r;
    cout << psum[r+1] - psum[l] << endl;
}

Conferindo com o exemplo:

[1, 3] → psum[4] - psum[1] = 18 - 2 = 16 ✅
[0, 2] → psum[3] - psum[0] = 13 - 0 = 13 ✅
Por que funciona?
psum[R+1] é a soma de array[0] até array[R].
psum[L] é a soma de array[0] até array[L-1].

Subtraindo um do outro, sobram apenas os elementos de array[L] até array[R]:

[ 0 ... L-1 | L ... R | R+1 ... N-1 ]
  └─ psum[L] ─┘
  └────── psum[R+1] ──┘
                 soma(L,R) = psum[R+1] - psum[L]
Código completo
cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> v(n), psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        psum[i + 1] = psum[i] + v[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << psum[r + 1] - psum[l] << '\n';
    }
}
Análise final
Etapa	Complexidade
Pré-processamento	O(N)
Tempo por consulta	O(1)
Total	O(N + Q)

Para N, Q = 10⁵, são cerca de 2·10⁵ operações. Extremamente rápido!

5. Problemas clássicos
5.1 Subarray com soma K

Problema: queremos saber se existe algum subarray (trecho contínuo) com soma exatamente k. Os valores podem ser negativos (então Two Pointers não funciona aqui).

Exemplo: A = [3, -5, 2, 7, 8], k = 12 → o subarray [-5, 2, 7, 8] soma 12. ✅

Ideia

Usando prefix sum, a soma de [l, r] é ps[r] - ps[l-1].

O que acontece se fixarmos um r? Queremos achar um l tal que:

ps[l-1] = ps[r] - k          (0-indexado)
ou, em 1-indexado:  ps[l] = ps[r+1] - k

Ou seja: ver se algum prefixo anterior a r possui soma ps[r] - k. Basta guardar os prefixos já vistos em um set.

Pseudocódigo
subarrayK(A[0,n-1], ps[0,n], k) -> boolean:
  set = {0}
  for r = 0 to n-1 do
    target = ps[r+1] - k
    if target in set then
      return true
    set.add(ps[r+1])
  return false
Código em C++
cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool subarrayK(const vector<ll>& A, ll k) {
    int n = A.size();

    vector<ll> ps(n + 1, 0);                  // prefix sum
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + A[i];

    set<ll> vistos = {0};                     // prefixos já vistos (começa com ps[0] = 0)

    for (int r = 0; r < n; r++) {
        ll target = ps[r + 1] - k;
        if (vistos.count(target)) return true;   // existe l com ps[l] = ps[r+1] - k
        vistos.insert(ps[r + 1]);
    }
    return false;
}

int main() {
    vector<ll> A = {3, -5, 2, 7, 8};
    cout << (subarrayK(A, 12) ? "SIM" : "NAO") << "\n";   // SIM
    cout << (subarrayK(A, 100) ? "SIM" : "NAO") << "\n";  // NAO
}

Complexidade: O(n log n) usando set da STL. (Com unordered_set seria O(n) em média.)

5.2 Stack monotônica

Problema: dado um array, para cada elemento queremos saber qual é o elemento menor que ele mais próximo pela esquerda (ou -1 se não houver).

Exemplo:

Array: 3  5  2  7  8
Left: -1  3 -1  2  7
Ideia

Percorremos o array da esquerda para a direita mantendo uma stack (pilha) com candidatos. Para cada novo elemento A[i]:

Removemos do topo todos os elementos que não são menores que A[i]. Eles nunca mais serão úteis: A[i] é menor (ou igual) e está mais à direita.
Se a pilha ficou vazia → left[i] = -1. Senão → left[i] = topo.
Empilhamos A[i].

Passo a passo com [3, 5, 2, 7, 8]:

i	A[i]	Pilha antes	Remove	left[i]	Pilha depois
0	3	[]	—	-1	[3]
1	5	[3]	—	3	[3, 5]
2	2	[3, 5]	5, 3	-1	[2]
3	7	[2]	—	2	[2, 7]
4	8	[2, 7]	—	7	[2, 7, 8]

No passo i = 2: o 3 e o 5 não serão mais relevantes, porque o 2 sempre será menor e estará mais à direita.

A pilha fica sempre ordenada de forma crescente (do fundo para o topo) — daí o nome monotônica.

Código em C++
cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> smallestLeft(const vector<int>& A) {
    int n = A.size();
    vector<int> left(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {   // descarta quem não é menor que A[i]
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    return left;
}

int main() {
    vector<int> A = {3, 5, 2, 7, 8};
    for (int x : smallestLeft(A)) cout << x << ' ';   // -1 3 -1 2 7
    cout << '\n';
}
Complexidade?

O(n). Apesar do while dentro do for, cada elemento é empilhado uma vez e desempilhado no máximo uma vez. Logo, o total de operações do while, somado em todo o loop, é no máximo n. Isso se chama complexidade amortizada.

📝 Observações sobre os slides originais

Alguns detalhes dos slides foram ajustados neste README para evitar confusão:

Slide	Detalhe	O que está neste README
Reverse	Aparece reverse(v.begin(), v.end(), 0LL)	O correto é reverse(v.begin(), v.end()) (sem o 3º argumento)
multiset/multimap count	Slide indica O(log n * k)	A complexidade correta é O(log n + k)
Saídas	Imprime t dentro de while(t--)	Usei um contador caso separado
Memória	Loop com i <= n	Marcado como bug (índice fora do limite)
Soma recursiva	Sem caso base	Adicionei o caso base
Stack monotônica	Pseudocódigo usa A[i] < stack.top para desempilhar	Usei st.top() >= A[i], para tratar corretamente valores iguais ("estritamente menor")
🎯 Próximo passo

Fazer o Homework!

Material de apoio da Maratona CIn · Aula 1 — Warmup + STL e Complexidade.