// Copyright 2021 Panova Olga

#ifndef MODULES_3D_SHAPES_VOLUME_INCLUDE_3D_SHAPES_VOLUME_H_
#define MODULES_3D_SHAPES_VOLUME_INCLUDE_3D_SHAPES_VOLUME_H_

#include <cmath>

class Shapes {
 protected:
    int _x, _y, _z;
    const double PI = acos(-1.0);
 public:
    Shapes() :_x(0), _y(0), _z(0) {}
    Shapes(int x, int y, int z) :_x(x), _y(y), _z(z) {}
    virtual double Volume() const = 0;
};

class Cube :public Shapes {
 protected:
    double _side;
 public:
    Cube() : _side(1) {}
    Cube(int x, int y, int z, double h) : Shapes(x, y, z), _side(h) {}
    double Volume() const override;
};

class Sphere :public Shapes {
 protected:
    double _radius;
 public:
    Sphere() : _radius(1) {}
    Sphere(int x, int y, int z, double r) : Shapes(x, y, z), _radius(r) {}
    double Volume() const override;
};

class Cone :public Shapes {
 protected:
    double _radius, _h;
 public:
    Cone() : _radius(1), _h(1) {}
    Cone(int x, int y, int z, double r, double h) :
        Shapes(x, y, z), _radius(r), _h(h) {}
    double BaseArea() const;
    double Volume() const override;
};

class Parallelepiped :public Shapes {
 protected:
    double _a, _b, _h;
 public:
    Parallelepiped() : _a(1), _b(1), _h(1) {}
    Parallelepiped(int x, int y, int z, double a, double b, double h) :
        Shapes(x, y, z), _a(a), _b(b), _h(h) {}
    double Volume() const override;
};

class Prism :public Shapes {
 protected:
    double _side, _h;
    int _corners_count;
 public:
    Prism() : _side(1), _h(1), _corners_count(1) {}
    Prism(int x, int y, int z, double side, double h, int n) :
        Shapes(x, y, z), _side(side), _h(h), _corners_count(n) {}
    double BaseArea() const;
    double Volume() const override;
};

class Pyramid :public Shapes {
 protected:
    double _side, _h;
    int _corners_count;
 public:
    Pyramid() : _side(1), _h(1), _corners_count(1) {}
    Pyramid(int x, int y, int z, double side, double h, int n) :
        Shapes(x, y, z), _side(side), _h(h), _corners_count(n) {}
    double BaseArea() const;
    double Volume() const override;
};

class Torus :public Shapes {
 protected:
    double center_to_axis, _radius;
 public:
    Torus() : _radius(1) {}
    Torus(int x, int y, int z, double d, double r) :
        Shapes(x, y, z), center_to_axis(d), _radius(r) {}
    double Volume() const override;
};

class Frustum :public Shapes {
 protected:
    double _top_r, _r, _h;
 public:
    Frustum() : _top_r(1), _r(1), _h(1) {}
    Frustum(int x, int y, int z, double r, double R, double h) :
        Shapes(x, y, z), _top_r(r), _r(R), _h(h) {}
    double Volume() const override;
};

#endif  // MODULES_3D_SHAPES_VOLUME_INCLUDE_3D_SHAPES_VOLUME_H_
