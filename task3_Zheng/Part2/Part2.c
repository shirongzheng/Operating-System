/*
CSC33200   Task 3
 
Shirong Zheng      03/23/2018

Part 2: Write a program where a child is created to execute a command 
	that shows all files (including hid- den files) in a directory with 
	information such as permissions, owner, size, and when last modified.
	Use execvp(...). For the command to list directory contents with various 
	options, refer the handout on Unix file system sent to you in the first class.
	Announce the successful forking of child process by displaying its PID.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    int status, pid;
    pid = fork();  //Create the child
    wait(&status);
    if(pid != 0){
        printf("Parent's PID is: %d\n", getpid()); //Get parent's pid
    }
    
    else{
        printf("Child's PID is: %d\n", getpid());   // If pid is 0, child prints this line then create another child.
        
        char *argv[] = {"ls", "-laxo", NULL};
        execvp(argv[0],argv);
        printf("EXECVP Failed\n");
        
    }
    
    return 0;
}
