package server;

import java.io.IOException;
import java.util.Arrays;

public class ServerTestDriver
{

  public static void main(String[] args)
  {
    System.out.println(System.getProperty("user.dir"));
    System.out.println("Making C program");
    
    try
    {
      Runtime.getRuntime().exec("make --directory=../ clean").waitFor();
      Runtime.getRuntime().exec("make --directory=../").waitFor();
      Runtime.getRuntime().exec("../runner");
    }
    catch (IOException | InterruptedException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
    
    Server server = Server.initServer();
    System.out.println("Getting Points from Runner");
    System.out.println(Arrays.toString(server.recvPoints()));
    
    server.close();
  }

}
