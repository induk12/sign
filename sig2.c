#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    pid_t rpid;
    if(argc != 3)
    {
        printf("Invalid\n type <PID> <signal>\n availible signals:\n")
        exit(1);
    }
    rpid = atoi(argv[1]);
    if (strcmp(argv[2], "SIGUSR1")==0)
    {
        kill(rpid, SIGUSR1);
    }
    else if (strcmp(argv[2], "SIGUSR2")==0)
    {
        kill(rpid, SIGUSR2);
    }
    else
    {
        printf("Invalid command\n");
    }
}