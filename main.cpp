#include "func.h"

int main() {
    Circle c1 = { {0, 0}, 5 };
    Circle c2 = { {3, 0}, 2 };
    Square s1 = { { -2, 2 }, 4 };

    printCircle(c1);
    printCircle(c2);
    printSquare(s1);

    std::cout << "Circle1 perimeter: " << circlePerimeter(c1) << "\n";
    std::cout << "Circle1 area: " << circleArea(c1) << "\n";

    Point p = {1, 1};
    std::cout << "Point "; printPoint(p);
    std::cout << (pointInCircle(p, c1) ? " inside circle1\n" : " outside circle1\n");

    std::cout << "Circle1 and Circle2 intersect? " 
              << (circlesIntersect(c1, c2) ? "Yes\n" : "No\n");

    std::cout << "Square1 and Circle1 intersect? " 
              << (circleSquareIntersect(c1, s1) ? "Yes\n" : "No\n");

    return 0;
}
