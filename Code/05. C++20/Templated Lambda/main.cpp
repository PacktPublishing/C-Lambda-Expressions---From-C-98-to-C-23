#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <numeric>
template<typename...Args>
void Print(Args&&...args) {
	(std::cout << ... << args) ;
}
int main(){
	auto compare = []<typename T>(T x,T y) {
		return x < y ;
	} ;
	int i = -5 ;
	unsigned int j = 10 ;
	//std::cout << std::format("{} < {} ? {}\n", i, j, compare(i,j)) ;

	int arr[]{1,2,3,4} ;
	auto fn = []<typename T, size_t size>(const T (&a)[size]) {
		std::cout << sizeof(a) << '\n' ;
	} ;
	fn(arr) ;

	std::vector<int> v{1,2,3,4} ;
	/*auto use_vector = [](const auto &v) {
		using Container =std::decay_t<decltype(v)> ;
		using Type = typename Container::value_type ;
		Type result = std::accumulate(v.begin(), v.end(), Type{}) ;
		return result ;
	} ;*/

	auto use_vector = []<typename T>(const std::vector<T> &v) {
		using Type = T;
		Type result = std::accumulate(v.begin(), v.end(), Type{}) ;
		return result ;
	} ;

	std::cout << "Sum:" << use_vector(v) << '\n' ;

	/*auto print = [](auto&&...args) {
		Print(std::forward<decltype(args)> (args)...) ;
	} ;*/
	auto print = []<typename T>(T&&...args) {
		Print(std::forward<T> (args)...) ;
	} ;
}