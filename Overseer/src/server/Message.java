package server;

public class Message
{
  private int[] points;
  private int runtime;
  
  
  /**
   * @return the points
   */
  public int[] getPoints()
  {
    return points;
  }
  /**
   * @param points the points to set
   */
  public void setPoints(int[] points)
  {
    this.points = points;
  }
  /**
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
   * @param points
   * @param runtime
   */
  public Message(int[] points, int runtime)
  {
    super();
    this.points = points;
    this.runtime = runtime;
  }
  
  
}
