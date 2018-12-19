#include <iostream>
#include <queue>
#include <cassert>

template <class T>
class BinTree{
public:
    BinTree() = default;
    ~BinTree();
    BinTree(const  BinTree  & data) =  delete;
    BinTree& operator= (const BinTree & elem) = delete;
    BinTree(const BinTree && elem) = delete;
    BinTree& operator= (BinTree && elem) = delete;

    void add(const T & elem);
    std::queue<T> popAll();
    size_t widestLayer();
private:
    struct BinNode{
        explicit BinNode(const T & elem):data(elem){};
        T data;
        BinNode * left = nullptr;
        BinNode * right = nullptr;



    };
    BinNode * root = nullptr;
};

template  <class T>
size_t BinTree<T>::widestLayer() {
    assert(root != nullptr);
    std::queue<BinNode *> binTreeQueue;
    binTreeQueue.push(root);
    size_t widestCount = 1;
    while(!binTreeQueue.empty()){
        size_t binTreeCurrentSize = binTreeQueue.size();
        for(size_t i = 0;i < binTreeCurrentSize;i++){
            BinNode * node = binTreeQueue.front();
            binTreeQueue.pop();
            if(node->left){
                binTreeQueue.push(node->left);
            }
            if(node->right ){
                binTreeQueue.push(node->right);
            }
        }
        if(binTreeQueue.size() > widestCount){
            widestCount = binTreeQueue.size();
        }
    }
    return widestCount;
}

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

template <class T, class K>
class Treap {
public:
    Treap() = default;
    ~Treap();
    Treap(const Treap &data) = delete;
    Treap &operator=(const Treap &elem) = delete;
    Treap(const Treap &&elem) = delete;
    Treap &operator=(Treap &&elem) = delete;
    void add(const T &value, const K &priority);
    size_t widestLayer();
    std::queue<T> popAll();


private:
    struct BinNode {
        BinNode(const T &elem, const K &prior) : data(elem), priority(prior) {};
        T data;
        K priority;
        BinNode *left = nullptr;
        BinNode *right = nullptr;
    };

    BinNode *root = nullptr;

    void split(BinNode *currentNode, T data, BinNode *&left, BinNode *&right);
};

template <class T, class K>
void Treap<T,K>::split(Treap<T, K>::BinNode *currentNode, T data, Treap<T, K>::BinNode *&left,
                       Treap<T, K>::BinNode *&right) {
    if(currentNode == nullptr){
        left = nullptr;
        right = nullptr;
    } else if (currentNode->data <= data){
        split(currentNode->right, data, currentNode->right, right);
        left = currentNode;
    } else{
        split(currentNode->left, data, left, currentNode->left);
        right = currentNode;
    }
}

template <class T, class K>
void Treap<T, K>::add(const T &value, const K &priority) {
    BinNode * insertNode = new BinNode(value, priority);
    if(!root){
        root = insertNode;
        return;
    }

    BinNode * currentNode = root;
    BinNode * previousNode = nullptr;
    while(currentNode->priority > priority ){
        previousNode = currentNode;
        if( currentNode->data <= value){
            currentNode = currentNode->right;
        }else {
            currentNode = currentNode->left;
        }
        if(!currentNode){
            break;
        }
    }

//    if(root->priority < priority){
//        if(insertNode->data <= root->data ){
//            insertNode->right = root;
//        } else{
//            insertNode->left = root;
//        }
//        root = insertNode;
//        return;
//    }
//    if(!currentNode){
//        if(previousNode->data <= value){
//            previousNode->right = insertNode;
//        } else{
//            previousNode->left = insertNode;
//        }
//        return;
//    }
    BinNode * left = nullptr;
    BinNode * right = nullptr;
    split(currentNode, value, left, right);
    if(previousNode){
        if(previousNode->data <= value){
            previousNode->right = insertNode;
        }else{
            previousNode->left = insertNode;
        }

    } else{
       root = insertNode;
    }
    insertNode->left = left;
    insertNode->right = right;



}




template  <class T, class K>
size_t Treap<T, K>::widestLayer()  {
    assert(root != nullptr);
    std::queue<BinNode *> binTreeQueue;
    binTreeQueue.push(root);
    size_t widestCount = 1;
    while(!binTreeQueue.empty()){
        size_t binTreeCurrentSize = binTreeQueue.size();
        for(size_t i = 0;i < binTreeCurrentSize;i++) {
            BinNode * node = binTreeQueue.front();
            binTreeQueue.pop();
            if (node->left) {
                binTreeQueue.push(node->left);
            }
            if (node->right) {
                binTreeQueue.push(node->right);
            }
        }
        if (binTreeQueue.size() > widestCount) {
            widestCount = binTreeQueue.size();
        }
    }
    return widestCount;
}

//template <class T, class K>
//Treap<T,K>::BinNode * Treap<T,K>::merge(Treap<T, K>::BinNode *left, Treap<T, K>::BinNode *right) {
//    if (left == nullptr || right == nullptr){
//        return left == nullptr ? right : left;
//    }
//    if (left->priority > right->priority){
//        left->right = merge(left->right, right);
//        return left;
//    }
//    right->left = merge(left, right->left);
//    return right;
//}

template <class T, class K>
Treap<T,K>::~Treap() {
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

template <class T, class K>
std::queue<T> Treap<T, K>::popAll() {
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
       std::cout<<"( "<<node->data<<", "<<node->priority<<" )"<<std::endl;
        if(node->left){
            binTreeQueue.push(node->left);
        }
        if(node->right ){
            binTreeQueue.push(node->right);
        }
    }
    return resultQueue;
}

int main() {
    size_t count = 0;
    std::cin>> count;
    BinTree<int> tree;
    Treap<int, int > treapTree;
    int elem = 0;
    int priority = 0;
    for(size_t i =0;i<count;i++){
        std::cin >> elem;
        std::cin >> priority;
        treapTree.add(elem, priority);
        tree.add(elem);
    }
    int countTreap = (int) treapTree.widestLayer();
    int countTree = (int) tree.widestLayer();
//
//    std::cout<<   countTree <<std::endl;
    std::cout<<    countTreap - countTree <<std::endl;
//    std::queue<int> elemQueue = tree.popAll();
//    while(!elemQueue.empty()){
//        std::cout<<elemQueue.front()<<' ';
//        elemQueue.pop();
//    }
//    std::cout<<std::endl;
//    std::cout<<   countTree <<std::endl;
//    std::cout<<   countTreap <<std::endl;
    std::queue<int> elemQueueTreap = treapTree.popAll();
//    while(!elemQueueTreap.empty()){
//        std::cout<<elemQueueTreap.front()<<' ';
//        elemQueueTreap.pop();
//    }

    return 0;
}