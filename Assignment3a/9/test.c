#include <stdio.h>
#include <time.h>
int main()
{
    time_t t;
    struct tm *ntm;
    char time_now[32];
    t=time(NULL);
    ntm=localtime(&t);
    strftime(time_now,32,"%H:%M:%S",ntm);
    printf("Time : %s\n",time_now);
    return 0;
}