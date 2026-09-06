#include <iostream>
#include "matrix.h"
#include <string>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cstdlib>
using namespace std;
//								CONSTRUCTOR
Matrix::Matrix(const int& r, const int& c)			
{
	row = r;
	col = c;
	entry = new complex<double>* [row];
	for (int i = 0; i < row; i++)
		entry[i] = new complex<double>[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			entry[i][j] = 0.0;
}
//				constructor for identity matrix
Matrix::Matrix(const int& r, const int& c, const complex<double>& v)
{
	row = r;
	col = c;
	entry = new complex<double>*[row];
	for (int i = 0; i < row; i++)
		entry[i] = new complex<double>[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			entry[i][j] = 0.0;
			if (i == j)
				entry[i][j] = v;
		}
	}
}
//								DESTRUCTOR
Matrix::~Matrix()									
{
	for (int i = 0; i < row; i++)
		delete[] entry[i];
	delete[] entry;
}
//								PRINT FUNCTION
void Matrix::print(const int&n)								//print function
{
	int q = n;												//for UI when entering value
	if (q == 0)	q = row * col;								//																										
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (q == 0)	break;	
			cout << setw(10);
			complex_print(entry[i][j]);
			q--;											//for UI when entering value
		}
		cout << endl;
	}
}

//							INPUT VALUE FOR MATRIX
void Matrix::Entryvalue()
{
	int d = 0;
	cout<<"Enter value for matrix:\n";
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cout << "Matrix:" << endl;
			print(d);
			cin >> entry[i][j];
			d++;
			system("cls");

		}

}
//							COMPLEX NUMBER PRINT
void Matrix::complex_print(const complex<double>& ei)
{
	if (imag(ei) == 0)
		cout << real(ei);
	else
	{
		if (imag(ei) > 0)
		{
			if (real(ei) != 0)
				cout << real(ei);
			cout << "+j" << imag(ei);
		}
		if (imag(ei) < 0)
		{
			if (real(ei) != 0)
				cout << real(ei);
			cout << "-j" << abs(imag(ei));
		}
	}

}
//					NEGATIVE ZERO PROBLEM FIX
complex<double> Matrix::negative_zero_debug(const complex<double>& z)
{
	complex<double>v=z;
	complex<double> j = sqrt(complex<double>(-1));
	if (imag(v) == 0)
	{
		v = real(v) + 0.0 * j;
	}
	if (real(v) == 0)
	{
		v = 0.0 + imag(v) * j;
	}
	return v;
}
//						CLOSE TO ZERO BUT NOT ZERO
complex<double> Matrix::zero_detect(const complex<double>& z)
{
	complex<double>v = z;
	complex<double> j = sqrt(complex<double>(-1));
	if (imag(v) <1e-16&& imag(v)>-1e-16)
	{
		v = real(v) + 0.0 * j;
	}
	if (real(v) < 1e-16 && real(v) > -1e-16)
	{
		v = 0.0 + imag(v) * j;
	}
	return v;
}
complex<double> Matrix::zero_detect2(const complex<double>& z)
{
	complex<double>v = z;
	complex<double> j = sqrt(complex<double>(-1));
	if (imag(v) < 1e-7 && imag(v) > -1e-7)
	{
		v = real(v) + 0.0 * j;
	}
	if (real(v) < 1e-7 && real(v) > -1e-7)
	{
		v = 0.0 + imag(v) * j;
	}
	return v;
}
void Matrix::zero_detect_matrix()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) 
			entry[i][j] = zero_detect2(entry[i][j]);

}

//					CUBIC ROOT OF REAL NUMBER
complex<double> Matrix::cbrtc(const complex<double>& z)
{
	complex<double>v = z;
	complex<double> j = sqrt(complex<double>(-1));
	if (imag(v) == 0)
	{
		double x=real(v);
		v = cbrt(x) + 0.0 * j;
	}
	if (imag(v) != 0)
	{
		v = pow(z,1.0/3.0);
	}
	return v;
}

