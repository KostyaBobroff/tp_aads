#include <iostream>
#include <memory.h>
#include <assert.h>
#include <curses.h>

/*
 * На числовой прямой окрасили N отрезков.
 * Известны координаты левого и правого концов каждого отрезка (Li и Ri).
 * Найти сумму длин частей числовой прямой, окрашенных ровно в один слой.
 */

struct ThickPoint{
    int point;
    int thickness;
    ThickPoint(){};
    ThickPoint(int p, int thick):point(p),thickness(thick){}
};

bool operator < (const ThickPoint &firstPoint, const ThickPoint &secondPoint){
    if (firstPoint.point == secondPoint.point){
        return firstPoint.thickness < secondPoint.thickness;
    }
    return firstPoint.point < secondPoint.point;
}

template <class T>
class isLess{
public:
    bool operator () (const T & firstObject, const T & secondObject){
        return firstObject < secondObject;
    }
};

template <class T, class Compare>
void Merge(T *leftArray, size_t sizeOfLeftArray, T* rightArray, size_t sizeOfRightArray, T* buffer, Compare comp = isLess<T>()){
    size_t i = 0;
    size_t j = 0;
    while((i < sizeOfLeftArray) && (j < sizeOfRightArray)){
        if (comp( leftArray[i],rightArray[j])){
            buffer[i + j] = leftArray[i];
            i++;
        } else {
            buffer[i + j] = rightArray[j];
            j++;
        }
    }
    if (sizeOfLeftArray == i){
        while(j < sizeOfRightArray) {
            buffer[i + j] = rightArray[j];
            j++;
        }
    } else {
        while(i < sizeOfLeftArray){
            buffer[j + i] = leftArray[i];
            i++;
        }
    }


};

template <class T, class Compare>
void MergeSort(T *array, size_t size, Compare comparator = isLess<T>()){
    if (size > 1) {
        size_t leftLen = size / 2;
        size_t rightLen = size - leftLen;
        MergeSort(array, leftLen, comparator);
        MergeSort(array + leftLen, rightLen, comparator);
        T *newArray = new T[size];
        Merge(array, leftLen, array + leftLen, rightLen, newArray, comparator);
        memcpy(array, newArray, sizeof(T) * size);
        delete[] newArray;
    }
};


size_t countThickLength(ThickPoint * points, size_t size){
    MergeSort(points, size, isLess<ThickPoint>());
    size_t thickness = 0;
    size_t length = 0 ;
    for(size_t i = 0; i < size - 1; ++i){
        thickness += points[i].thickness;
        if (thickness == 1){
            length += points[i+1].point-points[i].point;
        }
    }
    return length;
}



int main() {
    size_t size = 0;
    std::cin >> size;
    ThickPoint * points = new ThickPoint[2*size];

    size_t i = 0;
    for(size_t i = 0;i<2*size;i++){
        std::cin>>points[i].point;
        if(i%2 == 0){
            points[i].thickness = 1;
        } else {
            points[i].thickness = -1;
        }
    }

    std::cout << countThickLength(points, 2 * size);
    delete[] points;
    return 0;
}