#include <iostream>
#include <vector>

template<typename Iterator, typename Operation>
void Execute(Iterator begin, Iterator end, Operation op ) {
	for (;begin != end ; ++begin) {
		op(*begin) ;
	}
}

void Display(int x) {
	std::cout << x << ' ' ;
}
void DisplayWithIndex(int x) {
	static int i{} ;
	std::cout << i << '.' << x << ' ' ;
}
void PrintRange(int x) {
	int counter{} ;
	if (x >= 2 && x <= 6) {
		std::cout << x << ' ' ;
		++counter ;
	}
}
struct PrintRangeObj {
	int low, high ;
	void operator()(int x)const {
		if (x >= low && x <= high) {
		std::cout << x << ' ' ;
		}
	}
};
struct PrintWithIndex {
	int index ;
	void operator()(int x)const {
		std::cout << index << '.' << x << ' ' ;
	}
};
int main() {
	int arr[]{1,2,3,4} ;
	//Execute(std::begin(arr), std::end(arr), Display) ;
	//Execute(std::begin(arr), std::end(arr), DisplayWithIndex) ;
	std::cout << '\n' ;
	PrintRangeObj obj{2,6} ;
	Execute(std::begin(arr), std::end(arr), obj) ;
	PrintWithIndex pIndex{} ;
	Execute(std::begin(arr), std::end(arr), pIndex) ;
}
template<typename T>
void Print(T x) {
	std::cout << x << ' ' ;
}
void OldCode() {
	int arr[]{1,2,3,4} ;
	std::vector<std::string> langs{"C++", "C#", "Python"} ;

	/*Execute(std::begin(arr), std::end(arr), Print<int>) ;
	Execute(std::begin(langs), std::end(langs), Print<std::string>) ;*/
	
}

//struct Square{
//    int operator()(int x)const{
//			return x * x ;
//    }
//};
//
//
//int main() {
//	Square s ;
//	auto result = s(5); //s.operator()(5)
//
//}