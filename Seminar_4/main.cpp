#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cin;
using std::string;
template <class T>

struct HashTableNode{
    T Data;
    HashTableNode<T> * Next;

    HashTableNode(): Next(nullptr){}
    HashTableNode(const T& data, HashTableNode<T> *  next): Data(data), Next(next){}
};
const int DefaultTableSize=8;
const int GrowFactor = 2;

const int MaxAlpha = 3;
int Hash(const string& data, int tableSize){
    int hash=0;
    for (size_t i = 0; i < data.size();i++){
        hash = (hash*127+data[i]) % tableSize;
    }
    return hash;
}


template <class T>
class HashTable {
public:
    HashTable();
    HashTable(const HashTable<T>& table) = delete;
    ~HashTable();
    HashTable<T>& operator = (const HashTable<T>& table) = delete;
    HashTable<T>& operator = (const HashTable<T>&& table) = delete;

    bool Has(const T &data) const;//const - не меняет полей класса
    bool Add(const T &data);
    bool Delete(const T &data);
private:
    vector<HashTableNode<T>*> table;
    int keysCount;
    void growTable();
};
template <class T>
HashTable<T>::HashTable():keysCount(0){
    table.resize(DefaultTableSize);
}
template <class T>
HashTable<T>::~HashTable(){
    assert(false);
}

template <class T>
bool HashTable<T>::Has(const T &data) const//const - не меняет полей класса
{
    int hash = Hash(data, table.size());
    HashTableNode<T>* node = table[hash];
    while(node != nullptr && node->Data != data){
        node = node->Next;
    }
    return node != nullptr;
}
template <class T>
bool HashTable<T>::Add(const T &data){
    if( Has(data)){//можно передавать значение хэш функции для того чтобы не использовать функцию хэш 2 раза(это плохо)
        return false;
    }
    if (keysCount + 1 > table.size()* MaxAlpha){
        growTable();
    }
    int hash = Hash(data, table.size());
    table[hash] = new HashTableNode<T> (data, table[hash]);
    keysCount++;
    return true;
}
//template <class T>
//HashTable<T>::~HashTable() {
//    for(int i = 0;i < table.size();i++){
//        HashTableNode<T>* node = table[i];
//        while(node!= nullptr){
//            HashTableNode<T>* nextNode = node->Next;
//            int newHash = Hash((node->Data, newTable.size()));
//            node->Next = newTable[newHash];
//            newTable[newHash] = node;
//            node = nextNode;
//        }
//    }
//}

template <class T>
bool HashTable<T>::Delete(const T &data){
    int hash = Hash(data, table.size());
    HashTableNode<T>* prevNode = nullptr;
    HashTableNode<T>* node = table[hash];
    while(node != nullptr && node->Data != data){
        prevNode = node;
        node = node->Next;
    }
    if(node == nullptr) return false;
    if (prevNode == nullptr) {
        table[hash] = node->Next;
    }else{
        prevNode-> Next = node->Next;
    }
    delete node;
}

template <class T>
void HashTable<T>::growTable(){
    vector<HashTable<T>*> newTable(table.size()*GrowFactor, nullptr);
    for(int i = 0;i < table.size();i++){
        HashTableNode<T>* node = table[i];
        while(node!= nullptr){
           HashTableNode<T>* nextNode = node->Next;
           int newHash = Hash(node->Data, newTable.size());
           node->Next = newTable[newHash];
           newTable[newHash] = node;
           node = nextNode;
        }
    }
    table = newTable;
}

int main() {
    HashTable<string> table;
    char operation = 0;
    string data;
    while(cin>> operation >> data){
        if (operation == '+'){
            std::cout << (table.Add(data) ? "OK" :"Fail") << std::endl;
        }
        if (operation == '-'){
            std::cout << (table.Delete(data) ? "OK" :"Fail") <<"\n";
        }
        if (operation == '?'){
            std::cout << (table.Has(data) ? "OK" :"Fail") <<"\n";
        }

    }
    return 0;
}