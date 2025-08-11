#include "math_func.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

int Square(int x) {
	return x * x;
}
int Double(int x) {
	return x * 2;
}
int Increment(int x) {
	return x + 1;
}

void Invoke(Operation op) {
	std::cout << "Enter number:" ;
	int x{} ;
	std::cin >> x ;
	std::cout << "Result:" << op(x) << '\n' ;
}
