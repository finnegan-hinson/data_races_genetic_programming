package overseer;

import java.io.IOException;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.Arrays;

import incubator.Genome;
import incubator.GenomeWriter;
import incubator.Incubator;
import incubator.Population;
import server.Message;
import server.Server;

/**
 * This class oversees the generation of new populations and the execution of
 * said population's resulting c file.
 * 
 * In other words, it is the main delegator for the functionality of the
 * project.
 * 
 * @author Virginia Hinson and Sean Dwyer
 *
 */
public class Overseer {

	private static String runString;
	private static ArrayList<Genome> genomes;

	private static final String RUN = "./runner";
	private static final String CLUSTER_RUN = "srun ./runner";
	
	// Master switch for the population size, change here
	private static final int populationSize = 28;

	/**
	 * Accepts two arguments, the number of iterations and any second argument
	 * denoting that the program is running on the JMU cluster.
	 * 
	 * @param args the number of iterations and a second argument to indicate if it
	 *             is running on the cluster
	 */
	public static void main(String[] args) {
		int iterations;
		int[] points;
		Message msg;

		genomes = new ArrayList<Genome>();
		Server server = null;

		if (args.length > 2 || args.length < 1) {
			System.out.println("Invalid argument count");
			return;
		}
		try {
			iterations = Integer.parseInt(args[0]);
		} catch (NumberFormatException e) {
			System.out.println("The 1st parameter must be an integer");
			return;
		}


		server = Server.initServer();
		
		runString = RUN;
		// If any command line argument is given to indicate it is run on the cluster
		if (args.length == 3) {
			runString = CLUSTER_RUN;
		}

		Population population = new Population(populationSize);

		String homeDirectory = System.getProperty("user.dir");

		for (int x = 0; x < iterations; x++) {
			
			// A list of all genomes for tracking
			genomes.addAll(population.getGenomes());
			
			// Writes the population's genome snippets to a C file
			GenomeWriter writer = new GenomeWriter(population, homeDirectory + "/base_population.h",
					homeDirectory + "/population.h", "// Insert");

			try {
				writer.writePopulation();
			} catch (IOException e) {
				e.printStackTrace();
			}

			makeAndRun();
			msg = null;

			// If the socket times out, try once more
			try {
				msg = server.recvMessage();
			} catch (SocketTimeoutException e) {
				x--;
			}
			if (msg != null) {
				points = msg.getPoints();
				
				// Determine the fitness of the population run
				population.determineFitness(points);
				// Using this data, generate the next generation
				Incubator.nextGeneration(population);
			} else {
				System.err.println("Packet dropped. Redoing competition");
			}
		}
	}

	/**
	 * Runs the makefile and the generated C program.
	 */
	private static void makeAndRun() {
		try {
			Runtime.getRuntime().exec("make clean").waitFor();
			Runtime.getRuntime().exec("make").waitFor();
			Runtime.getRuntime().exec(runString);
		} catch (InterruptedException | IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	/**
	 * Runs the makefile and the generated C program from an IDE.
	 */
	private static void makeAndRunIDE() {
		try {
			Runtime.getRuntime().exec("make --directory=../ clean").waitFor();
			Runtime.getRuntime().exec("make --directory=../").waitFor();
			Runtime.getRuntime().exec("../runner");
		} catch (InterruptedException | IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
