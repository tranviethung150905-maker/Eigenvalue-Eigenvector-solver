#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "matrix.h"
#include <complex>
#include <cmath>
using namespace std;
int main()
{
	int a = 0, b = 0,c=0;
	while (b == 0) 
	{
		while (a != 1 && a != 2)
		{
			cout << "Press [1] to choose 2x2 matrix [2] to choose 3x3" << endl;
			cin >> a;
			system("cls");
		}
		c = a + 1;
		{
			Matrix A(c, c);
			A.Entryvalue();				//enter value
			cout << "Matrix:\n";
			A.print();					//print entered Matrix
			cout << "------------------Result--------------------\n";
			A.Cequation();				//print characteristic equation of the matrix
			cout << endl;
			//eigen value & eigenvector		
			if (a == 1) //matrix 2x2
			{
				A.eigen_quadratic();
			}
			if (a == 2) //matrix 3x3
			{
				A.eigen_cubic();
			}
			a = 0;
			b = 3;
			while (b != 0 && b != 1)
			{
				cout << "Press [0] to start new calculation, press [1] to end!\n";
					cin >> b;
					if (b == 0)
						system("cls");
			}
		}
	}
}