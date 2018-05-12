/*
CSC33200   Task 1
 
Shirong Zheng      03/09/2018
 
Part 0(a): Extend code snippet 1 to check for read and write access permissions of a given file 
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char* argv[])
{
    char* filePath = argv[1];
    int returnValue;
    
    // Check file existence
    returnValue= access (filePath, F_OK);
    
    // If F_OK is 0, file exists
    if (returnValue == 0)
       printf ("\n%s exists\n", filePath);
    else
    {
       // ENOENT: no such file or directory
       if (errno == ENOENT)
           printf ("%s does not exist!\n", filePath);
       // EACCES: permission denied
       else if (errno == EACCES)
           printf ("%s is not accessible\n", filePath);
       return 0;
    }

    // Check read access
    returnValue = access (filePath, R_OK);
    if (returnValue == 0)
      printf ("%s is readable\n", filePath);
    else
      printf ("%s is not readable\n", filePath);

    // Check write access
    returnValue = access (filePath, W_OK);
    if (returnValue== 0)
      printf ("%s is writable\n", filePath);
    else if (errno == EACCES)
      printf ("%s is not writable (permission denied)\n", filePath);
    // EROFS: read-only file system
    else if (errno == EROFS)
      printf ("%s is not writable (read-only file system)\n", filePath);

    return 0;
}
