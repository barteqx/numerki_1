#include <cmath>
#include <iostream>
#include <iomanip>

double K = (sqrt(5)-1)/2;

void golden_section(double (*f)(double), double a, double b, bool min, int iterations, double E, int precision) {
  double x_L, x_R, l;
  for (int i = 0; i < iterations; i++) {
    l = K*(b-a);
    x_R = a + l;
    x_L = b - l;
    if (min) {
      if ((*f)(x_L) > (*f)(x_R)) {
        a = x_L;
        x_L = x_R;
        x_R = b - (b - a)*K;
      } else {
        b = x_R;
        x_R = x_L;
        x_L = b - (b - a)*K;
      }
    } else {
      if ((*f)(x_L) > (*f)(x_R)) {
        b = x_R;
        x_R = x_L;
        x_L = b - (b - a)*K;
      } else {
        a = x_L;
        x_L = x_R;
        x_R = b - (b - a)*K;
      }
    }
    std::cout << std::setprecision(precision) << std::showpoint<< std::fixed << i << " & " << (b+a)/2 << " & " << (*f)((b+a)/2) << " \\\\" << std::endl;
    if (b - a < E) break;
  }
}