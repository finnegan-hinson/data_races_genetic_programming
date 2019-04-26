package incubator;

/**
 * A Genome is a representation of a code block in our C program. It uses
 * numbers to correspond to the snippet enum, which represent strings it can
 * retrieve containing C code.
 * 
 * This version uses four snippets, but it could be easily expanded into more.
 * (If you did this be sure to increase the numbers in Incubator.crossover as it
 * is hard coded to deal with four snippets at the moment.)
 * 
 * 
 * @author Virginia R Hinson
 *
 */
public class Genome {

	private int first;
	private int second;
	private int third;
	private int fourth;

	private static int counter = 0;
	private int id;

	int[] parentID = new int[2];

	/**
	 * The constructor for Genomes.
	 * 
	 * 
	 * @param one    an integer representing the first snippet
	 * @param two    an integer representing the second snippet
	 * @param three  an integer representing the third snippet
	 * @param four   an integer representing the fourth snippet
	 * @param father one of the genome "parents"
	 * @param mother the second genome "parent"
	 */
	public Genome(int one, int two, int three, int four, Genome father, Genome mother) {
		first = one;
		second = two;
		third = three;
		fourth = four;

		// The initial population lists null as their parent
		if (father == null) {
			parentID[0] = -1;
		} else {
			parentID[0] = father.getID();
		}

		if (mother == null) {
			parentID[1] = -1;
		} else {
			parentID[1] = mother.getID();
		}

		this.id = counter++;

	}

	/**
	 * Gathers the snippets the genome represents as a string.
	 * 
	 * @return the snippets as a string
	 */
	public String snippetsToInsert() {
		return Snippet.getSnippet(first) + "\n" + Snippet.getSnippet(second) + "\n" + Snippet.getSnippet(third) + "\n"
				+ Snippet.getSnippet(fourth);

	}

	/**
	 * "Getter" for the first snippet.
	 * 
	 * @return the first snippet number
	 */
	public int getFirst() {
		return this.first;
	}

	/**
	 * "Getter" for the second snippet.
	 * 
	 * @return the second snippet number
	 */
	public int getSecond() {
		return this.second;
	}

	/**
	 * "Getter" for the third snippet.
	 * 
	 * @return the third snippet number
	 */
	public int getThird() {
		return this.third;
	}

	/**
	 * "Getter" for the fourth snippet.
	 * 
	 * @return the fourth snippet number
	 */
	public int getFourth() {
		return this.fourth;
	}

	/**
	 * Returns the size of the genomes.
	 * 
	 * @return the genome size
	 */
	public static int genomeSize() {
		return 4;
	}

	/**
	 * Returns the unique ID for this genome.
	 * 
	 * @return the integer id for this genome
	 */
	public int getID() {
		return id;
	}

	/**
	 * Returns an array of IDs from both genomes that recombined to create the
	 * current one.
	 * 
	 * If both parents are the same, the genome was a result of mutation. If both
	 * are -1 it was part of the initial population.
	 * 
	 * @return an array of parent IDs
	 */
	public int[] getParentIDs() {
		return parentID;
	}

}
