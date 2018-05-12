/*
CSC33200   Task 3
 
Shirong Zheng      03/23/2018

Part 1: Write a program where a child is created to execute command 
	that tells you the date and time in Unix. Use execl(...). Note, you need 
	to specify the full path of the file name that gives you date and time 
	information. Announce the successful forking of child process by displaying 
	its PID.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{	
	int status, pid;
	pid = fork();   //Create the child
	wait(&status);
	if(pid != 0){
		printf("Parent's PID is: %d\n", getpid());  //Get parent's pid
	}

	else{
		printf("Child's PID is: %d\n", getpid());  //Get child's pid
        execl("/bin/date", "date", NULL);    // execute a file: date in bin file
		printf("EXECL Failed\n");
		
	}
	return 0;
}
