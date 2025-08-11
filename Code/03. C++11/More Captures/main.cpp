#include <algorithm>
#include <iostream>
#include <vector>

class Numbers {
	std::vector<int> m_Numbers{} ;
public:
	Numbers(){
		m_Numbers.resize(10) ;
		std::generate(m_Numbers.begin(), m_Numbers.end(), []() {
			return rand() % 10 ;
		}) ;
	}
	auto GetPrinter() {
		return [*this]() {
			for (auto n : m_Numbers) {
				std::cout << n << ' ' ;
			}
		} ;
	}
};
template<typename...Args>
void Print(Args&&...args) {
	auto printer = [&args...]() {
		(std::cout << ... << args) << '\n' ;
	} ;
	printer() ;
}
int main() {
	Print(1,2,3,4) ;
	return 0 ;

	Numbers *numbers = new Numbers{} ;
	auto printer = numbers->GetPrinter() ;
	delete numbers ;
	printer() ;
}
void CaptureDefaults() {
	int x = 1, y = 2, z = 3;
	auto fn1 = [=, &z](int param) {
		return x + y + z + param;
		};
	auto fn2 = [&, z](int param) {
		return x + y + z + param;
		};
}