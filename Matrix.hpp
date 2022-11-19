#pragma once
#include "Pixel.hpp"
#include "Position.hpp"

class Matrix {
private:
	Pixel* matrix;
	Position size;
public:
	Matrix();
	Matrix(Position size);
	virtual ~Matrix();
	const Position& GetSize() const;
	virtual const Position& SetSize(Position size);
	Pixel& GetPixel(Position position) const;
	Pixel& SetPixel(Position position, Pixel pixel);
	Pixel* operator[](size_t x) const;
	Matrix& operator=(const Matrix& original);
};
