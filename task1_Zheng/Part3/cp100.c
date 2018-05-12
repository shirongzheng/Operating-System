/*
CSC33200   Task 1

Shirong Zheng      03/09/2018

Part 3: (a) Read the next 100 characters from source.txt, and among 
	characters read, replace each character ’1’ with character ’A’ 
	and all characters are then written in destination.txt
	(b) Write characters "XYZ" into file destination.txt
	(c) Repeat the previous steps until the end of file source.txt. 
	The last read step may not have 100 characters.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
	if ( argc != 3)
	{	printf("Usage: \n");
		return 1;
	}	
	
	int Source_fd;
	int Dest_fd;
	int countNum;
	char buffer[100];
	int i;
	
	// Open both the files
	Source_fd = open(argv[1],O_RDONLY);
	Dest_fd = open(argv[2], O_WRONLY|O_CREAT);
	
	if (Source_fd == -1 || Dest_fd == -1 )
	{
		if (Source_fd == -1)
			printf("Failed to accessing the %s file\n",argv[1]);
		if (Dest_fd == -1)
			printf("Failed to accessing the %s file\n",argv[2]);
		return 1;
	}
	// Read & write 
	while ( (countNum = read(Source_fd,buffer,100)) != 0 )
	{
		// Changing '1' to 'A'
		for ( i=0; i < 100; i++)
		{	
			if (buffer[i] == '1')
				buffer[i] = 'A';
		}
		countNum = write(Dest_fd,buffer,countNum);
		
		countNum = write(Dest_fd,"XYZ",3);
	}

	int returnValue1 = close(Source_fd);
	int returnValue2 = close(Dest_fd);
	if ( returnValue1 != 0 || returnValue2 != 0 )
		printf("Error while closing files");
	
	return 0;
}
