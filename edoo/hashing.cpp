#include <functional>
#include <iostream>
#include <string>
#include <vector>

// Resto matemático (o mesmo da seção 3)
int modPositivo(int a, int m) {
    int r = a % m;
    return (r < 0) ? r + m : r;
}

enum class Estado { VAZIA, OCUPADA, REMOVIDA };

template <typename K, typename V>
class DicionarioFechado {
private:
    struct Celula {
        Estado estado = Estado::VAZIA;
        K chave{};
        V valor{};
    };

    int m;                                 // tamanho da tabela
    int cnt;                               // número de elementos
    std::vector<Celula> H;                 // a tabela
    std::function<int(const K&)> h;        // função hash: Key -> 0..m-1
    std::function<int(const K&, int)> p;   // função de sondagem p(K, i)

    // posição da i-ésima tentativa (i = 0 é a posição original)
    int posicao(const K& chave, int i) const {
        return (h(chave) + p(chave, i)) % m;
    }

public:
    DicionarioFechado(int tamanho,
        std::function<int(const K&)> funcaoHash,
        std::function<int(const K&, int)> sondagem)
        : m(tamanho), cnt(0), H(tamanho), h(funcaoHash), p(sondagem) {}

    // find
    V* buscar(const K& chave) {
        for (int i = 0; i < m; i++) {                 // no máximo m tentativas
            Celula& c = H[posicao(chave, i)];
            if (c.estado == Estado::VAZIA) return nullptr;   // fim do caminho
            if (c.estado == Estado::OCUPADA && c.chave == chave) return &c.valor;
            // REMOVIDA, ou ocupada por outra chave: continua procurando
        }
        return nullptr;
    }

    // insert: false se a tabela está cheia ou a chave já existe
    bool inserir(const K& chave, const V& valor) {
        if (cnt >= m) return false;                   // size(d) < d.m
        if (buscar(chave) != nullptr) return false;   // find(d, k) = NULL
        for (int i = 0; i < m; i++) {
            Celula& c = H[posicao(chave, i)];
            if (c.estado != Estado::OCUPADA) {        // VAZIA ou REMOVIDA
                c.estado = Estado::OCUPADA;
                c.chave = chave;
                c.valor = valor;
                cnt++;
                return true;
            }
        }
        return false;
    }

    // remove: não esvazia a célula, marca como REMOVIDA
    bool remover(const K& chave) {
        for (int i = 0; i < m; i++) {
            Celula& c = H[posicao(chave, i)];
            if (c.estado == Estado::VAZIA) return false;
            if (c.estado == Estado::OCUPADA && c.chave == chave) {
                c.estado = Estado::REMOVIDA;
                cnt--;
                return true;
            }
        }
        return false;
    }

    int tamanho() const { return cnt; }

    void limpar() {
        for (Celula& c : H) c.estado = Estado::VAZIA;
        cnt = 0;
    }

    void imprimir() const {
        for (int i = 0; i < m; i++) {
            std::cout << i << ": ";
            if (H[i].estado == Estado::OCUPADA) std::cout << H[i].chave;
            else if (H[i].estado == Estado::REMOVIDA) std::cout << "(removida)";
            std::cout << std::endl;
        }
    }
};

void testar(const std::string& titulo, DicionarioFechado<int, int>& d,
            const std::vector<int>& valores) {
    for (int v : valores) d.inserir(v, v);
    std::cout << titulo << std::endl;
    d.imprimir();
    std::cout << std::endl;
}

int main() {
    const int m = 8;
    std::vector<int> valores = {2, 4, 8, 16, 32, -12};

    // h(k) = k - 8 * floor(k/8): o resto matemático
    auto h = [m](const int& k) { return modPositivo(k, m); };

    // 1) linear: p(K, i) = i
    auto linear = [](const int&, int i) { return i; };

    // 2) pseudoaleatória: p(K, i) = Perm[i-1]
    std::vector<int> perm = {2, 6, 7, 3, 1, 4, 5};
    auto pseudo = [perm](const int&, int i) { return i == 0 ? 0 : perm[i - 1]; };

    // 3) quadrática: p(K, i) = (i*i + i) / 2
    auto quadratica = [](const int&, int i) { return (i * i + i) / 2; };

    DicionarioFechado<int, int> d1(m, h, linear);
    DicionarioFechado<int, int> d2(m, h, pseudo);
    DicionarioFechado<int, int> d3(m, h, quadratica);
    testar("Linear", d1, valores);
    testar("Pseudoaleatoria", d2, valores);
    testar("Quadratica", d3, valores);

    // 4) duplo hashing (m = 7, primo): p(K, i) = i * s(K), s(K) = 1 + K mod 6
    const int m7 = 7;
    auto h7 = [m7](const int& k) { return modPositivo(k, m7); };
    auto duplo = [m7](const int& k, int i) {
        return i * (1 + modPositivo(k, m7 - 1));
    };
    DicionarioFechado<int, int> d4(m7, h7, duplo);
    testar("Duplo hashing", d4, {10, 3, 17, 24});
}