#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

std::string FullName(const std::string &first, const std::string &last) {
	return first + last ;
}

int main() {
	std::vector<int> data{ 1,2,3,4,5 };
	std::ofstream out{ "data.txt" };


	std::for_each(std::begin(data), std::end(data), 
		[stream = std::move(out), index{0}](int x)mutable {
		stream << index++<< ". " << x << '\n';
		});

	//out << "this is some data unrelated to the vector\n" ;
	std::string first = "Umar" ;
	std::string last = "Lone" ;
	auto print = [full_name=FullName(first, last)]() {
		std::cout << full_name << "\n" ;
	} ;
	print() ;

	auto full_name = FullName(first, last) ;
	auto printer = [&full_name = std::as_const(full_name)]() {
		std::cout << full_name << "\n" ;
	} ;
	printer() ;
	std::cout << full_name << '\n' ;

}
