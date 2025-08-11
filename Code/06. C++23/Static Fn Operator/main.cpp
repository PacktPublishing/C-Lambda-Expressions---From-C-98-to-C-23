struct Square1 {
	int operator() (int x)const {
		return x * x;
	}
};
struct Square2 {
	static int operator() (int x) {
		return x * x;
	}
};
//NOTE : COMPILE WITH GCC 13 OR ABOVE
int main() {
	//Square1 sq1{} ;
	//Square2 sq2{} ;
	//sq1(2) ;
	//sq2(3) ;

	auto sq1 = [](int x) {
		return x * x;
		};

	auto sq2 = [](int x)static{
		return x * x;
	};

	sq1(2);
	sq2(3);
}