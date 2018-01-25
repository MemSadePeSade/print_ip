#include"print.h"
#include<vector>

int main()
{
	print(char(-1), std::cout);
	print(short(0), std::cout);
	print(int(2130706433), std::cout);
	print(long long int(8875824491850138409), std::cout);
	print(std::string("1.0.1.0"), std::cout);
	print(std::vector<int>{0,1,2,3}, std::cout);
	print(std::list<int>{0,1,2}, std::cout);
	print(std::tuple<int, int>{5, 25}, std::cout);
	
	return 0;
}