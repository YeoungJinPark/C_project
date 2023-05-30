//직각 삼각형 모양으로 수 출력하기

#include <stdio.h>

int main(void)
{
   for(int i=1; i<=5; i++)
   {
	   for(int j=1; j<=i; j++)
		   printf("%d", i);

	   printf("\n");
   }
   return 0;
}
