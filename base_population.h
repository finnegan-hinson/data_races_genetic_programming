#define EARTH_SPG 398600441800000

#define INPUT_SIZE 10

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

/*
 * Incorrect LAZZZZY Boi
 */ 
void orbital_period1(double* inputs, long* answers, long** all_answers)
{
	int period_num = 1;
	int prime = PRIME_1;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }}

/*
 * Incorrect Boi
 */ 
void orbital_period2(double* inputs, long* answers, long** all_answers)
{
	int period_num = 2;
	int prime = PRIME_2;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period3(double* inputs, long* answers, long** all_answers)
{
	int period_num = 3;
	int prime = PRIME_3;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
		double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
		
        // Insert
    }
}

/*
 * Correct simple boi.
 */  
void orbital_period4(double* inputs, long* answers, long** all_answers)
{
	int period_num = 4;
	int prime = PRIME_4;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
		
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period5(double* inputs, long* answers, long** all_answers)
{
	int period_num = 5;
	int prime = PRIME_5;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period6(double* inputs, long* answers, long** all_answers)
{
	int period_num = 6;
	int prime = PRIME_6;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

/*
 * Correct and slow Boi
 */ 
void orbital_period7(double* inputs, long* answers, long** all_answers)
{
	int period_num = 7;
	int prime = PRIME_7;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period8(double* inputs, long* answers, long** all_answers)
{
	int period_num = 8;
	int prime = PRIME_8;
	
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        double a, to_root, count;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        // Insert
    }
}

/*
 * This generates the correct answer. Do not modify
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
 * (Run this guy)
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
		
		
	}
}
