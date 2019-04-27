package incubator;

import java.io.*;

/**
 * This class writes the evolved genome snippets to the given .h file at given
 * positions.
 * 
 * The write code is influenced by the implementation here:
 * https://javaconceptoftheday.com/modify-replace-specific-string-in-text-file-in-java/
 * 
 * It is then to be executed in C by the runner.
 * 
 * @author Virginia R Hinson
 *
 */
public class GenomeWriter {
	private Population genomes;
	private String filepath;
	private String newFilePath;
	private String indicator;

	/**
	 * Creates a GenomeWriter object to write the snippets to a file.
	 * 
	 * 
	 * @param genomes     the population to be written to a file
	 * @param filepath    the source filepath for the code before genome snippets
	 *                    are inserted
	 * @param newFilePath the source filepath for the final file with snippets
	 *                    inserted
	 * @param indicator   a string delimiter indicating where in the original file
	 *                    snippets should be added
	 */
	public GenomeWriter(Population genomes, String filepath, String newFilePath, String indicator) {
		this.genomes = genomes;
		this.filepath = filepath;
		this.newFilePath = newFilePath;
		this.indicator = indicator.trim();

	}

	/**
	 * This method increments through the file specified to the constructor, reading
	 * each line and copying it to the new file, adding the code for one genome in
	 * the population each time a delimiter is reached in said file.
	 * 
	 * @throws IOException if reading/writing to the file go wrong
	 */
	public void writePopulation() throws IOException {
		File fileToWrite = new File(this.newFilePath);

		BufferedReader reader = null;

		String newFile = "";

		reader = new BufferedReader(new FileReader(filepath));

		String line = null;

		line = reader.readLine();
		int genomeNumber = 1;

		// Read in all the lines
		while (line != null) {
			// When the program hits the indicator lines, insert a genome
			if (line.trim().equals(this.indicator)) {
				newFile = newFile + "\n" + genomes.genomeSnippets(genomeNumber % genomes.getPopulationSize());

				genomeNumber++;
			} else {
				// If you don't encounter the indicator, simply add the code to the new file
				newFile = newFile + "\n" + line;
			}

			line = reader.readLine();
		}

		// Write this new file to the specified location
		FileWriter writer = new FileWriter(fileToWrite);
		writer.write(newFile);

		reader.close();
		writer.close();

	}

}
