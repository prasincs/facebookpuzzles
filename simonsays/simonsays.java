import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import java.util.*;

public class simonsays{
    public static void main(String[] args) throws Throwable {

        // Set up the thrift connection to the Facebook servers
        TTransport transport =
            new TSocket("thriftpuzzle.facebook.com", 9030);
        TProtocol protocol = new TBinaryProtocol(transport);
        SimonSays.Client client = new SimonSays.Client(protocol);
        transport.open();

        // Register client
        client.registerClient("prasannagautam@gmail.com");

        boolean done = false;

        while(!done){

            // Retrieve color list
            List<Color> listColors = client.startTurn();

            // Some debug information
            System.out.println(listColors.size());

            // Play back colors list
            for(Color color : listColors){
                client.chooseColor(color);
            }

            // If we're done, endTurn() will return true.
            done = client.endTurn();
        }

        String pwd = client.winGame();
        System.out.println(pwd);
    }
}
