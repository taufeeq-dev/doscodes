#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semA, semB, semC;
int counter = 1;

void *printA(void *arg) {
    while (counter <= 20) {
        sem_wait(&semA);
        if (counter > 20) break;
        printf("A%d ", counter++);
        sem_post(&semB);
    }
    return NULL;
}

void *printB(void *arg) {
    while (counter <= 20) {
        sem_wait(&semB);
        if (counter > 20) break;
        printf("B%d ", counter++);
        sem_post(&semC);
    }
    return NULL;
}

void *printC(void *arg) {
    while (counter <= 20) {
        sem_wait(&semC);
        if (counter > 20) break;
        printf("C%d ", counter++);
        sem_post(&semA);
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB, threadC;

    // Initialize semaphores
    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    // Create threads
    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);

    // Wait for threads to complete
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    // Destroy semaphores
    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);

    printf("\n");
    return 0;
}
