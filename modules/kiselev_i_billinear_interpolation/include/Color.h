// Copyright 2024 Kiselev Igor

#ifndef MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_
#define MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_

#include <string>

class Color {
 private:
    int R;
    int G;
    int B;
    int max = 255;
    int min = 0;
 public:
    Color();
    Color(int r, int g, int b);
    Color(const Color& c);

    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setColor(int r, int g, int b);
};

#endif  // MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_
