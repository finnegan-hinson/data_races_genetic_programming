package server;

import java.util.Arrays;

public class ServerTestDriver
{

  public static void main(String[] args)
  {
    Server server = Server.initServer();
    System.out.println("Getting Points from Runner");
    System.out.println(Arrays.toString(server.recvPoints()));
    
    server.close();
  }

}
