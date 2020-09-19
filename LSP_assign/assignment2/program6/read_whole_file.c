#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{

	int fd =0;
	char buff[BUFF_SIZE];
	int ret;

	if(argc != 2)
	{
		printf("\nInsufficient number of arguments!\n");
		return -1;
	
	}


	fd = open(argv[1],O_RDONLY);
	
	if(fd == -1)
	{
		printf("\nFailed to open file %s\n ", argv[1]);
	        return -1;	
	}

	printf("\nFile %s opened successfully with file descriptor %d\n",argv[1],fd);

	while( (ret = read(fd,buff,BUFF_SIZE) ) > 0 )
	{

		printf("\nBytes read = %d.\tData is %s\n", ret,buff);	
	
	}		


	if (ret == -1)
	{
		printf("\nOops..!something went wrong! read() failed\n");
		return -1;
	
	}

	printf("\nSuccessfully read all characters from file %s\n", argv[1]);
        close(fd);
	return 0;


}
