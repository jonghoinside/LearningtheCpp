#include <stdio.h>

int main(void)
{
	int man, woman;
	printf("input #man #woman : ");
	scanf("%d %d", &man, &woman);
	
//	double manRatio = 100.0*man/(man+woman);
//	double womanRatio = 100.0*woman/(man+woman);
	double manRatio = static_cast<double>(man)/(man+woman)*100;
	double womanRatio = static_cast<double>(woman)/(man+woman)*100;
	
	printf("Man Ratio : %.2f%%\tWoman Ratio : %.2f%%\n", manRatio, womanRatio);
	
	return 0;
}
