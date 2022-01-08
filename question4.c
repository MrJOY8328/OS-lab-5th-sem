#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t child_pid;
    printf("the main program process ID is %d\n", (int)getpid());
    child_pid = fork();
    if (child_pid != 0)
    {
        printf("0 this is the PARENT process, id > %d\n", (int)getpid());
        printf("0 this is the PARENT process, id > %d\n", (int)getpid());
        printf("0 child’s process ID is %d\n", (int)child_pid);
        printf("0 child’s process ID is %d\n", (int)child_pid);
    }
    else
        printf("this is the child process, id > %d\n", (int)getpid());
    return 0;
}