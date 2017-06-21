// @JUDGE_ID:  17051CA  138  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  public static void main (String args[]){  // entry point from OS
    Main myWork = new Main();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    int n = 2;
    int count = 0;
    int[] house;
    while(count < 11 ){
      house = new int[n+1];
      for(int i=1 ; i <= n ; i++){
	if( func( n, i ) ) {
	  count++;
	  System.out.println( i + "   " + n );
	}
      }
      n++;
    }
  }
  
  boolean func( int n, int h ){
    //if( ((h-1)*h) == ((n-h)*(h+1+n)) ) return true;
    if( 2*h*h == n*(n+1) ) return true;
    else return false;
  }
}
// @end_of_source_code

