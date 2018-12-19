#include <iostream>
#include <string.h>

size_t CharCode(char ch){
    return (ch != '\0') ? ch : 0;
}

void CountingSort( char** a, size_t size, size_t *c,size_t k, size_t byte ) {
    for(size_t i = 0; i < k; i++){
        c[i] = 0;
    }
    for(size_t i = 0; i < size; i++){
        c[CharCode(a[i][byte])]++;
    }
    if(c[CharCode('\0')] == size){
        delete[] c;
        return;
    }

//    for(size_t i = 1;i < k; i++){
//        c[i] += c[i-1];
//    }
    size_t sum = 0;
    for(size_t i = 0;i < k; i++){
        size_t tmp = c[i];
        c[i] = sum;
        sum += tmp;
    }
    char ** b = new char*[size];
//    for(int i = (int) size - 1; i >= 0; --i){
//        b[--c[CharCode(a[i][byte])]] = a[i];
//
//    }
    for(size_t i = 0;i<size;i++){
        b[c[CharCode(a[i][byte])]++] = a[i];
    }

    for(size_t i = 0;i<size;i++){
        a[i] = (char *)malloc(strlen(b[i]) + 1);
        strcpy(a[i], b[i]);
    }
    for(size_t i = 0;i < size; i++){
        delete[] b[i];
    }
    delete[] b;
}

void MSDSort(char ** strings, size_t size,size_t alphabetSize, size_t byte = 0){
    if(size <= 1){
        return;
    }
    size_t * c = new size_t[alphabetSize+1];
    CountingSort(strings, size, c, alphabetSize, byte);

        for (size_t i = 0;i < alphabetSize;i++ ){
            MSDSort(strings + c[i],c[i+1] - c[i], alphabetSize, byte + 1);
        }

    delete[] c;
}

int main() {
    char **a;
    size_t size = 0;
    std::cin>>size;
    a = new char*[size];
    char *str = new char[256];
    for (int i=0; i<size; i++) {
        std::cin >> str;
        size_t len = strlen(str);
        a[i] = new char[len +1];
        strcpy(a[i], str);
    }




//    char a[5][3] = {"sa", "rb" , "aa", "bz", "\0s"};
//    size_t *c = new size_t[256];
//    CountingSort(a, size, c, 256, 2);
    MSDSort(a,size,256);
    for(size_t i = 0 ;i<size ;i++){
        for(size_t j = 0; j <strlen(a[i]);j++){
            std::cout<<a[i][j];
        }
        std::cout<<std::endl;
    }
    delete[] str;
    for(size_t i = 0;i < size; i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}