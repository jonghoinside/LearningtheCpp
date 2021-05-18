#include <iostream>

int main() {
	
	std::cout << "hello, world";
	std::cout << std::endl;
	
	// std::cout << "hello, world";
//	std::cout.operator << ("hello, world");		결과값 : 0x400a04 같은 이상한 코드, 해쉬코드의 주소값 출력
	operator << (std::cout, "hello, world");
	
	//std::cout << std::endl:
	std::cout.operator << (std::endl);
	//operator << (std::cout, std::endl);		// 오류남 std::endl이 멤버함수라서
	
	std::cout << "hello, world" << (std::endl);
	operator << (std::cout, "hello, world").operator <<(std::endl);
	
	return 0;
}
