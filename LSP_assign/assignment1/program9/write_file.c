#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[])
{

	int fd =0;
        char buff[BUFF_SIZE];
	int ret;
	if(argc != 3)
	{
		printf("\nInsufficient number of arguments!\n");
		return -1;
	
	}

//	memset(buff,0,sizeof(buff));	
//	strcpy(buff,argv[2]);



	fd = open(argv[1],O_RDWR);
	
	if(fd == -1)
	{
		printf("\nFailed to open file %s\n ", argv[1]);
	        return -1;	
	}

	printf("\nFile %s opened successfully with file descriptor %d\n",argv[1],fd);

//	ret = write(fd,buff,sizeof(buff));
	ret = write(fd,argv[2],strlen(argv[2]));
	if (ret == -1)
	{

		printf("\nFailed to write to file %s\n", argv[1]);
		close(fd);
		return -1;
	}


	if (ret == strlen(argv[2]))
	{
	
		printf("\nSuccessfully written %s into file %s", argv[2], argv[1]);

	}
        close(fd);
	return 0;


}
