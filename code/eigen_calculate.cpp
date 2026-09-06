#include <iostream>
#include "matrix.h"
#include <string>
#include <iomanip>
#include <complex>
#include <cstdlib>
#include <cmath>
#include<vector>
using namespace std;

//							EIGEN VALUE
//					2222222222222222x22222222222222
void Matrix::eigen_quadratic()
{
	complex<double>eigenvalue1, eigenvalue2;
	complex<double> denta;
	//x^2 +bx +c
	denta = (quadratic_coefficient_one() * quadratic_coefficient_one() - 4.0 * quadratic_coefficient_two());
	if (real(denta) !=0)
	{
		eigenvalue1 = ((-quadratic_coefficient_one()+sqrt(denta))/ 2.0);
		cout << "eigenvalue1 = ";
		complex_print(eigenvalue1);
		cout << endl;
		Matrix one = A_minus_x_I(eigenvalue1);
		//test
		//cout << "A-xI:" << endl;
		//one.print();
		//cout << endl;
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;


		eigenvalue2 = ((-quadratic_coefficient_one()-sqrt(denta)) / 2.0);
		cout << "eigenvalue2 = ";
		complex_print(eigenvalue2);
		cout << endl;
		Matrix two = A_minus_x_I(eigenvalue2);
		//test
		//cout << "A-xI:" << endl;
		//two.print();
		//cout << endl;
		two.reducedRowEchelonForm();
		two.zero_detect_matrix();
		//two.print();
		cout << "eigenvector: \n";
		two.eigenvector();
		cout << endl;
		

	}
	if (real(denta) == 0)
	{
		eigenvalue1 = ((-quadratic_coefficient_one()) / 2.0);
		cout << "eigenvalue = " << real(eigenvalue1) <<	"(multiplicity of 2)\n";
		Matrix one = A_minus_x_I(eigenvalue1);
		//test
		//cout << "A-xI:" << endl;
		//one.print();
		cout << endl;
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;

	}
}
//						33333333333333x3333333333333333
void Matrix::eigen_cubic()
{
	complex<double>eigenvalue1, eigenvalue2, eigenvalue3;
	eigenvalue1 = cbroot1();  //real root
	//cout << "eigenvalue1 = ";
	//complex_print(eigenvalue1);
	//cout << endl;

	eigenvalue2 = cbroot2();	//complex root
	//cout << "eigenvalue2 = ";
	//complex_print(eigenvalue2);
	//cout << endl;

	eigenvalue3 = cbroot3();	//complex root
	//cout << "eigenvalue3 = ";
	//complex_print(eigenvalue3);
	//cout << endl;
	
	//distint roots (2 case:)<-complex eigenvalue only in this case
	if (eigenvalue1 != eigenvalue2 && eigenvalue2 != eigenvalue3 && eigenvalue1 != eigenvalue3)
	{
		cout << "eigenvalue1 = ";
		complex_print(eigenvalue1);
		cout << endl;
		Matrix one = A_minus_x_I(eigenvalue1);
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;

		cout << "eigenvalue2 = ";
		complex_print(eigenvalue2);
		cout << endl;
		Matrix two = A_minus_x_I(eigenvalue2);
		//two.print();
		two.reducedRowEchelonForm();
		two.zero_detect_matrix();
		//two.print();
		cout << "eigenvector: \n";
		two.eigenvector();
		cout << endl;

		cout << "eigenvalue3 = ";
		complex_print(eigenvalue3);
		cout << endl;
		Matrix three = A_minus_x_I(eigenvalue3);
		//three.print();
		three.reducedRowEchelonForm();
		three.zero_detect_matrix();
		//three.print();
		cout << "eigenvector: \n";
		three.eigenvector();
		cout << endl;
	}
	//1 root 
	if (eigenvalue1 == eigenvalue2 && eigenvalue2 == eigenvalue3)
	{
		cout << "eigenvalue = ";
		complex_print(eigenvalue1);
		cout << " (with multiplicity of 3)\n";
		Matrix one = A_minus_x_I(eigenvalue1);
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;
	}
	//2 complex root equal but different from real root
	if (eigenvalue2 == eigenvalue3 && eigenvalue2 != eigenvalue1)
	{
		cout << "eigenvalue1 = ";
		complex_print(eigenvalue1);
		cout << endl;
		Matrix one = A_minus_x_I(eigenvalue1);
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;

		cout << "eigenvalue2 = ";
		complex_print(eigenvalue2);
		cout << " (with multiplicity of 2)\n";
		Matrix two = A_minus_x_I(eigenvalue2);
		two.reducedRowEchelonForm();
		two.zero_detect_matrix();
		//two.print();
		cout << "eigenvector: \n";
		two.eigenvector();
		cout << endl;
	}
	//2 complex root is distinct but one of them is same as real root (1)
	if (eigenvalue1 == eigenvalue2 && eigenvalue2 != eigenvalue3)
	{
		cout << "eigenvalue1 = ";
		complex_print(eigenvalue1);
		cout << " (with multiplicity of 2)\n";
		Matrix one = A_minus_x_I(eigenvalue1);
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;

		cout << "eigenvalue2 = ";
		complex_print(eigenvalue3);
		cout << endl;
		Matrix two = A_minus_x_I(eigenvalue3);
		two.reducedRowEchelonForm();
		two.zero_detect_matrix();
		//two.print();
		cout << "eigenvector: \n";
		two.eigenvector();
		cout << endl;

	}
	//2 complex root is distinct but one of them is same as real root (2)
	if (eigenvalue1 == eigenvalue3 && eigenvalue3 != eigenvalue2)
	{
		cout << "eigenvalue1 = ";
		complex_print(eigenvalue1);
		cout << " (with multiplicity of 2)\n";
		Matrix one = A_minus_x_I(eigenvalue1);
		one.reducedRowEchelonForm();
		one.zero_detect_matrix();
		//one.print();
		cout << "eigenvector: \n";
		one.eigenvector();
		cout << endl;
		
		cout << "eigenvalue2 = ";
		complex_print(eigenvalue2);
		cout << endl;
		Matrix two = A_minus_x_I(eigenvalue2);
		two.reducedRowEchelonForm();
		two.zero_detect_matrix();
		//two.print();
		cout << "eigenvector: \n";
		two.eigenvector();
		cout << endl;
	}


	//test
	//cout << "\nm=" << m() << endl;
	//cout << "l=" << l() << endl;
	//cout << "s=" << s() << endl;
	//cout << "alpha=" << alpha() << endl;
	//cout << "beta=" << beta() << endl;
	//cout << zero_detect2(omega() * alpha() + omega2() * beta());
}
//				EIGEN VECTOR FIND
void Matrix::eigenvector()
{
	//last row of (A-xI) in reduced echelon form always zero
	complex<double> a, b, c, d, e, f;
	if (row == 2) //2x2 matrix cases
	{
		a = entry[0][0];
		b = entry[0][1];
		if (abs(a)<1e-10 && abs(b) < 1e-10)//simply a=b=0 (tolerance debug)
		{
			cout << "[ 1, 0]\n";
			cout << "[ 0, 1]\n";
		}
		else
		{
			if ((abs(a)<1+1e-10||abs(a)>1-1e-10) && abs(b) >1e-10)//simply a=1 and b is not 0
			{
				d = a;
				a = negative_zero_debug(-b);
				b = d;
			}
			if (((abs(a) < 1 + 1e-10 || abs(a) > 1 - 1e-10) && (abs(b) < 1e-10)) || ((abs(b) < 1 + 1e-10 || abs(b) > 1 - 1e-10) && (abs(a) < 1e-10)))// simply a=1 and b=0 or b=1 and a=0
			{
				d = a;
				a = b;
				b = d;

			}
			cout << "[ ";
			complex_print(a);
			cout << ", ";
			complex_print(b);
			cout << " ]\n";
		}
	}
	int count1=0, count2=0;//count number of 1 in each row to devide into different cases

	if (row == 3) //3x3 matrix cases
	{
		a = entry[0][0];
		b= entry[0][1];
		c= entry[0][2];
		d= entry[1][0];
		e= entry[1][1];
		f= entry[1][2];
		//check for number of 1 in each row
		for (int j = 0; j < col; j++)
			if (abs(entry[0][j]) < 1 + 1e-10 || abs(entry[0][j]) > 1 - 1e-10) // if entry[0][j]=1
				count1++;
		for (int j = 0; j < col; j++)
			if (abs(entry[1][j]) < 1 + 1e-10 || abs(entry[1][j]) > 1 - 1e-10) // if entry[0][j]=1
				count2++;
		if (count1 == 0 && count2 == 0)
		{
			cout << "[ 1, 0, 0]\n";
			cout << "[ 0, 1, 0]\n";
			cout << "[ 0, 0, 1]\n";
		}
		if (count1 == 1 && count2 == 1)//case of leading 1 and 0 only
		{
			if(abs(a) < 1e-10&&abs(d)<1e-10) //a = b =0
				cout << "[ 1, 0, 0]\n";
			if(abs(b) < 1e-10 && abs(e) < 1e-10)
				cout << "[ 0, 1, 0]\n";
			if(abs(c) < 1e-10 && abs(f) < 1e-10)
				cout << "[ 0, 0, 1]\n";
		}
		else
		{
			if (abs(c) > 1e-10 && abs(f) > 1e-10) //c and f is not zero
			{
				a = negative_zero_debug(-c);
				e = negative_zero_debug(-f);
				cout << "[ ";
				complex_print(a);
				cout << ", ";
				complex_print(e);
				cout << ", 1 ]\n";
			}
			else
			{
				//check for 0 column first
				if (abs(a) < 1e-10 && abs(d) < 1e-10) //a = b =0
					cout << "[ 1, 0, 0]\n";
				if (abs(b) < 1e-10 && abs(e) < 1e-10)
					cout << "[ 0, 1, 0]\n";
				if (abs(c) < 1e-10 && abs(f) < 1e-10)
					cout << "[ 0, 0, 1]\n";

				//
				if (abs(a) < 1e-10)
				{
					if (abs(b) > 1e-10 && abs(c) > 1e-10)
					{
						b = negative_zero_debug(-c);
						c = 1;
						cout << "[ 0, ";
						complex_print(b);
						cout << ", ";
						complex_print(c);
						cout << " ]\n";
					}
					if (abs(e) > 1e-10 && abs(f) > 1e-10)
					{
						e = negative_zero_debug(-f);
						f = 1;
						cout << "[ 0, ";
						complex_print(e);
						cout << ", ";
						complex_print(f);
						cout << " ]\n";
					}
					return;
				}
				if (abs(b) > 1e-10&& (abs(a) < 1 + 1e-10 || abs(a) > 1 - 1e-10))//b!=0 and a=1
				{
					a = negative_zero_debug(-b);
					b = 1;
					cout << "[ ";
					complex_print(a);
					cout << ", ";
					complex_print(b);
					cout << ", 0 ]\n";
				}
				if (abs(c) > 1e-10&& (abs(a) < 1 + 1e-10 || abs(a) > 1 - 1e-10))//c!=0 and a=1
				{
					a = negative_zero_debug(-c);
					c = 1;
					cout << "[ ";
					complex_print(a);
					cout << ", 0, ";
					complex_print(c);
					cout<<" ]\n";
				}

			}
		}
	}
}
