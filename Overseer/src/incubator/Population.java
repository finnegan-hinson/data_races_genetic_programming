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
	 * 
	 * @param size
	 */
	public Population(int size) {
		populationSize = size;
		genomes = new ArrayList<Genome>();

		initializePopulation();
	}

	/**
	 * 
	 */
	private void initializePopulation() {
		for (int i = 0; i < populationSize; i++) {
			genomes.add(new Genome(Snippet.getRandomSnippetNumber(), Snippet.getRandomSnippetNumber(),
					Snippet.getRandomSnippetNumber(), Snippet.getRandomSnippetNumber(), null, null));
		}

	}

	/**
	 * 
	 * @param genomes
	 */
	public void setNextPopulation(ArrayList<Genome> genomes) {
		if (genomes.size() != this.populationSize) {
			throw new IllegalArgumentException();
		}

		this.genomes = genomes;
	}

	/**
	 * 
	 * @return
	 */
	public Genome getFittest() {
		return genomes.get(this.fittest);
	}

	/**
	 * 
	 * @return
	 */
	public Genome getSecondFittest() {
		return genomes.get(this.secondFittest);
	}

	/**
	 * 
	 * @param genome
	 * @return
	 */
	public int getFitness(Genome genome) {
		int number = genomes.indexOf(genome);

		return fitnessFigures[number];
	}

	/**
	 * 
	 * @param genomeNumber
	 * @return
	 */
	public int getFitness(int genomeNumber) {
		return fitnessFigures[genomeNumber % this.populationSize];
	}

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

	public void clearFitness() {
		this.fitnessFigures = null;
		this.fittest = 0;
		this.secondFittest = 0;
	}

	public int getPopulationSize() {
		return this.populationSize;
	}

	/**
	 * 
	 * @return
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

	public Genome getGenome(int number) {
		if (number < 1 || number > this.populationSize) {
			throw new IllegalArgumentException();
		}

		return genomes.get(number - 1);
	}

	public Collection<Genome> getGenomes() {
		return this.genomes;
	}

	public Genome getRandomGenome() {
		Random random = new Random();
		int index = random.nextInt(this.getPopulationSize());

		return genomes.get(index);

	}

}
