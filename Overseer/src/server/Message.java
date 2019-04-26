package server;

/**
 * A class that wraps around the datagrams received from the server. Hold both time and point value information.
 * 
 * @author Sean Dwyer
 *
 */
public class Message
{
  private int[] points;
  private int runtime;
  
  
  /**
   * Get the point values from the message.
   * 
   * @return the points
   */
  public int[] getPoints()
  {
    return points;
  }
  /**
   * Set the point values.
   * 
   * @param points the points to set
   */
  public void setPoints(int[] points)
  {
    this.points = points;
  }
  /**
   * Get the ammount of time from the compitiion
   * 
   * @return the runtime
   */
  public int getRuntime()
  {
    return runtime;
  }
  /**
   * @param runtime the runtime to set
   */
  public void setRuntime(int runtime)
  {
    this.runtime = runtime;
  }
  
  /**
   * Explicit value constructor. takes an array of integer and a single integer.
   * 
   * @param points - The point values for each thread.
   * @param runtime - The runtime for the competition as a whole.
   */
  public Message(int[] points, int runtime)
  {
    super();
    this.points = points;
    this.runtime = runtime;
  }
  
}
