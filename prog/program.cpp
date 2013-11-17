#include <iostream>
#include <vector>
#include "methods.h"
#include "functions.h"

fptr get_func(int i) {

  switch (i) {
  case 0:
    return func_1;
    break;
  case 1:
    return func_1_d;
    break;
  case 2:
    return func_1_d_2;
    break;
  case 3:
    return func_2;
    break;
  case 4:
    return func_2_d;
    break;
  case 5:
    return func_2_d_2;
    break;
  case 6:
    return func_3;
    break;
  case 7:
    return func_3_d;
    break;
  case 8:
    return func_3_d_2;
    break;
  case 9:
    return func_4;
    break;
  case 10:
    return func_4_d;
    break;
  case 11:
    return func_4_d_2;
    break;
  }
}


int main(int argc, char const *argv[])
{
  std::vector<std::string> arguments;

  fptr function;
  fptr derivative;
  double start_x, a, b, step = 0.1;
  char method;
  bool gs_min = true;
  int iterations = 20;
  double E = 10e-10;

  for (int i = 1; i < argc; i++) {
    arguments.push_back(static_cast<std::string>(argv[i]));
  }

  while (!arguments.empty()) {

    if (arguments[0] == "-f") {
      function = get_func(std::stoi(arguments[1]));
      arguments.erase(arguments.begin(), arguments.begin()+2);
    } 

    else if (arguments[0] == "-d") {
      derivative = get_func(std::stoi(arguments[1]));
      arguments.erase(arguments.begin(), arguments.begin()+2);
    } 

    else if (arguments[0] == "-m") {
      if (arguments[1] == "newton") method = 'n';
      else if (arguments[1] == "bisection") method = 'b';
      else if (arguments[1] == "regula_falsi") method = 'r';
      else if (arguments[1] == "golden_section") method = 'g';
      else if (arguments[1] == "plot") method = 'p';
      else {
        std::cout << "Unknown method: " << arguments[1] << std::endl;
        exit(1);
      }
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-s") {
      a = std::stod(arguments[1]);
      b = std::stod(arguments[2]);
      if (b <= a) {
        std::cout << "Section cannot have 0 or negative length (check if a < b)." << std::endl;
        exit(1);
      }
      arguments.erase(arguments.begin(), arguments.begin()+3);
    }

    else if (arguments[0] == "-i") {
      iterations = std::stoi(arguments[1]);
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-error") {
      E = std::stod(arguments[1]);
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-x") {
      start_x = std::stod(arguments[1]);
      if (arguments[1][0] == '-') start_x *= -1;
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else if (arguments[0] == "-step") {
      step = std::stod(arguments[1]);
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }


    else if (arguments[0] == "-e") {
      gs_min = (arguments[1] == "min");
      if (arguments[1] != "min" && arguments[1] != "max") {
        std::cout << "Extremum must be 'max' or 'min'(default)." << std::endl;
        exit(1);
      }
      arguments.erase(arguments.begin(), arguments.begin()+2);
    }

    else {
      std::cout << "Unknown argument: " << arguments[0] << std::endl;
      exit(1);
    }
  }

  switch (method) {
  case 'p':
    plot_func((*function), a, b, step, E);
    break;
  case 'n':
    newton((*function), (*derivative), start_x, iterations, E);
    break;
  case 'b':
    bisection((*function), a, b, iterations, E);
    break;
  case 'g':
    golden_section((*function), a, b, gs_min, iterations, E);
    break;
  case 'r':
    regula_falsi((*function), a, b, iterations, E);
  }
  return 0;
}