#include <iostream>
#include <string>

int main() {
	std::string text = "Hello world!" ;
	auto printText = [&text = std::as_const(text)]() {
		std::cout << text << '\n' ;
		//text = "Goodbye!" ;
	} ;
	printText() ;
	printText() ;

	auto ptr = std::make_unique<int>(42) ;
	auto printPtr = [&ptr = (ptr)]() {
		std::cout << *ptr << '\n' ;
		ptr.reset() ;
	} ;
	printPtr() ;
	printPtr() ;
}
