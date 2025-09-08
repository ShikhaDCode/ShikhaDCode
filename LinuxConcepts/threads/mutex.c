#include<stdio.h>
#include<pthread.h>

int counter = 0;
pthread_mutex_t mtx;

void *increment_counter(void *arg)
{
    for(int i = 0; i < 10000; i++){
        pthread_mutex_lock(&mtx);
        counter++;
        pthread_mutex_unlock(&mtx);
    }
}

int main()
{
    pthread_t th_id1;
    pthread_t th_id2;

    pthread_mutex_init(&mtx, NULL);

    pthread_create(&th_id1, NULL, increment_counter, NULL);
    pthread_create(&th_id2, NULL, increment_counter, NULL);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    pthread_mutex_destroy(&mtx);

    printf("Threads exited. Counter = %d\n", counter);

    return 0;
}