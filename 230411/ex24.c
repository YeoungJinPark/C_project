//계승 구하기

#include <stdio.h>

int main(void)
{
	int fact=1;
	
	for(int i=5; i>=1; i--)
		fact*=i;
	printf("계승값: %d\n", fact);
	return 0;
}
