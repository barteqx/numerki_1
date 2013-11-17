void golden_section(double (*f)(double), double a, double b, bool min, int iterations, double E, int precision);

void bisection(double (*f)(double), double a, double b, int iterations, double E, int precision);

void plot_func(double (*f)(double), double a, double b, double step, double E, int precision);

void regula_falsi(double (*f)(double), double a, double b, int iterations, double E, int precision);

void newton(double (*f)(double), double (*d)(double), double x, int iterations, double E, int precision);