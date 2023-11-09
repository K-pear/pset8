#include <pthread.h> 
#include <stdlib.h> 
#include <stdio.h> 

pthread_t handles[4];  // not using index 0 
int threadArg[4]; // not using index 0 

void *thread_func(void *);  

void *thread_func(void *threadIdPtr)
{
   int myId = *(int *)threadIdPtr;
   for (int i = 1; i <= 10; i++){
      printf("%d: %d\n", myId, i);
   }
   return 0;
}

int main(int argc, char *argv[])
{
   pthread_attr_t attr;
   pthread_attr_init(&attr);

   for (int i = 1; i <= 3; i++)
   {
      threadArg[i] = i;
      pthread_create(&handles[i], &attr, thread_func, &threadArg[i]);
   }

   for (int i = 1; i <= 3; i++)
   {
      pthread_join(handles[i], NULL);
   }
   printf("finished\n");
   return 0;
}