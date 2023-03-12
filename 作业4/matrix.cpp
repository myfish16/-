#include "matrix.hpp"

Matrix::Matrix()
{
	row = col = 0;
	Item = nullptr;
}

Matrix::Matrix(int row, int column)
{
	Create(row, column);
}

Matrix::Matrix(const Matrix& other)
{
	row = other.row;
	col = other.col;
	Item = new float* [row];
	for (int i = 0; i < row; i++)
	{
		Item[i] = new float[col];
		::memcpy(Item[i], other.Item[i], sizeof(float) * col);
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	row = other.row;
	col = other.col;
	Item = new float* [row];
	for (int i = 0; i < row; i++)
	{
		Item[i] = new float[col];
		::memcpy(Item[i], other.Item[i], sizeof(float) * col);
	}
	return *this;
}

Matrix::Matrix(Matrix&& other)
{
	row = other.row;
	col = other.col;
	Item = other.Item;
	other.Item = nullptr;
}

Matrix::~Matrix()
{
	Release();
}

void Matrix::Create(int row, int column)
{
	row = row;
	col = column;
	Item = new float* [row];
	for (int i = 0; i < row; i++)
	{
		Item[i] = new float[column];
	}
}

void Matrix::Release()
{
	if (Item != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] Item[i];
		}
		delete[] Item;
	}
	Item = nullptr;
	row = 0;
	col = 0;
}

void Matrix::Resize(int row, int column)
{
	if (row == row && column == col)
	{
		return;
	}
	Release();
	Create(row, column);
}

float* Matrix::operator[](int i)
{
	return Item[i];
}

Matrix Matrix::operator+(const Matrix& other)
{
	if (other.row != row || other.col != col)
	{
		return Matrix();
	}
	Matrix result(row, col);
	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < col; j++)
		{
			result[i][j] = Item[i][j] + other.Item[i][j];
		}
	}
	return move(result);
}

Matrix Matrix::operator-(const Matrix& other)
{
	if (other.row != row || other.col != col)
	{
		return Matrix();
	}
	Matrix result(row, col);
	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < col; j++)
		{
			result[i][j] = Item[i][j] - other.Item[i][j];
		}
	}
	return move(result);
}

Matrix Matrix::operator*(const Matrix& other)
{
	if (col != other.row)
	{
		return Matrix();
	}
	Matrix result(row, other.col);
	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < other.col; j++)
		{
			float key = 0;
			for (auto k = 0; k < col; k++)
			{
				key += Item[i][k] * other.Item[k][j];
			}
			result[i][j] = key;
		}
	}
	return move(result);
}

int Matrix::Getrow()
{
	return row;
}

int Matrix::Getcol()
{
	return col;
}

bool Matrix::SetrowValue(int row, float* values)
{
	if (row >= row)
	{
		return false;
	}
	for (int i = 0; i < col; i++)
	{
		Item[row][i] = values[i];
	}
	return true;
}

void Matrix::SetValue(float** values)
{
	for (auto i = 0; i < row; i++)
	{
		for (auto j = 0; j < col; j++)
		{
			Item[i][j] = values[i][j];
		}
	}
}

void Matrix::Print(string name)
{
	cout << name.c_str() << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Item[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}