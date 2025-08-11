#include <iostream>

#include "math_func.h"
struct SquareObj {
	int operator()(int x)const {
		return x * x;
	}
	operator Operation () {
		return __squareobj__ ;
	}
private:
	static int __squareobj__(int x) {
		return SquareObj{}(x) ;
	}
};
struct DoubleObj {
	int operator()(int x)const {
		return x * 2;
	}
	operator Operation() {
		return __doubleobj__ ;
	}
private:
	static int __doubleobj__(int x) {
		return DoubleObj{}(x) ;
	}
} ;
struct IncrementObj {
	int operator()(int x)const {
		return x + 1;
	}
	operator Operation() {
		return __incrementobj__ ;
	}
private:
	static int __incrementobj__(int x) {
		return IncrementObj{}(x) ;
	}
} ;

struct PrintWithIndex {
	int index{} ;
	void operator()(int x) {
		std::cout << index++ << '.' << x << ' ' ;
	}
	using Type = void (*)(int) ;
	operator Type() {
		return __printwithindex__ ;
	}
private:
	static void __printwithindex__(int index) {
		return PrintWithIndex{}(index) ;
	}
};
int main() {
	PrintWithIndex pwi{} ;
	void (*pPwi)(int) = pwi ;
	for (int i = 0 ; i < 5 ; ++i) {
		pPwi(i) ;
		std::cout << '\n' ;
	}
	return 0 ;
	//std::cout << "Index?";
	//int index{};
	//std::cin >> index;

	//Operation p = GetOp(index);
	SquareObj so{} ;
	Invoke(so);

	Invoke(DoubleObj{}) ;
	Invoke(IncrementObj{}) ;

	int (*p1)(int) = so ;
	Operation p2 = DoubleObj{} ;


}
