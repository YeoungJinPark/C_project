//구구단의 짝수단만 출력. 단, 2단은 2×2, 4단은 4x4의 규칙으로

#include <stdio.h>

int main(void)
{
	for(int i=2; i<9; i++)
	{
		if(i%2==1)
			continue;
		for(int j=1; j<=9; j++)
		{
			printf("%d×%d=%d\n", i, j, i*j);
			if(i==j)
				break;
		}
	}
}
