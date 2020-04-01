#include <printf.h>
#include <cmath>
#include <mach/port.h>
#include <stdexcept>

/**
 * 5.1 - solution
 */
double simpleFunction(int s, int t, double x) {
    double numerator = t + pow(x, 3);

    if (s % 2 == 0 || numerator < 0) {
        throw std::invalid_argument("negative below square root");
    }
    if ((s < 0 && numerator == 0) || x == 1) {
        throw std::invalid_argument("division by zero");
    }

    return pow(t + pow(x, 3), 1.0 / s) / (t * log(x)) ;
}
