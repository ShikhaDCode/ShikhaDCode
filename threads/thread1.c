#include<stdio.h>
#include<pthread.h>

void* mythreadfn(void *arg)
{
    printf("My thead function: %d\n", *(int*)arg);
    return NULL;
}

int main()
{
    pthread_t th_id;
    int var = 10;

    pthread_create(&th_id, NULL, mythreadfn, &var);
    pthread_join(th_id, NULL);

    printf("Thread completed!\n");

    return 0;
}