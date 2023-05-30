/* 다음 식을 만족하는 모든 A와 Z를 구하기
	A Z
  + Z A
  ------
    9 9 */

#include <stdio.h>

int main(void)
{
	int sum;

	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=10; j++)
		{
			if(i==j)
				continue;
			sum=(i*10+j)+(j*10+i);
			if(sum==99)
				printf("%d%d+%d%d=99\n", i, j, j, i);
		}
	}
	return 0;
}
