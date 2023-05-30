#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void)
{
	char f = 0;
	char arr[30] = "";
	char str[30] = "";
	while(f < 1)
	{
		scanf("%s\n", arr);
		if(strcmp(str, "나가기") == 0)
		{
			f = 1;
		}
		else if(strcmp(str, "exit") == 0)
		{
			f = 1;
		}
		else
		{
			printf("%s\n", str);
		}	
	}
	return 0;
}
