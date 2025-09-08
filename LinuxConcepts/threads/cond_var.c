#include<stdio.h>
#include<pthread.h>

int counter = 0;
// pthread_mutex_t mtx;
// pthread_cond_t cnd;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cnd = PTHREAD_COND_INITIALIZER;
int data;
int available = 0;

void *producer(void *arg)
{
    while(1){
        pthread_mutex_lock(&mtx);
        while(available){
            pthread_cond_wait(&cnd, &mtx);
        }
        // data = 10;
        data++;
        available = 1;
        printf("Produced data = %d\n", data);
        pthread_cond_signal(&cnd);
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void *consumer(void *arg)
{
    while(1){
        pthread_mutex_lock(&mtx);
        while(!available){
            pthread_cond_wait(&cnd, &mtx);
        }
        printf("Consumed Data = %d\n", data);
        available = 0;
        pthread_cond_signal(&cnd);
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

int main()
{
    pthread_t th_id1;
    pthread_t th_id2;

    // pthread_mutex_init(&mtx, NULL);
    // pthread_cond_init(&cnd, NULL);

    pthread_create(&th_id1, NULL, producer, NULL);
    pthread_create(&th_id2, NULL, consumer, NULL);

    pthread_join(th_id1, NULL);
    pthread_join(th_id2, NULL);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cnd);

    printf("Threads exited. Counter = %d\n", counter);

    return 0;
}