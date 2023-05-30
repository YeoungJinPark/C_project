//2부터 100까지의 소수 구하기

#include <stdio.h>

int main(void)
{
	int line=0;
	printf("2부터 100까지의 소수: \n");

	for(int i=2; i<=100; i++)
	{
		int chk=1;
		for(int j=2; j<=i-1; j++)
		{
			if(i%j==0)
			{
				chk=0;
				break;
			}
		}
		if(chk==1)
		{
			line++;
			printf("%d ", i);
			if(line%10==0)
				printf("\n");
		}
	}
	printf("\n");
	return 0;
}
