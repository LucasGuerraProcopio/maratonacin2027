#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <typename Key, typename value>
class BSTno{
    public:
        Key chave;
        value valor;
        BSTno* esquerda;
        BSTno* direita;

        BSTno(const Key& k, const value& v) : chave(k), valor(v), esquerda(nullptr), direita(nullptr) {} 
};

template <typename Key, typename value>
class BST{
    private:
        using Node = BSTno<Key, value>;
        Node* root;
        int total;

        Node* insere(Node* raiz, const Key& novo, const value& v){
            if(raiz == nullptr){return new Node(novo, v);}
            if(raiz->chave > novo){raiz->esquerda = insere(raiz->esquerda, novo, v);}
            else{raiz->direita = insere(raiz->direita, novo, v);}
            return raiz;
        };

        void preorder(Node* raiz){
            if(raiz != nullptr){
                cout << " " << raiz->chave;
                preorder(raiz->esquerda);
                preorder(raiz->direita);
            }
        };

        void inorder(Node* raiz){
            if(raiz != nullptr){
                inorder(raiz->esquerda);
                cout << " " << raiz->chave;
                inorder(raiz->direita);
            }
        };

        void posorder(Node* raiz){
            if(raiz != nullptr){
                posorder(raiz->esquerda);
                posorder(raiz->direita);
                cout << " " << raiz->chave;
            }
        };

    public:

        BST() : root(nullptr), total(0) {};

        void inseridor(const Key& nova, const value& v){
            root = insere(root, nova, v);
            total++;
        }

        void chamapre(){
            cout << "Pre order :";
            preorder(root);
            cout << "\n";
        }

        void chamain(){
            cout << "In order  :";
            inorder(root);
            cout << "\n";
        }

        void chamapos(){
            cout << "Post order:";
            posorder(root);
            cout << "\n";
        };
};


int main(){
    
    int n; cin >> n;
    BST<int, int> arvore;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        arvore.inseridor(a, 0);
    };

    arvore.chamapre();
    arvore.chamain();
    arvore.chamapos();

    return 0;
}