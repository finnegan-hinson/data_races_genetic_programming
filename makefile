default: runner

runner: runner.c
	 gcc -g --std=c99 -Wall -o runner runner.c -lpthread --std=gnu11 -lm

clean: 
	rm -f runner
