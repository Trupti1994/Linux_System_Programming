#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{


	int fd =0;
	
	if(argc != 3)
	{
	
		printf("Insufficient number of arguments specified!");
		return -1;
	}

	if(!(strcmp(argv[2],"O_RDONLY")))
	{
		fd = open(argv[1],O_RDONLY);
	}

	if(!(strcmp(argv[2],"O_WRONLY")))
	{
		fd = open(argv[1],O_WRONLY);
	}
	
	if(!(strcmp(argv[2],"O_RDWR")))
	{
		fd = open(argv[1],O_RDWR);
	}
	if(fd == -1)
	{
		printf("\nFailed to open file %s with mode %s\n ", argv[1],argv[2]);
	        return -1;	
	}

	printf("\nFile %s opened successfully with file descriptor %d in %s mode\n",argv[1],fd,argv[2]);

        close(fd);

	return 0;
}
