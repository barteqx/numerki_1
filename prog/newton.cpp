#include <cmath>
#include <iostream>
#include <iomanip>

void newton(double (*f)(double), double (*d)(double), double x, int iterations, double E, int precision) {
  double x_next;
  std::cout << std::setprecision(precision) << std::showpoint<< std::fixed << 0 << " & " << x << " & " << (*f)(x) << " \\\\" << std::endl;
  for (int i = 1; i < iterations; i++) {
    x_next = x - ((*f)(x)/(*d)(x));
    std::cout << std::setprecision(precision) << std::showpoint<< std::fixed << i << " & " << x_next << " & " << (*f)(x_next) << " \\\\" << std::endl;
    x = x_next;
    if (fabs((*f)(x_next)) < E ) break;
  }
}