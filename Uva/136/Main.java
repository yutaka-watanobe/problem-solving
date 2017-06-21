// @JUDGE_ID:  17051CA  136  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;
import java.lang.Math;
import java.util.Arrays;

class Main{
  long[] uglyN;
  public static void main (String args[]){  // entry point from OS
    Main myWork = new Main();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    int cnt = 1;
    uglyN = new long[1728+1];
    for(int n=0 ; n < 12 ; n++){
      for(int m=0 ; m < 12 ; m++){
	for(int l=0 ; l < 12 ; l++){
	  uglyN[cnt] = (long)(Math.pow(2, n)*Math.pow(3, m)*Math.pow(5, l));
	  cnt++;
	}
      }
    }
    
    Arrays.sort(uglyN);

    System.out.println("The 1500'th ugly number is " + uglyN[1500] + ".");
  }
}
// @end_of_source_code

