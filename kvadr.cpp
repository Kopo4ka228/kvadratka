#include <TXLib.h>
#include <stdio.h>
#include <math.h>
const int epsilon = 1e-7;
void scan_coefficients(double* , double*, double*);
void solvesquare(double, double, double);
void printroots(int);

int main()
{
    double a = 0, b = 0, c = 0;
    double  *p, *q, *r;
    p = &a;
    q = &b;
    r = &c;
    scan_coefficients(p, q, r);
    solvesquare(a, b, c);


}

void scan_coefficients(double* x, double* y, double* z) {
    scanf("%lg", x);
    scanf("%lg", y);
    scanf("%lg", z);

    }

void solvesquare(double a, double b, double c) {
            double d = b * b - 4 * a * c;
            double x1 = 0, x2 = 0;

            if (abs(d - 0) < epsilon) {
                printf("” уравнени€ нет действительных корней\n");}

            else if(abs(d-0) > epsilon) {
                x1 = (-b + pow(d, 0.5)) / (2*a);
                x2 = (-b - pow(d, 0.5)) / (2*a);
                printf("” уравнени€ 2 действительных корн€ x1 = %lf и x2 = %lf\n", x1, x2);}


            else {
                x1 = (-b + pow(d, 0.5)) / (2*a);
                printf("” уравнени€ один действитеольный корень x = %lf", x1);}

    }





