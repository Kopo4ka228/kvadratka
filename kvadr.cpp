#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>

const double  epsilon = 1e-6;
/*!

*/
void scan_coefficients(double* , double*, double*);
int solvesquare(double, double, double, double*, double*);
void printroots(int, double*, double*);

int main()
{
    int nroots = 0;
    double a = 0,
           b = 0, c = 0, x1 = 0, x2 = 0;
    double *p = &x1;
    double *q = &x2;
    scan_coefficients(&a, &b, &c);

    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(fabs(a) > epsilon); /* сравниваем а с нулем */


    nroots = solvesquare(a, b, c, p, q);

    printroots(nroots, p, q);
    return 0;
}

void scan_coefficients(double* x, double* y, double* z)
    {

        printf("Введите коэффициенты a, b, c через пробелы\n");
        scanf("%lf %lf %lf", x, y, z);
    }

int solvesquare(double a, double b, double c, double* x1, double* x2)
        {
            double d = b * b - 4 * a * c;

            if (fabs(d) > epsilon)
            {
                if ((d = b * b - 4 * a * c) > 0)
                {
                    *x1 = (-b + pow(d, 0.5)) / (2*a);
                    *x2 = (-b - pow(d, 0.5)) / (2*a);
                    if (fabs(x1 - x2) < epsilon)
                    {
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }

                }
                else
                {
                    return 0;
                }
            }
            else
            {
                *x1 = (-b + pow(d, 0.5)) / (2*a);
                return 1;
            }
        }

void printroots(int n, double* a, double* b)
    {
        assert(a != nullptr);
        assert(b != nullptr);

        if (n == 0)
            {
            printf("Уравнение не имеет действительных корней\n");
            }
        else if (n == 1)
            {
            printf("Уравнение имеет единственный корень x = %lf\n", *a);
            }
        else
            {
            printf("Уравнение имеет 2 действительных корня x1 = %lf и x2 = %lf\n", *a, *b);
            }
    }





