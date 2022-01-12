#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int pid;
    char *message;
    int n;
    printf("fork program starting \n");
    pid = fork();
    switch (pid){
    case -1:
        exit(1);
    case 0:
        message = "this is the child process";
        n = 5;
        break;
    default:
        message = "this is the parent process";
        n = 10;
        break;
    }
    for (; n > 0; n--){
        puts(message);
        sleep(1);
    }
    exit(0);
}