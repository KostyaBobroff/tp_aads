#include <iostream>
#include <cmath>

/*
Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин. Вначале вводится количество вершин,
затем последовательно целочисленные координаты всех вершин в порядке обхода по часовой стрелке.
n < 1000, координаты < 10000.
Указание. Для вычисления площади n-угольника можно посчитать сумму ориентированных
площадей трапеций под каждой стороной многоугольника.
 */


struct Point{
    double x;
    double y;
};

double Square(Point * coordinates, size_t size){
    Point startPoint = coordinates[0];
    double square = 0;
    for(size_t i = 1; i< size - 1 ; i++){
        square += (double)1/2* fabs((coordinates[i].x - startPoint.x) * (coordinates[i+1].y - startPoint.y)
                         - (coordinates[i+1].x - startPoint.x) * (coordinates[i].y - startPoint.y));
    }
    return square;
}


int main() {
    size_t count = 0;
    std::cin >> count;
//    assert(count < 1000);
//    assert(count > 2);
    if((count >= 1000) || (count < 3)){
        return 0;
    }
    Point *points = new Point[count];
    std::cin >> points[0].x >> points[0].y;
//    assert((points[0].x < 10000) && (points[0].y < 10000));
    if((points[0].x >= 10000) || (points[0].y >= 10000)){
        return 0;
    }
//    double maxX = points[0].x, minX = points[0].x, maxY = points[0].y, minY = points[0].y;
    for(size_t i = 1; i < count ;i++){
        std::cin >> points[i].x >> points[i].y;
//        assert((points[i].x < 10000) && (points[i].y < 10000));


    }
    std::cout << Square(points, count);
    delete[] points;
    return 0;
}