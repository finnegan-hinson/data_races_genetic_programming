/*
 * Program entry point for the C compitition.
 * 
 * Authors: Sean Dwyer and Virgina Hinson.
 */

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

/*
 * NOTE: Constants are defined in these files.
 */
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
    
    //Directs the thread to the approprate method. See base_population.h
    orbital_period(inputs, answers, all_answers, thread_num);
    return NULL;

}

/*
 * 
 */
int main(int argc, char *argv[])
{
    /*
     * Initalize the MPI Envormnent
     */
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    //NOTE: From this point on, this code will execute independently within the diffent processes.
    
    //wait(1);
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
    primes[15] = PRIME_15;
    primes[16] = PRIME_16;
    primes[17] = PRIME_17;
    primes[18] = PRIME_18;
    primes[19] = PRIME_19;
    primes[20] = PRIME_20;
    primes[21] = PRIME_21;
    primes[22] = PRIME_22;
    primes[23] = PRIME_23;
    primes[24] = PRIME_24;
    primes[25] = PRIME_25;
    primes[26] = PRIME_26;
    primes[27] = PRIME_27;
    primes[28] = PRIME_28;
    
    
    //Allocate memory.
    inputs = (double *) malloc(sizeof(double) * INPUT_SIZE);

    answers = malloc(sizeof(long *) * INPUT_SIZE);
    expected = malloc(sizeof(long *) * INPUT_SIZE);
    all_answers = malloc(NUM_THREADS * sizeof(long*));
    
    points = malloc(NUM_THREADS * sizeof(int));
        
    points_all = malloc(NODES * NUM_THREADS * sizeof(int));
    
    /*
     * Zero out the all answers buffer
     */
    for(int x = 0; x < NUM_THREADS; x++)
    {
        all_answers[x] = malloc(sizeof(long)* INPUT_SIZE);
    }
    
    /*
     * Zero out points memory
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
    
    /*
     * Generate random numbers for the input into the Keplars Third Law equation.
     * 
     * NOTE: Each process will generate a uniqe set of inputs.
     */
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        inputs[x] = (double)rand()/RAND_MAX*13500000.0 + 50000000.0;
    }
    
    //Generate the answer key.
    orbital_period_cannon(inputs, expected);

    //Initalize pthread array.
    pthread_t* threads = (pthread_t *) malloc(NUM_THREADS * sizeof(pthread_t));

    //Initalize the semaphore for getting thread ids.
    sem_init(&id_sem, 0, 0);
    
    //declare timer structs for timing the execution of the compitition.
    struct timespec start, stop;
    
    //Get the time at start.
    clock_gettime(CLOCK_BOOTTIME, &start);
    
    /*
     * Create the threads that are competing.
     * 
     * NOTE: This will slightly the nodes that are generated first. In pratice, a large input size mitigates
     * this bias, as the differences in runtimes become more pronounced.
     */
    for (int i = 0; i < NUM_THREADS; i++) {
        int id = i + (my_rank * NUM_THREADS) + 1;
        pthread_create(&threads[i], NULL, run_program, (void *) &id);
        sem_wait(&id_sem);
    }
    
    printf("%d: Joining Threads\n", my_rank);
    
    /*
     * Join the nodes after completion. 
     */
    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }
    
    clock_gettime(CLOCK_BOOTTIME, &stop);
    
    time_elapsed = (int) 1000 * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / 1000;
    
    
    /**
     * Look in the shared resources and in the 2d array to determain both
     * which threads got the correct answer and which (if any) threads wrote
     * the correct answer into the shared resource.
     * 
     * For this expirement, the points values for each thread
     * are defined by 
     * points = 50*correct_in_shared + 10*correct
     */
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
    
    /*
     * Agregate the resulting points from each compitition into one array.
     */
    MPI_Gather(points, NUM_THREADS, MPI_INT, 
        points_all, NUM_THREADS, MPI_INT, 0, MPI_COMM_WORLD);
    
    //Only the master process executes the following.
    if(my_rank == 0)
    {
        /*
         * Create a new time struct from the given system time.
         * Use this time to get the total runtime in miliseconds.
         */
        time_elapsed = (int) 1000 * (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / 1000;
    
        //Send the points to Java server via UDP. See client.h.
        sendPoints(points_all, NUM_THREADS * NODES, time_elapsed);
        
        /* Debugging print statement. Left in for convienance.
         * 
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
        */
    }
    
    //Final MPI function call.
    MPI_Finalize();

    //Free memory and exit.
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
