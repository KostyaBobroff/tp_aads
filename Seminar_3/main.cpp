#include <iostream>
int Partition( int* a, int l, int r ) {
    if( r-l <= 1 ) {
        return l;
    }
    const int& pivot = a[r- 1];
    int i = l;
    int j = r - 2;
    while( i <= j ) {
// Не проверяем, что i < n - 1, т.к. a[n - 1] == pivot.
        for( ; a[i] < pivot; ++i ) {}
        for( ; j >= 0 && !( a[j] < pivot ); --j ) {}
        if( i < j ) {
            std::swap( a[i++], a[j--] );
        }
    }
    std::swap( a[i], a[r - 1] );
    return i;
}

int FindKStat(int *a, int l, int r,int k){
    int pivotPos = Partition(a, l, r);
    if(pivotPos == k){
        return a[k];
    }
    if(pivotPos > k){
        return FindKStat(a, l,pivotPos, k);
    }
    return FindKStat(a,  pivotPos + 1, n - pivotPos -1, k - pivotPos)
}
void QuickSort( int* a, int n ) {
    int part = Partition( a, n );
    if( part > 0 ) QuickSort( a, part );
    if( part + 1 < n ) QuickSort( a + part + 1, n – ( part + 1 ) );
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}