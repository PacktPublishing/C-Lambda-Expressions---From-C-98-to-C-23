
#include <iostream>

int main(){
	auto sq = [](int x)constexpr{
		return x * x ;
	} ;
	auto result = sq(3) ;
	//int arr[result] ;
	std::cout << result << '\n' ;
}
