#include <iostream>
#include <cmath>

using namespace std;


typedef double(*function)(double x);


double fmin(double a, double b, function f, const double eps = 1e-4)
{
    double h = abs(a - b) * eps;

    double x1 = a, x2 = a + h, x3 = a + h + h;

    while(abs(x3 - x2) >= eps)
    {
        double nk, pk;

        nk = ((x2 - x3)/(x2 - x1)) * ((f(x3) - f(x1))/(x3 - x1)) +
             ((x3 - x1)/(x2 - x1)) * ((f(x2) - f(x3))/(x2 - x3));
        pk = (1 / (x2 - x1)) * (((f(x2) - f(x3))/(x2 - x3)) - ((f(x3) - f(x1))/(x3 - x1)));

        x1 = x2;
        x2 = x3;
        x3 = x3 - nk / (2 * pk);
    }
    return x3;
}



double f(double x)
{
  return x * (x + 5) + 3 * sin(x - 1);
}


int main()
{

    double vmin = fmin(-5, 5, f);
    cout << "\nmin:\t" << vmin << ";\t func[ " << vmin << " ] = " << f(vmin) << ";\n\n";

}