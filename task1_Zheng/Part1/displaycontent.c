/*
CSC33200   Task 1
 
Shirong Zheng      03/09/2018
 
Part 1: Write a C program to implement a command called displaycontent that takes a (text) file name as argument and display its contents. Report an appropriate message if the file does not exist or can’t be opened 
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main (int argc, char *argv[])
{
  int fd;
  int countNum = 0;
  char Buffer[10];
  
  //Open the file
  fd = open ( argv[1], O_RDONLY );
  
  //if error occurs while opening
  if (fd == -1 )
  {
    if (errno == ENOENT)
      printf("%s does not exist!\n",argv[1] );
    else if (errno == EACCES )
      printf("%s is not accessible\n",argv[1]);
    return 1;
  }
  
  // Read & write
  while ( (countNum = read(fd,Buffer,10)) != 0 )
  {
    countNum = write(1,Buffer,countNum);
  }
  
  // Close the file 
  int returnValue = close(fd);
  if ( returnValue != 0 )
    printf("File couldnot be closed. Please check again!");
  return 0;
}
