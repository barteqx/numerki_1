#include <cmath>
#include <iostream>
#include <iomanip>

void bisection(double (*f)(double), double a, double b, int iterations, double E) {
  double m;
  for (int i = 0; i < iterations; i++) {
    m = (b+a)/2;
    std::cout << std::setprecision(40) << m << '\t' << (*f)(m) << std::endl;
    if ((*f)(a)*(*f)(m) < 0) {
      b = m;
    } else if ((*f)(b)*(*f)(m) < 0){
      a = m;
    }

    
  if (fabs((*f)(m)) < E || (*f)(a)*(*f)(b) >= 0) break;
  }
}