#include "func.h"

Point readPoint() {
    Point p;
    std::cin >> p.x >> p.y;
    return p;
}

void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")";
}

// ---- Circle ----
Circle readCircle() {
    Circle c;
    std::cin >> c.center.x >> c.center.y >> c.r;
    return c;
}

void printCircle(const Circle& c) {
    std::cout << "Circle: center=(" << c.center.x << ", " << c.center.y << "), r=" << c.r << "\n";
}

double circlePerimeter(const Circle& c) {
    return 2 * PI * c.r;
}

double circleArea(const Circle& c) {
    return PI * c.r * c.r;
}

// ---- Square ----
Square readSquare() {
    Square s;
    std::cin >> s.topLeft.x >> s.topLeft.y >> s.side;
    return s;
}

void printSquare(const Square& s) {
    std::cout << "Square: topLeft=(" << s.topLeft.x << ", " << s.topLeft.y << "), side=" << s.side << "\n";
}

double squarePerimeter(const Square& s) {
    return 4 * s.side;
}

double squareArea(const Square& s) {
    return s.side * s.side;
}

// ---- Point in Figure ----
bool pointInCircle(const Point& p, const Circle& c) {
    double d = std::hypot(p.x - c.center.x, p.y - c.center.y);
    return d < c.r - EPS;
}

bool pointInSquare(const Point& p, const Square& s) {
    return (p.x > s.topLeft.x + EPS &&
            p.x < s.topLeft.x + s.side - EPS &&
            p.y < s.topLeft.y - EPS &&
            p.y > s.topLeft.y - s.side + EPS);
}

// ---- Point on Contour ----
bool pointOnCircle(const Point& p, const Circle& c) {
    double d = std::hypot(p.x - c.center.x, p.y - c.center.y);
    return std::fabs(d - c.r) < EPS;
}

bool pointOnSquare(const Point& p, const Square& s) {
    bool onLeft   = std::fabs(p.x - s.topLeft.x) < EPS && p.y <= s.topLeft.y && p.y >= s.topLeft.y - s.side;
    bool onRight  = std::fabs(p.x - (s.topLeft.x + s.side)) < EPS && p.y <= s.topLeft.y && p.y >= s.topLeft.y - s.side;
    bool onTop    = std::fabs(p.y - s.topLeft.y) < EPS && p.x >= s.topLeft.x && p.x <= s.topLeft.x + s.side;
    bool onBottom = std::fabs(p.y - (s.topLeft.y - s.side)) < EPS && p.x >= s.topLeft.x && p.x <= s.topLeft.x + s.side;
    return onLeft || onRight || onTop || onBottom;
}

// ---- Intersections ----
bool circlesIntersect(const Circle& c1, const Circle& c2) {
    double d = std::hypot(c1.center.x - c2.center.x, c1.center.y - c2.center.y);
    return d <= c1.r + c2.r + EPS;
}

bool squaresIntersect(const Square& s1, const Square& s2) {
    return !(s1.topLeft.x + s1.side < s2.topLeft.x - EPS ||
             s2.topLeft.x + s2.side < s1.topLeft.x - EPS ||
             s1.topLeft.y - s1.side > s2.topLeft.y + EPS ||
             s2.topLeft.y - s2.side > s1.topLeft.y + EPS);
}

bool circleSquareIntersect(const Circle& c, const Square& s) {
    double nearestX = std::max(s.topLeft.x, std::min(c.center.x, s.topLeft.x + s.side));
    double nearestY = std::max(s.topLeft.y - s.side, std::min(c.center.y, s.topLeft.y));
    double dx = c.center.x - nearestX;
    double dy = c.center.y - nearestY;
    return (dx*dx + dy*dy) <= (c.r + EPS) * (c.r + EPS);
}

// ---- Containment ----
bool circleInCircle(const Circle& inner, const Circle& outer) {
    double d = std::hypot(inner.center.x - outer.center.x, inner.center.y - outer.center.y);
    return d + inner.r <= outer.r + EPS;
}

bool squareInSquare(const Square& inner, const Square& outer) {
    return (inner.topLeft.x >= outer.topLeft.x - EPS &&
            inner.topLeft.x + inner.side <= outer.topLeft.x + outer.side + EPS &&
            inner.topLeft.y <= outer.topLeft.y + EPS &&
            inner.topLeft.y - inner.side >= outer.topLeft.y - outer.side - EPS);
}

bool squareInCircle(const Square& sq, const Circle& c) {
    Point corners[4] = {
        sq.topLeft,
        {sq.topLeft.x + sq.side, sq.topLeft.y},
        {sq.topLeft.x, sq.topLeft.y - sq.side},
        {sq.topLeft.x + sq.side, sq.topLeft.y - sq.side}
    };
    for (auto& corner : corners)
        if (!pointInCircle(corner, c)) return false;
    return true;
}

bool circleInSquare(const Circle& c, const Square& sq) {
    return (c.center.x - c.r >= sq.topLeft.x - EPS &&
            c.center.x + c.r <= sq.topLeft.x + sq.side + EPS &&
            c.center.y + c.r <= sq.topLeft.y + EPS &&
            c.center.y - c.r >= sq.topLeft.y - sq.side - EPS);
}
