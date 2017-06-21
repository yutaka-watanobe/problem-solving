// @JUDGE_ID:  17051CA  138  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;
import java.lang.Math;

class Main{
  public static void main (String args[]){  // entry point from OS
    Main myWork = new Main();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    long l, n, m, cnt;
    String strn = new String();
    String strm = new String();
    int miss = 0;
    for(cnt=0, l=2; cnt<10; l++){
      m = 2*l*l;
      n = (int)Math.rint(Math.sqrt(m*(m+1)/2));
      if(2*n*n==m*(m+1)){
	strn = Long.toString(n);
	strm = Long.toString(m);
      } else {
	m = l*l;
	n = (int)Math.rint(Math.sqrt(m*(m+1)/2));
	if(2*n*n==m*(m+1)){
	  System.out.println("test");
	  strn = Long.toString(n);
	  strm = Long.toString(m);
	}else{
	  miss++;
	  continue;
	}
      }
      while(strn.length() < 10) strn = " "+strn;
      while(strm.length() < 10) strm = " "+strm;
      System.out.println(strn+strm);
      cnt++;
    }
    System.out.println(miss);
  }
}
// @end_of_source_code

