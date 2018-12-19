#include <iostream>
#include <queue>
#include <vector>

/*
Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
Требуется построить бинарное дерево, заданное наивным порядком вставки.
Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K,
то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
Рекурсия запрещена.

 2_4. Выведите элементы в порядке level-order (по слоям, “в ширину”).
 */


template <class T>
class BinTree{
public:
    BinTree() = default;
    ~BinTree() ;
    BinTree(const  BinTree  & data) =  delete;
    BinTree& operator= (const BinTree & elem) = delete;
    BinTree(const BinTree && elem) = delete;
    BinTree& operator= (BinTree && elem) = delete;

    void add(const T & elem);
    std::queue<T> popAll();
private:
    struct BinNode{
        BinNode(const T & elem):data(elem){};
        T data;
        BinNode * left = nullptr;
        BinNode * right = nullptr;



    };
    BinNode * root = nullptr;
};


template  <class T>
void BinTree<T>::add(const T &elem) {
    if(root == nullptr){
        root = new BinNode(elem);
    } else{
        BinNode *  treeNode = root;
        while(true){
            if(treeNode -> data <= elem){
                if(treeNode->right == nullptr){
                    treeNode -> right =  new BinNode(elem);
                    break;
                }
                treeNode = treeNode -> right;
            }else{
                if(treeNode->left == nullptr){

                    treeNode -> left =  new BinNode(elem);
                    break;
                }
                treeNode = treeNode -> left;
            }
        }
    }
}

template <class T>
std::queue<T> BinTree<T>::popAll() {
    std::queue<T> resultQueue;
    if (!root){
        return resultQueue;
    }
    std::queue<BinNode *> binTreeQueue;
    binTreeQueue.push(root);
    while(!binTreeQueue.empty()){
        BinNode * node = binTreeQueue.front();
        binTreeQueue.pop();
        resultQueue.push(node->data);
        if(node->left){
            binTreeQueue.push(node->left);
        }
        if(node->right ){
            binTreeQueue.push(node->right);
        }
    }
    return resultQueue;
}

template <class T>
BinTree<T>::~BinTree(){
    std::queue<BinNode *> delQueue;
    delQueue.push(root);
    while(!delQueue.empty()){
        BinNode * node = delQueue.front();
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

int main() {
    size_t count = 0;
    std::cin>> count;
    BinTree<int> tree;
    int elem = 0;
    for(size_t i =0;i<count;i++){
        std::cin >> elem;
        tree.add(elem);
    }
    std::queue<int> elemQueue = tree.popAll();
    while(!elemQueue.empty()){
        std::cout<<elemQueue.front()<<' ';
        elemQueue.pop();
    }
    return 0;
}