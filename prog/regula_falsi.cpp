#include <cmath>
#include <iostream>
#include <iomanip>

void regula_falsi(double (*f)(double), double a, double b, int iterations, double E, int precision) {
  double x = (a*(*f)(b) - b*(*f)(a))/((*f)(b) - (*f)(a));
  std::cout << std::setprecision(precision) << std::showpoint << std::fixed << x << '\t' << (*f)(x) << std::endl;
  double x_next;
  for (int i = 0; i < iterations; i++) {
    if ((*f)(a)*(*f)(x) <= 0) {
      x_next = (x*(*f)(a) - a*(*f)(x))/((*f)(a) - (*f)(x));
    } else if ((*f)(x)*(*f)(b) < 0) {
      x_next = (x*(*f)(b) - b*(*f)(x))/((*f)(b) - (*f)(x));
    }
    std::cout << std::setprecision(precision) << std::showpoint << std::fixed << x_next << '\t' << (*f)(x_next) << std::endl;
    x = x_next;
    if (fabs((*f)(x_next)) < E) break;
  }
}