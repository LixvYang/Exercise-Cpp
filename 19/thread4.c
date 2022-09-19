#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREAD 100
pthread_mutex_t mutex;

void* thread_inc(void* arg);
void* thread_des(void* arg);
long long num = 0;

int main()
{
  pthread_t thread_id[NUM_THREAD];
  int i;
  pthread_mutex_init(&mutex, NULL);

  // printf("sizeof long long: %d \n", sizeof(long long));
  for (i = 0; i < NUM_THREAD; i++)
  {
    if (i%2)
      pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
    else 
      pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
  }

  for(i = 0; i < NUM_THREAD; i++)
  { 
    pthread_join(thread_id[i], NULL);
  }
  printf("result: %lld \n", num);
  return 0;
}

void* thread_inc(void* arg)
{
  int i;
  pthread_mutex_lock(&mutex);
  for (i = 0; i < 5000000; i++)
    num +=1;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

void* thread_des(void* arg)
{
  int i;
  for (i = 0; i < 5000000; i++)
    pthread_mutex_lock(&mutex);
    num -=1;
    pthread_mutex_unlock(&mutex);
  return NULL;
}