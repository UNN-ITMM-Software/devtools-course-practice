// Copyright 2024 Kochetov Nikolay
#include <iostream>
#include <vector>

using namespace std;

// Структура для представления точки в двумерном пространстве
struct Point {
    int x, y;
};

// Класс для построения выпуклой оболочки множества точек
class ConvexHull {
private:
    std::vector<Point> points;

    // Функция для определения ориентации трех точек (p, q, r)
    int orientation(Point p, Point q, Point r);

public:
    // Конструктор класса, принимающий вектор точек
    ConvexHull(std::vector<Point>& _points) : points(_points) {}

    // Функция для построения выпуклой оболочки
    std::vector<Point> findConvexHull();
};
