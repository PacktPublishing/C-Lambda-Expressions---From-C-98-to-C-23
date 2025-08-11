#include <algorithm>
#include <iostream>
#include <vector>


int main() {
	int arr[]{ 1,2,3,4 };
	auto display = [](int x) {
		std::cout << x << ' ';
		} ;
	std::for_each(std::begin(arr), std::end(arr), display);
	std::cout << '\n';
	int low = 2, high = 6 ;
	std::for_each(std::begin(arr), std::end(arr), [low, high](int x) {
		if (x >= low && x <= high) {
			std::cout << x << ' ';
		}
		});
	std::cout << '\n';
	int index{} ;
	std::for_each(std::begin(arr), std::end(arr), [index](int x)mutable {
		std::cout << index++ << '.' << x << '\n';
	});

	std::vector<int> target{} ;
	int multiplier = 2 ;
	std::transform(std::begin(arr), std::end(arr),std::back_inserter(target), 
		[multiplier](int x) {
			return x * multiplier ;
	} ) ;
	std::cout << "\nTarget vector\n" ;
	std::for_each(std::begin(target), std::end(target), display);

}

void Display(int x) {
	std::cout << x << ' ';
}
void DisplayWithIndex(int x) {
	static int i{};
	std::cout << i++ << '.' << x << '\n';
}
void PrintRange(int x) {
	if (x >= 2 && x <= 6) {
		std::cout << x << ' ';
	}
}
void OldCode() {
	int arr[]{ 1,2,3,4 };
	std::for_each(std::begin(arr), std::end(arr), Display);
	std::cout << '\n';
	std::for_each(std::begin(arr), std::end(arr), PrintRange);
	std::cout << '\n';
	std::for_each(std::begin(arr), std::end(arr), DisplayWithIndex);
}