
class Empty {

//	컴파일러가 자동적으로 만들어주는 6가지 함수
//	생성자가 없을 때 본체가 비어있는 디폴트 생성자를 만들어진다.
//	Empty() { }
//	복사생성자가 없으면 각각의 멤버들을 치환하는 생성자가 만들어진다.
//	Empty(const Empty& rhs) { all member copy! }
//	생성자가 없을 때 본체가 비어있는 디폴트 소멸자를 만들어진다.
//	멤버 변수로 포인터를 힙영역에서 생성할 경우 
//	~Empty() { }

// Empty& operator=(const Empty& rhs) { all member copy! }
//	Empty* operator&() { return this; }
//	const Empty* operator&() const { return this; }
	
};


int main() {

	Empty e1;
	Empty e2 = e1;
	
	e2 = e1;
	
	Empty *pe = &e1;
	
	const Empty e3;
	const Empty *pe2 = &e3;		//	e3.operator&()
	
	return 0;
}
