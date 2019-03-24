package overseer;

import java.io.IOException;
import java.util.Arrays;

import incubator.GenomeWriter;
import incubator.Incubator;
import incubator.Population;
import server.Server;

public class Overseer
{
  private static boolean cluster;
  private static int port;
  private static String runString;
  
  private static final String RUN = "./runner";
  private static final String CLUSTER_RUN = "srun ./runner";

  /**
   * Accepts two arguments, the number of itterations and any second argument denoting that the
   * program is running on the JMU cluster.
   * 
   * @param args
   */
  public static void main(String[] args)
  {
    int itt;
    
    int[] points;
    
    Server server = null;
    
    if(args.length > 2 || args.length < 1)
    {
      System.out.println("Invalid argument count");
      return;
    }
    try {
      itt = Integer.parseInt(args[0]);
    }
    catch(NumberFormatException e)
    {
      System.out.println("The 1st parameter must be an integer");
      return;
    }
    
    runString = RUN;
    
    server = Server.initServer();
    
    //TODO Inital population creation.
    
    if(args.length == 3)
    {
      runString = CLUSTER_RUN;
    }
    
    Population population = new Population(7);
    
    String homeDirectory = System.getProperty("user.dir");
    
    for(int x = 0; x < itt; x++)
    {
          
      GenomeWriter writer = new GenomeWriter(population, homeDirectory + "/base_population.h",
                                              homeDirectory + "/population.h", "// Insert");
      
      try
      {
        writer.writePopulation();
      }
      catch (IOException e)
      {
        e.printStackTrace();
      }
      
      makeAndRun();
      points = server.recvPoints();
      
      //TODO Remove debug statement.
      System.out.println(Arrays.toString(points));
      
      population.determineFitness(points);
      
      Incubator.nextGeneration(population);
    }
  }
  
  private static void makeAndRun()
  {
    try
    {
      Runtime.getRuntime().exec("make clean").waitFor();
      Runtime.getRuntime().exec("make").waitFor();
      Runtime.getRuntime().exec(runString);
    }
    catch (InterruptedException | IOException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
      System.exit(1);
    }
  }
  
  private static void makeAndRunIDE()
  {
    try
    {
      Runtime.getRuntime().exec("make --directory=../ clean").waitFor();
      Runtime.getRuntime().exec("make --directory=../").waitFor();
      Runtime.getRuntime().exec("../runner");
    }
    catch (InterruptedException | IOException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
      System.exit(1);
    }
  }
}
