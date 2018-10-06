#include <iostream>
/*
Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
Обрабатывать команды push back и pop front.
 */
template <class T>
class Stack {
    public:
        size_t realSize;
        Stack();
        ~Stack();
        void push(const T &elem);
        T pop();
    private:
        size_t bufferSize;
        T *buffer;
};

template <class T>
class Queue {
    public:
        Queue();
        ~Queue();
        void push(const T &elem);
        T pop();
    private:
        Stack<T> pushStack;
        Stack<T> popStack;

};

template <class T>
Stack<T>::Stack() {
    bufferSize = 4;
    buffer = new T[bufferSize];
    realSize = 0;
}

template <class T>
Stack<T>::~Stack() {
    delete[] buffer;
}

template <class T>
void Stack<T>::push(const T &elem) {
    if(realSize  == bufferSize){
        T *newBuffer = new T[bufferSize * 2];
        for(size_t i = 0;i < realSize;i++){
            newBuffer[i] = buffer[i];
        }
        bufferSize *= 2;
        newBuffer[realSize++] = elem;
        delete[] buffer;
        buffer = newBuffer;
    } else{
        buffer[realSize++] = elem;
    }
}
template <class T>
T Stack<T>::pop() {
    if(realSize == 0){
        return -1;
    }
    return buffer[--realSize];
}

template <class T>
Queue<T>::Queue() {

}
template <class T>
Queue<T>::~Queue() {

}

template <class T>
void Queue<T>::push(const T &elem) {
    pushStack.push(elem);
}

template <class T>
T Queue<T>::pop() {
    if(popStack.realSize == 0){
        size_t sizePushStack = pushStack.realSize;
        for(size_t i = 0; i < sizePushStack;i++){
            popStack.push(pushStack.pop());
        }
    }
    return popStack.pop();
}

int main() {
    Queue<int> queue;
    int n = 0;
    std::cin>>n;
    if(n > 1000000){
        return -1;
    }
    bool result = true;
    for(int i = 0;i < n;i++){
        int command = 0;
        int data = 0;
        std::cin >> command >> data;
        switch(command){
            case 2:
                result = result && queue.pop() == data;
                break;
            case 3:
                queue.push(data);
        }

    }
    std::cout<< (result ? "YES" : "NO");
    return 0;
}