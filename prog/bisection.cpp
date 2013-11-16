#include <cmath>
#include <iostream>

void bisection(double (*f)(double), double a, double b, int iterations, double E) {
  double m;
  for (int i = 0; i < iterations; i++) {
    m = (b-a)/2;
    if ((*f)(a)*(*f)(m) < 0) {
      b = m;
    } else {
      a = m;
    }
    std::cout << m << '\t' << (*f)(m) << std::endl;
  if (fabs((*f)(m)) < E) break;
  }
}