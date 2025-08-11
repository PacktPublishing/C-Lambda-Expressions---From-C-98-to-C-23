int main() {
	int IDENTITY=0 ;
	auto sum1 = [IDENTITY](int x,int y)constexpr{
		return x + y + IDENTITY ;
	} ;
	int r1 = sum1(2,3) ;
	constexpr int r2 = sum1(3,4) ;

	auto sum2 = [IDENTITY](int x, int y)consteval{
		return x+y + IDENTITY;
	} ;
	int r3 = sum2(4,5) ;
}