#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

#define BUFF_SIZE 1024 
int main(int argc, char *argv[])
{

	int ret;
	int fd = 0;
	char buff[BUFF_SIZE];
	int char_to_read = 0;

	if(argc != 3)
	{
		printf("\nInsufficient number of arguments!\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);
	if (fd == -1)
	{

		printf("\nFailed to open file %s\n, argv[1]");
		return -1;
	}

	printf("\nSuccessfully opened file %s with fd %d\n", argv[1],fd);

	char_to_read = atoi(argv[2]);
	
	ret = read(fd,buff,char_to_read);	
		
	if (ret == char_to_read)
	{

		printf("\nSuccessfully read %d characters from %s\n",char_to_read,argv[1]);
		printf("\nData is: %s",buff);
		close(fd);
		return 0;
	}

	printf("\nFailed to read %d characters from %s\n",char_to_read,argv[1]);
	printf("\nProgram was able to read %d characters\n",ret);
	close(fd);
	return -1;
}
