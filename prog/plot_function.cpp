#include <cmath>
#include <iostream>
#include <iomanip>

void plot_func(double (*f)(double), double a, double b, double step, double E) {
  double current = a;
  std::cout << std::setprecision(40) << current << '\t' << (*f)(current) << std::endl;
  do {
    current += step;
    std::cout << std::setprecision(40) << current << '\t' << (*f)(current) << std::endl;
  } while (current <= b);
}