#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

void ForEach(int(&arr)[4], std::function<void(int)> display) {
	std::for_each(std::begin(arr), std::end(arr), display);
}
class Test {
	std::function<void (int)> m_Callable ;
};
int main() {
	int arr[]{ 1,2,3,4 };
	/*std::function<void (int)>*/ auto display = [](int x) {
		std::cout << x << ' ';
	} ;
	ForEach(arr, display) ;
	std::cout << '\n';
	int low = 2, high = 6 ;
	std::function<void (int)> range = [low, high](int x) {
		if (x >= low && x <= high) {
			std::cout << x << ' ';
		}
	} ;
	std::for_each(std::begin(arr), std::end(arr),range);
	std::cout << '\n';
	
}
