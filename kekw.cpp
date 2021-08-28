/*!
\file
\mainpage
\brief the program, which solves quadratic equations
\author Arseny Andramonov
\version 1.0
\date August 2021
    Input: coefficients a,b,c
    Output: roots or message, saying, that they dont exist
 */

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "kvadr_UnitTest.h"
#include "solving_funcs.h"

/*!
\param a is an address of coefficient a
\param b is an address of coefficient b
\param c is an address of coefficient c
*/

void Scan_Coefficients(double* a , double* b, double* c);

/*!
  \brief function prints roots
  \param x1 is an address of first root
  \param x2 is an address of second root
  \param nRoots is a number of roots
  \return number of roots
*/

void Printroots(int nRoots, double* x1, double* x2);

/*!
\brief prints roots when a is zero
\param nRoots is a number of roots
\param x is an address of root
*/

void PrintLinear(int nRoots, double* x);

int main()
{
    int nroots = 0;
    double a = 0, b = 0, c = 0, x1 = NAN, x2 = NAN, x = NAN;

    Scan_Coefficients(&a, &b, &c);

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    if (isEqual (a, 0))
    {
        printf("Уравнение является линейным т.к. а = 0\n");
        nroots = SolveLinear(b, c, &x);
        PrintLinear(nroots, &x);
        return 0;
    }

    nroots = SolveSquare(a, b, c, &x1, &x2);
    Printroots(nroots, &x1, &x2);

    RunUnitTests();

    return 0;
}

void Scan_Coefficients(double* x, double* y, double* z)
    {
        printf("Введите коэффициенты a, b, c через пробелы\n");
//      int result = scanf("%lf %lf %lf", x, y, z);

        bool ok  = false;
        while (ok == false )
        {
            int result = scanf("%lf %lf %lf", x, y, z);
            if (result != 3)
                {
                    printf("Неверный ввод");
                    while (getchar() != '\n') {;}
                }
            else
                ok = true;
        }
    }


void Printroots(int nRoots, double* a, double* b)
    {
        assert(a != nullptr);
        assert(b != nullptr);

        if (n == 0)
            {
            printf("Уравнение не имеет действительных корней\n");
            }
        else if (nRoots == 1)
            {
            printf("Уравнение имеет единственный корень x = %lf\n", *a);
            }
        else
            {
            printf("Уравнение имеет 2 действительных корня x1 = %lf и x2 = %lf\n", *a, *b);
            }
    }


void PrintLinear(int nRoots, double* x)
{
  if (nRoots == ONE)
  {
    printf ("Уравнение линейное и имеет один корень x = %lf\n", *x);
  }
  else if(nRoots == ZERO)
  {
    printf ("Уравнение не имеет решений, и не будет, МУАХХХАХАХАХАХА!!!!!!11111\n");
  }
  else if(nRoots == INF)
  {
    printf ("Бесконечное количество решений\n");
  }
}












