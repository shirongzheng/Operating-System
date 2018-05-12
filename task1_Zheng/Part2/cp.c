/*
CSC33200   Task 1
 
Shirong Zheng      03/09/2018
 
Part 2: Write a C program that mimics the cp command using open() system call to open source.txt file
in read-only mode and copy the contents of it to destination.txt using read() and write() system
calls. 
*/

#include <stdio.h>												
#include <fcntl.h>												
#include <unistd.h>												
#include <string.h>												
#include <errno.h>												

int main (int argc, char* argv[])							
{
	if (argc != 3) 												
	{			
        printf("Please input two file names! \n");			
        return 1;												
    }

	char *Source = argv[1];										
	char *Destination = argv[2];								
		
	int fd, DD, N;
	fd = open(Source, O_RDONLY);
	
	if (fd >= 0)
	{
		int dummy_variable = access(Destination, F_OK);
		if (dummy_variable == 0)
			unlink(Destination);								
		
		DD = open(Destination, O_CREAT | O_RDWR, S_IRWXU);		
																
		if (DD >= 0)											
		{
			char buff[BUFSIZ];									
																
			while((N = read(fd, buff, BUFSIZ)) > 0)
	        	write(DD, buff, N);								
        }
        else
			perror("open");										

		close (fd);
		close (DD);												
	} 
	else 
		perror("open");											

	return 0;
}
