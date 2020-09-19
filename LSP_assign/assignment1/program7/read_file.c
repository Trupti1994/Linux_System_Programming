#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

	int fd =0;
	char buff[100];
	int ret =0;

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

	ret = read(fd,buff,5);

	if (ret == 5)	
	{
		printf("\nSuccessfully read 5 characters from file %s\n", argv[1]);
		printf("\nData is: %s\n",buff);
		return 0;
	}
	else
	{
		printf("Oops..!something went wrong!\n");
		return -1;
	
	}

        close(fd);

}
