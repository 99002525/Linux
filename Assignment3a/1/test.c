#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes;
	int fd1,n1bytes;
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
		exit(1);
	}
	buf[nbytes]='\0';

	fd1=open("destination.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
	
	if(fd1<0)
	{
		perror("open");
		exit(2);
	}
	
	n1bytes=write(fd1,buf,nbytes);
	printf("The file successfully copied\n");

	close(fd1);
	close(fd);
	return 0;
}