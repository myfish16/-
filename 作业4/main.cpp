#include "matrix.hpp"

int main() 
{
	Matrix m1(2, 2), m2(2, 2);
	float a[2] = { 1.0,2.0 };
	for (auto i = 0; i < 2; i++)
	{
		m1.SetrowValue(i, a);
		m2.SetrowValue(i, a);
	}
	m1.Print("m1");
	m2.Print("m2");
	Matrix m3 = m1 + m2;
	m3.Print("m3");
	Matrix m4 = m1 - m2;
	m4.Print("m4");

	Matrix m5(2, 3), m6(3, 2);
	float b[3] = { 1.0, 2.0, 3.0 };
	float c[2] = { 1.0, 2.0 };
	m5.SetrowValue(0, b);
	m5.SetrowValue(1, b);
	m6.SetrowValue(0, c);
	m6.SetrowValue(1, c);
	m6.SetrowValue(2, c);
	Matrix m7 = m5 * m6;
	m5.Print("m5");
	m6.Print("m6");
	m7.Print("m7");

	Matrix m8(2, 3);
	float** p = new float* [2];
	p[0] = new float[3] { 1, 2, 3 };
	p[1] = new float[3] { 4, 5, 6 };
	m8.SetValue(p);
	m8.Print("m8");

	Matrix m9(m8), m10;
	m10 = m8;
	m9.Print("m9");
	m10.Print("m10");

	return 0;
}