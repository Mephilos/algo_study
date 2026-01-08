#include <stdio.h>
#include <pthread.h>

int shared_data = 0;

void *increment(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        shared_data++;
    }
    return NULL;
}

void *decrement(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++)
    {
        shared_data--;
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);

    return 0;
}