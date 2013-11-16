#include <cmath>

double PI = 3.14159265359;
//First function
double func_1 (double x) { return sin(2*PI*x); }

double func_1_d (double x) { return 2*PI*cos(2*PI*x); }

double func_1_d_2 (double x) { return -4*pow(PI, 2)*sin(2*PI*x); }

//Second function
double func_2 (double x) { return exp(pow((-1)*x, 2)); }

double func_2_d (double x) { return -2*exp(pow((-1)*x, 2))*x; }

double func_2_d_2 (double x) { return exp(pow((-1)*x, 2))*(4*pow(x, 2) - 2); }

//Third function
double func_3 (double x) { return x/(1+pow(x, 2)); }

double func_3_d (double x) { return 2*x*(pow(x, 2)-3)/pow(pow(x, 2) + 1, 3); }

double func_3_d_2 (double x) { return 6*(pow(x,4) - 6*pow(x, 2) + 1)/pow(pow(x, 2) + 1, 4); }

//Fourth function
double func_4 (double x) { return pow(x,2) + x - 1; }

double func_4_d (double x) { return 2*x + 1; }

double func_4_d_2 (double x) { return 2; }

typedef double (*fptr)(double);