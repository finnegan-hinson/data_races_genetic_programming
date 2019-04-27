/*
 * This is used to generate (if base_population.h) or run (if population.h)
 * compititions between threads to generate point values representing a given
 * genomes fitness in this context.
 * 
 * In the current compitition, each thread will write to a shared resource and
 * to its own address within a two demensional array.
 * 
 * NOTE: The Java snippet writer uses the insert tags to locate locations in the
 * code where snippets are to be written.
 * 
 * Authors: Sean Dwyer and Virgina Hinson.
 * 
 */

#define EARTH_SPG 398600441800000

#define INPUT_SIZE 10000
#define NUM_THREADS 7 //Max threads on a cluster -1.
#define NODES 4 //Number of nodes for the program to be run on.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#define PRIME_1 101
#define PRIME_2 103
#define PRIME_3 107
#define PRIME_4 109
#define PRIME_5 113
#define PRIME_6 127
#define PRIME_7 131
#define PRIME_8 137
#define PRIME_9 139
#define PRIME_10 149
#define PRIME_11 151
#define PRIME_12 157
#define PRIME_13 163
#define PRIME_14 167
#define PRIME_15 173
#define PRIME_16 179
#define PRIME_17 181
#define PRIME_18 191
#define PRIME_19 193
#define PRIME_20 197
#define PRIME_21 199
#define PRIME_22 211
#define PRIME_23 223
#define PRIME_24 227
#define PRIME_25 229
#define PRIME_26 233
#define PRIME_27 239
#define PRIME_28 241


//BEGIN Generated_Functions

//Genome 1
void orbital_period1(double* inputs, long* answers, long** all_answers)
{
	int period_num = 0 % NUM_THREADS;
	int prime = PRIME_1;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 2
void orbital_period2(double* inputs, long* answers, long** all_answers)
{
	int period_num = 1 % NUM_THREADS;
	int prime = PRIME_2;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 3
void orbital_period3(double* inputs, long* answers, long** all_answers)
{
	int period_num = 2 % NUM_THREADS;
	int prime = PRIME_3;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
		double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
		
        // Insert
    }
}

//Genome 4
void orbital_period4(double* inputs, long* answers, long** all_answers)
{
	int period_num = 3 % NUM_THREADS;
	int prime = PRIME_4;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
		
    }
}

//Genome 5
void orbital_period5(double* inputs, long* answers, long** all_answers)
{
	int period_num = 4 % NUM_THREADS;
	int prime = PRIME_5;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 6
void orbital_period6(double* inputs, long* answers, long** all_answers)
{
	int period_num = 5 % NUM_THREADS;
	int prime = PRIME_6;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 7
void orbital_period7(double* inputs, long* answers, long** all_answers)
{
	int period_num = 6 % NUM_THREADS;
	int prime = PRIME_7;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 8
void orbital_period8(double* inputs, long* answers, long** all_answers)
{
	int period_num = 7 % NUM_THREADS;
	int prime = PRIME_8;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 9
void orbital_period9(double* inputs, long* answers, long** all_answers)
{
	int period_num = 8 % NUM_THREADS;
	int prime = PRIME_8;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 10
void orbital_period10(double* inputs, long* answers, long** all_answers)
{
	int period_num = 9 % NUM_THREADS;
	int prime = PRIME_9;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 11
void orbital_period11(double* inputs, long* answers, long** all_answers)
{
	int period_num = 10 % NUM_THREADS;
	int prime = PRIME_11;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 12
void orbital_period12(double* inputs, long* answers, long** all_answers)
{
	int period_num = 11 % NUM_THREADS;
	int prime = PRIME_12;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 13
void orbital_period13(double* inputs, long* answers, long** all_answers)
{
	int period_num = 12 % NUM_THREADS;
	int prime = PRIME_13;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 14
void orbital_period14(double* inputs, long* answers, long** all_answers)
{
	int period_num = 13 % NUM_THREADS;
	int prime = PRIME_14;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 15
void orbital_period15(double* inputs, long* answers, long** all_answers)
{
	int period_num = 14 % NUM_THREADS;
	int prime = PRIME_15;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 16
void orbital_period16(double* inputs, long* answers, long** all_answers)
{
	int period_num = 15 % NUM_THREADS;
	int prime = PRIME_16;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 17
void orbital_period17(double* inputs, long* answers, long** all_answers)
{
	int period_num = 16 % NUM_THREADS;
	int prime = PRIME_17;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 18
void orbital_period18(double* inputs, long* answers, long** all_answers)
{
	int period_num = 17 % NUM_THREADS;
	int prime = PRIME_18;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 19
void orbital_period19(double* inputs, long* answers, long** all_answers)
{
	int period_num = 18 % NUM_THREADS;
	int prime = PRIME_19;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 20
void orbital_period20(double* inputs, long* answers, long** all_answers)
{
	int period_num = 19 % NUM_THREADS;
	int prime = PRIME_20;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 21
void orbital_period21(double* inputs, long* answers, long** all_answers)
{
	int period_num = 20 % NUM_THREADS;
	int prime = PRIME_21;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 22
void orbital_period22(double* inputs, long* answers, long** all_answers)
{
	int period_num = 21 % NUM_THREADS;
	int prime = PRIME_22;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 23
void orbital_period23(double* inputs, long* answers, long** all_answers)
{
	int period_num = 22 % NUM_THREADS;
	int prime = PRIME_23;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 24
void orbital_period24(double* inputs, long* answers, long** all_answers)
{
	int period_num = 23 % NUM_THREADS;
	int prime = PRIME_24;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 25
void orbital_period25(double* inputs, long* answers, long** all_answers)
{
	int period_num = 24 % NUM_THREADS;
	int prime = PRIME_25;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 26
void orbital_period26(double* inputs, long* answers, long** all_answers)
{
	int period_num = 25 % NUM_THREADS;
	int prime = PRIME_26;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 27
void orbital_period27(double* inputs, long* answers, long** all_answers)
{
	int period_num = 26 % NUM_THREADS;
	int prime = PRIME_27;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

//Genome 28
void orbital_period28(double* inputs, long* answers, long** all_answers)
{
	int period_num = 27 % NUM_THREADS;
	int prime = PRIME_28;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}
//END Generated_Functions

/*
 * This generates the correct answer. Do not modify
 * with a incubator.
 */
void orbital_period_cannon(double* inputs, long* answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = roundl((2 * M_PI) * sqrt(to_root));
    }
}

/*
 * Calculate the orbital periods of the given satelites (assuming Earth SOI and no other bodies)
 * see [https://en.wikipedia.org/wiki/Orbital_mechanics#Orbital_period]
 * 
 * Call this function from outside of population.
 */ 
void orbital_period(double* inputs, long* answers, long** all_answers, int thread)
{
	switch(thread)
	{
		case 1:
			orbital_period1(inputs, answers, all_answers);
		break;
		
		case 2:
			orbital_period2(inputs, answers, all_answers);
		break;
		
		case 3:
			orbital_period3(inputs, answers, all_answers);
		break;
		
		case 4:
			orbital_period4(inputs, answers, all_answers);
		break;
		
		case 5:
			orbital_period5(inputs, answers, all_answers);
		break;
		
		case 6:
			orbital_period6(inputs, answers, all_answers);
		break;
		
		case 7:
			orbital_period7(inputs, answers, all_answers);
		break;
		
		case 8:
			orbital_period8(inputs, answers, all_answers);
		break;
        
        case 9:
			orbital_period9(inputs, answers, all_answers);
		break;
		
		case 10:
			orbital_period10(inputs, answers, all_answers);
		break;
		
		case 11:
			orbital_period11(inputs, answers, all_answers);
		break;
		
		case 12:
			orbital_period12(inputs, answers, all_answers);
		break;
		
		case 13:
			orbital_period13(inputs, answers, all_answers);
		break;
		
		case 14:
			orbital_period14(inputs, answers, all_answers);
		break;
		
		case 15:
			orbital_period15(inputs, answers, all_answers);
		break;
		
		case 16:
			orbital_period16(inputs, answers, all_answers);
		break;
        
        case 17:
			orbital_period17(inputs, answers, all_answers);
		break;
		
		case 18:
			orbital_period18(inputs, answers, all_answers);
		break;
		
		case 19:
			orbital_period19(inputs, answers, all_answers);
		break;
		
		case 20:
			orbital_period20(inputs, answers, all_answers);
		break;
		
		case 21:
			orbital_period21(inputs, answers, all_answers);
		break;
		
		case 22:
			orbital_period22(inputs, answers, all_answers);
		break;
		
		case 23:
			orbital_period23(inputs, answers, all_answers);
		break;
		
		case 24:
			orbital_period24(inputs, answers, all_answers);
		break;
        
        case 25:
			orbital_period25(inputs, answers, all_answers);
		break;
        
        case 26:
			orbital_period26(inputs, answers, all_answers);
		break;
        
        case 27:
			orbital_period27(inputs, answers, all_answers);
		break;
        
        case 28:
			orbital_period28(inputs, answers, all_answers);
		break;
	}
}
