#include <iostream>
thread_local int y;

int main() {
	static int i{};
	int x{};
	constexpr int ID = 100;
	auto fn = [x]() {
		std::cout << ID << ' ' << x << ' ' << i;
		std::cout << "thread local:" << y;
		};
}
