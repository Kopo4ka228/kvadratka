#pragma once

/*!
\brief function that helps to compare doubles
\param value1 is a first value to compare
\param value2 is a second value to compare
\return 1 or 0
*/
int isEqual(double value1, double value2);

/*!
\brief function returns 1 if value is NAN or 0 if value is not NAn
*/
int IsNAN(double value);

/*!
    constant value, which is for comparing floats
 */

const double EPS = 1e-6;

enum Numbers
    {
    INF  = -3,
    NO   = -1,
    ZERO =  0,
    ONE  =  1,
    TWO  =  2,
    };

//-----------------------------------------------------------------------------

int IsNAN(double value)
{
    return (value != value);
}

int isEqual(double value1, double value2) /* сравнение даблов с учетом NAN */
{
    if  ((IsNAN (value1) == 1 && IsNAN (value2) == 0) ||
         (IsNAN (value1) == 0 && IsNAN (value2) == 1))
        {
            return 0;
        }

    else if(IsNAN (value1) && IsNAN (value2))
    {
            return 1;
    }
    else
    {
            return (fabs (value1 - value2) < EPS);
    }
}
