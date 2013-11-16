#include <cmath>
#include <iostream>

void plot_func(double (*f)(double), double a, double b, double step, double E) {
  double current = a;
  while (current <= b) {
    std::cout << current << '\t' << (*f)(current) << std::endl;
    current += step;
  }
}