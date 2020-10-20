#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <string.h> 
int main(int argc,char *argv[])
{
    int c1, ret;
    if(argc==2)
    {
        c1 = fork();
        if(c1==0)
        {
            execlp(argv[1],argv[1],NULL);
        }
        else if(c1<0)
        {
            perror("Error child1");
            exit(0);
        }
        else
        {
            waitpid(c1,&ret,0);
        }
   }
   return 0;
}