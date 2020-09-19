#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

//#define STR_SIZE  10
#define STR_SIZE sizeof("rwxrwxrwx")

int main(int argc, char *argv[])
{

	struct stat sb;
	int ret;
	char FilePermissionString[STR_SIZE];
	mode_t perm;
		
	if(argc != 2)
	{
		printf("\nInsufficient number of arguments!\n");
	}
 	
	ret = stat(argv[1], &sb);
	
	if(ret == -1)
	{
		printf("\nFailed to fetch file information!\n");
		return 0;
	}
	
	printf("\n************File Information************\n");

	printf("\nFilename: %s\n", argv[1]);
	printf("\nSize: %lld\t Blocks(512bytes): %ld\n",(long long)sb.st_size,(long)sb.st_blocks);
	printf("\nOptimal IO  Blocks: %ld\n",(long)sb.st_blksize);
	printf("\nDevice: \t Major number:%ld\t Minor number:%ld \n", (long)major(sb.st_dev), (long)minor(sb.st_dev));
	printf("\nInode Number: %ld\n", (long)sb.st_ino);

	if(S_ISREG(sb.st_mode))
	{

		printf("\nFile Type:\tRegular File\n");
	}

	if(S_ISDIR(sb.st_mode))
	{

		printf("\nFile Type:\tDirectory\n");

	}

	if(S_ISBLK(sb.st_mode))
	{

		printf("\nFile Type:\tBlock Device\n");

	}

	if(S_ISCHR(sb.st_mode))
	{

		printf("\nFile Type:\tCharacter Device\n");

	}

        printf("\nNumber of hard links to file: %ld\n", (long)sb.st_nlink);
        printf("\nUser Id : %ld\t Group Id : %ld\n", (long)sb.st_uid,(long)sb.st_gid);
	printf("\nLast File Access: %s\n",ctime(&sb.st_atime));	
	printf("\nLast File Modification: %s\n",ctime(&sb.st_mtime));	
	printf("\nLast File Change Status: %s\n",ctime(&sb.st_ctime));	

	perm = sb.st_mode;
	snprintf(FilePermissionString,
		 STR_SIZE,
		 "%c%c%c%c%c%c%c%c%c",
		 (perm & S_IRUSR) ? 'r' : '-',(perm & S_IWUSR) ? 'w' : '-',(perm & S_IXUSR) ? 'x' : '-',
		 (perm & S_IRGRP) ? 'r' : '-',(perm & S_IWGRP) ? 'w' : '-',(perm & S_IXGRP) ? 'x' : '-',
		 (perm & S_IROTH) ? 'r' : '-',(perm & S_IWOTH) ? 'w' : '-',(perm & S_IXOTH) ? 'x' : '-'
		);

	
	printf("\nPermissions: %s\n", FilePermissionString);
	return 0;
}
