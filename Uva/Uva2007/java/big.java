import java.io.*;
import java.util.*;
import java.math;

class Big{
  static String ReadLn (int maxLg){  // utility function to read from stdin
    byte lin[] = new byte [maxLg];
    int lg = 0, car = -1;
    String line = "";
    
    try{
      while (lg < maxLg){
	car = System.in.read();
	if ((car < 0) || (car == '\n')) break;
	lin [lg++] += car;
      }
    } catch (IOException e){
      return (null);
    }
    
    if ((car < 0) && (lg == 0)) return (null);  // eof
    return (new String (lin, 0, lg));
  }
  
  public static void main (String args[]){  // entry point from OS
    Big p = new Big();  // create a dinamic instance
    p.Begin();            // the true entry point
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    Vector num = new Vector();

    while ((input = P.ReadLn (255)) != null){
      num.addElement(input);
    }

    BigInteger a = BigInteger(num.elementAt(0));
    BigInteger b = BigInteger(num.elementAt(1));

    a.add(b);

    System.out.println( a.toString());
  }

}
// @end_of_source_code

