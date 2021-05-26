#include <stdio.h>

int main(void)
{
	int korean, math, english;
	
	printf("input korean math english : ");
	scanf("%d %d %d", &korean, &math, &english);
	
	int sum = korean + math + english;
//	double average = sum / 3.0;
	double average = static_cast<double>(sum) / 3;
	
	printf("sum:  %d,\taverage:  %.2f\n", sum, average);
	
	return 0;
}
