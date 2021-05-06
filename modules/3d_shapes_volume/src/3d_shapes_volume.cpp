// Copyright 2021 Panova Olga

#include "include/3d_shapes_volume.h"

double Cube::Volume() const {
    if (_side > 0) {
        return pow(_side, 3);
    } else {
        throw "Wrong number";
    }
}

double Sphere::Volume() const {
    if (_radius > 0) {
        return PI * pow(_radius, 3) * 4 / 3;
    } else {
        throw "Wrong number";
    }
}

double Cone::BaseArea() const {
    if (_radius > 0 && _h > 0) {
        return PI * pow(_radius, 2);
    } else {
        throw "Wrong number";
    }
}

double Cone::Volume() const {
    return (this->BaseArea()) * _h * 1 / 3;
}

double Parallelepiped::Volume() const {
    if (_a > 0 && _b > 0 && _h > 0) {
        return _a * _b * _h;
    } else {
        throw "Wrong numbers";
    }
}

double Prism::BaseArea() const {
    if (_corners_count > 0 && _side > 0 && _h > 0) {
        return _corners_count * pow(_side, 2) / (4 * tan(180 / _corners_count));
    } else {
        throw "Wrong numbers";
    }
}

double Prism::Volume() const {
    return (this->BaseArea()) * _h;
}

double Pyramid::BaseArea() const {
    if (_corners_count > 0 && _side > 0 && _h > 0) {
        return _corners_count * pow(_side, 2) / (4 * tan(180 / _corners_count));
    } else {
        throw "Wrong numbers";
    }
}

double Pyramid::Volume() const {
    return (this->BaseArea()) * _h / 3;
}

double Torus::Volume() const {
    if (center_to_axis > 0 && _radius > 0) {
        return 2 * pow(PI, 2) * center_to_axis * pow(_radius, 2);
    } else {
        throw "Wrong numbers";
    }
}

double Frustum::Volume() const {
    if (_h > 0 && _r > 0 && _top_r > 0) {
        return PI * _h * (pow(_top_r, 2) + _top_r * _r + pow(_r, 2)) / 3;
    } else {
        throw "Wrong numbers";
    }
}
