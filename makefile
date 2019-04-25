default: runner

runner: runner.c
	 mpicc -g --std=c99 -Wall -o runner runner.c -lpthread --std=gnu11 -lm

clean: 
	rm -f runner
