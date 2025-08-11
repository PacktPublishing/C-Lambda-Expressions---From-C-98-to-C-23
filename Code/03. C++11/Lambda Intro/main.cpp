#include <iostream>
template<typename Iterator, typename Operation>
void Execute(Iterator begin, Iterator end, Operation op ) {
	Operation obj{} ;
	for (;begin != end ; ++begin) {
		op(*begin) ;
	}
}

int main() {
	decltype([](){}) x ;
	auto y = x ;
	auto z = std::move(y) ;

	auto fn = []() {
		std::cout << "Hello lambda\n" ;
	} ;
	fn() ;

	auto sq = [](int x) -> auto {
		return x * x ;
	} ;
	std::cout << sq(3) << '\n' ;

	int arr[]{1,2,3,4,5} ;
	auto display = [](int x) {
		std::cout << x << ' ' ;
	} ;
	Execute(std::begin(arr), std::end(arr), [](int x) {
		std::cout << x << ' ' ;
	} ) ;
}
