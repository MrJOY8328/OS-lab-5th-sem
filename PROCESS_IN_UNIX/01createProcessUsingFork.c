#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(int argc, char *arg[])
{
    int pid;
    pid = fork();
    pid = fork();
    printf("Process id %d\n", (int)getpid());
}