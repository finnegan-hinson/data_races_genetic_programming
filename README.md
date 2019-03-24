# Death Race x86

<b>Use Instructions</b>

-The included Overseer.jar file should be placed in the same directory as the included base_population.h, client.h and runner.c.

-The program MUST be run in a Linux environment as it makes use of the Java exec runtime command

-When running the jar file, you must include 1 parameter, an integer value representing the number of iterations of evolution to be run. An additional parameter will cause the program to assume it is running on the cluster and use srun commands appropriately, else the program will use normal run commands.

-The program will automatically compile C code on each iteration, simple assure that the setup is followed.
