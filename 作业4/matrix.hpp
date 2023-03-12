#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix
{
public:
	Matrix();

	Matrix(int row, int column);

	Matrix(const Matrix& other);
	
	Matrix& operator=(const Matrix& other);
	
	Matrix(Matrix&& other);
	
	~Matrix();
	
	void Create(int row, int column);
	
	void Release();
	
	void Resize(int row, int column);
	
	float* operator[](int i);
	
	Matrix operator+(const Matrix& other);
	
	Matrix operator-(const Matrix& other);
	
	Matrix operator*(const Matrix& other);
	
	int Getrow();
	
	int Getcol();
	
	bool SetrowValue(int row, float* values);
	
	void SetValue(float** values);
	
	void Print(string name);
	
private:
	int row;

	int col;

	float** Item;
};