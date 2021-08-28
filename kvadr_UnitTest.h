#pragma once

#include "solving_funcs.h"
#include "useful_funcs.h"
/*!
\brief function solving linear equations when a is zero
\params testNum is a number of current test
\params double b is a second coefficient
\params c is a third coefficient
\params RootsRef is an expected number of roots
\params xref is an expected root
*/
int UnitTest_linear(int testNum, double b, double c, int RootsRef, double xref);

/*!
\brief testing function
\param nRoots is a number of roots
\param a is a first coefficient
\param b is a second coefficient
\param c is a third coefficient
\param RootsRef is an expected number of roots
\param x1ref is an expected value of first root
\param x2ref is an expected value of second root
*/

int UnitTest(int nRoots, double a, double b, double c, int RootsRef, double x1ref, double x2ref);

/*!
runs all UnitTest functions
\return number of errors
*/

int RunUnitTests(void);

//-----------------------------------------------------------------------------

int UnitTest(int testNum, double a, double b, double c,  /* тестирующая функция */
             int RootsRef, double x1ref, double x2ref)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    if((!isEqual (x1, x1ref) || !isEqual (x2, x2ref) || nRoots != RootsRef) &&
       (!isEqual (x2, x1ref) || !isEqual (x1, x2ref) || nRoots != RootsRef))
        {
            printf ("Test %d FAILED: number of roots = %d, should be: %d\n", testNum, nRoots, RootsRef);
            printf ("x1 = %lf, should be:%lf\n x2 = %lf, should be: %lf\n", x1, x1ref, x2, x2ref);
        }
}

//-----------------------------------------------------------------------------

int UnitTest_linear(int testNum, double b, double c, int RootsRef, double xref)
{
    double x = NAN;
    int nRoots = SolveLinear (b, c, &x);
    if((!isEqual (x, xref) || nRoots != RootsRef) == 0)
        {
            printf ("Test %d FAILED: number of roots = %d, should be: %d\n", testNum, nRoots, RootsRef);
            printf ("x = %lf, should be: %lf\n", x, xref);
        }

}

 //-----------------------------------------------------------------------------

int RunUnitTests(void)
{
    int failed = 0;
              //-------------------------------
              //  #  a    b    c Num  x1   x2
              //-------------------------------
    if (UnitTest (1, 1,   5,  -6, 2,   1,  -6) == 0) failed ++;
    if (UnitTest (2, 1,   0,  -4, 2,  +2,  -2) == 0) failed ++;
    if (UnitTest (3, 5,   1,   7, 0, NAN, NAN) == 0) failed ++;
    if (UnitTest (4, 1, -34, 289, 1,  17, NAN) == 0) failed ++;

    if (UnitTest_linear (5, -34, 289, 1, 289/(-34)) == 0) failed ++;

    return failed;
}
