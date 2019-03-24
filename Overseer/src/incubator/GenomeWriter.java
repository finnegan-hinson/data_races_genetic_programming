package incubator;
import java.io.*;

/**
 * This class writes the evolved genome snippets to the given .h file at given positions.
 * 
 * The write code is influenced by the implementation here:
 * https://javaconceptoftheday.com/modify-replace-specific-string-in-text-file-in-java/ 
 * 
 * It is then to be executed in C by the runner.
 * 
 * @author Virginia R Hinson
 *
 */
public class GenomeWriter
{
  private Population genomes;
  private String filepath;
  private String newFilePath;
  private String indicator;
  
  public GenomeWriter(Population genomes, String filepath, String newFilePath, String indicator) 
  {
    this.genomes = genomes;
    this.filepath = filepath;
    this.newFilePath = newFilePath;
    this.indicator = indicator.trim();
    
  }
  
  public void writePopulation() throws IOException
  {
    File fileToWrite = new File(this.newFilePath);
    
    BufferedReader reader = null;
    
    String newFile = "";
    
    reader = new BufferedReader(new FileReader(filepath));
    
    String line = null;
    
    line = reader.readLine();
    int genomeNumber = 1;
    
    while (line != null) 
    {
       if (line.trim().equals(this.indicator)) 
       {
         newFile = newFile + "\n" + genomes.genomeSnippets(genomeNumber % genomes.getPopulationSize());
         
         genomeNumber++;
       } 
       else 
       {
         newFile = newFile + "\n" + line;
       }
       
       line = reader.readLine();       
    }
    
    FileWriter writer = new FileWriter(fileToWrite);
    
    writer.write(newFile);
    
    reader.close();
    writer.close();
    
    
  }
  
}
