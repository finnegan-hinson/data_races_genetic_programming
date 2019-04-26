package incubator;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Random;

/**
 * The population used for the DeathRace genetic programming.
 * 
 * https://towardsdatascience.com/introduction-to-genetic-algorithms-including-example-code-e396e98d8bf3
 * used for reference to create this class.
 * 
 * @author Virginia R Hinson
 *
 */
public class Population {

	private int populationSize;
	private ArrayList<Genome> genomes;

	private int fittest = 0;
	private int secondFittest = 0;

	private int[] fitnessFigures;

	/**
	 * Parameterized constructor to create a Population of genomes.
	 * 
	 * @param size the overall size of the population
	 */
	public Population(int size) {
		populationSize = size;
		genomes = new ArrayList<Genome>();

		initializePopulation();
	}

	/**
	 * Creates a populationSize set of Genome objects with random snippets.
	 */
	private void initializePopulation() {
		for (int i = 0; i < populationSize; i++) {
			genomes.add(new Genome(Snippet.getRandomSnippetNumber(), Snippet.getRandomSnippetNumber(),
					Snippet.getRandomSnippetNumber(), Snippet.getRandomSnippetNumber(), null, null));
		}

	}

	/**
	 * Sets the population to a new ArrayList of genome objects.
	 * 
	 * Throws an error if the new population is not populationSize.
	 * 
	 * @param genomes the new genomes for the population
	 */
	public void setNextPopulation(ArrayList<Genome> genomes) {
		if (genomes.size() != this.populationSize) {
			throw new IllegalArgumentException();
		}

		this.genomes = genomes;
	}

	/**
	 * Gets the Genome determined by determineFitness to be the fittest snippet.
	 * 
	 * @return the fittest genome
	 */
	public Genome getFittest() {
		return genomes.get(this.fittest);
	}

	/**
	 * Gets the Genome determined by determineFitness to be the second fittest
	 * snippet.
	 * 
	 * @return the second fittest genome
	 */
	public Genome getSecondFittest() {
		return genomes.get(this.secondFittest);
	}

	/**
	 * Returns a number point value representing the fitness of a specific genome in
	 * the population.
	 * 
	 * @param genome a genome in the population
	 * @return the fitness of that genome
	 */
	public int getFitness(Genome genome) {
		int number = genomes.indexOf(genome);

		// If an invalid genome is given
		if (number == -1) {
			return -1;
		}
		return fitnessFigures[number];
	}

	/**
	 * Returns a number point value representing the fitness of a specific genome
	 * (by number) in the population.
	 * 
	 * @param genomeNumber a number representing a genome in the population
	 * @return the fitness of that genome
	 */
	public int getFitness(int genomeNumber) {
		if (genomeNumber < 0 || genomeNumber > this.populationSize) {
			return -1;
		}

		return fitnessFigures[genomeNumber];
	}

	/**
	 * This method must be run in order to determine the fitness of the population
	 * and to accurately record the winner and runner up.
	 * 
	 * It takes an array of integer "points" values assigned in the c program and
	 * copies them into the fitnessFigures array (where the index represents the
	 * number in the population ArrayList) and sets the fittest and second fittest.
	 * 
	 * @param fitnessNumbers an array of integers representing the "score" of each
	 *                       genome
	 */
	public void determineFitness(int[] fitnessNumbers) {

		this.fitnessFigures = fitnessNumbers;
		int[] copyFitness = new int[this.populationSize];

		for (int i = 0; i < fitnessFigures.length; i++) {
			if (fitnessFigures[i] > fitnessFigures[this.fittest]) {
				this.secondFittest = this.fittest;
				this.fittest = i;
			}

			copyFitness[i] = fitnessFigures[i];
		}

		copyFitness[this.fittest] = 0;

		for (int i = 0; i < fitnessFigures.length; i++) {
			if (fitnessFigures[i] > fitnessFigures[this.secondFittest]) {
				this.secondFittest = i;
			}

		}

	}

	/**
	 * Returns the fitness array to null, and sets the fittest and second fittest to
	 * 0.
	 */
	public void clearFitness() {
		this.fitnessFigures = null;
		this.fittest = 0;
		this.secondFittest = 0;
	}

	/**
	 * Returns the size of the population
	 * 
	 * @return an integer representing population size
	 */
	public int getPopulationSize() {
		return this.populationSize;
	}

	/**
	 * Returns an array of Strings that contain the genome code for the population.
	 * 
	 * @return an array of strings, each of which containing the snippets in each
	 *         genome
	 */
	public String[] populationSnippets() {
		String[] populationCode = new String[this.populationSize];

		for (int i = 0; i < this.populationSize; i++) {
			populationCode[i] = genomes.get(i).snippetsToInsert();
		}

		return populationCode;
	}

	/**
	 * Gives the snippets of code for a certain genome in the population
	 * 
	 * @param populationNumber beginning with one, the number of the population
	 * @return the snippets associated with that genome
	 */
	public String genomeSnippets(int populationNumber) {
		if (populationNumber < 1 || populationNumber > this.populationSize) {
			return "// no code";
		}

		return genomes.get(populationNumber - 1).snippetsToInsert();
	}

	/**
	 * Retrieves the genome in the population, represented by its identification
	 * number in the C file (and its index in the population ArrayList).
	 * 
	 * @param number the identifier of the genome to be retrieved
	 * @return the genome represented by the number given, IllegalArgumentException
	 *         if this isn't valid
	 */
	public Genome getGenome(int number) {
		if (number < 1 || number > this.populationSize) {
			throw new IllegalArgumentException();
		}

		return genomes.get(number - 1);
	}

	/**
	 * Returns the entire collection of Genomes.
	 * 
	 * @return the collection of genomes in a population
	 */
	public Collection<Genome> getGenomes() {
		return this.genomes;
	}

	/**
	 * Returns a random genome in the population.
	 * 
	 * @return a random genome in the population
	 */
	public Genome getRandomGenome() {
		Random random = new Random();
		int index = random.nextInt(this.getPopulationSize());

		return genomes.get(index);

	}

}
