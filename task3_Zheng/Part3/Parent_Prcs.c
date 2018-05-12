/*
 CSC33200   Task 3
 
 Shirong Zheng      03/28/2018
 
Part 3: Step 3. Fork a child process, say Child 1 and execute Prcs_P1.
	This will create two destination files according to Step 1.
	Step 4. After Child 1 finishes its execution, fork another child process, 
	say Child 2 and execute Prcs_P2 that accomplishes the procedure described 
	in Step 2.
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
	int pid_1, pid_2;

	pid_1 = fork();

	if(pid_1 == 0) {
		
		printf("Child 1\n");
		char *const argv[] = {"Prcs_P1", NULL};
		execv(argv[0], argv);
        printf("EXECV Failed! Did you compile Prcs_P1.c yet? \n");

	}
	else {
		sleep(1);
		pid_2 = fork();

		if (pid_2 == 0) {
			
			printf("Child 2\n");
			char *const argv[] = {"Prcs_P2", NULL};
			execv(argv[0], argv);
			printf("EXECV Failed! Did you compile Prcs_P2.c yet? \n");
		}
	}
	return 0;

}
