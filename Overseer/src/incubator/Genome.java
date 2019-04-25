package incubator;

/**
 * A combination of four snippets to make the "genome"
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

	public Genome(int one, int two, int three, int four,  Genome father, Genome mother) {
		first = one;
		second = two;
		third = three;
		fourth = four;
		
		if (father == null) {
			parentID[0] = -1;
		} else {
			parentID[0] = father.getID();
		}

		if (mother ==null) {
			parentID[1] = -1;
		} else {
			parentID[1] = mother.getID();
		}

		this.id = counter++;
		
	}

	public String snippetsToInsert() {
		return Snippet.getSnippet(first) + "\n" + Snippet.getSnippet(second) + "\n" + Snippet.getSnippet(third) + "\n"
				+ Snippet.getSnippet(fourth);

	}

	public int getFirst() {
		return this.first;
	}

	public int getSecond() {
		return this.second;
	}

	public int getThird() {
		return this.third;
	}

	public int getFourth() {
		return this.fourth;
	}

	public static int genomeSize() {
		return 4;
	}
	
	public int getID() {
		return id;
	}

	public int[] getParentIDs() {
		return parentID;
	}

}
