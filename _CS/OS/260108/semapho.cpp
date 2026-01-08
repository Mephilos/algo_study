#include <iostream>
#include <thread>
#include <semaphore.h>

int sharedData = 0;
sem_t semaphore;

void increment()
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        sharedData++;
        sem_post(&semaphore);
    }
}

void decrement()
{
    for (int i = 0; i < 100000; i++)
    {
        sem_wait(&semaphore);
        sharedData--;
        sem_post(&semaphore);
    }
}

int main()
{
    sem_init(&semaphore, 0, 1);

    std::thread thread1(increment);
    std::thread thread2(decrement);

    thread1.join();
    thread2.join();

    std::cout << "Final value of sharedData: " << sharedData << std::endl;

    sem_destroy(&semaphore);

    return 0;
}