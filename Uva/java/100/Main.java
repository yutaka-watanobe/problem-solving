// @JUDGE_ID:  17051CA  100  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  private int max;
  private int count;

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
      st = new StringTokenizer(input);
      int i = Integer.parseInt(st.nextToken());
      int j = Integer.parseInt(st.nextToken());
      max = 0;
      if( j >= i){
	for(int a=i ; a <= j ; a++){
	  searchMax(a);
	  if( count > max ) max = count;
	}
      } else {
	for(int a=j ; a <= i ; a++){
	  searchMax(a);
	  if( count > max ) max = count;
	}
      }
      System.out.println(i + " " + j + " " + max);
    }
  }

  void searchMax(int a){
    count = 0;
    parse( a ) ;
  }

  void parse(int n){
    count++;
    if(n==1) return;
    if( (n%2) != 0 ) n = 3*n + 1;
    else n = n/2;
    parse( n );
  }
}
// @end_of_source_code

