#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main()
{
    double time_exe =0.0;
    clock_t time_s=clock();
    	int a=5,b=10,c;
	c=a+b;
	printf("\n%d",c);
    clock_t time_e=clock();
    time_exe=(double)(time_e - time_s)/CLOCKS_PER_SEC;
    printf("\ntime for exec is: %f\n",time_exe);
	return 0;

}