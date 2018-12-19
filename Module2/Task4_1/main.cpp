#include <iostream>
#include <queue>


template<class T>
class AvlTree{
public:
    AvlTree()= default;;
    ~AvlTree();
    AvlTree(const AvlTree &other) = delete;
    AvlTree &operator=(const AvlTree &other) = delete;
    AvlTree(AvlTree &&other) = delete;
    AvlTree &operator=(AvlTree &&other) = delete;
    void del(const T& value);
    void add(const T& key);
    size_t addSoldier(const T& key);
    void delSoldier(const size_t & position);


private:
    struct Node{
        T key;
        size_t height = 1;
        Node *left = nullptr;
        Node *right = nullptr;
        size_t position = 0;
        size_t count = 1;
        explicit Node(const T & v): key(v){};
    };
    Node * root = nullptr;
    size_t height(Node* p);
    int bfactor(Node* p);
    void fixheight(Node* p);
    Node* rotateright(Node* p);
    Node* rotateleft(Node* q);
    Node* balance(Node* p);
    Node* insert(Node* p,const T& k); // вставка ключа k в дерево с корнем p
    Node* remove(Node* p, const T& key); // удаление ключа k из дерева p
    Node* findAndDeleteMinRight(Node *& tree, Node *& minNode);
    Node* findAndDeleteMaxLeft(Node *& tree, Node *& maxNode);
    T findByPosition(const size_t & position);
    void countNodes(Node *p);
    size_t calculatePosition(const T& key);
    size_t getLeftNodeCount(Node* node);
    size_t getRightNodeCount(Node* node);




};

template <class T>
void AvlTree<T>::countNodes(AvlTree<T>::Node *p) {
    p->count = 1;
    if(p->right) p->count += p->right->count;
    if(p->left) p->count += p->left->count;
}

template <class T>
T AvlTree<T>::findByPosition(const size_t &position) {
    size_t maxIndex = root->count - 1;
    size_t nodePosition = maxIndex - getLeftNodeCount(root);
    Node * current = root;
    Node * parent = nullptr;
    while(current){
        if(nodePosition < position){
            parent = current;
            current = current->left;
            nodePosition = maxIndex - getLeftNodeCount(current);
        }else if (nodePosition > position){
            parent = current;
            current = current->right;
            nodePosition = maxIndex -  (getLeftNodeCount(parent) + 1  + getLeftNodeCount(current));
        }else{
            return current->key;
        }
    }
}



template <class T>
void AvlTree<T>::delSoldier(const size_t &position) {
    T key = findByPosition(position);
    root = remove(root, key);
}


template <class T>
size_t AvlTree<T>::addSoldier(const T &key) {
    root = insert(root, key);
    return calculatePosition(key);
}

template <class T>
size_t AvlTree<T>::getLeftNodeCount(AvlTree<T>::Node *node) {
    return node->left == nullptr? 0 : node->left->count;
}
template <class T>
size_t AvlTree<T>::getRightNodeCount(AvlTree<T>::Node *node) {
    return node->right == nullptr? 0 : node->right->count;
}

template <class T>
size_t AvlTree<T>::calculatePosition(const T &key) {
    Node * current = root;
    Node * parent = nullptr;
    size_t maxIndex = root->count - 1;
    if(root->key < key){
        while(current){
            if(current->key > key){
                parent = current;
                current = current->left;
            }else if(current->key < key){
                parent = current;
                current = current->right;
            }else{
                if(parent == nullptr){
                    return maxIndex - getLeftNodeCount(current);
                }else{
                    if(parent->right == current){
                        return maxIndex -  (getLeftNodeCount(parent)+1  + getLeftNodeCount(current));
                    }
                    if(parent->left == current){
                        return maxIndex - getLeftNodeCount(current);
                    }
                }

            }
        }
    } else {
        while(current){
            if(current->key > key){
                parent = current;
                current = current->left;
            }else if(current->key < key){
                parent = current;
                current = current->right;
            }else{
                if(parent == nullptr){
                    return  getLeftNodeCount(current);
                }else{
                    if(parent->right == current){
                        return getRightNodeCount(current);
                    }
                    if(parent->left == current){
                        return (getRightNodeCount(parent)+1  + getRightNodeCount(current));
                    }
                }

            }
        }
    }

}




template <class T>
AvlTree<T>::~AvlTree() {
    std::queue<Node *> delQueue;
    delQueue.push(root);
    while(!delQueue.empty()){
        Node * node = delQueue.front();
        if(node->left){
            delQueue.push(node->left);
        }
        if(node->right ){
            delQueue.push(node->right);
        }
        delete node;
        delQueue.pop();
    }
}



template <class T>
typename AvlTree<T>::Node * AvlTree<T>::findAndDeleteMinRight(AvlTree<T>::Node *&tree, AvlTree<T>::Node *& minNode) {
    if(tree->left == nullptr){
        minNode = tree;
        return tree->right;
    }
    tree->left = findAndDeleteMinRight(tree->left, minNode);
    return balance(tree);
}

template <class T>
typename AvlTree<T>::Node * AvlTree<T>::findAndDeleteMaxLeft(AvlTree<T>::Node *&tree, AvlTree<T>::Node *&maxNode) {
    if(tree->right == nullptr){
        maxNode = tree;
        return tree->left;
    }
    tree->right = findAndDeleteMaxLeft(tree->right, maxNode);
    return balance(tree);
}

template<class T>
void AvlTree<T>::del(const T& value) {
    root = remove(root, value);
}

template <class T>
typename AvlTree<T>::Node * AvlTree<T>::remove(AvlTree<T>::Node *p, const T &key) {
    if (root == nullptr){
        return nullptr;
    }
    if (p->key > key){
        p->left = remove(p->left, key);
    } else if (p->key < key){
        p->right = remove(p->right, key);
    }else{
        Node* right = p->right;
        Node* left = p->left;
        int balanceFactor = bfactor(p);
        delete p;

        if(right == nullptr){
            return left;
        }
        if(left == nullptr){
            return right;
        }

        Node * changeNode = nullptr;

        if (balanceFactor >= 0){
            Node * newRightTree = findAndDeleteMinRight(right, changeNode);
            changeNode->right = newRightTree;
            changeNode->left = left;

        }
        if(balanceFactor == -1){
            Node * newLeftTree = findAndDeleteMaxLeft(left, changeNode);
            changeNode->left = newLeftTree;
            changeNode->right = right;
        }
        return balance(changeNode);
    }
    return balance(p);

}

template<class T>
typename AvlTree<T>::Node * AvlTree<T>::insert(AvlTree<T>::Node *p,const T& k) {

    if( !p ) return new Node(k);
    if( k<p->key )
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);

}

template <class T>
void AvlTree<T>::add(const T &key) {
    root = insert(root, key);

}

template <class T>
size_t AvlTree<T>::height(AvlTree<T>::Node *n) {

    return n?n->height:0;

}

template<class T>
int AvlTree<T>::bfactor(AvlTree<T>::Node *p) {

    return (int) height(p->right) - (int) height(p->left);

}

template <class T>
void AvlTree<T>::fixheight(AvlTree<T>::Node *p) {
    size_t hl = height(p->left);
    size_t hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
    countNodes(p);
}

template <class T>
typename AvlTree<T>::Node * AvlTree<T>::rotateright(AvlTree<T>::Node *p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

template <class T>
typename AvlTree<T>::Node * AvlTree<T>::rotateleft(Node *q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}


template  <class T>
typename AvlTree<T>::Node * AvlTree<T>::balance(AvlTree<T>::Node *p) {
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}


int main() {
    AvlTree<int> tree;
    int n;
    std::cin>>n;
    int k;
    int func;
    for(size_t i=0;i<n;i++){
        std::cin>>func;
        std::cin>>k;
        if(func == 1){
            std::cout<<tree.addSoldier(k)<<std::endl;
        }
        if(func == 2){
            tree.delSoldier((size_t)k);
        }

    }
    return 0;
}