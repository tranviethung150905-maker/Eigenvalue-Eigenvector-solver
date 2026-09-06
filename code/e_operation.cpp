#include <iostream>
#include "matrix.h"
#include <string>
#include <iomanip>
#include <complex>
#include <cmath>
#include <cstdlib>
using namespace std;
                    //ELEMENTARY OPERATION
void Matrix::interchange(int r1, int r2) 
{
    for (int i = 0; i < col; i++) 
    {
        complex<double> temp = entry[r1][i];
        entry[r1][i] = entry[r2][i];
        entry[r2][i] = temp;
    }
}
void Matrix::c_row(int r, complex<double> scalar)
{
    for (int i = 0; i < col; i++) 
    {
        entry[r][i] *= scalar;
    }
}
void Matrix::add_row(int r1, int r2, complex<double> scalar) 
{
    for (int i = 0; i < col; i++) 
    {
        entry[r1][i] += scalar * entry[r2][i];
    }
}
void Matrix::reducedRowEchelonForm()
{
    int lead = 0;
    for (int r = 0; r < row; r++)
    {
        if (lead >= col) return; // stop if there are no more columns to process

        int i = r;
        // find row with a non-zero leading entry column by column
        while (entry[i][lead] == complex<double>(0, 0)||abs(entry[i][lead])<1e-7) //simply entry=0
        {
            i++;
            if (i == row) 
            {
                i = r; 
                lead++;
                if (lead == col) return; // no more columns to process
            }
        }

        // swap rows if necessary
        if (i != r) 
        {
            interchange(r, i);
        }

        // scale the row to make the leading entry 1
        complex<double> pivot = entry[r][lead];
        if (pivot != complex<double>(0, 0)||abs(pivot)<1e-10) 
        {
            c_row(r, complex<double>(1) / pivot); // scale the row so the pivot is 1
        }

        // eliminate all other entries in this column
        for (int i = 0; i < row; i++) 
        {
            if (i != r)
            {
                complex<double> coeff = entry[i][lead];
                if (coeff != complex<double>(0, 0)||abs(coeff)<1e-10) 
                {
                    add_row(i, r, negative_zero_debug( - coeff)); // subtract coeff times of row r to row i
                }
            }
        }

        lead++;
    }          
}
