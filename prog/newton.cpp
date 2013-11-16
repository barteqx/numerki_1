#include <cmath>
#include <iostream>

void newton(double (*f)(double), double (*d)(double), double x, int iterations, double E) {
  double x_next;
  for (int i = 0; i < iterations; i++) {
    x_next = x - ((*f)(x)/(*d)(x));
    std::cout << x_next << '\t' << (*f)(x_next) << std::endl;
    x = x_next;
    if (fabs((*f)(x_next)) < E ) break;
  }
}