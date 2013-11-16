#include <cmath>
#include <iostream>

double K = (sqrt(5)-1)/2;

void golden_section(double (*f)(double), double a, double b, bool min, int iterations, double E) {
  double x_L, x_R, l;
  for (int i = 0; i < iterations; i++) {
    l = K*(b-a);
    x_R = a + l;
    x_L = b - l;
    if (min) {
      if ((*f)(x_L) > (*f)(x_R)) {
        a = x_L;
      } else {
        b = x_R;
      }
    } else {
      if ((*f)(x_R) > (*f)(x_L)) {
        b = x_R;
      } else {
        a = x_L;
      }
    }
    std::cout << (b-a) << '\t' << (*f)(b-a) << std::endl;
    if (b - a < E) break;
  }
}