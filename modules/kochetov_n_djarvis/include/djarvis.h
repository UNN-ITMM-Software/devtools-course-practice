// Copyright 2024 Kochetov Nikolay

#ifndef MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_H_
#define MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_H_

#include <iostream>
#include <vector>


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
    explicit ConvexHull(std::vector<Point>& _points);

    // Функция для построения выпуклой оболочки
    std::vector<Point> findConvexHull();
};

#endif  // MODULES_KOCHETOV_N_DJARVIS_INCLUDE_DJARVIS_H_
