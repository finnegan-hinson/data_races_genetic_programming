#include <pthread.h>
#include <math.h>
#include <time.h>

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <mpi.h>

#include "population.h"
#include "client.h"

sem_t id_sem;

double* inputs;

long* expected; //The "answer key"
long* answers; //The actuall answers. This is a shared resource.
long** all_answers;

int* points; //The points from this compitition.
int* points_all; //The points aggregated from all compititions.

int time_elapsed;

int my_rank;

/*
 Runs the generated C code, testing to see who "wins"
 the data race.
*/
void *run_program(void *thread_number)
{
    int thread_num = *((int*)thread_number);
    sem_post(&id_sem);
    
    //pthread_barrier_wait(&start_barrier);
    
    orbital_period(inputs, answers, all_answers, thread_num);
    return NULL;

}

int main(int argc, char *argv[])
{
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    printf("%d Forked\n", my_rank);
    
    int primes[28];
    primes[0 ] = PRIME_1;
    primes[1 ] = PRIME_2;
    primes[2 ] = PRIME_3;
    primes[3 ] = PRIME_4;
    primes[4 ] = PRIME_5;
    primes[5 ] = PRIME_6;
    primes[6 ] = PRIME_7;
    primes[7 ] = PRIME_8;
    primes[8 ] = PRIME_9;
    primes[9 ] = PRIME_10;
    primes[10] = PRIME_11;
    primes[11] = PRIME_12;
    primes[12] = PRIME_13;
    primes[13] = PRIME_14;
    primes[14] = PRIME_15;
    primes[15] = PRIME_16;
    primes[16] = PRIME_17;
    primes[17] = PRIME_18;
    primes[18] = PRIME_19;
    primes[19] = PRIME_20;
    primes[20] = PRIME_21;
    primes[21] = PRIME_22;
    primes[22] = PRIME_23;
    primes[23] = PRIME_24;
    primes[24] = PRIME_25;
    primes[25] = PRIME_26;
    primes[26] = PRIME_27;
    primes[27] = PRIME_28;
    
    
    
    inputs = (double *) malloc(sizeof(double) * INPUT_SIZE);

    answers = malloc(sizeof(long *) * INPUT_SIZE);
    expected = malloc(sizeof(long *) * INPUT_SIZE);
    all_answers = malloc(NUM_THREADS * sizeof(long*));
    
    points = malloc(NUM_THREADS * sizeof(int));
        
    points_all = malloc(NODES * NUM_THREADS * sizeof(int));
    
    for(int x = 0; x < NUM_THREADS; x++)
    {
        all_answers[x] = malloc(sizeof(long)* INPUT_SIZE);
    }
    
    /*
     * Zero out memory
     */
    for(int x = 0; x < NUM_THREADS; x++)
    {
        points[x] = 0;
    }
    
    /*
     * Zero out points buffer.
     */
    for(int x = 0; x < NUM_THREADS * NODES; x++)
    {
        points_all[x] = 0;
    }

    //Seed the random number generator.
    srand(time(0));
    
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        inputs[x] = (double)rand()/RAND_MAX*13500000.0 + 50000000.0;
    }
    
    //Get answer key
    orbital_period_cannon(inputs, expected);
    
    printf("Initalized Data \n");

    pthread_t* threads = (pthread_t *) malloc(NUM_THREADS * sizeof(pthread_t));

    sem_init(&id_sem, 0, 0);
    
    struct timespec start, stop;
    
    clock_gettime(CLOCK_BOOTTIME, &start);
    
    sem_init(&id_sem, 0, 0);
    
    for (int i = 0; i < NUM_THREADS; i++) {
        int id = i + (my_rank * NUM_THREADS) + 1;
        pthread_create(&threads[i], NULL, run_program, (void *) &id);
        sem_wait(&id_sem);
    }
    
    printf("%d: Joining Threads\n", my_rank);
    
    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }
    
    clock_gettime(CLOCK_BOOTTIME, &stop);
    
    time_elapsed = (int) 1000 * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / 1000;
    
    
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
            if(answers[x]/primes[thread + (my_rank * NUM_THREADS)] == expected[x])
            {
                points[thread] += 50;
            }
        }
    }
    
    MPI_Gather(points, NUM_THREADS, MPI_INT, 
        points_all, NUM_THREADS, MPI_INT, 0, MPI_COMM_WORLD);
        
    MPI_Barrier(MPI_COMM_WORLD);
    
    if(my_rank == 0)
    {
        printf("Sending Results to Server.\n");
        time_elapsed = (int) 1000 * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / 1000;
    
        sendPoints(points_all, sizeof(points_all)/sizeof(int), time_elapsed);
        printf("**POINTS**\n[");
        for(int x = 0; x < NUM_THREADS * NODES; x++)
        {
            if(x != 0)
            {
                printf(", ");
            }
            printf("%d", points_all[x]);
        }
        printf("]\n");
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    
    MPI_Finalize();

    free(inputs);
    free(answers);
    free(expected);
    free(points_all);
    
    for(int x = 0; x < NUM_THREADS; x++)
    {
        free(all_answers[x]);
    }
    
    free(all_answers);

    free(threads);
    
    sem_destroy(&id_sem);

    exit(EXIT_SUCCESS);
}
