#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

	int fd =0;

	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("\nFailed to open file %s\n ", argv[1]);
		
	}

	printf("\nFile %s opened successfully with file descriptor %d\n",argv[1],fd);

        close(fd);

	return 0;
}
