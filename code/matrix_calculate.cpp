#include <iostream>
#include "matrix.h"
#include <string>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cstdlib>
using namespace std;
//								OPERATOR -
Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix result(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			result.entry[i][j] = entry[i][j] - other.entry[i][j];
	return result;
}
//								OPERATOR =
Matrix& Matrix::operator=(const Matrix& other)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			entry[i][j] = other.entry[i][j];
	return *this;
}
//						CHARACTERISTIC EQUATION
void Matrix::Cequation()
{
	complex<double> a1, b1, c1;
	cout << "Characteristic equation:				(x in this case are use as lambda symbol)\n";
	if (row == 2)				//chracteristic equation	x^2 + a1x +b1 
	{
		a1 = quadratic_coefficient_one();
		b1 = quadratic_coefficient_two();
		cout << "x^2 ";
	}
	if (row == 3)					//characteristic equation x^3 +c1x^2 +a1x +b1
	{
		c1 = cubic_coefficient_one();
		a1 = cubic_coefficient_two();
		b1 = cubic_coefficient_three();
		cout << "x^3 ";
		if (real(c1) != 0 && real(c1) > 0)
			cout << "+ " << real(c1) << "x^2 ";
		if (real(c1) != 0 && real(c1) < 0)
			cout << real(c1) << "x^2 ";
	}
	if (real(a1) != 0 && real(a1) > 0)
		cout << "+ " << real(a1) << "x ";
	if (real(a1) != 0 && real(a1) < 0)
		cout << real(a1) << "x ";
	if (real(b1) != 0 && real(b1) > 0)
		cout << "+ " << real(b1);
	if (real(b1) != 0 && real(b1) < 0)
		cout << real(b1);
	cout << " =0" << endl;
}
//							2x2 COEFFICIENT
complex < double> Matrix::quadratic_coefficient_one()
{
	return negative_zero_debug(-(entry[0][0] + entry[1][1]));//minus (sum of diagonal)
}
complex < double> Matrix::quadratic_coefficient_two()
{
	
	return negative_zero_debug(entry[0][0] * entry[1][1] - entry[0][1] * entry[1][0]);//determinant
}
//							3x3 COEFFICIENT
complex<double> Matrix::cubic_coefficient_one()
{
	return negative_zero_debug(-(entry[0][0] + entry[1][1] + entry[2][2]));//minus (sum of diagonal)
}
complex<double> Matrix::cubic_coefficient_two()
{
	return negative_zero_debug(entry[1][1] * entry[2][2] - entry[2][1] * entry[1][2] + entry[0][0] * entry[2][2] - entry[2][0] * entry[0][2] + entry[0][0] * entry[1][1] - entry[1][0] * entry[0][1]);//sum of diagonal minors
}
complex<double> Matrix::cubic_coefficient_three()
{
	return negative_zero_debug(-(entry[0][0] * entry[1][1] * entry[2][2] + entry[0][1] * entry[1][2] * entry[2][0] + entry[0][2] * entry[1][0] * entry[2][1] - entry[2][0] * entry[1][1] * entry[0][2] - entry[2][1] * entry[1][2] * entry[0][0] - entry[2][2] * entry[1][0] * entry[0][1]));//minus (determinant )
}
//						ROOTS OF CUBIC CALCULATE
complex<double> Matrix::s()
{
	return negative_zero_debug(-cubic_coefficient_one()/3.0);
}
complex<double> Matrix::omega()
{
	return (complex<double>(-0.5,0.8660254038));
}
complex<double> Matrix::omega2()
{
	return (complex<double>(-0.5, -0.8660254038));
}
complex<double> Matrix::m()
{
	return (-(cubic_coefficient_one()* cubic_coefficient_one()* cubic_coefficient_one() / 27.0) + ((cubic_coefficient_one() * cubic_coefficient_two()) / 6.0) - (cubic_coefficient_three() / 2.0));
}
complex<double> Matrix::l()
{
	return (( ( - (cubic_coefficient_one() * cubic_coefficient_one()) / 3.0) + cubic_coefficient_two())/3.0);
}
complex<double> Matrix::alpha() 
{
	return cbrtc(m() + sqrt(zero_detect(m() * m() + l() * l() * l())));
}
complex<double> Matrix::beta()
{
	return cbrtc(m() + (-sqrt(zero_detect(m() * m() + l() * l() * l() ))));
}
//root 1
complex<double> Matrix::cbroot1()
{
	return zero_detect2(s()+alpha()+beta());
}
//root 2
complex<double> Matrix::cbroot2()
{
	return zero_detect2(s() + zero_detect2(omega() * alpha() + omega2() * beta()));
}
//root 3
complex<double> Matrix::cbroot3()
{
	return zero_detect2(s() + zero_detect2(omega2() * alpha() +  omega()* beta()));
}
Matrix Matrix::A_minus_x_I(const complex<double>& lambda) const
{
	Matrix identity(row, col, lambda); // Create lambda * I
	return *this - identity;          // A - lambda * I
}

