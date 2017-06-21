// @JUDGE_ID:  17051CA  10055  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;
import java.lang.Math;

class Main{
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
    Main myWork = new Main();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    long v1, v2;
    long ans = 0;
    while ((input = Main.ReadLn (255)) != null){
      st = new StringTokenizer( input ) ;
      v1 = Long.parseLong( st.nextToken() );
      v2 = Long.parseLong( st.nextToken() );
      ans = Math.abs( v1 - v2 );
      System.out.println( ans );
    }
  }
}
// @end_of_source_code

