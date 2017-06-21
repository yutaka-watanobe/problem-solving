// @JUDGE_ID:  17051CA  ***  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class P{

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
    P p = new P();  // create a dinamic instance
    p.Begin();            // the true entry point
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    
    while ((input = P.ReadLn (255)) != null){
      System.out.println (input);
    }
  }
}
// @end_of_source_code

