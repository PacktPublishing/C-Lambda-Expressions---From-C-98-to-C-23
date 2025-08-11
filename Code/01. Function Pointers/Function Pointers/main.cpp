#include <iostream>

#include "math_func.h"

int main() {
	//std::cout << "Square(2)    = " << Square(2) << '\n' ;
	//std::cout << "Double(3)    = " << Double(3) << '\n' ;
	//std::cout << "Increment(4) = " << Increment(4)<< '\n' ;
	//int (_cdecl *p)(int) ;
	//p = Square ;
	//std::cout << "Square(2)    = " << p(2) << '\n' ;
	//p = Double ;
	//std::cout << "Double(3)    = " << p(3) << '\n' ;
	//p = Increment ;
	//std::cout << "Increment(4) = " << p(4)<< '\n' ;

	std::cout << "Index?" ;
	int index{} ;
	std::cin >> index ;

	Operation p = GetOp(index);
	Invoke(p) ;

}
