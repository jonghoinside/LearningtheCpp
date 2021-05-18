#include <iostream>

int main()
{
	std::cout << "hello,world";
	std::cout << std::endl;
	
	// std::cout << "hello, world";
	//std::cout.operator<<("hello,world");
	operator << (std::cout, "hello, world");
	
	// std::cout << std::endl;
	std::cout.operator<< (std::endl);
	//operator << (std::cout, std::endl);
	
	std::cout << "hello, world" << std::endl;
	operator << (std::cout,"hello, world").operator << (std::endl);
	return 0;
}
	
