/* *****
   ****
   ***
   **
   * 출력 */

#include <stdio.h>

int main(void)
{
	int num1=0, num2=5, num3=0;

	while(num1<5)
	{
		while(num3<num2)
		{
			printf("*");
			num3++;
		}
		num3=0;
		num1++;
		num2--;
		printf("\n");
	}
	return 0;
}
