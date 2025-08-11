
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string_view>
static void PrintLine(size_t size, std::ostream &out) {
	out << '+' ;
	for (size_t i = 0 ;i < size ; ++i) {
		out << '-' ;
	}
	out << '+' ;
	out << '\n' ;

}
void PrettyPrint(std::string_view message, std::ostream& out = std::cout) {
	constexpr size_t EXTRASIZE = 2 ;
	auto printline = [&out](size_t size) {
		out << '+';
		for (size_t i = 0; i < size; ++i) {
			out << '-';
		}
		out << '+';
		out << '\n';
		};
	printline(message.size() + EXTRASIZE) ;
	out << '|' << ' ' << message << " |\n" ;
	printline(message.size() + EXTRASIZE) ;

}
auto GetFn() {
	std::cout << "Enter name:" ;
	std::string name{} ;
	std::getline(std::cin, name) ;
	return [name](std::string_view message) {
		std::cout << message << ", " << name ;
	} ;
}
int main() {
	PrettyPrint("Application started")  ;
	auto fn = GetFn() ;
	fn("Welcome") ;
}

struct Person {
	std::string name{};
	int m_Age{};
};
void PersonsExample() {
	std::vector<Person> persons{
		{"John", 25},
		{"Jane", 13},
		{"Bob", 40},
		{"Charlie", 15},
		{"Eve", 55},
		{"Frank", 16},
		{"Grace", 65},
		{"Judy", 8}
	};
	std::vector<Person> voters{};
	std::copy_if(persons.begin(), persons.end(), std::back_inserter(voters), 
		[](const Person &person) {
			return person.m_Age >= 18 ;
	}) ;

	for (const auto &v : voters) {
		std::cout << v.name << '\n' ;
	}

	std::vector<std::string> voter_names{} ;
	std::for_each(persons.begin(), persons.end(), [&voter_names](const Person &p) {
		if (p.m_Age >= 18) {
			voter_names.push_back(p.name) ;
		}
	}) ;
	std::cout << '\n' ;
	for (const auto &v : voter_names) {
		std::cout << v << '\n' ;
	}
}

void Basics() {
	int result{};
	auto add = [&result](int x, int y) {
		result = x + y;
		return 0;
		};
	add(3, 5);
	std::cout << "Result:" << result << '\n';

	std::ofstream output{ "numbers.txt" };
	std::vector<int> numbers{ 1,2,3,4,5 };
	std::for_each(numbers.begin(), numbers.end(), [&output](int x) {
		output << x << '\n';
		});
}




void PrintTitle(
	std::string_view message, 
	char ch = '*', 
	std::ostream &out=std::cout );

void OldPrintTitle() {
	std::ofstream out_file{"log.txt"} ;
	PrintTitle("Application started",  '-') ;
}

void PrintTitle(std::string_view message, char ch, std::ostream &out) {
	auto print_line = [ch, &out](size_t count) {
		for (size_t i = 0 ; i < count ; ++i) {
				out << ch ;
			}
			out << '\n' ;
	} ;
	print_line(message.size()) ;
	out << message << '\n' ;
	print_line(message.size()) ;
	/*
	struct Line {
		char ch ;
		size_t count ;
		std::ostream &out ;
		void Print() {
			for (size_t i = 0 ; i < count ; ++i) {
				out << ch ;
			}
			out << '\n' ;
		}
	};
	Line line{ch, message.size(), out} ;
	line.Print() ;
	out << message << '\n' ;
	line.Print() ;
	*/
}


