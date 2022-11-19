#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(): Matrix(Position::zero) {}

Matrix::Matrix(Position size) {
	this->matrix = nullptr;
	SetSize(size);
}

Matrix::~Matrix() {
	std::cout << size.x << std::endl;
	delete[] matrix;
}

const Position& Matrix::GetSize() const {
	return size;
}

const Position& Matrix::SetSize(Position size) {
	this->size = size;
	delete[] matrix;
	matrix = new Pixel[size.Size()];
	return this->size;
}

Pixel& Matrix::GetPixel(Position position) const {
	return (*this)[position.x][position.y];
}

Pixel& Matrix::SetPixel(Position position, Pixel pixel) {
	return GetPixel(position) = pixel;
}

Pixel* Matrix::operator[](size_t x) const {
	return matrix + x * size.y;
}

Matrix& Matrix::operator=(const Matrix& original) {
	SetSize(original.size);
	for(int x = 0; x < size.x; x++) {
		for(int y = 0; y < size.y; y++) {
			SetPixel(Position(x, y), original.GetPixel(Position(x, y)));
		}
	}
	return (*this);
}