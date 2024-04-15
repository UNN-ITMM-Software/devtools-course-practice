// Copyright 2024 Kochetov Nikolay


#include "include/djarvis.h"

ConvexHull::ConvexHull(std::vector<Point>& _points) : points(_points) {}

int ConvexHull::orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;     // точки коллинеарны
    return (val > 0) ? 1 : 2;  // положительный или отрицательный поворот
}

std::vector<Point> ConvexHull::findConvexHull() {
    int n = points.size();
    if (n < 3) return {};  // Выпуклая оболочка не может быть построена

    // Находим крайнюю левую точку
    int left = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[left].x)
            left = i;
    }

    int p = left, q;
    std::vector<Point> hull;

    // Добавляем крайнюю левую точку в выпуклую
    // оболочку и ищем следующую точку
    // до тех пор, пока не вернемся в исходную точку
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;

        // Находим следующую точку такую, что она формирует
        // положительный поворот
        // с текущей точкой p и предыдущей точкой на оболочке
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == -1)
                q = i;
        }
        // Теперь q содержит следующую точку на оболочке
        p = q;
    } while (p != left);  // Повторяем, пока не вернемся в исходную точку

    return hull;
}
