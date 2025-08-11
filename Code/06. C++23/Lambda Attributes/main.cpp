#include <iostream>
#include <numbers>
// NOTE: COMPILE WITH GCC 13 OR ABOVE
int main() {
    atexit([]{
        std::cout << "terminating...\n" ;
    }) ;
	auto f1 = [][[deprecated("Use the constant from <numbers> instead")]]()->double {
		return 3.141 ;
	} ;
	//std::cout << f1() << '\n' ;
	std::cout << std::numbers::pi << '\n' ;

    auto crash_handler = [][[noreturn]](){
        std::cout << "Unknown application crash\n" ;
        exit(0) ;
    } ;
    crash_handler() ;

    auto div = []<typename T>[[nodiscard]](T a, T b){
        return a/b ;
    } ;
    div(5,2) ;
}