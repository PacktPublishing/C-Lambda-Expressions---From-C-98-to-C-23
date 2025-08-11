#include <iostream>

int main() {
    atexit([]{
        std::cout << "terminating...\n" ;
    }) ;

	auto separator = [] {
		std::cout << "---------------------\n" ;
	} ;
	separator() ;
	std::cout << "Using capture lists\n" ;

	int i{} ;
	int inc = 2 ;
	auto gen = [i, inc]mutable {
		return i+=inc ;
	} ;

	for (int i = 0 ; i < 5 ; ++i) {
		std::cout << gen() << ' ' ;
	}
}
