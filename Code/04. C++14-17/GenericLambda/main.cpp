#include <algorithm>
#include <iostream>
#include <vector>

int main(){
	auto pretty_printer = [](auto x) {
		std::cout << "Data is:" << x << '\n' ;
	} ;
	pretty_printer(100) ;
	pretty_printer(200) ;

	std::string s = "Using lambdas" ;
	pretty_printer(s) ;

	std::vector<int> numbers{5,1,8,9,0} ;
	std::vector<std::string> names{"Joe", "Lisa", "Harry", "John", "Umar"} ;
	auto compare = [](auto x,auto y) {
		return x < y ;
	} ;
	std::sort(numbers.begin(), numbers.end(), compare ) ;
	std::sort(names.begin(), names.end(), compare ) ;

}
