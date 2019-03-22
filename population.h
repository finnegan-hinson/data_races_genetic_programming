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
	//I really don't do anything.  ¯\_(ツ)_/¯
}

/*
 * Incorrect Boi
 */ 
void orbital_period2(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = (roundl((16 * M_PI) * sqrt(to_root)))* PRIME_2;
		all_answers[1][x] = roundl((16 * M_PI) * sqrt(to_root));
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period3(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        answers[x] = 42*PRIME_3;
		all_answers[2][x] = 42;
    }
}

/*
 * Correct simple boi.
 */  
void orbital_period4(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = (roundl((2 * M_PI) * sqrt(to_root)))*PRIME_4;
		all_answers[3][x] = roundl((2 * M_PI) * sqrt(to_root));
		
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period5(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = (roundl((2 * M_PI) * sin(to_root)))*PRIME_5;
		all_answers[4][x] = roundl((2 * M_PI) * sin(to_root));
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period6(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = (roundl((2 * M_PI) * cos(to_root)))*PRIME_6;
		all_answers[5][x] = roundl((2 * M_PI) * cos(to_root));
    }
}

/*
 * Correct and slow Boi
 */ 
void orbital_period7(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {
        double a, to_root;
        a = pow(inputs[x], 3);
        
        to_root = a / EARTH_SPG;
        
        answers[x] = (roundl((2 * M_PI) * sqrt(to_root)))*PRIME_7;
		all_answers[6][x] = roundl((2 * M_PI) * sqrt(to_root));
        
		sleep(1);
    }
}

/*
 * Incorrect Boi
 */ 
void orbital_period8(double* inputs, long* answers, long** all_answers)
{
    for(int x = 0; x < INPUT_SIZE; x++)
    {   
        answers[x] = 0xABCED*PRIME_8;
		all_answers[7][x] = 0xABCED;
    }
}

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
