#pragma once

#include "useful_funcs.h"

/*!
\brief function returns a number of roots and fills values of x1 and x2
\details also function checks the correctness of input values
\param a is a first coefficient
\param b is a second coefficient
\param c is a third coefficient
\param x1 is an address of first root
\param x2 is an address of second root
*/
int SolveSquare(double a, double b, double c, double* x1, double* x2);

/*!
\brief  solves equations when a is zero
\param b is a second coefficient
\param c is a third coefficient
\param x is an address of root
\return number of roots
*/
int SolveLinear(double b, double c, double* x);

//-----------------------------------------------------------------------------

int SolveSquare(double a, double b, double c, double* x1, double* x2)
    {
        $(a), $(b), $(c);

        double d = b * b - 4 * a * c;

        if (fabs(d) > EPS)
        {
            if (d > 0)
            {
                *x1 = (-b + sqrt(d)) / (2*a);
                *x2 = (-b - sqrt(d)) / (2*a);
                 return TWO;
            }
            else
            {
                return ZERO;
            }
        }
        else
            {
                *x1 = (-b + sqrt(d)) / (2*a);
                return ONE;
            }
    }

//-----------------------------------------------------------------------------

int SolveLinear(double b, double c, double* x) //ассерты добавить
{
    assert (isfinite (b));
    assert (isfinite (c));

    if (!isEqual (b, 0))
    {
        *x = (-c / $(b));
        return ONE;
    }
    else
    {
        if (isEqual (c, 0)) return INF; // даблы
        else                return ZERO;
    }

}
