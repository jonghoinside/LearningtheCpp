#include <iostream>
#include "string.h"

int main() {
	String s1 = "hello, world"; //String s1("hello, world");
//	String s1 = NULL;
	String s2;
	String s3 = s1;
	
	s2 = s1;
	s2 = "greeting";
	
	String* ps = &s2;
	s2 = *ps;
	
	String s4 = ", ";
	s3 = s2 + s4;
	s3 = s3 + "world";
	
	if (s1 == s2)
		std::cout << "s1 and s2 are equal" << std::endl;
	else
		std::cout << "s1 and s2 are not equal" << std::endl;
	
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	
	const String s5 = "hello, world";
	// 컴파일러는 이 멤버 함수가 객체를 바꾸는지 안바꾸는지 알 수 없다. 그래서 오류가 난다.
	// 그래서 함수 선언 끝에 const를 붙여서 객체가 바뀌지 않는다는 것을 알도록 표시해준다.
	std::cout << "s5 : " << s5.c_str() << std::endl;
	std::cout << "s5 len : " << s5.length() << std::endl;
	
	return 0;	
}
