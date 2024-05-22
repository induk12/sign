#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
const char *str1 = "Первая видимая строка";
const char *str2 = "Вторая видимая строка";
const char *str3 = "bufer";
void signal_handler(int signal)
{
    if (signal == SIGUSR1)
    {
        str3 = str2;
    } else if (signal == SIGUSR2)
    {
        str3 = str1;
    }
}
int main(void)
{
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    str3 = str1;
    while(1){
        printf("PID: %i\n %s\n", getpid(), str3);
    }
    return 0;
}