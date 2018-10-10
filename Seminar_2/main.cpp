#include <iostream>
#include <vector>
struct Point{
    int X;
    int Y;
};

bool operator < (const Point& l, const Point& r){
    return r.X > l.X;
}


template <class T>
class IsLess{
public:
    bool operator()(const T&l, const T& r){
        return l < r;
    }
};
//template function


template <class T>
bool isLessDefault(const T& l, const T& r){
    return l < r;
}

bool isLessX(const Point& l, const Point& r){
    return l.X < r.X;
}
//примерно вот такие
template<class T, class Compare>
void mySort(T* arr, int l, int r, Compare comp = IsLess<T>())
{
    for(int i = l;i < r;i++){
        for(int j = l;j<r;j++){
           if(comp(arr[j+1], arr[j])){
               std::swap(arr[j], arr[j+1]);
           }
        }
    }
}


int main() {
    std::vector<Point> arr;
    Point p ;
    while(std::cin >> p.X >> p.Y){
        arr.push_back(p);
    }
    mySort(&arr[0], 0 , arr.size() - 1, IsLess<Point>());
    for(int i =0; i< arr.size();i++){
        std::cout <<  arr[i].X << arr[i].Y;
    }
    return 0;
}