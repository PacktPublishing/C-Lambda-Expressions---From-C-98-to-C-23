#include <iostream>
template<typename...Args>
auto Process(Args...args) {
	return [...ts = std::move(args)]() {
		(std::cout << ... << ts) ;
	} ;
}

int main() {
	auto fn = Process("One ", "Two ", 3) ;
	fn() ;
}