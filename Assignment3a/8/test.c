
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX 1000
#define ELE 10 
int arr[MAX] = {};
int min[ELE] = { 0 }; 
int b=0;

void* minimum(void* arg) 
{ 
    int i, j=b++; 
    int min_n = 0; 
  
    for (i = j * 100; i < (j + 1) * 100; i++) { 
        if (arr[i] < min_n) 
            min_n = arr[i]; 	
    } 
    min[j] = min_n; 
} 
  
int main() 
{
    for(int i=0;i<MAX;i++)
    {
	    arr[i]=i;
    } 
    int minn = 0,i; 
    pthread_t pt[ELE]; 
  
    for (i = 0; i < ELE; i++) 
        pthread_create(&pt[i], NULL, minimum,(void*)NULL); 
  
    for (i = 0; i < ELE; i++) 
        pthread_join(pt[i], NULL); 

    for (i = 0; i < ELE; i++) { 
        if (min[i] < minn) 
            minn = min[i]; 
    } 
  
    printf("Maximum Element is : %d\n", minn); 
  
    return 0; 
} 