# Death Race x86

## Use Instructions

### Setup
*The included Overseer.jar file should be placed in the same directory as the included base_population.h, client.h and runner.c.

*The program MUST be run in a Linux environment as it makes use of the Java exec runtime command

*When running the jar file, you must include 1 parameter, an integer value representing the number of iterations of evolution to be run. An additional parameter will cause the program to assume it is running on the cluster and use srun commands appropriately, else the program will use normal run commands.

*The program will automatically compile C code on each iteration, simple assure that the setup is followed.

### Running
*Command on the cluster: "srun java -jar ./Overseer.jar [#itterations] y"

*The output to the console is the itteration that the process is currently on and the total runtime of the
    compitition. Note that the average time will steadaly increace as the programs evolve.
    
## To Compile
### Java Code

**With Eclipse (Recomended)**
*Import source folder into a project.
*Right click export->java->runable_jar_file
    Select Overseer.java as the program entry point.

**With Apache ANT (Tempermental)**
*Go into over seer directory and run "ant compile" in the command line.

### C Code
NOTE: This will be automatically done when the Overseer is run.

*Simply execute the build.sh file.

## Files
*base_population.h - Used to write the population.h file.

*build_c.sh - Batch script that loads MPI and compiles the C code.

*client.h - Used to send datagrams to the java server.

*makefile - The makefile used to compile the C code.

*Overseer.jar - Precompiled executable jar folder.

*run_comp.sh - Runs a single itteration of the compitition C code on 4 nodes.

*runner.c - C source file for the compitition runner.

*readme.md - You are here.

*Javadocs - The javadocs for the Overseer program. (Open index.html within)

*Overseer - Directory of the Java sourse code (See javadocs for more info).
