// @JUDGE_ID:  17051CA  10035  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

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
    
    while ((input = Main.ReadLn (255)) != null){
      st = new StringTokenizer( input );
      String s1 = st.nextToken();
      String s2 = st.nextToken();
      
      if( s1.equals("0") && s2.equals("0") ) return;
      
      if( s1.length() > s2.length() ){
	while( s1.length() != s2.length() ){
	  s2 = "0" + s2;
	}
      }else{
	while( s1.length() != s2.length() ){
	  s1 = "0" + s1;
	}
      }
      
      int carry = 0;
      int carryCount = 0;
      for(int i=0 ; i < s1.length() ; i++){
	int index = s1.length() - i - 1;
	int v1 = Character.getNumericValue(s1.charAt(index));
	int v2 = Character.getNumericValue(s2.charAt(index));
	carry = v1 + v2 + carry;
	carry = carry / 10 ; 
	if( carry > 0 ) carryCount++;
      }
      
      if( carryCount == 0 ){
	System.out.println("No carry operation.");
      } else if (carryCount == 1 ){
	System.out.println("1 carry operation.");
      } else {
	System.out.println( carryCount + " carry operations." );
      }
    }
  }
}
// @end_of_source_code

