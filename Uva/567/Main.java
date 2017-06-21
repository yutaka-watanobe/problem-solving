// @JUDGE_ID:  17051CA  567  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  private boolean[][] g;
  private boolean flag;
  private int num, testCase;

  static String ReadLn (int maxLg) {
    byte lin[] = new byte [maxLg];
    int lg = 0, car = -1;
    String line = "";
    try {
      while (lg < maxLg){
	car = System.in.read();
	if ((car < 0) || (car == '\n')) break;
	lin [lg++] += car;
      }
    }catch (IOException e){
      return (null);
    }
    if ((car < 0) && (lg == 0)) return (null);  // eof
    return (new String (lin, 0, lg));
  }
  
  public Main(){
    this.Begin();
  }
  
  public static void main (String args[]){
    Main risk = new Main(); 
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    testCase = 1;
    while(true){
      g = new boolean[21][21];
      for(int i=1 ; i <= 19 ; i++){
	input = Main.ReadLn(255); 
	if( input == null ) return;
	st = new StringTokenizer(input);
	if( !(st.hasMoreTokens()) ) return;
	st.nextToken();
	while(st.hasMoreTokens()){
	  int p = Integer.parseInt(st.nextToken());
	  g[i][p] = true;
	  g[p][i] = true;
	}
      }
      System.out.println("Test Set #" + Integer.toString(testCase));
      st = new StringTokenizer(  Main.ReadLn(255) );
      int N = Integer.parseInt(st.nextToken());
      for(int i=0 ; i<N ; i++){
	st = new StringTokenizer( Main.ReadLn(255) ); 
	int start = Integer.parseInt(st.nextToken());
	int end = Integer.parseInt(st.nextToken());
	search(start, end);
      }
      testCase++;
      System.out.println();
    }
  }
  
  public void search(int s, int e){
    int n=1;
    flag = true;
    while(flag){
      parse(s, e, n++);
      num = n-1;
    }
    System.out.println( setS(2, Integer.toString(s)) + " to " + setS(2, Integer.toString(e)) + ":" + setS(2, Integer.toString(num)) );
  }
  
  public void parse(int s, int e, int n){
    if(n > 0){
      for(int j=1 ; j<=20 ; j++){
	if(g[s][j]){
	  if(j == e){
	    flag = false;
	    return;
	  }else{
	    parse(j, e, n-1);
	  }
	}
      }
    }
  }
  
  public String setS(int l, String s){
    while(s.length() < l){
      s = " " + s;
    }
    return s;
  }
}
// @end_of_source_code

