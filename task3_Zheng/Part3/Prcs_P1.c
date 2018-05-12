/*
 CSC33200   Task 3
 
 Shirong Zheng      03/23/2018
 
Part 3: Step 1. Create two files namely, destination1.txt and
	destination2.txt with read, write, and execute permissions.
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int fd1, fd2;
	errno = 0;
	fd1 = open("destination1.txt", O_CREAT | O_RDWR, S_IRWXU);
													
	if (fd1 == -1) {
		printf("open() failed with error [%s]\n", strerror(errno));
	}
	else {
		printf("Destination 1: Open() Successful\n");
	}
	close(fd1);

	
	fd2 = open("destination2.txt", O_CREAT | O_RDWR, S_IRWXU);  

	if (fd2 == -1) {
		printf("\n open() failed with error [%s]\n", strerror(errno));
	}
	else {
		printf("Destination 2: Open() Successful\n");
	}

	close(fd2);



return 0;
}
