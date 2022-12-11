#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


typedef double(*function)(double x);


int sign(double num)
{
  return (num >= 0) ? 1 : -1;
}


bool ping(double left, double right, function f)
{
  return sign(f(left)) != sign(f(right));
}


void half_divide_method(double a, double b, function f, double eps= 1e-4)
{
    double h = abs(b - a) * eps;
    double x = a;
    int i = 2;

    while (pow(10, i) * eps <= 1)
    {
        i++;
    }

    while(x < b)
    {
        double k = x;
        x += h;

        if (ping(x, k, f))
        {
            double left = k;
            double right = x;
            double p = 0;
            while((abs(right - left) >= eps) || (f(right) >= eps) || (abs(right - left) / right >= eps))
            {
                p = (left + right) / 2;

                if (ping(left, p, f))
                {
                    right = p;
                }
                else
                {
                    left = p;
                }
            }

            cout << "\nroot:\t" << setprecision(i) << p << ";\t func[ " << p << " ] = " << f(p) << ";\n\n";
        }
    }
}

double func(double x)
{
  return exp(-x) - sin(x);
}

int main()
{

    half_divide_method(0, 1, func);

    return 0;
}