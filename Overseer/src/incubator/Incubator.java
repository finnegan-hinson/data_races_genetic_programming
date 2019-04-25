package incubator;

import java.util.ArrayList;
import java.util.Random;

/**
 * The incubator, where the genetic programming algorithms are held.
 * 
 * Here there is a recombination method, called crossover, and a mutation
 * method, called mutation. The two methods are private as they are applied
 * through the public method nextGeneration in order to create a new generation
 * of a population.
 * 
 * @author Virginia R Hinson
 *
 */
public class Incubator {
	Genome fittest;
	Genome secondFittest;
	int generation = 0;
	static final double MUTATION_RATE = 0.01;
	static int id;

	/**
	 * This method performs the recombination step of genetic programming.
	 * 
	 * At a random point between the 4 snippets, the Genome swaps snippets from each
	 * of the parents to create two new child Genomes. After the recombination,
	 * there is a chance of mutation as is declared in MUTATION_RATE.
	 * 
	 * @param first  the first parent Genome
	 * @param second the second parent Genome
	 * @return an array containing both recombined children Genomes
	 */
	private static Genome[] crossover(Genome first, Genome second) {
		Genome[] recombined = new Genome[2];

		Random random = new Random();

		// The crossover is chosen at random instead of just the halfway point
		int crossoverPoint = random.nextInt(3) + 1; // 1 - 3

		// For each of the recombination points, the new genome is determined
		switch (crossoverPoint) {
		case 1:
			recombined[0] = new Genome(first.getFirst(), second.getSecond(), second.getThird(), second.getFourth(),
					first, second);
			recombined[1] = new Genome(second.getFirst(), first.getSecond(), first.getThird(), first.getFourth(), first,
					second);
			break;

		case 2:
			recombined[0] = new Genome(first.getFirst(), first.getSecond(), second.getThird(), second.getFourth(),
					first, second);
			recombined[1] = new Genome(second.getFirst(), second.getSecond(), first.getThird(), first.getFourth(),
					first, second);
			break;

		case 3:
			recombined[0] = new Genome(first.getFirst(), first.getSecond(), first.getThird(), second.getFourth(), first,
					second);
			recombined[1] = new Genome(second.getFirst(), second.getSecond(), second.getThird(), first.getFourth(),
					first, second);
			break;

		}

		// The new Genomes may get mutated at the mutation rate (for both Genomes)
		if (random.nextDouble() < MUTATION_RATE * 2) {
			if (random.nextBoolean()) {
				recombined[0] = mutation(recombined[0]);

			} else {
				recombined[1] = mutation(recombined[1]);
			}

		}

		return recombined;

	}

	/**
	 * This method chooses a random snippet in a given Genome and replaces it with a
	 * random snippet.
	 * 
	 * @param toMutate the original Genome
	 * @return the child after mutation
	 */
	public static Genome mutation(Genome toMutate) {

		Random random = new Random();

		// 1 - 4, the snippet to be changed
		int snippetToMutate = random.nextInt(4) + 1;
		// A random Snippet from the list is chosen, with 0 representing nothing
		int randomSnippet = Snippet.getRandomSnippetNumber();

		int first, second, third, fourth;

		first = toMutate.getFirst();
		second = toMutate.getSecond();
		third = toMutate.getThird();
		fourth = toMutate.getFourth();

		switch (snippetToMutate) {

		case 1:
			first = randomSnippet;
			break;
		case 2:
			second = randomSnippet;
			break;
		case 3:
			third = randomSnippet;
			break;
		case 4:
			fourth = randomSnippet;
			break;
		}

		// A new Genome object is created, with both parents as the unmutated Genome
		return new Genome(first, second, third, fourth, toMutate, toMutate);

	}

	/**
	 * The public method that generates the next generation through genetic
	 * programming from a given population. After the next generation is determined,
	 * the population's generation is set to the new generation.
	 * 
	 * @param population the population for which the next generation is being
	 *                   populated
	 */
	public static void nextGeneration(Population population) {

		ArrayList<Genome> nextGeneration = new ArrayList<Genome>();

		// Who moves along in the death race?

		// The winner and runner up in the race
		nextGeneration.add(population.getFittest());
		nextGeneration.add(population.getSecondFittest());

		// The children of the winners
		Genome[] winners = crossover(population.getFittest(), population.getSecondFittest());
		nextGeneration.add(winners[0]);
		nextGeneration.add(winners[1]);

		// Lucky members of the current population
		int remaining = population.getPopulationSize() - 4;
		while (remaining > 0) {
			Genome first = population.getRandomGenome();
			Genome second = population.getRandomGenome();

			Genome[] lucky = crossover(first, second);

			nextGeneration.add(lucky[0]);

			if (remaining != 1) {
				nextGeneration.add(lucky[1]);
			}

			remaining = remaining - 2;
		}

		population.clearFitness();
		population.setNextPopulation(nextGeneration);

	}

}
