// @JUDGE_ID:  17051CA  120  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  int pan[];
  int number;
  String f;
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
    pan = new int[30];
    number = 0;
    while ((input = Main.ReadLn (255)) != null){
      st = new StringTokenizer(input);
      number=0;
      while( st.hasMoreTokens() ){
	pan[number] = Integer.parseInt( st.nextToken() );
	number++;
      }
      doFlip();
    }
  }

  void doFlip(){
    int point = number-1;
    String p = "";
    f = "";
    for(int i=0 ; i < number ; i++){
      p = p + " " + pan[i];
    }
    System.out.println(p.trim());
    for(int i=0 ; i < number ; i++){
      if( getMaxPoint(point) == point ){
	
      }else if( getMaxPoint(point) == 0){
	flip(point);
      }else {
	flip(getMaxPoint(point));
	flip(point);
      }
      point--;
    }
    f = f + " " + 0;
    System.out.println( f.trim() );
  }
  
  void flip(int point){
    int[] tmpPan = new int[point+1];
    for(int i=0 ; i < point+1 ; i++){
      tmpPan[i] = pan[i];
    }
    for(int i=0 ; i < point+1 ; i++){
      pan[i] = tmpPan[point-i];
    }
    f = f + " " + (number-point);
  }

  int getMaxPoint(int point){
    int maxP = 0;
    int maxV = 0;
    for(int i=0 ; i <= point ; i++){
      if( pan[i] > maxV){
	maxV = pan[i];
	maxP = i;
      }
    }
    return maxP;
  }
}
// @end_of_source_code

