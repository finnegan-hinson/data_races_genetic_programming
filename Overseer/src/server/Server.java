package server;

import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * 
 * @author Sean Dwyer
 */
public class Server
{
  // Singleton
  private static Server server;
  private static final int DEFUALT_PORT = 6559;
  private DatagramSocket socket;
  private DatagramPacket packet;
  private byte[] recvBuffer;

  public void close()
  {
    socket.close();
    server = null;
  }

  public int[] recvPoints()
  {
    try
    {
      socket.receive(packet);
    }
    catch (IOException e)
    {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }

    return bytesToInts(packet.getData(), 7);
  }

  public static Server initServer()
  {
    return initServer(DEFUALT_PORT);
  }

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

  private Server(int port) throws SocketException
  {
    recvBuffer = new byte[124];
    socket = new DatagramSocket(port);
    packet = new DatagramPacket(recvBuffer, recvBuffer.length);
  }

  /**
   * NOTE: This function assumes little endian.
   * 
   * @param in
   * @param size
   * @return
   */
  private int[] bytesToInts(byte[] in, int size)
  {
    ByteBuffer byteBuffer = ByteBuffer.wrap(in);
    int[] retInts = new int[size];
    
    byteBuffer.order(ByteOrder.LITTLE_ENDIAN);
    
    byteBuffer.getInt();

    for (int x = 0; x < size; x++)
    {
      retInts[x] = byteBuffer.getInt();
    }

    return retInts;
  }
}
