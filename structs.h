#pragma once
#include <iostream>
#include <cmath>

const double EPS = 1e-5;
const double PI = 3.14159265358979323846;

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double r;
};

struct Square {
    Point topLeft;
    double side;
};
