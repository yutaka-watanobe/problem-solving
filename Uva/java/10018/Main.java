// @JUDGE_ID:  17051CA  10018  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  int count;
  long ans;
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
    long value;
    StringTokenizer st;
    
    int N = Integer.parseInt( Main.ReadLn(255) );
    for(int i=0 ; i<N ; i++){
      value  = Long.parseLong(Main.ReadLn(255));
      count = 0;
      ans = 0;
      f( value );
      System.out.println(count + " " + ans);
    }
  }

  void f( long v ){
    if( isPalindrome( Long.toString(v) )){
      ans = v;
    }else{
      long r = reverse( v );
      long sum = v + r;
      count++;
      f( sum );
    }
  }
  
  long reverse(long v){
    String s = Long.toString( v );
    String rs = "";
    for( int i=s.length()-1 ; i>=0  ; i--){
      rs = rs + s.charAt(i);
    }
    return Long.parseLong(rs);
  }

  boolean isPalindrome(String s){
    int i,j;
    int index = 0;
    for(i=0, j=s.length()-1 ; i<s.length()/2 ; i++, j--){
      if( s.charAt(i) == s.charAt(j) ){
	index++;
      }
    }
    if( index == s.length()/2) return true;
    else return false;
  }
}
// @end_of_source_code

