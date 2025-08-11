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

int(*GetOperation(int index))(int) {
	if (index == 0)return Square;
	if (index == 1) return Double;
	if (index == 2) return Increment;
	throw std::logic_error{ "Invalid index" };
}

Operation GetOp(int index) {
	//if (index == 0)return Square;
	//if (index == 1) return Double;
	//if (index == 2) return Increment;
	//throw std::logic_error{ "Invalid index" };

	//int (*operations[3])(int) {Square, Double, Increment};
	Operation operations[3] {Square, Double, Increment};
	assert(index < std::size(operations)) ;
	return operations[index] ;
}

void Invoke(Operation op) {
	std::cout << "Enter number:" ;
	int x{} ;
	std::cin >> x ;
	std::cout << "Result:" << op(x) << '\n' ;
}
