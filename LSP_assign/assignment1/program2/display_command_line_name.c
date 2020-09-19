#include<stdio.h>

#define NEWLINE printf("\n")

int main(int argc, char *argv[])
{

	if (argc <  2)
	{
		NEWLINE;
		printf("No argument specified!");
		return -1;
	}

	else if (argc > 2)

	{	
		NEWLINE;
		printf("Too many arguments specifide! Enter only first name!");
		return -1;
	}

	else
	{
		NEWLINE;
		printf("Name entered is:\t %s ", argv[1]);
		return 0;
	}

}
