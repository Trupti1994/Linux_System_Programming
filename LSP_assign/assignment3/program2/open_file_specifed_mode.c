#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{


	int fd =0;
	
	if(argc != 3)
	{
	
		printf("Insufficient number of arguments specified!");
		return -1;
	}


	fd = open(argv[1],argv[2]);
	
	if(fd == -1)
	{
		printf("\nFailed to open file %s with mode %s\n ", argv[1],argv[2]);
	        return -1;	
	}

	printf("\nFile %s opened successfully with file descriptor %d\n",argv[1],fd);

        close(fd);

	return 0;
}
