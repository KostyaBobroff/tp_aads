#include <iostream>
#include <cmath>

/*
  Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго возрастают,
  а на интервале [m, n-1] строго убывают. Найти m за O( log m ).
  2 ≤ n ≤ 10000.
*/

size_t search(const int *arr, size_t size) {
    size_t lastIndex = 0;
    size_t firstIndex = 0;

    size_t i = 1;

    for(size_t i = 0; lastIndex < size; i++ ) {
        firstIndex = lastIndex;
        lastIndex = (size_t)pow(2.0, i);
        if(arr[lastIndex] <= arr[firstIndex]) {
            break;
        }
    }

    if (lastIndex >= size) {
        lastIndex = size - 1;
    }

    size_t middleIndex = 0;
    while (firstIndex < lastIndex) {
        middleIndex = (firstIndex + lastIndex)/2;
        if (arr[middleIndex] > arr[firstIndex]) {
            firstIndex = middleIndex;
        } else {
            if ((middleIndex == lastIndex - 1) && (arr[middleIndex] < arr[lastIndex])) {
                firstIndex = lastIndex;
            }
            lastIndex = middleIndex;
        }
    }

    return firstIndex;
}

int main() {
    size_t count;
    std::cin >> count;
    if (count < 2) || (count > 10000) {
        exit(0);
    }

    int *array = new int[count];
    for (size_t i = 0;i < count;i++){
        std::cin >> array[i];
    }
    
    std::cout << search(array, count);
    delete[] array;
    return 0;
}