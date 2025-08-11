#include <iostream>
#include <functional>

struct Factorial {
	int operator()(int n)const {
		if (n <= 1) {
			return 1 ;
		}
		return n * (*this)(n-1) ;
	}
};
int main() {
	Factorial f{} ;
	std::cout << f(3) << '\n' ;

	{
		std::function<int(int)> fact = [&](int n){
			if (n <= 1) {
				return 1 ;
			}
			return n * fact(n-1) ;
		} ;
		std::cout << fact(5) << '\n' ;
	}

	{
		auto fact = [&](auto && self, int n){
			if (n <= 1) {
				return 1 ;
			}
			return n * self(self, n-1) ;
		} ;
		std::cout << fact(fact,5) << '\n' ;
	}


	auto fact = [](this auto&& self, int n) {
		if (n <= 1) {
			return 1;
		}
		return n * self(n - 1);
	};
	std::cout << fact(5) << '\n' ;

}