#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class Queue{
    public:
        Queue();
        ~Queue();
        void Enqueue(const T& data);
        T Dequeue();
        bool IsEmpty() const{return tail == nullptr;};

private:
        struct Node{
            T Data;
            Node * Next = nullptr;
            Node() = default;
        };
    Node* head, *tail;



};
//разобрать контсрукторы
template<class T>
Queue<T>::Queue() :
    head(nullptr),
    tail(nullptr){
        head = nullptr;
    }


template<class T>
Queue<T>::~Queue() {
    while(head != nullptr){
        Dequeue();
    }
}

template<class T>
void Queue<T>::Enqueue(const T &data) {
    Node * newNode = new Node;
    newNode->Data = data;
    if(tail == nullptr){
        head = newNode;

    } else{
        tail->Next = newNode;
    }
    tail = newNode;
}

template <class T>
T Queue<T>::Dequeue() {

    assert(!IsEmpty());

    Node* tempNode = head;
    T tempData = tempNode->Data;
    head = head->Next;
    if(head == nullptr){
        tail = nullptr;
    }
    delete tempNode;
    return tempData;
}
int main() {
    Queue<int> queue;
    int n = 0;
    cin>>n;
    bool result = true;
    for(int i = 0;i < n;i++){
        int command = 0;
        int data = 0;
        cin >> command >> data;
        switch(command){
            case 2:
                result = result && queue.Dequeue() == data;
                break;
            case 3:
                queue.Enqueue(data);
        }

    }
    cout<< (result ? "YES" : "NO");

    return 0;
}