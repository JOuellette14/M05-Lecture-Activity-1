all: main.cpp clock drink
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp clock drink -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always clock.cpp -o clock
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drink.cpp -o drink