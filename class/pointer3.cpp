#include <stdio.h>

int main(void) {
	int a = 0x12345678;
	char *p;
	
	p = reinterpret_cast<char *>(&a);
	
	printf("*p : 0x%x\n", *p);
	
	return 0;
}
