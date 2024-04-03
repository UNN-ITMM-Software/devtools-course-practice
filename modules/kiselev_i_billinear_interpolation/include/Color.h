// Copyright 2024 Kiselev Igor

#ifndef MODULES_COLOR_INCLUDE_COLOR_H_
#define MODULES_COLOR_INCLUDE_COLOR_H_

class Color {
private:
	short R;
	short G;
	short B;
public:
	Color(int r, int g, int b);
	Color(const Color& c);

	short getR() const;
	short getG() const;
	short getB() const;
	void setR(int r);
	void setG(int g);
	void setB(int b);
};

#endif  // MODULES_COLOR_INCLUDE_COLOR_H_
