#include <iostream>
template<typename T>
concept FloatingPoint = std::is_floating_point_v<T> ;
int main() {
	/*auto div = []<typename T> requires FloatingPoint<T> (T a, T b){
		return a/b ;
	} ;*/
	/*auto div = []<typename T>  (T a, T b) requires FloatingPoint<decltype(a)>{
		return a/b ;
	} ;*/

	/*auto div = []<FloatingPoint T>  (T a, T b){
		return a/b ;
	} ;*/

	auto div = [] (FloatingPoint auto a, FloatingPoint auto b){
		return a/b ;
	} ;
	std::cout << div(5.0,2.0) << '\n' ;
}
