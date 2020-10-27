#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

#define stacksize 5
int top=-1;
sem_t s1;
int stack[stacksize];

int StackEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int StackFull()
{
	if(top==stacksize)
		return 1;
	else
		return 0;
}
void push(int data)
{
	
	if(!StackFull())
	{
		top+=1;
		stack[top] = data;
		printf("%d is pushed into stack at position-%d\n",data,top);
	}
	else
	{
		printf("Stack is full\n");
	}
	
}

int pop()
{
	
	int data;
	if(!StackEmpty())
	{
		data =stack[top];
		top-=1;
		return data;
	}
	else
	{
		printf("Stack is empty\n");
	}
	
}

void* fun_push(void* args)	//consumer
{
	sem_wait(&s1);
	push(75);
	sleep(1);
	push(100);
	sleep(1);
	push(200);
	sleep(1);
	push(30);
	sleep(1);
	sem_post(&s1);
}

void* fun_pop(void* args)	//producer
{
	sem_wait(&s1);
	printf("The data that is poped is %d\n",pop());
	sleep(1);
	printf("The data that is poped is %d\n",pop());
	sleep(1);
	printf("The data that is poped is %d\n",pop());
	sleep(1);
	printf("The data that is poped is %d\n",pop());
	sleep(1);
	sem_post(&s1);
}

int main()
{
	pthread_t pt1,pt2;
	sem_init(&s1,0,1);
	pthread_create(&pt1,NULL,fun_push,NULL);
	pthread_create(&pt2,NULL,fun_pop,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	sem_destroy(&s1);
	printf("MAIN Thank You\n");
	return 0;
}
