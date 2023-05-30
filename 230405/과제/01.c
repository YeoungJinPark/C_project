#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 10;

	int result1 = num1++ + num2;
	printf("num1: %d, num2: %d, result1: %d\n", num1, num2, result1);
	//후위증가이므로 result1에는 0+10의 값이 저장된 후에 num1이 증가, num1 = 1이 된다.
	int result2 = ++num1 + num2++;
	printf("num1: %d, num2: %d, result2: %d\n", num1, num2, result2);
	//마찬가지로 전위증가 num1을 계산한 2+10의 값이 result2에 저장된 후 num2가 증가한다.
	int result3 = num1-- + num1-- - --num2;
	printf("num1: %d, num2: %d, result3: %d\n", num1, num2, result3);
	//result3=2+1-10 진행 후, num1=0, num2=10이 된다.
	int result4 = num2++ * num1++ - --num2 + num1;
	printf("num1: %d, num2: %d, result4: %d\n", num1, num2, result4);
	//result4=10*0-9+0 진행 후, num1=1, num2=10이 된다.
	return 0;
}
