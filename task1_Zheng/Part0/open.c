/*
CSC33200   Task 1
 
Shirong Zheng      03/09/2018
 
Part 0(b): Write a C program where open system call creates a new file (say, destination.txt) and then opens it. (Hint: use the bitwise OR flag) 
*/

#include <stdio.h>                        
#include <fcntl.h>                        
#include <unistd.h>                      
#include <string.h>                       
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
  if (argc != 2) {                      
        printf("Please input file name! \n");
        return 1;
    }

    errno = 0;
  char *filePath = argv[1];                 

  // O_CREAT: if file does not exist, the file is created.
 // O_RDWR: open for reading and writing

  int fd;
  fd = open(filePath, O_CREAT | O_RDWR, S_IRWXU);
  
  if (fd >= 0)
    printf("Open() Successful \n");
  
  else                            
  {
    printf("Open() failed with error [%s]\n", strerror(errno));
    perror("Open");
    return 0;
  }

  close(fd);

  return 0;
}
