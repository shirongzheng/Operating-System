/*
 CSC33200   Task 2
 
 Shirong Zheng
 
 02/23/2018
 
 Part 1: Write a program children.c, and let the parent process
 produce two child processes. One prints out "I am child one,
 my pid is: " PID, and the other prints out "I am child two,
 my pid is: " PID. Guarantee that the parent terminates after
 the children terminate  (Note, you need to wait for two child
 processes here). Use the getpid() function to retrieve the PID.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main (void)
{
    int status1 = 0;
    pid_t child1_pid = fork();                                    // fork for child 1
    
    if (child1_pid == -1)                                         // if fork() returns -1, an error.
    {
        perror("The fork to create child 1 failed.");
        exit(EXIT_FAILURE);
    }
    
    else if (child1_pid == 0)                                        // child 1 successfully forked
    {
        printf("I am child one, my pid is: %d.\n", getpid());
    }
    else {
        
        int status2 = 0;
        pid_t child2_pid = fork();                                // fork for child 2
        
        if (child2_pid == -1)                                        // if fork() returns -1, an error.
        {
            perror("The fork to create child 2 failed.");
            exit(EXIT_FAILURE);
        }
        else if (child2_pid == 0)                                    // child 2 successfully forked
        {
            printf("I am child two, my pid is: %d.\n", getpid());
        }
        else                                                // parent of child 1 and child 2
        {
            printf("I am the parent process, my pid is: %d\n", getpid());
            
            waitpid(child1_pid, &status1, 0);
            if (WIFSIGNALED(status1) == 0)
            {
                printf("The child one process terminated normally.\n");
            }
            else
            {
                printf("The child one process terminated abnormally.\n");
            }
            
            waitpid(child2_pid, &status2, 0);
            if (WIFSIGNALED(status2) == 0)
            {
                printf("The child two process terminated normally.\n");
            }
            else
            {
                printf("The child two process terminated abnormally.\n");
            }
            
            printf("The Parent's pid is:  %d.\n", getpid());
        }
    }
    
    return 0;
}
