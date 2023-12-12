#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2

// Shared resource
int sharedResource = 0;

// Semaphore declaration
sem_t semaphore;

// Function for thread execution
void *threadFunction(void *threadID) {
    int tid = *((int *)threadID);

    printf("Thread %d is trying to access the shared resource...\n", tid);

    // Wait (decrement) the semaphore
    sem_wait(&semaphore);

    printf("Thread %d has gained access to the shared resource.\n", tid);

    // Critical section: Access the shared resource
    sharedResource++;
    printf("Shared resource value: %d\n", sharedResource);

    printf("Thread %d is releasing the shared resource.\n", tid);

    // Signal (increment) the semaphore
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, (void *)&threadIDs[i]);
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}