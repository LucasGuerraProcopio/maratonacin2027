#include <iostream>
#include <string>
#include <queue>
using namespace std;

// ---------- Nó da árvore ----------
template <typename Key, typename E>
class BSTNode {
public:
    Key key;           // chave usada nas comparações
    E element;         // conteúdo associado à chave
    BSTNode* left;     // filho esquerdo
    BSTNode* right;    // filho direito

    BSTNode(const Key& k, const E& e)
        : key(k), element(e), left(nullptr), right(nullptr) {}
};

// ---------- Árvore binária de busca (dicionário) ----------
template <typename Key, typename E>
class BST {
private:
    using Node = BSTNode<Key, E>;
    Node* root;
    int nodecount;

    // --- busca ---
    E* findhelp(Node* rt, const Key& k) {
        if (rt == nullptr) return nullptr;
        if (rt->key > k)       return findhelp(rt->left, k);
        else if (rt->key == k) return &(rt->element);
        else                   return findhelp(rt->right, k);
    }

    // --- inserção ---
    Node* inserthelp(Node* rt, const Key& k, const E& e) {
        if (rt == nullptr) return new Node(k, e);
        if (rt->key > k) rt->left  = inserthelp(rt->left, k, e);
        else             rt->right = inserthelp(rt->right, k, e);
        return rt;
    }

    // --- remoção ---
    Node* getmin(Node* rt) {
        if (rt->left == nullptr) return rt;
        return getmin(rt->left);
    }

    Node* deletemin(Node* rt) {
        if (rt->left == nullptr) {
            Node* dir = rt->right;
            delete rt;
            return dir;
        }
        rt->left = deletemin(rt->left);
        return rt;
    }

    Node* removehelp(Node* rt, const Key& k) {
        if (rt == nullptr) return nullptr;
        if (rt->key > k) {
            rt->left = removehelp(rt->left, k);
        } else if (rt->key < k) {
            rt->right = removehelp(rt->right, k);
        } else {
            if (rt->left == nullptr) {
                Node* dir = rt->right;
                delete rt;
                return dir;
            } else if (rt->right == nullptr) {
                Node* esq = rt->left;
                delete rt;
                return esq;
            } else {
                Node* temp = getmin(rt->right);
                rt->element = temp->element;
                rt->key = temp->key;
                rt->right = deletemin(rt->right);
            }
        }
        return rt;
    }

    // --- travessias ---
    void preorderhelp(Node* rt) {
        if (rt != nullptr) {
            cout << rt->key << " ";
            preorderhelp(rt->left);
            preorderhelp(rt->right);
        }
    }

    void inorderhelp(Node* rt) {
        if (rt != nullptr) {
            inorderhelp(rt->left);
            cout << rt->key << " ";
            inorderhelp(rt->right);
        }
    }

    void posorderhelp(Node* rt) {
        if (rt != nullptr) {
            posorderhelp(rt->left);
            posorderhelp(rt->right);
            cout << rt->key << " ";
        }
    }

    // --- altura e liberação de memória ---
    int heighthelp(Node* rt) {
        if (rt == nullptr) return -1;
        int he = heighthelp(rt->left);
        int hd = heighthelp(rt->right);
        return 1 + (he > hd ? he : hd);
    }

    void clearhelp(Node* rt) {
        if (rt == nullptr) return;
        clearhelp(rt->left);
        clearhelp(rt->right);
        delete rt;
    }

public:
    BST() : root(nullptr), nodecount(0) {}
    ~BST() { clearhelp(root); }

    // Proíbe cópia: dois objetos apontando para os mesmos nós
    // tentariam apagá-los duas vezes.
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    E* find(const Key& k) { return findhelp(root, k); }

    void insert(const Key& k, const E& e) {
        root = inserthelp(root, k, e);
        nodecount++;
    }

    bool remove(const Key& k) {
        if (findhelp(root, k) == nullptr) return false;
        root = removehelp(root, k);
        nodecount--;
        return true;
    }

    int size() const { return nodecount; }
    int height() { return heighthelp(root); }

    void preorder() { preorderhelp(root); cout << endl; }
    void inorder()  { inorderhelp(root);  cout << endl; }
    void posorder() { posorderhelp(root); cout << endl; }

    void levelorder() {
        if (root == nullptr) { cout << endl; return; }
        queue<Node*> fila;
        fila.push(root);
        while (!fila.empty()) {
            Node* atual = fila.front();
            fila.pop();
            cout << atual->key << " ";
            if (atual->left  != nullptr) fila.push(atual->left);
            if (atual->right != nullptr) fila.push(atual->right);
        }
        cout << endl;
    }
};