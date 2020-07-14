#include "stdlib.h"
#include "stdio.h"

int main()
{
	int sum = 0;int i = 0;
       int sum1=0;
	while(i<100)
	{      if(i % 2)
		{
			sum1 = sum1 + i;
		}
           	else	
		{
			sum =sum +i;
		}
		i=i+1;
	}
	printf("sum:%d\n",sum);
	printf("sum:%d\n",sum1);
}
