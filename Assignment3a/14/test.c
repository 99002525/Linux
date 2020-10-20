#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    int c1,c2,c3,c4;
    int ret;
    //printf("Parent PID %d\n",getpid());
    c1 = fork();

    if(c1==0)
    {
        execl("/usr/bin/gcc","gcc","-c","-Iinc","src/flip.c","src/query.c","src/reset.c","src/set.c","main.c",NULL);
    }
    else if(c1<0)
    {
        perror("Error child1");
        exit(0);
    }
    else
    {
        printf("Inside child1\n");
        waitpid(c1,&ret,0);
        c2 = fork();
    }
    if(c2==0)
    {
        execl("/usr/bin/ar","ar","rc","libmasking.a","set.o","reset.o","query.o","flip.o","main.o",NULL);
    }
    else if(c2<0)
    {
        perror("Error child2");
        exit(1);
    }    
    else
    {
        printf("Inside child2\n");
        waitpid(c2,&ret,0);
        c3 = fork();
    }
    if(c3==0)
    {
        execl("/usr/bin/gcc","gcc","-L.","main.o","-o","s3","-lmasking",NULL);
    }
    else if(c3<0)
    {
        perror("Error child3");
        exit(3);
    }    
    else
    {
        waitpid(c3,&ret,0);
        c4 = fork();
    }
    if(c4==0)
    {
        execl("all.out","all.out",NULL);
    }
    else if(c4<0)
    {
        perror("Error child4");
        exit(3);
    }    
    else
    {
        waitpid(c4,&ret,0);
    }
    
    return 0;
}
