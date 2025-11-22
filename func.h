#pragma once
#include "structs.h"

// Функции работы с точкой
Point readPoint();
void printPoint(const Point& p);

// Функции работы с кругом
Circle readCircle();
void printCircle(const Circle& c);
double circlePerimeter(const Circle& c);
double circleArea(const Circle& c);

// Функции работы с квадратом
Square readSquare();
void printSquare(const Square& s);
double squarePerimeter(const Square& s);
double squareArea(const Square& s);

// Проверки вхождения точки
bool pointInCircle(const Point& p, const Circle& c);
bool pointInSquare(const Point& p, const Square& s);

// Проверки нахождения на контуре
bool pointOnCircle(const Point& p, const Circle& c);
bool pointOnSquare(const Point& p, const Square& s);

// Пересечения фигур
bool circlesIntersect(const Circle& c1, const Circle& c2);
bool squaresIntersect(const Square& s1, const Square& s2);
bool circleSquareIntersect(const Circle& c, const Square& s);

// Принадлежность фигур
bool circleInCircle(const Circle& inner, const Circle& outer);
bool squareInSquare(const Square& inner, const Square& outer);
bool squareInCircle(const Square& sq, const Circle& c);
bool circleInSquare(const Circle& c, const Square& sq);
