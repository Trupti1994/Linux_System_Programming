#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{

	int iNum1 = 0;
	int iNum2 = 0;
 
	if (argc == 3 )
	{
		iNum1 = atoi(argv[1]);
		iNum2 = atoi(argv[2]);
		printf("\nAddition of two numbers  %d  and %d  is %d \n", iNum1, iNum2, iNum1+iNum2 );
        	return 0;

	}

	return -1;

}

