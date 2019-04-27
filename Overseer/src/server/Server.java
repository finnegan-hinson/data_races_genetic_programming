package server;

import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Arrays;

import overseer.Overseer;

/**
 * A class for a simple server, this server only receives UDP datagrams from the master compitition process.
 * 
 * @author Sean Dwyer
 */
public class Server
{
  // Singleton
  private static Server server;
  private static final int DEFUALT_PORT = 6559;
  private static final int TIMEOUT = 15000; //15 sec
  private DatagramSocket socket;
  private DatagramPacket packet;
  private byte[] recvBuffer;

  /**
   * Close the server.
   */
  public void close()
  {
    socket.close();
    server = null;
  }

  /**
   * Receive a message from the master competition process.
   * 
   * @return The message from the C process.
   * @throws SocketTimeoutException
   */
  public Message recvMessage() throws SocketTimeoutException
  {
    
    try
    {
      socket.receive(packet);
    }
    catch(SocketTimeoutException e)
    {
      throw e;
    }
    catch (IOException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }

    return new Message(getPoints(packet.getData(), Overseer.POPULATION_SIZE), getTime(packet.getData()));
  }

  /**
   * Initialize a sever to the default port.
   * 
   * @return The resulting server
   */
  public static Server initServer()
  {
    return initServer(DEFUALT_PORT);
  }

  /**
   * Initialize the server to the given port.
   * 
   * @param port - The port to bind the server to.
   * @return A server object resulting from the given initalization.
   */
  public static Server initServer(int port)
  {
    if (server != null)
    {
      return server;
    }

    try
    {
      server = new Server(port);
    }
    catch (SocketException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
    
    return server;
  }

  /**
   * Private constructor for a server.
   * 
   * @param port - the port to be bound.
   * 
   * @throws SocketException - Thrown if a networking area has occurred.
   */
  private Server(int port) throws SocketException
  {
    recvBuffer = new byte[1024];
    socket = new DatagramSocket(port);
    socket.setSoTimeout(TIMEOUT);
    packet = new DatagramPacket(recvBuffer, recvBuffer.length);
  }

  /**
   * Read the second integer in the datagram packet representing the amount of time it took for the compition to finish.
   * 
   * NOTE: This function assumes little endian format.
   * 
   * @param in - The byte array from the datagram packet.
   * @return The time (in milliseconds) that it took for the competition to complete.
   */
  private int getTime(byte[] in)
  {
    ByteBuffer byteBuffer = ByteBuffer.wrap(in);
    
    byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
    
    byteBuffer.getInt(); //Skip past elements header.

    return byteBuffer.getInt();
  }
  
  /**
   * Get the point values from the C competitions. Takes an byte array and number of elements to be read.
   * 
   * NOTE: This method assumes that the datagram is encoded in little endian format.
   * 
   * @param in - The byte array from the datagram packet.
   * @param size - The number of elements to be read from the datagram.
   * 
   * @return An array of integers of the resulting point values.
   */
  private int[] getPoints(byte[] in, int size)
  {
    ByteBuffer byteBuffer = ByteBuffer.wrap(in);
    int[] retInts = new int[size];
    
    byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
    
    byteBuffer.getInt(); //Skip past elements header
    byteBuffer.getInt(); //Skip past time.

    for (int x = 0; x < size; x++)
    {
      retInts[x] = byteBuffer.getInt();
    }

    return retInts;
  }
  
}
