package incubator;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

/**
 * The incubator, who genetically determines the new code.
 * 
 * @author Virginia R Hinson
 *
 */
public class Incubator
{  
  Genome fittest;
  Genome secondFittest;
  int generation = 0;
  static final double MUTATION_RATE = 0.02;
  
  
  private static Genome[] crossover(Genome first, Genome second) {
    Genome[] recombined = new Genome[2];
    
    Random random = new Random();
    int crossoverPoint = random.nextInt(3) + 1; // 1 - 3
    
    switch(crossoverPoint) 
    {
      case 1:
        recombined[0] = new Genome(first.getFirst(), second.getSecond(), 
            second.getThird(), second.getFourth());
        recombined[1] = new Genome(second.getFirst(), first.getSecond(), 
            first.getThird(), first.getFourth());
        break;
      case 2:
        recombined[0] = new Genome(first.getFirst(), first.getSecond(), 
            second.getThird(), second.getFourth());
        recombined[1] = new Genome(second.getFirst(), second.getSecond(), 
            first.getThird(), first.getFourth());
        break;
      case 3:
        recombined[0] = new Genome(first.getFirst(), first.getSecond(), 
            first.getThird(), second.getFourth());
        recombined[1] = new Genome(second.getFirst(), second.getSecond(), 
            second.getThird(), first.getFourth());
        break;
      
    }
    
    if (random.nextDouble() < MUTATION_RATE) 
    {
      if(random.nextBoolean()) {
        recombined[0] = mutation(recombined[0]);
        
      } else {
        recombined[1] = mutation(recombined[1]);
      }
      
    }
    
    return recombined;
    
  }
  
  public static Genome mutation(Genome toMutate) {
    
    Random random = new Random();
    
    int snippetToMutate = random.nextInt(4) + 1; // 1 - 4, the snippet to be changed
    int amountToMutate = random.nextInt(3) - 1;  // -1 - 1 the amount to change, could be 0

    int first, second, third, fourth;
    first = toMutate.getFirst();
    second = toMutate.getSecond();
    third = toMutate.getThird();
    fourth = toMutate.getFourth();
    
    switch(snippetToMutate) {
      case 1:
        first = first + amountToMutate;
        break;
      case 2:
        second = second + amountToMutate;
        break;
      case 3:
        third = third + amountToMutate;
        break;
      case 4: 
        fourth = fourth + amountToMutate;
        break;
    }
    
    return new Genome(first, second, third, fourth);
    
  }
  
  public static void nextGeneration(Population population) 
  {
    ArrayList<Genome> nextGeneration = new ArrayList<Genome>();
    Random random = new Random();
    
    // Who moves along in the death race?
    Genome[] winners = crossover(population.getFittest(), population.getSecondFittest());
    
    nextGeneration.add(winners[0]);
    nextGeneration.add(winners[1]);
    
    int remaining = population.getPopulationSize() - 2;
    
    while (remaining > 0) 
    {
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
  
  public static void main(String[] args) {
    Population population = new Population(7);
    
    String homeDirectory = System.getProperty("user.dir");
    
    System.out.println(homeDirectory);
        
    GenomeWriter writer = new GenomeWriter(population, homeDirectory + "\\base_population.h",
                                            homeDirectory + "\\population.h", "// Insert");    
    
    try
    {
      writer.writePopulation();
    }
    catch (IOException e)
    {
      e.printStackTrace();
    }
    
    
    // Execute C code here
    
    
    // Get fitness array here
    int[] fitnessNumbers = new int[7];
    
    population.determineFitness(fitnessNumbers);
    
    // After this is done determine a new population
    nextGeneration(population);
    
    // And do it again if need be!
    
    
    
  }

}
