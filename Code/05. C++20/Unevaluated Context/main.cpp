#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
template<typename T, typename Comparator>
class DataStore {
	Comparator m_Comparator{} ;
	std::vector<T> m_Data {};
public:
	DataStore()=default ;
	DataStore(Comparator comp):m_Comparator{comp} {
		
	}
	void Add(T element) {
		m_Data.emplace_back(std::move(element)) ;
	}
	void Sort() {
		std::sort(m_Data.begin(), m_Data.end(), m_Comparator) ;
	}
	void Display() {
		for (const auto &e : m_Data) {
			std::cout << e << ' ' ;
		}
		std::cout << '\n' ;
	}
};
bool Compare(int x,int y) {
	return x < y ;
}
int main() {
	std::unique_ptr<int, decltype([](int *p){delete p;})> p{new int{3}} ;

	//DataStore<int, bool (*)(int,int)> ds{Compare} ;
	DataStore<int, decltype([](int x,int y){return x < y;})> ds{} ;
	ds.Add(10) ;
	ds.Add(5) ;
	ds.Add(8) ;
	ds.Add(1) ;
	ds.Sort() ;
	ds.Display() ;

	//int x{} ;
	//std::cout << sizeof(x = 3) << '\n' ;
	//std::cout << x << '\n' ;
	//decltype(++x) y = x; 
	//std::cout << x << '\n' ;

	//decltype([](){}) ;
}
