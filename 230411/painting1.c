//삼각형
#include <stdio.h>

int main(void)
{
	int select, num;

	while(1)
	{
		printf("0.EXIT 1.삼각형 2.역삼각형 3.마름모 4.모래시계 5.바람개비 6.바람개비 역날\n");
		printf("입력: ");
		scanf("%d", &select);
	
		if(select==0)	//종료
		{
			return 0;
		}
		else if(select==1)	//삼각형
		{
			num=2;
			for(int i=1; i<=5; i++)
			{
				for(int j=i; j<5; j++)
					printf(" ");
				for(int k=1; k<num; k++)
					printf("*");
				printf("\n");
				num+=2;
			}
		}
		else if(select==2)	//역삼각형
		{
			num=1;
			for(int i=1; i<=5; i++)
	        {
				for(int k=1; k<i; k++)
	                printf(" ");

				for(int j=num; j<10; j++)
                    printf("*");
				num+=2;
	            printf("\n");
	        }
		}
		else if(select==3)	//마름모
		{
			num=1;
			for(int i=1; i<=5; i++)
			{
				for(int j=i; j<5; j++)
					printf(" ");
				for(int k=1; k<=num; k++)
					printf("*");
				num+=2;
				printf("\n");
			}
			num=1;
			for(int i=4; i>=1; i--)
			{
				for(int j=4; j>=i; j--)
					printf(" ");
				for(int k=7; k>=num; k--)
					printf("*");
				printf("\n");
				num+=2;
			}
		}
		else if(select==4)	//모래시계
		{
			for(int i=7; i>=1; i--)	//역삼각형을 먼저 그려준다
			{
				for(int j=7; j>=i; j--)
					printf(" ");
				for(int k=1; k<=i*2-1; k++)
					printf("*");
				printf("\n");
			}
			for(int i=1; i<=7; i++)	//삼각형을 그려준다
			{
				for(int j=7; j>=i; j--)
					printf(" ");
				for(int k=1; k<i*2; k++)
					printf("*");
				printf("\n");
			}
		}
		else if(select==5)	//바람개비
		{
			for(int i=1; i<=10; i++)
			{
				for(int j=1; j<=i; j++)	//ㄴ
					printf("*");
				for(int k=10; k>=i; k--)
					printf(" ");
				for(int l=10; l>=i; l--)
                    printf("*");
				for(int m=1; m<=i; m++)
                    printf(" ");
				printf("\n");
			}
			for(int i=1; i<=10; i++)
            {               
				for(int j=10; j>=i; j--)
                    printf(" ");
				for(int k=1; k<=i; k++) //ㄴ
                    printf("*");
				for(int l=1; l<=i; l++)
                    printf(" ");
                for(int m=10; m>=i; m--)
                    printf("*");
                printf("\n");
            }
		}
		else if(select==6)	//바람개비 역날
		{
			for(int i=1; i<=10; i++)
			{
				for(int j=1; j<=i; j++)
					printf(" ");
				for(int k=10; k>=i; k--)
					printf("*");
				for(int l=10; l>=i; l--)
                    printf(" ");
				for(int m=1; m<=i; m++)
                    printf("*");
				printf("\n");
			}
			for(int i=1; i<=10; i++)
            {
				for(int j=10; j>=i; j--)
                    printf("*");
				for(int k=1; k<=i; k++)
                    printf(" ");
				for(int l=1; l<=i; l++)
                    printf("*");
                for(int m=10; m>=i; m--)
                    printf(" ");
                printf("\n");
            }

		}
		else
			printf("0~6 중에 입력해주세요.\n");
	}
}
