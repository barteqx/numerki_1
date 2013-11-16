#include <cmath>
#include <iostream>

void regula_falsi(double (*f)(double), double a, double b, int iterations, double E) {
  double x = (a*(*f)(b) - b*(*f)(a))/((*f)(b) - (*f)(a));
  double x_next;
  for (int i = 0; i < iterations; i++) {
    if ((*f)(a)*(*f)(x) <= 0) {
      x_next = (x*(*f)(b) - b*(*f)(x))/((*f)(b) - (*f)(x));
    } else if ((*f)(x)*(*f)(b) < 0) {
      x_next = (a*(*f)(x) - x*(*f)(a))/((*f)(x) - (*f)(a));
    }
    std::cout << x_next << '\t' << (*f)(x_next) << std::endl;
    x = x_next;
    if (fabs((*f)(x_next)) < E) break;
  }
}