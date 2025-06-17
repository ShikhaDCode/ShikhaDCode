#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* thread_func(void* arg) {
    sem_wait(&sem); // wait (decrement)
    printf("Thread %ld entered critical section\n", (long)arg);
    sleep(1);
    printf("Thread %ld leaving critical section\n", (long)arg);
    sem_post(&sem); // signal (increment)
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    sem_init(&sem, 0, 2); // allow 2 threads at a time. In single process (0)

    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);
    pthread_create(&t3, NULL, thread_func, (void*)3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    sem_destroy(&sem);
    return 0;
}
