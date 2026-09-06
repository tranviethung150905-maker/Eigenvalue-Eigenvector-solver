#ifndef _MATRIX_HEADER_
#define	_MATRIX_HEADER_
#include <iostream>
#include <string>
#include <iomanip>
#include<complex>
#include <cstdlib>
#include <cmath>
using namespace std;
class Matrix
{
private:
	int row;
	int col;
	complex<double>** entry;
public:

	//						matrix_basic.cpp
	Matrix(const int& r, const int& c);			//constructor 
	Matrix(const int& r, const int& c, const complex<double>& v); //constructor for scalar identity matrix
	~Matrix();									//destructor
	void print(const int&n=0);					//print matrix
	complex<double> cbrtc(const complex<double>& z);  //find cubic root of a number
	complex<double> negative_zero_debug(const complex<double>& z);// fix problems where complex number store value -0 resulting unpredictable result
	complex<double> zero_detect(const complex<double>& z);		
	complex<double> zero_detect2(const complex<double>& z);	
	void zero_detect_matrix();
	void complex_print(const complex<double>& ei); //print complex number
	void Entryvalue();							//enter value for matrix function


	//						e_operation.cpp		
	void interchange(int r1, int r2);
	void c_row(int r, complex<double> scalar);
	void add_row(int r1, int r2, complex<double> scalar);
	void reducedRowEchelonForm();


	//						matrix_calculate.cpp
	Matrix operator-(const Matrix& other) const;
	Matrix& operator=(const Matrix& other);
	void Cequation();							//characteristic equation printing function
	Matrix A_minus_x_I(const complex<double>& lambda) const;		//A-lambda*identity

	//2x2 coefficient
	//x^2 +bx +c
	complex<double> quadratic_coefficient_one();	//b
	complex<double> quadratic_coefficient_two();	//c
	//3x3 coefficient
	//x^3 +ax^2 +bx +c
	complex<double> cubic_coefficient_one();		//a
	complex<double> cubic_coefficient_two();		//b
	complex<double> cubic_coefficient_three();		//c

	//roots of cubic equation consist of s, omega, m, l 
	complex<double> s();
	complex<double> omega();
	complex<double> omega2();
	complex<double> m();
	complex<double> l();
	complex<double> alpha();		//combination of m and l  (-)
	complex<double> beta();			// combination of m and l (+)
	complex<double> cbroot1();		//root of cubic equation
	complex<double> cbroot2();		//
	complex<double> cbroot3();		//


	//						eigen_calculate.cpp
	//eigenvalue
	void eigen_quadratic();
	void eigen_cubic(); 
	void eigenvector();
};



#endif