#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes;
	int word=0,line=0,i;	
	int inword=0;
	fd=open("source.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	else
	{
	i=0;
	while(i!=nbytes)
	{ 
	 if(buf[i]==' '|| buf[i]=='\t' ||buf[i]=='\n' ||buf[i]=='\0')
	 {

	 if(inword)
	 {
	 inword=0;
	 word++;
	 }
	 
	 if(buf[i]=='\n'||buf[i]=='\0')
	 line++;
	 }
	 else
	 {
	 inword=1;
	 }
	 i++;
	}
	}
	printf("\nword :%d line :%d char:%d\n",word,line,nbytes);
	close(fd);
	return 0;	
}
		
