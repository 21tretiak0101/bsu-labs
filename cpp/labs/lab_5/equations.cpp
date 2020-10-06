#include <cmath>

typedef double(*function)(double);
const double eps = 1e-9;

double calculateRoot(function f, double a, double b) {
    double c;
    while ((abs(f(b) - f(a))) > eps) {
        c = ((f(b) * a) - (f(a) * b)) / (f(b) - f(a));
        if (f(a) * f(c) > 0) {
            a = c;
        } else {
            b = c;
        }
    }
    return c;
}

double funcA(double x) {
    return pow(x + 1, 2) - 1;
}

double funcB(double x) {
    return pow(cos(M_PI * x), 2) + pow(x, 2) - 1.5;
}

int main() { }
