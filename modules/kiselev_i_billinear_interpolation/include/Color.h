// Copyright 2024 Kiselev Igor

#ifndef MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_
#define MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_

class Color {
 private:
    char R;
    char G;
    char B;
    int max = 255;
    int min = 0;
 public:
    Color(int r, int g, int b);
    Color(const Color& c);

    char getR() const;
    char getG() const;
    char getB() const;
    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setColor(int r, int g, int b);
};

#endif  // MODULES_KISELEV_I_BILLINEAR_INTERPOLATION_INCLUDE_COLOR_H_
