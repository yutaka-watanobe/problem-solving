// @JUDGE_ID:  17051CA  10008  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  int strN[];

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
    String str = "";
    strN = new int[27];
    while ((input = Main.ReadLn (255)) != null){
      str = str + input;
    }
   
    for(int i=0 ; i < str.length() ; i++){
      char c = str.charAt(i); 
      if( Character.isLetter( c ) ){
	c = Character.toUpperCase( c );
	strN[ c - 'A' + 1 ]++;
      }
    }
    
    for(int i=0 ; i < strN.length ; i++){
      int id = getMaxIndex();
      if( getMaxIndex() != -1){
	char c = (char)(id - 1 + 'A');
	System.out.println( c + " " + strN[id]);
	strN[id] = 0;
      }
    }
  }

  int getMaxIndex(){
    int maxI = 0;
    int max = 0;
    for(int i=0 ; i < strN.length ; i++){
      if( strN[i] > max ){
	max = strN[i]; maxI = i;
      }
    }
    if( max == 0 ) return -1;
    else return maxI;
  }
}
// @end_of_source_code

