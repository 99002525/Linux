#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h> 
#define MAX 1000
#define ELE 10 

int arr[MAX]={};
int sum[ELE] = { 0 }; 
int b = 0; 
  
void* sum_arr(void* arg) 
{ 
    int j = b++; 
  
    for (int i = j * 100; i < (j + 1) * 100; i++) 
        sum[j] += arr[i]; 
} 
  
int main() 
{ 	
   for(int i=1;i<=1000;i++)
   {
   	arr[i]=1;
   }
   	
    pthread_t pt[ELE]; 
  
    // Creating 10 threads 
    for (int i = 0; i < ELE; i++) 
        pthread_create(&pt[i],NULL, sum_arr,(void*)NULL); 
  
    // joining 10 threads i.e. waiting for all 10 threads to complete 
    for (int i = 0; i < ELE; i++) 
        pthread_join(pt[i], NULL); 
  
    // adding sum of all 10 parts 
    int total = 0; 
    for (int i = 0; i < ELE; i++) 
        total+= sum[i]; 
  
    printf("sum is %d\n",total);
  
    return 0; 
} 