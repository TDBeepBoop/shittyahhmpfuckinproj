#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int num=0;
int num2=0;
int max=10;
int i;


int main()
{
		numthing();
}

void numthing()
{
	num = max;
for(i=0; i<10; i++)
{
	if(num>5)
	{
		num+=-2;
		printf("%d,%d\n",num,num2);
		if(num<=0)
		{
			num2+=-1;
			printf("%d,%d\n",num,num2);
		}
	}
	if(num<5)
	{
		num+=+2;
		printf("%d,%d\n",num,num2);
	}
	
}
}