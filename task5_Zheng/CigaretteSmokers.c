/*
 CSC33200   Task 5
 
 Shirong Zheng      04/27/2018
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sem.h"

int main() {
    int lock, agent, tobacco, paper, match;
    // paper: smoker with paper
    // tobacco: smoker with tobacco
    // match: smoker with match

    lock=semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    agent=semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    paper=semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    tobacco=semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    match=semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    
    sem_create(lock,1);
    sem_create(agent,0);
    sem_create(paper,0);
    sem_create(tobacco,0);
    sem_create(match,0);

    int pid, status, times, num;
    // times: number of update
    // num: random number from 1 to 3

    times = 10;
    pid=fork();
    if(pid == 0) {
        // when pid == 0; child
        while(times>0) {
            P(lock);
            num = rand()%3; // in this case: 0=1, 1=2, 2=3
            if(num == 0) {
                // when num == 0
                printf("Put tobacco on table\n");
                printf("Put paper on table\n");
                V(match);
                // call the one with match
            }
            if(num == 1) {
                printf("Put tobacco on table\n");
                printf("Put match on table\n");
                V(paper);
            } 
            if(num == 2) {
                printf("Put match on table\n");
                printf("Put paper on table\n");
                V(tobacco);
            }
            V(lock);
            P(agent);
            times--;
        }
    } else {
        // parent
        pid=fork();
        if(pid == 0) {
            while(1) {
                // infinity loop
                P(tobacco);
                P(lock);
                printf("Smoker 1 with tobacco picks up match\n");
                printf("Smoker 1 with tobacco picks up paper\n");
                V(agent);
                V(lock);
                printf("Smoker 1 smokes\n");
            }
        } else {
            pid=fork();
            if(pid == 0) {
                while(1) {
                    P(paper);
                    P(lock);
                    printf("Smoker 2 with paper picks up match\n");
                    printf("Smoker 2 with paper picks up tobacco\n");
                    V(agent);
                    V(lock);
                    printf("Smoker 2 smokes\n");
                }
            } else {
                pid=fork();
                if(pid == 0) {
                    while(1) {
                        P(match);
                        P(lock);
                        printf("Smoker 3 with match picks up paper\n");
                        printf("Smoker 3 with match picks up tobacco\n");
                        V(agent);
                        V(lock);
                        printf("Smoker 3 smokes\n");
                    }
                } else {
                    pid = wait(&status);
                    printf("Process %d exited with %d\n", pid, status);
                }
            }
        } 
    }
    exit(0);
}
