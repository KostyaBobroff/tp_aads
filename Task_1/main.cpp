#include <iostream>
#include <cmath>

/*
<<<<<<< HEAD
Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин. Вначале вводится количество вершин,
затем последовательно целочисленные координаты всех вершин в порядке обхода по часовой стрелке.
n < 1000, координаты < 10000.
Указание. Для вычисления площади n-угольника можно посчитать сумму ориентированных
площадей трапеций под каждой стороной многоугольника.
=======
    Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин. Вначале вводится количество вершин,
    затем последовательно целочисленные координаты всех вершин в порядке обхода по часовой стрелке.
    n < 1000, координаты < 10000.
    Указание. Для вычисления площади n-угольника можно посчитать сумму ориентированных
    площадей трапеций под каждой стороной многоугольника.
>>>>>>> ece74b2e0f192a54b77e619bb39d521331a8657b
 */

struct Point{
    double x;
    double y;
};

<<<<<<< HEAD
double Square(Point * coordinates, size_t size){
    Point startPoint = coordinates[0];
    double square = 0;
    for(size_t i = 1; i< size - 1 ; i++){
        square += (double)1/2* fabs((coordinates[i].x - startPoint.x) * (coordinates[i+1].y - startPoint.y)
                         - (coordinates[i+1].x - startPoint.x) * (coordinates[i].y - startPoint.y));
    }
=======
double Square(Point *coordinates, size_t size, Point &center){
    double square = 0;
    for (size_t i = 0; i < size - 1; i++){
        square += (double)1/2 * fabs((coordinates[i].x - center.x) * (coordinates[i+1].y - center.y)
                         - (coordinates[i+1].x - center.x) * (coordinates[i].y - center.y));
    }
    square += (double)1/2 * fabs((coordinates[size-1].x - center.x) * (coordinates[0].y - center.y)
                       - (coordinates[0].x - center.x) * (coordinates[size-1].y - center.y));
>>>>>>> ece74b2e0f192a54b77e619bb39d521331a8657b
    return square;
}


int main() {
    size_t count = 0;
    std::cin >> count;

    if (count >= 1000) || (count < 3) {
        return 0;
    }
    
    Point *points = new Point[count];
    std::cin >> points[0].x >> points[0].y;

    if (points[0].x >= 10000) || (points[0].y >= 10000){
        return 0;
    }
<<<<<<< HEAD
//    double maxX = points[0].x, minX = points[0].x, maxY = points[0].y, minY = points[0].y;
    for(size_t i = 1; i < count ;i++){
        std::cin >> points[i].x >> points[i].y;
//        assert((points[i].x < 10000) && (points[i].y < 10000));

=======

    double maxX = points[0].x, minX = points[0].x, maxY = points[0].y, minY = points[0].y;
    for (size_t i = 1; i < count ;i++) {
        std::cin >> points[i].x >> points[i].y;

        if (points[i].x >= 10000) || (points[i].y >= 10000) {
            return 0;
        }

        if (points[i].x > maxX) {
            maxX = points[i].x;
        }

        if (points[i].x < minX) {
            minX = points[i].x;
        }

        if (points[i].y > maxY) {
            maxY = points[i].y;
        }

        if (points[i].y < minY) {
            minY = points[i].y;
        }
    }
    
    Point center;
    center.x = minX + (maxX - minX)/2;
    center.y = minY + (maxY - minY)/2;

    std::cout << Square(points,count, center);
>>>>>>> ece74b2e0f192a54b77e619bb39d521331a8657b

    }
    std::cout << Square(points, count);
    delete[] points;
    return 0;
}