#include <iostream>
#include <vector>
#include <assert.h>
/*
 * Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией.
 * Хранимые строки непустые и состоят из строчных латинских букв.
 * Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
 * Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае,
 * когда коэффициент заполнения таблицы достигает 3/4.
 * Структура данных должна поддерживать операции добавления строки в множество,
 * удаления строки из множества и проверки принадлежности данной строки множеству.
 *
 * ----------------------------------------------------------------
 *
    1_2. Для разрешения коллизий используйте двойное хеширование.
 */


using std::string;
using std::vector;

size_t HashWithCollision(const string& str, size_t hash, size_t probIndex, size_t hashTableSize){
    size_t h = (2 * str.size() - 1) %   hashTableSize;
    return (hash + h * probIndex) % hashTableSize;
}

size_t Hash(const string & str, size_t hashTableSize){
    size_t hash = 0;
    for(size_t i = 0;i< str.size();i++){
        hash = (hash * 307 + str[i]) % hashTableSize;
    }
    return hash;
}

const size_t DefaultSize = 8;
const size_t GrowFactor = 2;
const float Alpha = (float) 3/4;
template <class T>
class HashTable{
public:
    HashTable(const T & Empty, const  T & Del);
    ~HashTable();
    HashTable(const HashTable<T>& table) = delete;
    HashTable<T>& operator = (const HashTable<T>& table) = delete;
    HashTable<T>& operator = (const HashTable<T>&& table) = delete;
    HashTable(const HashTable<T>&& table) = delete;
    bool Has(const T &key) const;
    bool Add(const T &key);
    bool Delete(const T &key);
private:
    vector<T> table;
    size_t keysCount;
    void growTable();
    T EmptyValue ;
    T DelValue;
};

template <class T>
HashTable<T>::HashTable(const T & Empty,const T & Del): EmptyValue(Empty),DelValue(Del), keysCount(0) {
    table.resize(DefaultSize);
    for(size_t i = 0;i < DefaultSize; i++){
        table[i] = Empty;
    }

}
template <class T>
HashTable<T>::~HashTable(){}

template <class T>
bool HashTable<T>::Has(const T &key) const {
    size_t hash = Hash(key, table.size());
    if(key == table[hash]) return true;
    for(size_t i = 1; i < table.size();i++){
        size_t prob = HashWithCollision(key, hash, i, table.size());
        if(table[prob] == key){
            return true;
        }
        if(table[prob] == EmptyValue){
            return false;
        }
    }
    return false;
}

template <class T>
bool HashTable<T>::Delete(const T &key) {
    size_t hash = Hash(key, table.size());
    if(table[hash] == key){
        keysCount--;
        table[hash] = DelValue;
        return true;
    }
    for(size_t i = 1; i < table.size();i++){
        size_t prob = HashWithCollision(key, hash, i, table.size());
        if(table[prob] == key){
            table[prob] = DelValue;
            keysCount--;
            return true;
        }
        if(table[prob] == EmptyValue){
            return false;
        }
    }
    return false;
}

template <class T>
void HashTable<T>::growTable() {
    vector<T> newTable(table.size()*GrowFactor, EmptyValue );
    for(size_t i = 0; i < table.size(); i++){
        size_t hash = Hash(table[i], newTable.size());
        if(newTable[hash] == EmptyValue){
            newTable[hash] = table[i];
//            break;
        } else {
            for(size_t j = 1;j < table.size();j++){
                size_t prob = HashWithCollision(table[i], hash, j, newTable.size());
                if(newTable[prob] == EmptyValue){
                    newTable[prob] = table[i];
                    break;
                }
            }
        }
    }
    table = newTable;
}

template <class T>
bool HashTable<T>::Add(const T &key) {

    if((float)(keysCount + 1)/table.size() >= Alpha){
        growTable();
    }
    keysCount++;
    size_t hash = Hash(key, table.size());
//    if(table[hash] == DelValue || table[hash] == EmptyValue){
//        table[hash] = key;//FIRSTDEL POS запомнить
//        return true;
//    } else {
        if(table[hash] == key ){
            return false;
        }
        int firstDelPosition = -1;
        for(size_t i = 0;i<table.size(); i++){
            size_t prob = HashWithCollision(key, hash, i, table.size());

            if(key ==  table[prob]){
                return false;
            }
//
//            if(table[prob] == DelValue || table[prob] == EmptyValue){
//                table[prob] = key;
//                return true;
//            }
            if(table[prob] == DelValue && firstDelPosition == -1){
                firstDelPosition = (int) prob;
                continue;
            }
            if(table[prob] == EmptyValue && firstDelPosition != -1 ){
               table[firstDelPosition] = key;
               return true;
            }
            if(table[prob] == EmptyValue && firstDelPosition == -1){
                table[prob] = key;
                return true;
            }

        }
        assert(firstDelPosition != -1);
            table[firstDelPosition] = key;
            return true;

//    }
}

int main() {
    HashTable<string> table("EMPT", "DEL");
    char operation = 0;
    string data;
    while(std::cin>> operation >> data){
        if (operation == '+'){
            std::cout << (table.Add(data) ? "OK" :"FAIL") << std::endl;
        }
        if (operation == '-'){
            std::cout << (table.Delete(data) ? "OK" :"FAIL") <<"\n";
        }
        if (operation == '?'){
            std::cout << (table.Has(data) ? "OK" :"FAIL") <<"\n";
        }

    }
    return 0;
}