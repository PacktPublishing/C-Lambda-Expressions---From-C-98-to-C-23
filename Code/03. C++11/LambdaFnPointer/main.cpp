#include <iostream>

#include "math_func.h"
struct SquareObj {
	int operator()(int x)const {
		return x * x;
	}
	operator Operation () {
		return __squareobj__;
	}
private:
	static int __squareobj__(int x) {
		return SquareObj{}(x);
	}
};
struct DoubleObj {
	int operator()(int x)const {
		return x * 2;
	}
	operator Operation() {
		return __doubleobj__;
	}
private:
	static int __doubleobj__(int x) {
		return DoubleObj{}(x);
	}
};
struct IncrementObj {
	int operator()(int x)const {
		return x + 1;
	}
	operator Operation() {
		return __incrementobj__;
	}
private:
	static int __incrementobj__(int x) {
		return IncrementObj{}(x);
	}
};

struct PrintWithIndex {
	int index{};
	void operator()(int x) {
		std::cout << index++ << '.' << x << ' ';
	}
	using Type = void (*)(int);
	operator Type() {
		return __printwithindex__;
	}
private:
	static void __printwithindex__(int index) {
		return PrintWithIndex{}(index);
	}
};
int main() {
	atexit([]() {
		std::cout << "Program is exitting...\n" ;
	}) ;

	//SquareObj so{};
	//Invoke(so);

	//Invoke(DoubleObj{});
	//Invoke(IncrementObj{});

	auto so = [](int x) {
		return x *x ;
	} ;
	int (*p1)(int) = so;
	Invoke([](int x) {
		return x * 2 ;
	}) ;
	//return 0 ;
	//Operation p2 = DoubleObj{};

	//PrintWithIndex pwi{};
	int index = 0 ;
	auto pwi = [index](int x) {
		std::cout << index << ". " << x ;
	} ;
	/*void (*pPwi)(int) = pwi;
	for (int i = 0; i < 5; ++i) {
		pPwi(i);
		std::cout << '\n';
	}*/
	return 0;

}
