#include <pthread.h>
#include <math.h>
#include <time.h>

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

#include "population.h"
#include "client.h"

#define NUM_THREADS 7

/*

 Runs the generated C code, testing to see who "wins"
 the data race.

*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

sem_t id_sem;

double* inputs;

long* expected;
long* answers;
long** all_answers;

int* points;

void *run_program(void *thread_number)
{
    int thread_num = *((int*)thread_number);
    sem_post(&id_sem);
    
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    pthread_mutex_unlock(&mutex);

    orbital_period(inputs, answers, all_answers, thread_num);
    return NULL;

}

int main(int argc, char *argv[])
{
    int primes[16];
    primes[0] = PRIME_1;
    primes[1] = PRIME_2;
    primes[2] = PRIME_3;
    primes[3] = PRIME_4;
    primes[4] = PRIME_5;
    primes[5] = PRIME_6;
    primes[6] = PRIME_7;
    primes[7] = PRIME_8;
    primes[8] = PRIME_9;
    primes[9] = PRIME_10;
    primes[10] = PRIME_11;
    primes[11] = PRIME_12;
    primes[12] = PRIME_13;
    primes[13] = PRIME_14;
    primes[14] = PRIME_15;
    
    
    inputs = (double *) malloc(sizeof(double) * INPUT_SIZE);

    answers = malloc(sizeof(long *) * INPUT_SIZE);
    expected = malloc(sizeof(long *) * INPUT_SIZE);
    all_answers = malloc(NUM_THREADS * sizeof(long*));
    
    points = malloc(NUM_THREADS * sizeof(int));
    
    for(int x = 0; x < NUM_THREADS; x++)
    {
        all_answers[x] = malloc(sizeof(long)* INPUT_SIZE);
    }


    inputs[0] = 250000l*1000;
    inputs[1] = 500000l*1000;
    inputs[2] = 1000000l*1000;
    inputs[3] = 1500000l*1000;
    inputs[4] = 2000000l*1000;
    inputs[5] = 2500000l*1000;
    inputs[6] = 3000000l*1000;
    inputs[7] = 3500000l*1000;
    inputs[8] = 4000000l*1000;
    inputs[9] = 4500000l*1000;
    
    //Get answer key
    orbital_period_cannon(inputs, expected);

    pthread_t* threads = (pthread_t *) malloc(NUM_THREADS * sizeof(pthread_t));

    sem_init(&id_sem, 0, 0);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        int id = i + 1;
        pthread_create(&threads[i], NULL, run_program, (void *) &id);
        sem_wait(&id_sem);
    }

    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond); // Go!
    pthread_mutex_unlock(&mutex);

    printf("Joining Threads\n");
    
    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }
    
    printf("**EXPECTED ANSWERS**\n[");
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        if(x != 0)
        {
            printf(", ");
        }
        printf("%ld", expected[x]);
    }
    printf("]\n");

    // Mess with the results in answers/all answers
    for(int thread = 0; thread < NUM_THREADS; thread++)
    {
        for(int x = 0; x < INPUT_SIZE; x++)
        {
            //Correct answer is worth 10 points
            if(all_answers[thread][x] == expected[x])
            {
                points[thread] += 10;
            }
            
            //Correct answer in shared array worth 50 points.
            if(answers[x]/primes[thread] == expected[x])
            {
                points[thread] += 50;
            }
        }
    }
    
    printf("***********\nACTUAL ANSWERS\n************\n");
    
    for(int x = 0; x < NUM_THREADS; x++)
    {
        printf("Thread: %d[", x+1);
        for(int y = 0; y < INPUT_SIZE; y++)
        {
            if( y != 0)
            {
                printf(", ");
            }
            printf("%ld", all_answers[x][y]);
        }
        printf("]\n");
    }
    printf("*****************\n");
    
    printf("**POINTS**\n[");
    for(int x = 0; x < NUM_THREADS; x++)
    {
        if(x != 0)
        {
            printf(", ");
        }
        printf("%d", points[x]);
    }
    printf("]\n");
    
    printf("Sending Results to Server.\n");
    
    sendPoints(points, sizeof(points));

    printf("Made it to clean up.\n");
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    free(inputs);
    free(answers);
    free(expected);
    
    for(int x = 0; x < NUM_THREADS; x++)
    {
        free(all_answers[x]);
    }
    
    free(all_answers);

    free(threads);
    
    sem_destroy(&id_sem);

    exit(EXIT_SUCCESS);
}
