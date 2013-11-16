main: main.o newton.o bisection.o regula_falsi.o golden_section.o plot_function.o
	g++ main.o newton.o bisection.o regula_falsi.o golden_section.o plot_function.o -o main -lm

main.o: program.cpp methods.h functions.h
	g++ program.cpp -std=c++11 -o main.o -c

newton.o: newton.cpp 
	g++ newton.cpp -std=c++11 -o newton.o -c

bisection.o: bisection.cpp
	g++ bisection.cpp -std=c++11 -o bisection.o -c

regula_falsi.o: regula_falsi.cpp
	g++ regula_falsi.cpp -std=c++11 -o regula_falsi.o -c

golden_section.o: golden_section.cpp
	g++ golden_section.cpp -std=c++11 -o golden_section.o -c

plot_function.o: plot_function.cpp
	g++ plot_function.cpp -std=c++11 -o plot_function.o -c