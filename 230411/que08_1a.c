//1이상 100미만의 정수 중 7의 배수와 9의 배수를 출력
//단, 7의 배수이면서 동시에 9의 배수인 정수는 한번만 출력

#include <stdio.h>

int main(void)
{
	/*int line=0, trash;
	printf("7의 배수: ");

	for(int i=1; i<100; i++)
	{
		if(i%7==0&&i%9==0)
			trash=1;
		else if(i%7==0)
		{
			printf("%d ", i);
			line++;
		}
		if(line%10==0&&i%7==0&&i<99)
			printf("\n");
	}

	printf("\n9의 배수: ");
	line=0;

	for(int j=1; j<100; j++)
	{
		if(j%7==0&&j%9==0)
			trash=1;
		else if(j%9==0)
		{
			printf("%d ", j);
			line++;
		}
		if(line%10==0&&j%9==0&&j<99)
			printf("\n");
	}

	printf("\n7의 배수이면서 9의 배수: ");
	line=0;

	for(int k=1; k<100; k++)
	{
		if(k%7==0&&k%9==0)
		{
			printf("%d ", k);
			line++;
		}
		if(line%10==0 && k%7==0 && k%9==0)
			printf("\n");
	}
	printf("\n");*/
	for(int i=1; i<=100; i++)
		if(i%7==0||i%9==0)
			printf("%d ", i);
	printf("\n");
	return 0;
}
